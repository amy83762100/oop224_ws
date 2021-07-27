/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author Pei-Yi Lin
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/26  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
using namespace std;
namespace sdds {
	PreTriage::PreTriage(const char* dataFilename):m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit",2),m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage",2) {
		int len = strlen(dataFilename);
		m_dataFilename = new char[len+1];
		strcpy(m_dataFilename, dataFilename);
		m_dataFilename[len] = '\0';
		m_averCovidWait = 15;
		m_averTriageWait = 5;
		load();
	}
	PreTriage::~PreTriage() {
		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: " << m_averCovidWait << endl;
		cout << "   Triage: " << m_averTriageWait << endl;
		cout << "Saving m_lineup..." << endl;
		ofstream csvfile(m_dataFilename, ofstream::trunc);
		if (csvfile.is_open()) {
			csvfile << m_averCovidWait << ',' << m_averTriageWait << endl;
			for (int i = 0; i < m_lineupSize; i++) {
				cout << i + 1 << " - ";
				m_lineup[i]->csvWrite(cout);
				cout << endl;
				m_lineup[i]->csvWrite(csvfile);
				csvfile << endl;
			}
		}
		else cout << "fail to save m_lineup";
		for (int i = 0; i < maxNoOfPatients; i++)
		{
			delete m_lineup[i];
		}
		delete[] m_dataFilename;
		cout << "done!" << endl;
	}
	const Time PreTriage::getWaitTime(const Patient& p)const {
		int noOfPatient = 0;
		for (int i = 0; i < m_lineupSize; i++) {
			if (*m_lineup[i] == p) noOfPatient++;
		}
		return noOfPatient;
	}
	void PreTriage::setAverageWaitTime(const Patient& p) {
		Time CT;
		CT.setToNow();
		Time AWT = p == 'C' ? m_averCovidWait : m_averTriageWait;
		p == 'C' ? m_averCovidWait : m_averTriageWait = ((CT-Time(p)) + (AWT * (unsigned int)(p.number() - 1))) / (unsigned int)p.number();

	}
	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}
	int PreTriage::indexOfFirstInLine(char type) const {
		int index = -1;
		for (int i = 0; i < m_lineupSize; i++)
			if (*m_lineup[i] == type) {
				index = i; break;
			}
		return index;
	}
	void PreTriage::load() {
		ifstream csvfile(m_dataFilename);
		cout << "Loading data..." << endl;
		csvfile >> m_averCovidWait;
		csvfile.ignore(1, ',');
		csvfile >> m_averTriageWait;
		csvfile.ignore(1, '\n');
		Patient* patient=nullptr;
		for (int i = 0; (i < maxNoOfPatients) && csvfile; i++) {
			char type=0;
			csvfile >> type;
			csvfile.ignore(1, ',');
			if (type == 'C') patient = new CovidPatient;
			else if (type == 'T')patient = new TriagePatient;
			else break;
			if (patient) {
				patient->fileIO(true);
				//patient->csvRead(csvfile);
				csvfile >> *patient;
				patient->fileIO(false);
				m_lineup[i] = patient;
				m_lineupSize++;
			}
		}
		if (csvfile) cout << "Warning: number of records exceeded 100" << endl;
		if (m_lineupSize == 0) cout << "No data or bad data file!" << endl;
		else cout << m_lineupSize << " Records imported..." << endl;
		cout << endl;
	}
	void PreTriage::reg() {
		if (m_lineupSize >= maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
			return;
		}
		int selection;
		m_pMenu >> selection;
		if (selection == 1) m_lineup[m_lineupSize] = new CovidPatient;
		if (selection == 2) m_lineup[m_lineupSize] = new TriagePatient;
		if (selection == 0) return;
		m_lineup[m_lineupSize]->setArrivalTime();
		cout << "Please enter patient information: " << endl;
		m_lineup[m_lineupSize]->fileIO(false);
		m_lineup[m_lineupSize]->read(cin);
		cout << endl << "******************************************" << endl;
		m_lineup[m_lineupSize]->write(cout);
		cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
		cout << "******************************************" << endl << endl;
		m_lineupSize++;
	}
	void PreTriage::admit() {
		int selection, index;
		char type='\0';
		m_pMenu >> selection;
		if (selection == 1) type = 'C';
		if (selection == 2) type = 'T';
		if (selection == 0) return;
		index = indexOfFirstInLine(type);
		if (index == -1)return;
		cout << endl << "******************************************" << endl;
		m_lineup[index]->fileIO(false);
		cout << "Calling for ";
		m_lineup[index]->write(cout);
		cout << "******************************************" << endl << endl;
		setAverageWaitTime(*m_lineup[index]);
		removePatientFromLineup(index);
	}
	void PreTriage::run() {
		int selection;
		while (true)
		{
			m_appMenu >> selection;
			if (selection == 1) reg();
			if (selection == 2) admit();
			if (selection == 0) break;
		}
	}
}
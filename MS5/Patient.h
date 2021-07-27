#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"
namespace sdds {
    class Patient:public IOAble {
        char* m_name;
        int m_OHIPnumber;
        Ticket m_ticket;
        bool m_fileIO;
    public:
        Patient(int ticketNumber, bool fileIO = false);
        Patient& operator=(const Patient&) = delete;
        ~Patient();
        virtual char type() const = 0;
        bool fileIO() const;
        void fileIO(bool fileIO);
        void setArrivalTime();
        operator Time()const;
        int number() const;
        std::ostream& csvWrite(std::ostream& ostr)const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
    };
    bool operator==(const Patient&, const char&);
    bool operator==(const Patient&, const Patient&);
}
#endif // !SDDS_PATIENT_H_

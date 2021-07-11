#ifndef SDDS_MENU_H
#define SDDS_MENU_H
namespace sdds {
    class Menu {
        char* m_text; // holds the menu content dynamically
        int m_noOfSel;  // holds the number of options displayed in menu content
        void display()const;
    public:
        Menu(const char* MenuContent, int NoOfSelections);
        virtual ~Menu();
        int& operator>>(int& Selection);
        // add safe copying logic
        Menu(const Menu&);
    };
}
#endif //!SDDS_MENU_H
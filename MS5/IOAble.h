#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>
namespace sdds {
    class IOAble {
        
    public:
        virtual std::ostream& csvWrite(std::ostream&) const = 0;
        virtual std::istream& csvRead(std::istream&) = 0;
        virtual std::ostream& write(std::ostream&) const = 0;
        virtual std::istream& read(std::istream&) = 0;
        virtual ~IOAble() {};
    };
    std::ostream& operator<<(std::ostream& ostr, IOAble& ioable);
    std::istream& operator>>(std::istream& istr, IOAble& ioable);
}
#endif // !SDDS_IOABLE_H


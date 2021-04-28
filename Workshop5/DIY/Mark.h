
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_value = 0;
    public:
        void isValid();
        Mark();
        Mark(int value);
        operator int()const;
        Mark& operator+=(int value);
        Mark& operator=(const Mark& value);
        operator double() const;
        operator char() const;
    };
    int operator+=(int& value, const Mark& right);
}
#endif 

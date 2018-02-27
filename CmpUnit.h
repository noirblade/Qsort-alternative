//
// Created by teodor on 1/8/18.
//

#ifndef SUPERQUICKSORT_CMPUNIT_H
#define SUPERQUICKSORT_CMPUNIT_H

#include <iostream>

class CmpUnit {

public:
    explicit CmpUnit(){};
    CmpUnit(const CmpUnit& unit) : count(unit.count) { }
    int count = 0;
    friend std::ostream& operator<<(std::ostream& os, const CmpUnit& unit)
    {
        os << unit.count;
        return os;
    }
    friend bool operator<( const CmpUnit& lhs, const CmpUnit& rhs )
    {
        //std::cout << "COUNT " << lhs.count << " < " << rhs.count << std::endl;
        return lhs.count < rhs.count;
    }

    friend bool operator>( const CmpUnit& lhs, const CmpUnit& rhs )
    {
        //std::cout << "COUNT " << lhs.count << " > " << rhs.count << std::endl;
        return lhs.count > rhs.count;
    }
};


#endif //SUPERQUICKSORT_CMPUNIT_H

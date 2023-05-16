#ifndef AK_IT_P_NS_ANTONSCVETKOVS_4MD_ETALONS_H
#define AK_IT_P_NS_ANTONSCVETKOVS_4MD_ETALONS_H
#include <iostream>
#include "Helpers.h"

using namespace std;

class eTalons {
public:
    eTalons();
    virtual void Print() const;
    virtual void Use() = 0;
    virtual void Add(int) = 0;

private:
    static string serialGenerator();

    string serial;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_4MD_ETALONS_H

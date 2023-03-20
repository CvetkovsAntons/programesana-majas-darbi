#ifndef AK_IT_P_NS_ANTONSCVETKOVS_2MD_2UZD_ARRAY_H
#define AK_IT_P_NS_ANTONSCVETKOVS_2MD_2UZD_ARRAY_H

#include <iostream>
#include <cassert>

using namespace std;


class Array {
public:
    Array(int = 6);
    ~Array();
    const Array &operator=(const Array &);
    double &operator[](int) const;

private:
    int size;
    double *ptr;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_2MD_2UZD_ARRAY_H

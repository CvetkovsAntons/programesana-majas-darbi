#ifndef AK_IT_P_NS_ANTONSCVETKOVS_2MD_2UZD_VECTOR_H
#define AK_IT_P_NS_ANTONSCVETKOVS_2MD_2UZD_VECTOR_H

#include "iostream"

using namespace std;

class Vector {
    friend ostream &operator<<(ostream &, const Vector &);
    friend istream &operator>>(istream &, Vector &);

public:
    Vector(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
    ~Vector();
    Vector &operator=(const Vector &);
    Vector operator+(const Vector &) const;
    const Vector operator-(const Vector &) const;
    const Vector operator*(const Vector &) const;
    bool operator>(const Vector &) const;
    bool operator<(const Vector &) const;
    bool operator>=(const Vector &) const;
    bool operator<=(const Vector &) const;
    bool operator==(const Vector &) const;
    bool operator!=(const Vector &) const;
    double getMagnitude() const;

private:
    double* coordinates = new double[6];
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_2MD_2UZD_VECTOR_H

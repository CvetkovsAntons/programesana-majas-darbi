#ifndef AK_IT_P_NS_ANTONSCVETKOVS_2MD_1UZD_TIME_H
#define AK_IT_P_NS_ANTONSCVETKOVS_2MD_1UZD_TIME_H

#include "iostream"

using namespace std;

class Time {
    friend ostream &operator<<(ostream &, const Time &);
    friend istream &operator>>(istream &, Time &);

public:
    Time(int = 0, int = 0, int = 0);
    Time& operator=(const Time &);
    Time operator++();
    Time operator++(int);
    Time operator--();
    Time operator--(int);
    bool operator>(const Time &) const;
    bool operator<(const Time &) const;
    bool operator>=(const Time &) const;
    bool operator<=(const Time &) const;
    bool operator==(const Time &) const;
    bool operator!=(const Time &) const;

private:
    int hours;
    int minutes;
    int seconds;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_2MD_1UZD_TIME_H

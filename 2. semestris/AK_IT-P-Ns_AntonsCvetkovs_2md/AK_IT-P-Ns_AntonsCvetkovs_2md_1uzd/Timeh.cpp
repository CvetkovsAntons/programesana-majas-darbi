#include "Time.h"

Time::Time(int h, int m, int s) {
    Time::hours = (h>=0 && h <24) ? h : 0; // ja ir noradits nepareizs laiks, tad peiskiram 0
    Time::minutes = (m>=0 && m<60) ? m : 0;
    Time::seconds = (s>=0 && s<60) ? s : 0;
}

ostream &operator<<(ostream &output, const Time &obj) {
    output
            << (obj.hours < 10 ? "0" : "") << obj.hours << ":"
            << (obj.minutes < 10 ? "0" : "") << obj.minutes << ":"
            << (obj.seconds < 10 ? "0" : "") << obj.seconds
            <<
            endl;

    return output;
}

istream&operator>>(istream &input, Time &obj) {
    string inputH, inputM, inputS;

    cout << "Enter hours: ";
    cin >> inputH;

    int i = 0;
    while (i < inputH.length()) {
        if (isdigit(inputH[i]) == false || stoi(inputH) < 0 || stoi(inputH) > 23) { // parbaudam, vai kads no simboliem ir burts
            cout << "Enter hours: ";
            input >> inputH;
            i = 0;
            continue;
        }

        i++;
    }

    cout << "Enter minutes: ";
    cin >> inputM;

    i = 0;
    while (i < inputM.length()) {
        if (isdigit(inputM[i]) == false || stoi(inputM) < 0 || stoi(inputM) > 59) { // parbaudam, vai kads no simboliem ir burts
            cout << "Enter minutes: ";
            input >> inputM;
            i = 0;
            continue;
        }

        i++;
    }

    cout << "Enter seconds: ";
    cin >> inputS;

    i = 0;
    while (i < inputS.length()) {
        if (isdigit(inputS[i]) == false || stoi(inputS) < 0 || stoi(inputS) > 59) { // parbaudam, vai kads no simboliem ir burts
            cout << "Enter seconds: ";
            input >> inputS;
            i = 0;
            continue;
        }

        i++;
    }

    obj.hours = stoi(inputH);
    obj.minutes = stoi(inputM);
    obj.seconds = stoi(inputS);

    return input;
}


Time& Time::operator=(const Time &right) {
    if (*this == right) {
        return *this;
    }

    Time::hours = right.hours;
    Time::minutes = right.minutes;
    Time::seconds = right.seconds;

    return *this;
}

Time Time::operator++() {
    if (Time::seconds == 59) {
        if (Time::minutes == 59) {
            if (Time::hours == 23) {
                Time::hours = 0;
            } else {
                Time::hours++;
            }

            Time::minutes = 0;
        } else {
            Time::minutes++;
        }

        Time::seconds = 0;
    } else {
        Time::seconds++;
    }

    return *this;
}

Time Time::operator++(int) {
    if (Time::minutes == 59) {
        if (Time::hours == 23) {
            Time::hours = 0;
        } else {
            Time::hours++;
        }

        Time::minutes = 0;
    } else {
        Time::minutes++;
    }

    return *this;

}

Time Time::operator--() {
    if (Time::seconds == 0) {
        if (Time::minutes == 0) {
            if (Time::hours == 0) {
                Time::hours = 23;
            } else {
                Time::hours--;
            }

            Time::minutes = 59;
        } else {
            Time::minutes--;
        }

        Time::seconds = 59;
    } else {
        Time::seconds--;
    }

    return *this;
}

Time Time::operator--(int) {
    if (Time::minutes == 0) {
        if (Time::hours == 0) {
            Time::hours = 23;
        } else {
            Time::hours--;
        }

        Time::minutes = 59;
    } else {
        Time::minutes--;
    }

    return *this;
}

bool Time::operator>(const Time &right) const {
    if (Time::hours > right.hours) {
        return true;
    }

    if (Time::hours == right.hours) {
        if (Time::minutes > right.minutes) {
            return true;
        }

        if (Time::minutes == right.minutes && Time::seconds > right.seconds) {
            return true;
        }
    }

    return false;
}

bool Time::operator<(const Time &right) const {
    return !(*this > right);
}

bool Time::operator>=(const Time &right) const {
    if (*this > right || *this == right) {
        return true;
    }

    return false;
}

bool Time::operator<=(const Time &right) const {
    if (*this < right || *this == right) {
        return true;
    }

    return false;
}

bool Time::operator==(const Time &right) const {
    if (Time::hours == right.hours &&
        Time::minutes == right.minutes &&
        Time::seconds == right.seconds) {
        return true;
    }

    return false;
}

bool Time::operator!=(const Time &right) const {
    return !(*this == right);
}

#include "Time.h"

Time::Time(int h, int m, int s) {
    hours = (h>=0 && h <24) ? h : 0; // ja ir noradits nepareizs laiks, tad peiskiram 0
    minutes = (m>=0 && m<60) ? m : 0;
    seconds = (s>=0 && s<60) ? s : 0;
}

ostream& operator<<(ostream& output, const Time& obj) {
    output
            << (obj.hours < 10 ? "0" : "") << obj.hours << ":"
            << (obj.minutes < 10 ? "0" : "") << obj.minutes << ":"
            << (obj.seconds < 10 ? "0" : "") << obj.seconds
            <<
            endl;

    return output;
}

istream& operator>>(istream& input, Time& obj) {
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


Time& Time::operator=(const Time& right) {
    if (*this == right) {
        return *this;
    }

    hours = right.hours;
    minutes = right.minutes;
    seconds = right.seconds;

    return *this;
}

Time Time::operator++() {
    if (seconds == 59) {
        if (minutes == 59) {
            if (hours == 23) {
                hours = 0;
            } else {
                hours++;
            }

            minutes = 0;
        } else {
            minutes++;
        }

        seconds = 0;
    } else {
        seconds++;
    }

    return *this;
}

Time Time::operator++(int) {
    if (minutes == 59) {
        if (hours == 23) {
            hours = 0;
        } else {
            hours++;
        }

        minutes = 0;
    } else {
        minutes++;
    }

    return *this;

}

Time Time::operator--() {
    if (seconds == 0) {
        if (minutes == 0) {
            if (hours == 0) {
                hours = 23;
            } else {
                hours--;
            }

            minutes = 59;
        } else {
            minutes--;
        }

        seconds = 59;
    } else {
        seconds--;
    }

    return *this;
}

Time Time::operator--(int) {
    if (minutes == 0) {
        if (hours == 0) {
            hours = 23;
        } else {
            hours--;
        }

        minutes = 59;
    } else {
        minutes--;
    }

    return *this;
}

bool Time::operator>(const Time &right) const {
    if (hours > right.hours) {
        return true;
    }

    if (hours == right.hours) {
        if (minutes > right.minutes) {
            return true;
        }

        if (minutes == right.minutes && seconds > right.seconds) {
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
    if (hours == right.hours &&
        minutes == right.minutes &&
        seconds == right.seconds) {
        return true;
    }

    return false;
}

bool Time::operator!=(const Time &right) const {
    return !(*this == right);
}

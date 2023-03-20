#include "Vector.h"
#include "cmath"

Vector::Vector(double x1, double y1, double z1, double x2, double y2, double z2) {
    vector[0] = x1;
    vector[1] = y1;
    vector[2] = z1;
    vector[3] = x2;
    vector[4] = y2;
    vector[5] = z2;
}

ostream &operator<<(ostream &output, const Vector &obj) {
     cout << "x1: " << obj.vector[0] << "\n"
          << "y1: " << obj.vector[1] << "\n"
          << "z1: " << obj.vector[2] << "\n"
          << "x2: " << obj.vector[3] << "\n"
          << "y2: " << obj.vector[4] << "\n"
          << "z2: " << obj.vector[5]
          << endl;

    return output;
}

istream &operator>>(istream &input, Vector &obj) {
    double x1, y1, z1, x2, y2, z2;

    cout << "Enter x1: ";
    input >> x1;
    obj.vector[0] = x1;

    cout << "Enter y1: ";
    input >> y1;
    obj.vector[1] = y1;

    cout << "Enter z1: ";
    input >> z1;
    obj.vector[2] = z1;

    cout << "Enter x2: ";
    input >> x2;
    obj.vector[3] = x2;

    cout << "Enter y2: ";
    input >> y2;
    obj.vector[4] = y2;

    cout << "Enter z2: ";
    input >> z2;
    obj.vector[5] = z2;

    return input;
}

Vector &Vector::operator=(const Vector &right) {
    vector = right.vector;

    return *this;
}

Vector Vector::operator+(const Vector &right) const {
    return Vector(
            vector[0] + right.vector[0],
            vector[1] + right.vector[1],
            vector[2] + right.vector[2],
            vector[3] + right.vector[3],
            vector[4] + right.vector[4],
            vector[5] + right.vector[5]
    );
}

const Vector Vector::operator-(const Vector &right) const {
    return Vector(
            vector[0] - right.vector[0],
            vector[1] - right.vector[1],
            vector[2] - right.vector[2],
            vector[3] - right.vector[3],
            vector[4] - right.vector[4],
            vector[5] - right.vector[5]
    );
}

const Vector Vector::operator*(const Vector &right) const {
    return Vector(
        vector[1] * right.vector[2] - vector[2] * right.vector[1],
        vector[2] * right.vector[0] - vector[0] * right.vector[2],
        vector[0] * right.vector[1] - vector[1] * right.vector[0],
        vector[4] * right.vector[5] - vector[5] * right.vector[4],
        vector[5] * right.vector[3] - vector[3] * right.vector[5],
        vector[3] * right.vector[4] - vector[4] * right.vector[3]
    );
}

bool Vector::operator>(const Vector &right) const {
    double magnitude1 = sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2] +
                       vector[3]*vector[3] + vector[4]*vector[4] + vector[5]*vector[5]);

    cout << "Magnitude 1: " << magnitude1 << endl;

    double magnitude2 = sqrt(right.vector[0]*right.vector[0] + right.vector[1]*right.vector[1] +
                          right.vector[2]*right.vector[2] + right.vector[3]*right.vector[3] +
                          right.vector[4]*right.vector[4] + right.vector[5]*right.vector[5]);

    cout << "Magnitude 2: " << magnitude2 << endl;

    return magnitude1 > magnitude2;
}

bool Vector::operator<(const Vector &right) const {
    return !(*this > right);
}

bool Vector::operator>=(const Vector &right) const {
    double magnitude1 = sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2] +
                       vector[3]*vector[3] + vector[4]*vector[4] + vector[5]*vector[5]);

    cout << "Magnitude 1: " << magnitude1 << endl;

    double magnitude2 = sqrt(right.vector[0]*right.vector[0] + right.vector[1]*right.vector[1] +
                       right.vector[2]*right.vector[2] + right.vector[3]*right.vector[3] +
                       right.vector[4]*right.vector[4] + right.vector[5]*right.vector[5]);

    cout << "Magnitude 2: " << magnitude2 << endl;

    if (magnitude1 > magnitude2 || magnitude1 == magnitude2) {
        return true;
    }

    return false;
}

bool Vector::operator<=(const Vector &right) const {
    double magnitude1 = sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2] +
                       vector[3]*vector[3] + vector[4]*vector[4] + vector[5]*vector[5]);

    cout << "Magnitude 1: " << magnitude1 << endl;

    double magnitude2 = sqrt(right.vector[0]*right.vector[0] + right.vector[1]*right.vector[1] +
                       right.vector[2]*right.vector[2] + right.vector[3]*right.vector[3] +
                       right.vector[4]*right.vector[4] + right.vector[5]*right.vector[5]);

    cout << "Magnitude 2: " << magnitude2 << endl;

    if (magnitude1 < magnitude2 || magnitude1 == magnitude2) {
        return true;
    }

    return false;
}

bool Vector::operator==(const Vector &right) const {
    double magnitude1 = sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2] +
                       vector[3]*vector[3] + vector[4]*vector[4] + vector[5]*vector[5]);

    cout << "Magnitude 1: " << magnitude1 << endl;

    double magnitude2 = sqrt(right.vector[0]*right.vector[0] + right.vector[1]*right.vector[1] +
                       right.vector[2]*right.vector[2] + right.vector[3]*right.vector[3] +
                       right.vector[4]*right.vector[4] + right.vector[5]*right.vector[5]);

    cout << "Magnitude 2: " << magnitude2 << endl;

    return magnitude1 == magnitude2;
}

bool Vector::operator!=(const Vector &right) const {
    return !(*this == right);
}

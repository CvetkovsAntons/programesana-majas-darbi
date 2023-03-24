#include "Vector.h"
#include "cmath"
// konstruktors pieskir parmetru vertibas masiva
Vector::Vector(double x1, double y1, double z1, double x2, double y2, double z2) {
    coordinates[0] = x1;
    coordinates[1] = y1;
    coordinates[2] = z1;
    coordinates[3] = x2;
    coordinates[4] = y2;
    coordinates[5] = z2;
}

Vector::~Vector() { // destruktors deallocate masivu
    delete [] coordinates;
}

ostream &operator<<(ostream &output, const Vector &obj) {
    output << "x1: " << obj.coordinates[0] << "\n"
          << "y1: " << obj.coordinates[1] << "\n"
          << "z1: " << obj.coordinates[2] << "\n"
          << "x2: " << obj.coordinates[3] << "\n"
          << "y2: " << obj.coordinates[4] << "\n"
          << "z2: " << obj.coordinates[5]
          << endl;

    return output;
}

istream &operator>>(istream &input, Vector &obj) {
    double x1, y1, z1, x2, y2, z2;

    cout << "Enter x1: ";
    input >> x1;
    obj.coordinates[0] = x1;

    cout << "Enter y1: ";
    input >> y1;
    obj.coordinates[1] = y1;

    cout << "Enter z1: ";
    input >> z1;
    obj.coordinates[2] = z1;

    cout << "Enter x2: ";
    input >> x2;
    obj.coordinates[3] = x2;

    cout << "Enter y2: ";
    input >> y2;
    obj.coordinates[4] = y2;

    cout << "Enter z2: ";
    input >> z2;
    obj.coordinates[5] = z2;

    return input;
}
// dabujam vektora magnitudu pec formulas sqrt(a^2+b^2+c^2)
// a = x2 - x1, b = y2 - y1, c = z2 - z1
double Vector::getMagnitude() const {
    return sqrt(pow(coordinates[3] - coordinates[0], 2) +
            pow(coordinates[4] - coordinates[1], 2) +
            pow(coordinates[5] - coordinates[2], 2));
}

Vector &Vector::operator=(const Vector &right) {
    if (*this == right) {
        return *this;
    }

    for (int i = 0; i < sizeof(coordinates); i++) {
        coordinates[i] = right.coordinates[i];
    }

    return *this;
}

Vector Vector::operator+(const Vector &right) const {
    return Vector(
            coordinates[0] + right.coordinates[0],
            coordinates[1] + right.coordinates[1],
            coordinates[2] + right.coordinates[2],
            coordinates[3] + right.coordinates[3],
            coordinates[4] + right.coordinates[4],
            coordinates[5] + right.coordinates[5]
    );
}

const Vector Vector::operator-(const Vector &right) const {
    return Vector(
            coordinates[0] - right.coordinates[0],
            coordinates[1] - right.coordinates[1],
            coordinates[2] - right.coordinates[2],
            coordinates[3] - right.coordinates[3],
            coordinates[4] - right.coordinates[4],
            coordinates[5] - right.coordinates[5]
    );
}

const Vector Vector::operator*(const Vector &right) const {
    return Vector(
            coordinates[1] * right.coordinates[2] - coordinates[2] * right.coordinates[1],
            coordinates[2] * right.coordinates[0] - coordinates[0] * right.coordinates[2],
            coordinates[0] * right.coordinates[1] - coordinates[1] * right.coordinates[0],
            coordinates[4] * right.coordinates[5] - coordinates[5] * right.coordinates[4],
            coordinates[5] * right.coordinates[3] - coordinates[3] * right.coordinates[5],
            coordinates[3] * right.coordinates[4] - coordinates[4] * right.coordinates[3]
    );
}

bool Vector::operator>(const Vector &right) const {
    return getMagnitude() > right.getMagnitude();
}

bool Vector::operator<(const Vector &right) const {
    return !(*this > right);
}

bool Vector::operator>=(const Vector &right) const {
    return getMagnitude() >= right.getMagnitude();
}

bool Vector::operator<=(const Vector &right) const {
    return getMagnitude() <= right.getMagnitude();
}

bool Vector::operator==(const Vector &right) const {
    return getMagnitude() == right.getMagnitude();
}

bool Vector::operator!=(const Vector &right) const {
    return !(*this == right);
}

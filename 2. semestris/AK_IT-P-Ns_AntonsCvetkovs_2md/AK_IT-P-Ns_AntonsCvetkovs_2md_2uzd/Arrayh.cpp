#include "Array.h"

Array::Array(int arraySize) {
    size = arraySize;
    ptr = new double[size];
    assert(ptr != 0);
    for (int i = 0; i < size; i++)
        ptr[i] = 0;
}

double &Array::operator[](int index) const {
    assert(0 <= index && index < size);
    return ptr[index];
}

const Array &Array::operator=(const Array &right) {
    if (&right != this) {
        delete [ ] ptr;
        size = right.size;
        ptr = new double[size];
        assert(ptr != 0);

        for (int i = 0; i < size; i++)
            ptr[i] = right.ptr[i];

        return *this;
    }

    return *this;
}

Array::~Array() {
    delete [] ptr;
}
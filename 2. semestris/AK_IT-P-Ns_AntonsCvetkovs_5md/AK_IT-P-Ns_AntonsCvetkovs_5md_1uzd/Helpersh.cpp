#include "Helpers.h"

template <class Type>
Type randomNumber(Type min, Type max) // funkcija, kas var uzgeneret random int vai float
{
    std::random_device rd;
    std::mt19937 gen(rd());

    if constexpr (is_integral_v<Type>) { // parbaudu vai Type ir int
        uniform_int_distribution<Type> dis(min, max);
        return dis(gen);
    } else if constexpr (is_floating_point_v<Type>) {  // parbaudu vai Type ir float
        uniform_real_distribution<Type> dis(min, max);
        return dis(gen);
    } else {
        throw invalid_argument("Unsupported type for randomNumber");
    }
}

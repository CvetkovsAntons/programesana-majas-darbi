#include "Helpers.h"

int randomNumber(int min, int max) {
    random_device rd; // funkcija izmanto <random> biblioteku
    mt19937 gen(rd());
    uniform_int_distribution<> random(min,max);

    return random(gen);
}
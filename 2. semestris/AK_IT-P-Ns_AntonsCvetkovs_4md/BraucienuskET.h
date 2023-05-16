#ifndef AK_IT_P_NS_ANTONSCVETKOVS_4MD_BRAUCIENUSKET_H
#define AK_IT_P_NS_ANTONSCVETKOVS_4MD_BRAUCIENUSKET_H
#include "eTalons.h"

using namespace std;

class BraucienuskET : public eTalons {
public:
    BraucienuskET(int);
    void Print() const;
    void Use() override;
    void Add(int);

private:
    int trips = 1;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_4MD_BRAUCIENUSKET_H

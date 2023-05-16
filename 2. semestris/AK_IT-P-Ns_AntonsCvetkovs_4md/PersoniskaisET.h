#ifndef AK_IT_P_NS_ANTONSCVETKOVS_4MD_PERSONISKAISET_H
#define AK_IT_P_NS_ANTONSCVETKOVS_4MD_PERSONISKAISET_H
#include "eTalons.h"

using namespace std;

class PersoniskaisET : public eTalons {
public:
    PersoniskaisET(int, string, string);
    void Print() const;
    void Use() override;
    void Add(int) override;

private:
    int trips = 1;
    string name;
    string surname;
    int totalTrips = 0;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_4MD_PERSONISKAISET_H

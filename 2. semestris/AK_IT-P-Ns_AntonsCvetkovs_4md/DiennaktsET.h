#ifndef AK_IT_P_NS_ANTONSCVETKOVS_4MD_DIENNAKTSET_H
#define AK_IT_P_NS_ANTONSCVETKOVS_4MD_DIENNAKTSET_H
#include "eTalons.h"
#include <ctime>

using namespace std;

class DiennaktsET : public eTalons {
public:
    DiennaktsET();
    void Print() const;
    void Use() override;
    void Add(int);

private:
    time_t activation_date = 0;
    bool activated = false;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_4MD_DIENNAKTSET_H

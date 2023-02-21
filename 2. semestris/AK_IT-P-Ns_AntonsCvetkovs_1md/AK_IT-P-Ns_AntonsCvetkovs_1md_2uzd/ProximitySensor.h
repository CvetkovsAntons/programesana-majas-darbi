#ifndef AK_IT_P_NS_ANTONSCVETKOVS_1MD_2UZD_PROXIMITYSENSOR_H
#define AK_IT_P_NS_ANTONSCVETKOVS_1MD_2UZD_PROXIMITYSENSOR_H
#include <iostream>

using namespace std;

class ProximitySensor {
public:
    ProximitySensor(string);
    static bool Scan(int);
    bool GetState() const;
    void SetState();
    void PrintSensor();

private:
    bool state;
    string serial_number;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_1MD_2UZD_PROXIMITYSENSOR_H

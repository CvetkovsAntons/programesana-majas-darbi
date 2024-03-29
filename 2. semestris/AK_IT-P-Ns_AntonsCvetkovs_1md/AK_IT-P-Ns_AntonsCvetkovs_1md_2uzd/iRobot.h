#ifndef AK_IT_P_NS_ANTONSCVETKOVS_1MD_2UZD_IROBOT_H
#define AK_IT_P_NS_ANTONSCVETKOVS_1MD_2UZD_IROBOT_H
#include <iostream>

#include "ProximitySensor.h"

using namespace std;

class iRobot {
public:
    iRobot(string, string, string);
    void SwitchOnOff();
    void Run(const int[10]);
    void PrintRobot();

private:
    string model_name;
    ProximitySensor LeftSensor;
    ProximitySensor RightSensor;
    string alarm;
    string map;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_1MD_2UZD_IROBOT_H

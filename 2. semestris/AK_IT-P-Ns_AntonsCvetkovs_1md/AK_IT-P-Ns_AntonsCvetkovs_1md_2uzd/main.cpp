#include <iostream>

#include "iRobot.h"

using namespace std;

int main() {
    int goodRoute[10] = {23, 35, 55, 74, 45, 47, 34, 77, 23, 98}; // masivs bez strupcela
    int badRoute[10] = {23, 35, 55, 74, 45, 46, 34, 77, 23, 98}; // masivs ar strupcelu

    iRobot robot1("Robot1", "left_sensor_1", "right_sensor_1");
    robot1.SwitchOnOff();
    robot1.Run(goodRoute);
    robot1.PrintRobot();

    cout << endl;

    iRobot robot2("Robot2", "left_sensor_2", "right_sensor_2");
    robot2.SwitchOnOff();
    robot2.Run(badRoute);
    robot2.PrintRobot();

    return 0;
}

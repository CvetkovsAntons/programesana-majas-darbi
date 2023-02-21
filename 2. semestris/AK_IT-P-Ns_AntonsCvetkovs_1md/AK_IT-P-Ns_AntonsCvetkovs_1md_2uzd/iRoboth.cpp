#include "iRobot.h"

using namespace std;

iRobot::iRobot(string model_name, string serial_number_leftSensor, string serial_number_rightSensor) :
    LeftSensor(serial_number_leftSensor),
    RightSensor(serial_number_rightSensor) {
    iRobot::model_name = model_name;
}

void iRobot::SwitchOnOff() {
    LeftSensor.SetState(); // iesledz kreiso sensoru
    RightSensor.SetState(); // iesledz labo sensoru
}

void iRobot::Run(const int room[10]) {
    if (LeftSensor.GetState() && RightSensor.GetState()) { // ja abi sensori ir ieslegti
        for (int i = 0; i < 10; i++) { // tad izpildam ciklu for
            if (room[i] < 10 || room[i] > 99) { // ja skaitlis ir mazaks par 10 un lielaks par 99 izvadam kludu
                cout << "Entered move direction value at the index " << i << " is invalid!" << endl;
                iRobot::alarm = "red"; // pieskir alarm vertibu "red"
                return; // partraucam funkcijas izpildi
            }

            string number = to_string(room[i]); // parvers int to string lai uztaisit parbaudes

            if (!ProximitySensor::Scan((int) number[0]) && !ProximitySensor::Scan((int)number[1])) { // ja abi cipari ir para, tad ir strupcels
                iRobot::alarm = "red";
                return; // partraucam funkcijas izpildi
            }

            if (ProximitySensor::Scan((int) number[0]) && ProximitySensor::Scan((int) number[1])) { // ja abi cipari ir ne para
                iRobot::map += "f"; // tad robots brauc uz prieksu
                continue;
            }

            if (!ProximitySensor::Scan((int) number[0]) && ProximitySensor::Scan((int) number[1])) { // ja kreisais ciaprs ir para un labais ne para
                iRobot::map += "r"; // tad robots brauc pa labi
                continue;
            }

            if (ProximitySensor::Scan((int) number[0]) && !ProximitySensor::Scan((int) number[1])) { // ja kreisais ciaprs ir ne para un labais para
                iRobot::map += "l"; // tad robots brauc pa kreisi
            }
        }

        iRobot::alarm = "green"; // pieksiram vertibu "green" mainigajam alarm
        return;
    }

    cout << "You have to turn on the robot first!" << endl; // ja abi sensori nav ieslegti, izvadam kludu
}

void iRobot::PrintRobot() {
    cout << "Model Name: " << iRobot::model_name << endl;
    cout << "Map: " << iRobot::map << endl;
    cout << "Alarm: " << iRobot::alarm << endl;
}

#ifndef AK_IT_P_NS_ANTONSCVETKOVS_3MD_2MD_BOX_H
#define AK_IT_P_NS_ANTONSCVETKOVS_3MD_2MD_BOX_H
#include <iostream>

using namespace std;

struct BoxStruct {
    double width;
    double height;
    string border_color;
};

class Box {
public:
    Box(double, double, string);
    void SetBox(double, double, string);
    BoxStruct GetKatrsParameters() const;
    void PrintBox() const;

private:
    double width = 20;
    double height = 10;
    string border_color = "#000000";
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_3MD_2MD_BOX_H

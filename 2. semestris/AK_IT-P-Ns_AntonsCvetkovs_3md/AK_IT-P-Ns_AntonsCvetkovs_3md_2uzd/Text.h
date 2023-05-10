#ifndef AK_IT_P_NS_ANTONSCVETKOVS_3MD_2MD_TEXT_H
#define AK_IT_P_NS_ANTONSCVETKOVS_3MD_2MD_TEXT_H
#include <iostream>

using namespace std;

struct TextStruct {
    string font;
    double size;
    string color;
    string data;
};

class Text {
public:
    Text(string, double, string, string);
    void SetText(string, double, string, string);
    TextStruct GetKatrsParameters() const;
    void PrintText() const;

private:
    string font = "Times New Roman";
    double size = 12;
    string color = "#000000";
    string data = "";
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_3MD_2MD_TEXT_H

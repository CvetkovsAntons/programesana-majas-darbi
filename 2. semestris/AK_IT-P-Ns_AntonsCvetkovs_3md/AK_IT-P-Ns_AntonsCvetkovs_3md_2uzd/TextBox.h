#ifndef AK_IT_P_NS_ANTONSCVETKOVS_3MD_2MD_TEXTBOX_H
#define AK_IT_P_NS_ANTONSCVETKOVS_3MD_2MD_TEXTBOX_H
#include "Text.h"
#include "Box.h"

using namespace std;

class TextBox : public Text, public Box {
public:
    TextBox(string, double, string, string, double, double, string);
    void SetTextBox(string, double, string, string, double, double, string);
    void PrintTextBox() const;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_3MD_2MD_TEXTBOX_H

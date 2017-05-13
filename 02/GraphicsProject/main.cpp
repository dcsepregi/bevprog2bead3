#include "graphics.hpp"
#include "widgets.hpp"
#include "texteditor.hpp"
#include "window.hpp"
#include "pushbutton.hpp"
#include "Board.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;

class ValamiButton;

class MyWindow : public Window {
public:
    vector<Widget> *vw;
    Board *board;
    ValamiButton *vButton;
    MyWindow();

    void valami(){
        }
};

class ValamiButton : public PushButton {
    MyWindow *mywparent;
public:
    ValamiButton(MyWindow *parent, int x, int y, int sx, int sy, std::string s, std::string azonosito) :PushButton(parent, x, y, sx, sy, s, azonosito) {
        mywparent=parent;
    }
    virtual void action();
};

MyWindow::MyWindow() {
        board = new Board(vw);
        vButton = new ValamiButton(this, 10, 200, 100, 40, "vbut", "");
        widgets.push_back(vButton);
}

void ValamiButton::action()
{
    mywparent->valami();
}

int main()
{
    gout.open(400,400);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}

#include "graphics.hpp"
#include "widgets.hpp"
#include "texteditor.hpp"
#include "statictext.hpp"
#include "window.hpp"
#include "pushbutton.hpp"
#include "Board.hpp"
#include <vector>

using namespace std;
using namespace genv;

class ValamiButton;

class MyWindow : public Window {
public:
    //Board *board;
    ValamiButton *vButton;
    Board *board;
    MyWindow();

    void valami(){
        board = new Board(vw);
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
    vButton = new ValamiButton(this, 10, 350, 100, 40, "new game", "new");
    vw.push_back(vButton);
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

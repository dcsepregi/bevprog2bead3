#include "pushbutton.hpp"

using namespace std;
using namespace genv;

PushButton::PushButton(Window * parent, int x, int y, int sx, int sy, string s, string azonosito)
    : Widget(x,y,sx,sy),
    _parent(parent),
    _felirat(s),
    _azonosito(azonosito)
{
}

PushButton::PushButton(int x, int y, int sx, int sy, string s)
    : Widget(x,y,sx,sy),
    _felirat(s)
{
    _azonosito="";
}

void PushButton::draw() const {
    if (_focused) gout << color(80,80,80);
        else gout << color(30,30,30);
    gout << move_to(_x, _y) << box(_size_x, _size_y)
         << color(255,255,255);
    gout << move_to(_x+_size_x/2-gout.twidth(_felirat)/2, _y+20)
         << text(_felirat);
}
void PushButton::handle(genv::event ev) {
    if (ev.button==btn_left && ev.pos_x>=_x && ev.pos_x<=_x+_size_x && ev.pos_y>=_y && ev.pos_y<=_y+_size_y) {
        action();
    }
}
void PushButton::action() {
    _parent->esemeny(_azonosito);
}

FunctorButton::FunctorButton(int x, int y, int sx, int sy, std::string s, std::function<void()> functor):PushButton(x,y,sx,sy,s), _functor(functor)
{
}

void FunctorButton::action()
{
    _functor();
}

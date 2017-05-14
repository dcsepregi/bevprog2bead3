#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy)
{
    _x=x;
    _y=y;
    _size_x = sx;
    _size_y=sy;
    _focused=false;
}

Widget::Widget(int x, int y, int sx, int sy, int num, int mi, int ma) ///counter widget
{
    _x=x;
    _y=y;
    _size_x=sx;
    _size_y=sy;
    _num=num;
    _min=mi;
    _max=ma;
}

bool Widget::_increase(int mouse_x, int mouse_y) const ///mouse click on increase sign
{
    return mouse_x>_x+_size_x-_size_y/2 && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y/2;
}

bool Widget::_decrease(int mouse_x, int mouse_y) const ///mouse click on decrease sign
{
    return mouse_x>_x+_size_x-_size_y/2 && mouse_x<_x+_size_x && mouse_y>_y+_size_y/2 && mouse_y<_y+_size_y;
}

bool Widget::is_selected(int mouse_x, int mouse_y) const
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

void Widget::handle(event ev) {
}

bool Widget::focusable() const {return true;}

void Widget::focus() {
    _focused = true;
}

void Widget::unfocus() {
    _focused = false;
}

void Widget::draw() const {}

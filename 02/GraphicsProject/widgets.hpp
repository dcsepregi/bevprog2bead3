#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Widget {
protected:
    bool _focused;
    int _x, _y, _size_x, _size_y, _min, _max;
public:
    int _num;
    Widget(int x, int y, int sx, int sy);
    Widget(int x, int y, int sx, int sy, int num, int mi, int ma); ///counter widget
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    //virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual bool _increase(int mouse_x, int mouse_y) const; ///mouse click on increase sign
    virtual bool _decrease(int mouse_x, int mouse_y) const; ///mouse click on decrease sign
    virtual bool focusable() const;
    virtual void focus();
    virtual void unfocus();
};


#endif // WIDGETS_HPP_INCLUDED

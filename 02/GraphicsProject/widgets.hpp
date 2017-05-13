#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>

class Widget {
protected:
    int _x, _y, _size_x, _size_y, _num, _min, _max;
    std::vector<std::string> _vs;
public:
    Widget(int x, int y, int sx, int sy); ///checkbox widget
    Widget(int x, int y, int sx, int sy, int num, int mi, int ma); ///counter widget
    Widget(int x, int y, int sx, int sy, std::vector<std::string> &vs); ///selector widget
    virtual bool _mouse_over(int mouse_x, int mouse_y) const; ///mouse click on _size_x*_size_y field
    virtual bool _mouse_over2(int mouse_x, int mouse_y) const; ///reduced by a square on right side
    virtual int _mouse_over3(int mouse_x, int mouse_y, int db) const; ///reduced to a square on right side
    virtual bool _increase(int mouse_x, int mouse_y) const; ///mouse click on increase sign
    virtual bool _decrease(int mouse_x, int mouse_y) const; ///mouse click on decrease sign
    virtual bool _open(int mouse_x, int mouse_y) const; ///reduced to a square on right side
    virtual int _select(int mouse_x, int mouse_y, int db) const; ///returns which item has been selected
    virtual void draw() const;
    virtual void write() const;
    virtual void handle(genv::event ev);
};


#endif // WIDGETS_HPP_INCLUDED

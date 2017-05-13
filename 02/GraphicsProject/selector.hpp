#ifndef SELECTOR_HPP_INCLUDED
#define SELECTOR_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>

class Selector : public Widget {
protected:
    bool _checked;
    int _selected, _start, _items;
    bool _checked2, _nyit;
    std::string _s;
public:
    Selector(int x, int y, int sx, int sy, std::vector<std::string> &vs);
    virtual void draw() const ;
    virtual void write() const ;
    virtual void handle(genv::event ev);
};

#endif // SELECTOR_HPP_INCLUDED

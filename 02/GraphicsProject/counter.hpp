#ifndef COUNTER_HPP_INCLUDED
#define COUNTER_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Counter : public Widget {
public:
    Counter(int x, int y, int sx, int sy, int num, int mi, int ma);
    virtual void draw() const ;
    virtual void write() const;
    virtual void handle(genv::event ev);
};

#endif // COUNTER_HPP_INCLUDED

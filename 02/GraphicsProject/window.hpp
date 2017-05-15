#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>


class Window {
protected:
    int elem;
    std::vector<Widget*> vw;
    std::vector<Widget*> vw2;
    int szdb1=0;
    int szdb2=0;
    int szdb3=0;
public:
    virtual void esemeny(std::string mitortent){}
    void ellenor(int mezo);
    void event_loop() ;
};



#endif // WINDOW_HPP_INCLUDED

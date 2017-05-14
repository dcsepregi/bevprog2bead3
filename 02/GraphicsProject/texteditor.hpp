#ifndef TEXTEDITOR_HPP_INCLUDED
#define TEXTEDITOR_HPP_INCLUDED
#include <string>
#include "widgets.hpp"

class TextEditor : public Widget{
    std::string _s;
    bool _ticknum;
    int _tick;
public:
    //TextEditor(int x, int y, int sx, int sy, std::string s);
    TextEditor(int x, int y, int sx, int sy, char c);
    virtual bool focusable() const {return true;}
    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual void setrgb(int r, int g, int b);
    virtual void _inctick();
    inline char value() {return _c;}
    void setchar(char c) {_c=c;}
};



#endif // TEXTEDITOR_HPP_INCLUDED

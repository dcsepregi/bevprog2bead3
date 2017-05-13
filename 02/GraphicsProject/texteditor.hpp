#ifndef TEXTEDITOR_HPP_INCLUDED
#define TEXTEDITOR_HPP_INCLUDED
#include <string>
#include "widgets.hpp"

class TextEditor : public Widget{
    std::string _s;
    char _c;
    int _r, _g, _b;
public:
    TextEditor(int x, int y, int sx, int sy, std::string s);
    TextEditor(int x, int y, int sx, int sy, char c);
    virtual bool focusable() const {return true;}
    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual void setrgb(int r, int g, int b);
    inline std::string value() {return _s;}
};



#endif // TEXTEDITOR_HPP_INCLUDED

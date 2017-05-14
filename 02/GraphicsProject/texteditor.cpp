#include "texteditor.hpp"
#include <string>
using namespace std;
using namespace genv;

//TextEditor::TextEditor(int x, int y, int sx, int sy, string s) : Widget(x,y,sx,sy) {_s=s; _r=0; _g=0; _b=0;}
TextEditor::TextEditor(int x, int y, int sx, int sy, char c) : Widget(x,y,sx,sy) {_c=c; _r=255; _g=255; _b=255; _tick=0;}

void TextEditor::draw() const {
    if (_c==' ') {
        gout << color(255,255,255);
    } else {
        gout << color(155,155,155);
    }
    gout << move_to(_x, _y) << box(_size_x, _size_y);
    gout << color(0,0,0) << move_to(_x+1, _y+1) << box(_size_x-2, _size_y-2);
    gout << move_to(_x+10,_y+2*_size_y/3) << color(_r,_g,_b);
   /* if (!_focused && _s=="")
        gout << text("hostname");
    else*/ gout << text(_c);
    if (_focused && _ticknum) gout <<text("|");
}

void TextEditor::setrgb(int r, int g, int b)
{
    _r=r;
    _g=g;
    _b=b;
}

void TextEditor::handle(event ev) {
    _tick++;
    if(_tick<=20)
        _ticknum=true;
    else _ticknum=false;
    if(_tick>40)
        _tick=0;
    if (ev.type == ev_key) {
        if (ev.keycode >= '1' && ev.keycode <= '9') {
            _c = ev.keycode;
            }
        if (ev.keycode==key_backspace)
            _c = ' ';
    }
}

void TextEditor::_inctick() {
    _tick++;
}

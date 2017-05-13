#include "selector.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;
using namespace std;

Selector::Selector(int x, int y, int sx, int sy, vector<string>& vs)
    : Widget(x,y,sx,sy,vs)
{
    _checked=false;
    _checked2=false;
    _selected=0;
    _s="";
    _start=0;
    _nyit=false;
    if(_vs.size()<3) _items=_vs.size();
    else _items=3;
}

void Selector::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+_size_x-_size_y,_y) << color(255,255,255) << box(_size_y,_size_y);
    gout << move_to(_x+_size_x-_size_y+2,_y+2) << color (0,0,0) << box(_size_y-4,_size_y-4);
    gout << move_to(_x+_size_x-_size_y,_y+_size_y) << genv::move(_size_y/2, -_size_y/4) << color(255,255,255) << line(-_size_y/4,-_size_y/2) << line(_size_y/2,0) << line(-_size_y/4,_size_y/2);
    if(_nyit) {
        for(int i=0; i<_items; i++)
        {
            gout << move_to(_x,_y+(i+1)*_size_y) << color(255,255,255) << box(_size_x, _size_y);
            gout << move_to(_x+2,_y+(i+1)*_size_y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
            gout << move_to(_x+4,_y+(i+1)*_size_y+2*_size_y/3) << color(255,255,255) << text(_vs[_start+i]);
            gout << move_to(_x+_size_x-_size_y,_y+(i+1)*_size_y) << color(255,255,255) << box(_size_y,_size_y);
            gout << move_to(_x+_size_x-_size_y+2,_y+(i+1)*_size_y+2) << color (0,0,0) << box(_size_y-4,_size_y-4);
        }
        if(_vs.size()>3)
        {
            gout << move_to(_x+_size_x-_size_y,_y+(_items+1)*_size_y) << genv::move(_size_y/2, -_size_y/4) << color(255,255,255) << line(-_size_y/4,-_size_y/2) << line(_size_y/2,0) << line(-_size_y/4,_size_y/2);
            gout << move_to(_x+_size_x-_size_y,_y+_size_y) << genv::move(_size_y/2, _size_y/4) << color(255,255,255) << line(-_size_y/4,_size_y/2) << line(_size_y/2,0) << line(-_size_y/4,-_size_y/2);
        }
    }
    else
    {
        for(int i=0; i<_items; i++)
        {
            gout << move_to(_x,_y+(i+1)*_size_y) << color(0,0,0) << box(_size_x,_size_y);
        }
        gout << move_to(_x,_y+_size_y) << color(255,255,255) << box(_size_x,_size_y);
        gout << move_to(_x+2,_y+_size_y+2) << color(0,0,0) << box(_size_x-4,_size_y-4);
        if(_checked2)
        {
            gout << move_to(_x+4,_y+_size_y+2*_size_y/3) << color(255,255,255) << text(_s) << text('|');
        }
        else
        {
            if(_s=="")
            {
                gout << move_to(_x+4,_y+_size_y+2*_size_y/3) << color(255,255,255) << text("new item");
            }
            else
            {
                gout << move_to(_x+4,_y+_size_y+2*_size_y/3) << color(255,255,255) << text(_s);
            }
        }

    }
}

void Selector::write() const
{
    gout << move_to(_x+4,_y+2*_size_y/3) << color(255,255,255) << text(_vs[_selected]);
}

void Selector::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }
    if (ev.type == ev_mouse && _mouse_over(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;
    }

    if (ev.type == ev_mouse && _open(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _nyit = !_nyit;
    }

    if (ev.type == ev_mouse && _mouse_over(ev.pos_x, ev.pos_y-_size_y) && ev.button==btn_left && _nyit==false) {
        _checked2 = !_checked2;
    }

    if (ev.type == ev_mouse && _nyit==true && ev.button==btn_left) {
        if(_select(ev.pos_x, ev.pos_y, _vs.size())>=0)
        {
            _selected=_select(ev.pos_x, ev.pos_y, _vs.size())+_start;
            _nyit=false;
        }
        if(_mouse_over3(ev.pos_x, ev.pos_y, _items)==1 && _start>0)
            _start--;
        if(_mouse_over3(ev.pos_x, ev.pos_y, _items)==2 && _start<_vs.size()-_items)
            _start++;
    }

    if(ev.type==ev_key && ev.keycode>0 && _checked2)
    {
        char c=ev.keycode;
        string sh=_s+c+'|';
        if(gout.twidth(sh)<_size_x-_size_y)
        {
            _s+=c;
        }
    }

    if(ev.type==ev_key && ev.keycode==key_enter && ev.keycode>0)
    {
        _vs.push_back(_s);
        _s="";
    }

    if(_vs.size()<3) _items=_vs.size();
    else _items=3;

    if(ev.type==ev_key && ev.keycode==key_backspace)
    {
        if (_s.size()>0)
            _s.erase(_s.size()-1);
        if (_s.size()>0)
            _s.erase(_s.size()-1);
    }
}

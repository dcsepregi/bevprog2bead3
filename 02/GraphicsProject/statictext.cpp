#include "statictext.hpp"
#include <string>
using namespace std;
using namespace genv;
/*StaticText::StaticText(int x, int y, int sx, int sy, string s) : Widget(x,y,sx,sy) {
    _s=s;
}*/
StaticText::StaticText(int x, int y, int sx, int sy, char c) : Widget(x,y,sx,sy) {
    _c=c;
}
void StaticText::draw() const {
    gout << color(255,255,255) << move_to(_x, _y) << box(_size_x, _size_y);
    gout << color(0,0,0) << move_to(_x+2, _y+2) << box(_size_x-4, _size_y-4) << color(255,255,255);
    gout << move_to(_x+4,_y+2*_size_y/3) << color(255,255,255) << text(_c);
}

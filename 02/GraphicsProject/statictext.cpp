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
    gout << color(0,0,0) << move_to(_x, _y) << box(_size_x, _size_y) << color(255,255,255);
    gout << move_to(_x+_size_x-gout.twidth(_s),_y+20) << color(255,255,255) << text(_c);
}

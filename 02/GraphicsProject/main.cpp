#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include <ctime>
#include <random>

using namespace std;
using namespace genv;

void event_loop(vector<Widget*>& widgets) {
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode!=key_escape ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->_mouse_over(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
            widgets[i]->write();
        }
        gout << refresh;
    }
}


int main()
{
    vector<string> vs1;
    vector<string> vs2;

    srand(time(NULL));

    for (int i=0;i<4;i++) {
        string s="";
        int melyik = rand() % 7;
        switch (melyik) {
            case 0 : s = "Alma"; break;
            case 1 : s = "Banán"; break;
            case 2 : s = "Cseresznye"; break;
            case 3 : s = "Dinnye"; break;
            case 4 : s = "Eper"; break;
            case 5 : s = "Füge"; break;
            case 6 : s = "Gesztenye"; break;
        }
        vs1.push_back(s);
    }

    for (int i=0;i<4;i++) {
        string s="";
        int melyik = rand() % 7;
        switch (melyik) {
            case 0 : s = "Alma"; break;
            case 1 : s = "Banán"; break;
            case 2 : s = "Cseresznye"; break;
            case 3 : s = "Dinnye"; break;
            case 4 : s = "Eper"; break;
            case 5 : s = "Füge"; break;
            case 6 : s = "Gesztenye"; break;
        }
        vs2.push_back(s);
    }

    gout.open(400,400);
    vector<Widget*> w;
    Counter * b1 = new Counter(10,10,120,30,9000,8995,9999); ///x koordinata, y koordinata, szelesseg, magassag, szamlalo kezdoertek, minimum ertek, maximum ertek
    Counter * b2 = new Counter(150,10,120,30,-50,-100,300); ///x koordinata, y koordinata, szelesseg, magassag, szamlalo kezdoertek, minimum ertek, maximum ertek
    Selector * s1 = new Selector(10,50,120,30,vs1);
    Selector * s2 = new Selector(150,50,120,30,vs2);
    w.push_back(b1);
    w.push_back(b2);
    w.push_back(s1);
    w.push_back(s2);
    event_loop(w);
    return 0;
}

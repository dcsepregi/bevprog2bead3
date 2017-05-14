#include "window.hpp"
#include <iostream>

using namespace genv;

void Window::event_loop() {
    gin.timer(40);
    event ev;
    int focus = -1;
    int szdb1=0;
    int szdb2=0;
    int szdb3=0;
    while(gin >> ev && ev.keycode!=key_escape) {
        if (ev.type == ev_key && ev.keycode == key_tab) {
            if(focus!=-1) {
                vw[focus]->unfocus();
            }
            do {
                focus++;
                if (focus>=vw.size()) focus =0;
            } while (!vw[focus]->focusable()); //TODO:vegtelenciklus!
            vw[focus]->focus();
        }
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<vw.size();i++) {
                if (vw[i]->is_selected(ev.pos_x, ev.pos_y) && vw[i]->focusable()) {
                        if (focus!=-1) vw[focus]->unfocus();
                        focus = i;
                        vw[focus]->focus();
                }
            }
        }

        if (focus!=-1) {
        if (focus!=vw.size()-1)
        {

        szdb1=0;

        for (int i=(focus/3)*3; i<((focus/3)*3)+3; i++) ///3x3 mezo ellenorzes
        {
            int db=0;
            for (int j=-3; j<3; j++)
            {
                db++;
                if((i+j*9)%18==focus%18 && i+j*9>0 && i+j*9<81)
                    if(vw[i+j*9]->value()==vw[focus]->value() && vw[focus]->value()!=' ')
                        szdb1++;
            }
        }

        szdb2=0;

        for (int i=focus%9; i<81; i+=9) ///oszlop ellenorzes
            if(vw[i]->value()==vw[focus]->value() && vw[focus]->value()!=' ')
                szdb2++;

        szdb3=0;

        for (int i=(focus/9)*9; i<((focus/9)*9)+9; i++) ///sor ellenorzes
            if(vw[i]->value()==vw[focus]->value() && vw[focus]->value()!=' ')
                szdb3++;
        if(szdb1>1)
                vw[focus]->setrgb(255,0,0);
            else
                if(szdb2>1)
                    vw[focus]->setrgb(255,0,0);
                else
                    if(szdb3>1)
                        vw[focus]->setrgb(255,0,0);
                    else
                vw[focus]->setrgb(255,255,255);

            vw[focus]->_inctick();
        }
            vw[focus]->handle(ev);
        }

        for (size_t i=0;i<vw.size();i++) {
            vw[i]->draw();
        }

        gout << refresh;
    }
}

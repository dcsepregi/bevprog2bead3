#include "window.hpp"
#include <iostream>

using namespace genv;

void Window::ellenor(int mezo){
        szdb1=0;

        for (int i=(mezo/3)*3; i<((mezo/3)*3)+3; i++) ///3x3 mezo ellenorzes
        {
            for (int j=-2; j<3; j++)
            {
                if((i+j*9)/27==mezo/27 && (i+j*9)>0 && (i+j*9)<81)
                    if(vw[i+j*9]->value()==vw[mezo]->value() && vw[mezo]->value()!=' ')
                        szdb1++;
            }
        }

        szdb2=0;

        for (int i=mezo%9; i<81; i+=9) ///oszlop ellenorzes
            if(vw[i]->value()==vw[mezo]->value() && vw[mezo]->value()!=' ')
                szdb2++;

        szdb3=0;

        for (int i=(mezo/9)*9; i<((mezo/9)*9)+9; i++) ///sor ellenorzes
            if(vw[i]->value()==vw[mezo]->value() && vw[mezo]->value()!=' ')
                szdb3++;

        if(szdb1>1)
                vw[mezo]->setrgb(255,0,0);
            else
                if(szdb2>1)
                    vw[mezo]->setrgb(255,0,0);
                else
                    if(szdb3>1)
                        vw[mezo]->setrgb(255,0,0);
                    else
                vw[mezo]->setrgb(255,255,255);
}

void Window::event_loop() {
    bool win;
    bool tele;
    gin.timer(40);
    event ev;
    int focus = -1;
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

        for (size_t i=0;i<vw.size();i++) {
            vw[i]->draw();
        }

        if (focus!=-1) {
        if (focus!=vw.size()-1)
        {

        ellenor(focus);

        vw[focus]->_inctick();

        }
            vw[focus]->handle(ev);
        }

        tele=true;
        int i=0;

        while(i<vw.size()-1 && tele)
        {
            if(vw[i]->value()==' ')
                tele=false;
            i++;
        }

        if (tele)
        {
            win=true;
            for(int i=0; i<vw.size()-1; i++)
            ellenor(i);
                if(szdb1>1 || szdb2>1 || szdb3>1)
                    win=false;
        }

        if(win)
        {
            gout << move_to(300,350) << color(255,255,255) << text("You won!");
        }


        gout << refresh;
    }
}

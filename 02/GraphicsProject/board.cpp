#include "Board.hpp"
#include <vector>
#include "texteditor.hpp"
#include "statictext.hpp"
#include <fstream>
#include <ctime>
#include <random>

using namespace genv;
using namespace std;

Board::Board(vector<Widget*>& vw){
    char c;
    StaticText *st;
    TextEditor *tx;
    ifstream fs("sudoku.txt");
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            {
                fs >> c;
                st = new StaticText(10+j*35,10+i*35,30,30,c);
                tx = new TextEditor(10+j*35,10+i*35,30,30,' ');
                if(c=='_')
                    vw.push_back(tx);
                else
                    vw.push_back(st);
            }
}

Board::Board(vector<Widget*>& vw, vector<Widget*> vw2){
    srand(time(NULL));
    int oszlop;
    int oszlop2;
    char c;
    StaticText *st;
    TextEditor *tx;
    ifstream fs("solved.txt");
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            {
                fs >> c;
                st = new StaticText(10+j*35,10+i*35,30,30,c);
                    vw2.push_back(st);
            }
    oszlop = rand() % 9;
    oszlop2 = rand() %9;
    while(oszlop2/3 != oszlop/3 || oszlop2==oszlop)
    {
        oszlop2 = rand() %9;
    }

    for (int i=0; i<9; i++)
    {
        char seged=vw[oszlop+i]->value();
        vw2[oszlop+i]->setchar(vw2[oszlop2+i]->value());
        vw2[oszlop2+i]->setchar(seged);
    }

    for(int i=0; i<81; i++)
    {
        if (vw[i]->value()!=' ')
            vw[i]->setchar(vw2[i]->value());
    }
}

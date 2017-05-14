#include "Board.hpp"
#include <vector>
#include "texteditor.hpp"
#include "statictext.hpp"
#include <fstream>

using namespace genv;
using namespace std;

Board::Board(vector<Widget*>& vw){
    char c;
    int db;
    StaticText *st;
    TextEditor *tx;
    ifstream fs("sudoku.txt");
    fs >> db;
    for(int k=0;k<db; k++)
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                {
                    fs >> c;
                    st = new StaticText(10+j*30,10+i*30,20,20,c);
                    tx = new TextEditor(10+j*30,10+i*30,20,20,' ');
                    if(c=='_')
                        vw.push_back(tx);
                    else
                        vw.push_back(st);
                }
}

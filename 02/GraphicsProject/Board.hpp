#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include <vector>
#include "texteditor.hpp"
#include "statictext.hpp"
#include <fstream>

class Board{
protected:
    int _db;
public:
        Board(std::vector<Widget*>& vw);
        int retdb() {return _db;}
};


#endif // BOARD_HPP_INCLUDED

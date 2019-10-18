#ifndef BOARD_H
#define BOARD_H
class board 
{
    
    private:
        int cells[3][3];
        char player;
    public:
        board();
        void makeMove();
        bool checkTris();
};
#endif
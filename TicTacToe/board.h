#ifndef BOARD_H
#define BOARD_H
class board
{
    private:
        char cells[3][3];     //game board
        int row;              //row indicator
        char col;             //column indicator
        int col_num;          //column numeric indicator
        char opp_move;        //opponent move
        char symb;            //choice of X or O
        char opp_symb;        //symbol not chosen by player
    public:
        board();              //initializer
        void playerSymb();    //makes user choose X or O
        void chooseCell();    //makes user choose a cell for their move
        void plMove();        //makes user move
        int chooseMove();    //algorithm that chooses the best move
        void oppMove();       //actually makes a move on the board
        bool checkTris();     //checks if someone won
        bool checkEmpty();    //checks if chosen cell is empty
        void showBoard();     //outputs the state of the board
        void clearBoard();    //clears the board
};
#endif

#ifndef BOARD_H
#define BOARD_H
class board
{
    private:
        char cells[3][3];                          //game board
        int row;                                   //row indicator
        char col;                                  //column indicator
        int col_num;                               //column numeric indicator
        char opp_move;                             //opponent move
        char symb;                                 //choice of X or O
        char opp_symb;                             //symbol not chosen by player
        char winner;                               //winner of the game
    public:
        board();                                   //initializer
        void playerSymb();                         //makes user choose X or O
        void chooseCell();                         //makes user choose a cell for their move
        void plMove();                             //makes user move
        int chooseMove();                          //returns the best move from minimax algorithm
        void oppMove();                            //actually makes a move on the board
        int evaluate();                            //evaluate the state of the board
        int minimax(int depth, bool isMax);        //minimax algorithm
        char checkTris();                          //checks if someone won
        bool checkDraw();                          //checks if there is a tie
        bool checkEmpty();                         //checks if chosen cell is empty
        void showBoard();                          //outputs the state of the board
        void clearBoard();                         //clears the board
        void game();                               //starts a game
};
#endif

// PRoject for solving suduko probleam with implementation of DSA and Oops.

#include <iostream>
#include <stdlib.h>
#define N 9                               // We define N as 9 
using namespace std;

int board[N][N] = {                         // 2D array of [9][9]
    {5, 3, 0, 0, 7, 0, 0, 0, 0},            //The 0 here represent the paced to be filled
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

class GameSolver                           //Class implementation
{
private:               // this class solve the 9x9 grid by using the backtracking algorithm.
    int row, col;

public:
    GameSolver() {}             //constructor block
    GameSolver(int row, int col)
    {
        this->row = row;          //this pointer
        this->col = col;
    }
    friend void printSudoko();                 // Function declaration
    friend bool presentInRow(int row, int num);
    friend bool presentInCol(int col, int num);
    friend bool presentInRow(int boxRow, int boxCol, int num);
    friend bool isEmpty(int &row, int &col);
    friend bool isValid(int row, int col, int num);
    friend bool sudokoSolve();
};

class UserSolver : public GameSolver                  //User solver class inherited with Gamesolver
{
private:
    int x, y;
    int row, col;                   //child class that takes the input from the user, checks the inputs and provides result.

public:
    UserSolver(int x, int y, int row, int col)
    {
        this->x = x;           //this pointer
        this->y = y;
        this->row = row;
        this->col = col;
    }
    friend void displayConsole(int copyBoard[N][N]);  //function declartaion
    friend void solveConsole(int copyBoard[N][N]);
    friend bool check(int copyBoard[N][N]);
};

void printSudoko()                     // Function to print suduko
{
    cout << "--------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
            if (j == 2 || j == 5)
                cout << "|";
        }
        cout << endl;
        if (i == 2 || i == 5)
            cout << "--------------------" << endl;
    }
    cout << "--------------------" << endl;
}

bool presentInRow(int row, int num)      //Function to check if particular number is in the Row or not
{
    for (int col = 0; col < N; col++)
    {
        if (board[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool presentInCol(int col, int num)   //Function to check if particular number is in the coloumn or not
{
    for (int row = 0; row < N; row++)
    {
        if (board[row][col] == num)
        {
            return true;
        }
    }
    return false;
}
bool presentInRow(int boxRow, int boxCol, int num) //check if numbe ris alread present in row or not
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row + boxRow][col + boxCol] == num)
            {
                return true;
            }
        }
    }
    return false;
}

bool isEmpty(int &row, int &col)  //Function to check for empty part and check if we can add values or not
{
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (board[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool isValid(int row, int col, int num)  // it returns onl valid numbers that are not present
{
    return !presentInRow(row, num) && !presentInCol(col, num) && !presentInRow(row - row % 3, col - col % 3, num);
}

bool sudokoSolve()
{                                          //use to solve the entire Sudoku using brute force and backtracking algorithms
    GameSolver obj(0, 0);
    if (!isEmpty(obj.row, obj.col))
    {
        return true;
    }
    for (int num = 1; num <= N; num++)
    {
        if (isValid(obj.row, obj.col, num))
        {
            board[obj.row][obj.col] = num;
            if (sudokoSolve())
            {
                return true;
            }
            board[obj.row][obj.col] = 0;
        }
    }
    return false;
}

void displayConsole(int copyBoard[N][N])
{
    UserSolver obj(0, 0, 0, 0);           //Use to display the output in format with colors
    cout << "\033[1m\033[34m";
    cout << "--------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (copyBoard[i][j] != 0)
            {
                cout << "\033[1m\033[34m" << copyBoard[i][j] << " ";
                obj.y++;
            }
            else if (copyBoard[i][j] == 0 && i == obj.x && j == obj.y)
            {
                cout << "\033[32m"
                     << "X"
                     << " ";
            }
            else
            {
                cout << "\033[1m\033[34m"
                     << "_ ";
            }
            if (j == 2 || j == 5)
            {
                cout << "\033[1m\033[34m"
                     << "|";
            }
        }
        if (obj.y == 9)
        {
            obj.x++;
        }
        obj.y = 0;
        cout << endl;
        if (i == 2 || i == 5)
            cout << "--------------------" << endl;
    }
    cout << "--------------------" << endl;
}

void solveConsole(int copyBoard[N][N])  //takes an argument of two dimensional array copy Board which is the duplicate of the original grid and checks whether the cells are empty or not
{
    UserSolver obj(0, 0, 0, 0);
    for (obj.row = 0; obj.row < N; obj.row++)
    {
        for (obj.col = 0; obj.col < N; obj.col++)
        {

            if (copyBoard[obj.row][obj.col] == 0)
            {
                int value;
                cin >> value;
                copyBoard[obj.row][obj.col] = value;
                system("CLS");
                displayConsole(copyBoard);
            }
        }
    }
}

bool check(int copyBoard[N][N])  //it takes an argument of two dimensional array copy Board which is the duplicate of the original grid and checks whether the cells are empty or not
{
    int i, j;
    bool flag = true;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (board[i][j] != copyBoard[i][j])
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main()       // Main body
{
    int copyBoard[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            copyBoard[i][j] = board[i][j];
        }
    }
    GameSolver obj1(0, 0); // parameterized constructor calling
    UserSolver obj(0, 0, 0, 0);
    sudokoSolve();
    displayConsole(copyBoard);
    solveConsole(copyBoard);
    if (check(copyBoard))
    { 
        system("CLS"); //Clears the console
        cout << "You Won" << endl;
    }
    else
    {
        system("CLS");
        cout << "Sorry! You lost..." << endl;
        cout << "Solved Sudoku: " << endl;
        printSudoko();
    }
    return 0;
}
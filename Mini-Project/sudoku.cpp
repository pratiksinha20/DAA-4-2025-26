#include <iostream>
using namespace std;

#define N 9

bool isSafe(int board[N][N], int row, int col, int num)
{
    for (int x = 0; x < N; x++)
        if (board[row][x] == num)
            return false;

    for (int x = 0; x < N; x++)
        if (board[x][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int board[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (board[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(board, row, col, num))
                    {
                        board[row][col] = num;

                        if (solveSudoku(board))
                            return true;

                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int board[N][N];

    cout << "Enter Sudoku (0 for empty):\n";

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    if (solveSudoku(board))
    {
        cout << "\nSolved Sudoku:\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists!";
    }

    return 0;
}
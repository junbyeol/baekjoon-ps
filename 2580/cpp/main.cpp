#include <iostream>
using namespace std;

int board[9][9];
int breaker = false;

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    solve(board);

    return 0;
}

void solve(int board[][9])
{
    if (breaker)
        return;

    bool zero_exist = false;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
            }
        }
    }
}

#include <iostream>
using namespace std;

struct Zero
{
    int row;
    int col;
    int bitmask;
};

int board[9][9];
int breaker = false;
Zero zeros[81];
int zero_cnt = 0;

int result[81];

void solve(int answers[], int depth);

int main()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 0)
                zeros[zero_cnt++] = {i, j, 0};
        }

    for (int i = 0; i < zero_cnt; i++)
    {
        Zero now = zeros[i];
        for (int j = 0; j < 9; j++)
        {
            if (board[now.row][j] != 0)
                now.bitmask = now.bitmask | (1 << board[now.row][j]);

            if (board[j][now.col] != 0)
                now.bitmask = now.bitmask | (1 << board[j][now.col]);
        }
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int block_row_start = (now.row / 3) * 3;
                int block_col_start = (now.col / 3) * 3;
                if (board[block_row_start + j][block_col_start + k] != 0)
                    now.bitmask = now.bitmask | (1 << board[block_row_start + j][block_col_start + k]);
            }
        }
        zeros[i] = now;
    }

    // for (int i = 0; i < zero_cnt; i++)
    // {
    //     Zero now = zeros[i];
    //     cout << now.row << " " << now.col << " " << now.bitmask << " ";
    //     for (int i = 0; i < 9; i++)
    //     {
    //         cout << (now.bitmask >> (i + 1)) % 2;
    //     }
    //     cout << "\n";
    // }

    solve({}, 0);

    int printt = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != 0)
                cout << board[i][j] << " ";
            else
                cout << result[printt++] << " ";
        }
        cout << "\n";
    }

    return 0;
}

void solve(int answers[], int depth)
{
    if (breaker)
        return;

    if (depth == zero_cnt)
    {
        breaker = true;
        for (int i = 0; i < depth; i++)
        {
            result[i] = answers[i];
        }
        return;
    }

    Zero now = zeros[depth];
    for (int i = 1; i <= 9; i++)
    {
        if ((now.bitmask >> i) % 2 == 0)
        {
            int tmp[81] = {};
            bool valid = true;

            for (int j = 0; j < 9; j++)
            {
                if (board[now.row][j] == i || board[j][now.col] == i)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        int block_row_start = (now.row / 3) * 3;
                        int block_col_start = (now.col / 3) * 3;
                        if (board[block_row_start + j][block_col_start + k] == i)
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid)
                        break;
                }
            }

            if (valid)
            {
                for (int j = 0; j < depth; j++)
                {
                    if ((now.col == zeros[j].col && answers[j] == i) ||
                        (now.row == zeros[j].row && answers[j] == i) ||
                        (now.row / 3 == zeros[j].row / 3 && now.col / 3 == zeros[j].col / 3 && answers[j] == i))
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid)
            {
                for (int j = 0; j < depth; j++)
                {
                    tmp[j] = answers[j];
                }
                tmp[depth] = i;
                solve(tmp, depth + 1);
            }
        }
    }
}

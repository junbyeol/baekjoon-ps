#include <iostream>
using namespace std;
typedef pair<int, int> crd;

int color = 0;
int board[128][128];

void color_board(crd start, crd end, crd hole)
{
    // cout << start.first << " " << start.second << " " << end.first << " " << end.second << " " << hole.first << " " << hole.second << "\n";
    if (end.first - start.first == 2 && end.second - start.second == 2)
    {
        if (hole.first != start.first || hole.second != start.second)
        {
            board[start.first][start.second] = color;
        }
        if (hole.first != start.first + 1 || hole.second != start.second)
        {
            board[start.first + 1][start.second] = color;
        }
        if (hole.first != start.first || hole.second != start.second + 1)
        {
            board[start.first][start.second + 1] = color;
        }
        if (hole.first != start.first + 1 || hole.second != start.second + 1)
        {
            board[start.first + 1][start.second + 1] = color;
        }
        color++;
        return;
    }
    crd middle = {(start.first + end.first) / 2, (start.second + end.second) / 2};

    // 2사분면
    if (hole.first < middle.first && hole.second < middle.second)
    {
        board[middle.first][middle.second - 1] = color;
        board[middle.first - 1][middle.second] = color;
        board[middle.first][middle.second] = color;
        color++;

        // 2
        color_board(start, middle, hole);
        // 1
        color_board({start.first, middle.second}, {middle.first, end.second}, {middle.first - 1, middle.second});
        // 3
        color_board({middle.first, start.second}, {end.first, middle.second}, {middle.first, middle.second - 1});
        // 4
        color_board(middle, end, middle);
        return;
    }

    // 3사분면
    if (hole.first >= middle.first && hole.second < middle.second)
    {
        board[middle.first - 1][middle.second - 1] = color;
        board[middle.first - 1][middle.second] = color;
        board[middle.first][middle.second] = color;
        color++;

        // 2
        color_board(start, middle, {middle.first - 1, middle.second - 1});
        // 1
        color_board({start.first, middle.second}, {middle.first, end.second}, {middle.first - 1, middle.second});
        // 3
        color_board({middle.first, start.second}, {end.first, middle.second}, hole);
        // 4
        color_board(middle, end, middle);
        return;
    }

    // 1사분면
    if (hole.first < middle.first && hole.second >= middle.second)
    {
        board[middle.first - 1][middle.second - 1] = color;
        board[middle.first][middle.second - 1] = color;
        board[middle.first][middle.second] = color;
        color++;

        // 2
        color_board(start, middle, {middle.first - 1, middle.second - 1});
        // 1
        color_board({start.first, middle.second}, {middle.first, end.second}, hole);
        // 3
        color_board({middle.first, start.second}, {end.first, middle.second}, {middle.first, middle.second - 1});
        // 2
        color_board(middle, end, middle);
        return;
    }

    // 4사분면
    board[middle.first][middle.second - 1] = color;
    board[middle.first - 1][middle.second] = color;
    board[middle.first - 1][middle.second - 1] = color;
    color++;

    // 2
    color_board(start, middle, {middle.first - 1, middle.second - 1});
    // 1
    color_board({start.first, middle.second}, {middle.first, end.second}, {middle.first - 1, middle.second});
    // 3
    color_board({middle.first, start.second}, {end.first, middle.second}, {middle.first, middle.second - 1});
    // 2
    color_board(middle, end, hole);
}

int main()
{
    int N, r, c;
    cin >> N;
    cin >> r >> c;

    int len = 1 << N;

    crd hole = {len - c, r - 1};

    board[hole.first][hole.second] = -1;
    color++;

    color_board({0, 0}, {len, len}, hole);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
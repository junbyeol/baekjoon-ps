#include <iostream>
using namespace std;
typedef pair<int, int> crd;

char board[1024][1024];

void color_board(crd start, crd end, crd hole)
{
    // cout << start.first << " " << start.second << " " << end.first << " " << end.second << " " << hole.first << " " << hole.second << "\n";
    if (end.first - start.first == 2 && end.second - start.second == 2)
    {
        if (hole.first != start.first || hole.second != start.second)
        {
            board[start.first][start.second] = (start.first + start.second) % 4 == 0 ? 'b' : 'c';
        }
        if (hole.first != start.first + 1 || hole.second != start.second)
        {
            board[start.first + 1][start.second] = (start.first + start.second) % 4 == 0 ? 'b' : 'c';
        }
        if (hole.first != start.first || hole.second != start.second + 1)
        {
            board[start.first][start.second + 1] = (start.first + start.second) % 4 == 0 ? 'b' : 'c';
        }
        if (hole.first != start.first + 1 || hole.second != start.second + 1)
        {
            board[start.first + 1][start.second + 1] = (start.first + start.second) % 4 == 0 ? 'b' : 'c';
        }
        return;
    }
    crd middle = {(start.first + end.first) / 2, (start.second + end.second) / 2};

    // 2사분면
    if (hole.first < middle.first && hole.second < middle.second)
    {
        board[middle.first][middle.second - 1] = 'a';
        board[middle.first - 1][middle.second] = 'a';
        board[middle.first][middle.second] = 'a';

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
        board[middle.first - 1][middle.second - 1] = 'a';
        board[middle.first - 1][middle.second] = 'a';
        board[middle.first][middle.second] = 'a';

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
        board[middle.first - 1][middle.second - 1] = 'a';
        board[middle.first][middle.second - 1] = 'a';
        board[middle.first][middle.second] = 'a';

        // 2
        color_board(start, middle, {middle.first - 1, middle.second - 1});
        // 1
        color_board({start.first, middle.second}, {middle.first, end.second}, hole);
        // 3
        color_board({middle.first, start.second}, {end.first, middle.second}, {middle.first, middle.second - 1});
        // 4
        color_board(middle, end, middle);
        return;
    }

    // 4사분면
    board[middle.first][middle.second - 1] = 'a';
    board[middle.first - 1][middle.second] = 'a';
    board[middle.first - 1][middle.second - 1] = 'a';

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
    int TC, K;
    cin >> TC >> K;

    int len = 1 << K;

    for (int t = 0; t < TC; t++)
    {
        int r, c;
        cin >> r >> c;
        board[r - 1][c - 1] = '@';

        color_board({0, 0}, {len, len}, {r - 1, c - 1});
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
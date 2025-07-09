#include <iostream>
using namespace std;

typedef pair<int, int> pii;

int N;
int board[10][10];

int bishop(int x, int y, int placed_cnt, int minus_bit, int plus_bit);

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int max_val = bishop(0, 0, 0, 0, 0) + bishop(0, 1, 0, 0, 0);

    cout << max_val << "\n";

    return 0;
}

int bishop(int x, int y, int placed_cnt, int minus_bit, int plus_bit)
{
    if (x == N)
    {
        return placed_cnt;
    }

    int nextx = y + 2 < N ? x : x + 1;
    int nexty = y + 2 < N ? y + 2 : (x % 2 == (x + y) % 2 ? 1 : 0);

    if (!board[x][y] || ((minus_bit & (1 << (N + x - y))) != 0) || ((plus_bit & (1 << (x + y))) != 0))
    {
        return bishop(nextx, nexty, placed_cnt, minus_bit, plus_bit);
    }

    return max(bishop(nextx, nexty, placed_cnt, minus_bit, plus_bit), bishop(nextx, nexty, placed_cnt + 1, minus_bit | (1 << (N + x - y)), plus_bit | (1 << (x + y))));
}

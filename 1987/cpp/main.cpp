#include <iostream>
#include <climits>
using namespace std;

int R, C;
char alphabet[20][20];
int dist[20][20];

void dfs(int r, int c, int depth, int v);

int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> alphabet[i][j];
            dist[i][j] = -1;
        }

    dist[0][0] = 1;

    dfs(0, 0, 1, 1 << (alphabet[0][0] - 65));

    int max_val = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            max_val = max(max_val, dist[i][j]);
        }
    }

    cout << max_val << "\n";

    return 0;
}

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool is_visited(int v, char c)
{
    return (v & (1 << (c - 65))) != 0;
}

void dfs(int r, int c, int depth, int v)
{
    bool is_done = true;

    for (int i = 0; i < 4; i++)
    {
        if (0 <= r + dx[i] && r + dx[i] < R && 0 <= c + dy[i] && c + dy[i] < C && !is_visited(v, alphabet[r + dx[i]][c + dy[i]]))
        {
            dfs(r + dx[i], c + dy[i], depth + 1, v | (1 << (alphabet[r + dx[i]][c + dy[i]] - 65)));
            is_done = false;
        }
    }

    if (is_done)
    {
        dist[r][c] = max(dist[r][c], depth);
        return;
    }
}

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

bool is_valid(int x, int MAX)
{
    return 0 <= x && x < MAX;
};

int main()
{
    int M, N;
    int dist[1000][1000];

    queue<pair<int, int>> q;

    cin >> M >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> dist[i][j];
            if (dist[i][j] == 1)
                q.push({i, j});
        }

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (is_valid(x + dx[i], N) && is_valid(y + dy[i], M) && dist[x + dx[i]][y + dy[i]] == 0)
            {
                dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
                q.push({x + dx[i], y + dy[i]});
            }
        }
    }

    int max_val = 0;
    bool is_all_done = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (dist[i][j] == 0)
                is_all_done = false;
            max_val = max(max_val, dist[i][j]);
        }
    }

    cout << (is_all_done ? max_val - 1 : -1) << "\n";

    return 0;
}

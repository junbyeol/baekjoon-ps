#include <iostream>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;

bool is_valid(int x, int MAX)
{
    return 0 <= x && x < MAX;
};

int main()
{
    int M, N, H;
    int dist[100][100][100];

    queue<tuple<int, int, int>> q;

    cin >> M >> N >> H;

    for (int k = 0; k < H; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                cin >> dist[i][j][k];
                if (dist[i][j][k] == 1)
                    q.push({i, j, k});
            }

    int dx[] = {0, 1, 0, -1, 0, 0};
    int dy[] = {1, 0, -1, 0, 0, 0};
    int dz[] = {0, 0, 0, 0, 1, -1};

    while (!q.empty())
    {
        auto [x, y, z] = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            if (is_valid(x + dx[i], N) && is_valid(y + dy[i], M) && is_valid(z + dz[i], H) && dist[x + dx[i]][y + dy[i]][z + dz[i]] == 0)
            {
                dist[x + dx[i]][y + dy[i]][z + dz[i]] = dist[x][y][z] + 1;
                q.push({x + dx[i], y + dy[i], z + dz[i]});
            }
        }
    }

    int max_val = 0;
    bool is_all_done = true;

    for (int k = 0; k < H; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (dist[i][j][k] == 0)
                    is_all_done = false;
                max_val = max(max_val, dist[i][j][k]);
            }

    cout << (is_all_done ? max_val - 1 : -1) << "\n";

    return 0;
}

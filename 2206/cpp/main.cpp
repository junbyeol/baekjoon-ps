#include <iostream>
#include <queue>
#include <climits>
#include <tuple>
#include <string>
using namespace std;

int M, N;
bool map[1000][1000];
int dist[2][1000][1000];

priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq;

int main()
{
    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = str[j] != '1';
            dist[0][i][j] = dist[1][i][j] = INT_MAX;
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    pq.push({0, 0, false});
    dist[0][0][0] = 1;

    while (!pq.empty())
    {
        auto [x, y, wall] = pq.top();
        // cout << x << " " << y << " " << (wall ? "true" : "false") << "\n";
        pq.pop();

        if (x == M - 1 && y == N - 1)
            break;

        for (int i = 0; i < 4; i++)
        {
            int xt = x + dx[i], yt = y + dy[i];
            if (0 <= xt && xt < M && 0 <= yt && yt < N)
            {
                if (wall)
                {
                    if (map[xt][yt] && dist[1][xt][yt] > dist[1][x][y] + 1)
                    {
                        dist[1][xt][yt] = dist[1][x][y] + 1;
                        pq.push({xt, yt, wall});
                    }
                }
                else
                {
                    if (dist[!map[xt][yt]][xt][yt] > dist[0][x][y] + 1)
                    {
                        dist[!map[xt][yt]][xt][yt] = dist[0][x][y] + 1;
                        pq.push({xt, yt, !map[xt][yt]});
                    }
                }
            }
        }
    }

    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << (dist[0][i][j] == INT_MAX ? -1 : dist[0][i][j]) << " ";
    //     }
    //     cout << "\n";
    // }
    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << (dist[1][i][j] == INT_MAX ? -1 : dist[1][i][j]) << " ";
    //     }
    //     cout << "\n";
    // }

    if (dist[0][M - 1][N - 1] == INT_MAX)
    {
        cout << (dist[1][M - 1][N - 1] == INT_MAX ? -1 : dist[1][M - 1][N - 1]) << "\n";
    }
    else
    {
        cout << min(dist[0][M - 1][N - 1], dist[1][M - 1][N - 1]) << "\n";
    }

    return 0;
}

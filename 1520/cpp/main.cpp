#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int>>> pq; // { height,{ x, y }}
int map[500][500];
int dp[500][500];

int main()
{
    int X, Y;
    cin >> X >> Y;

    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            cin >> map[i][j];
        }
    }

    dp[0][0] = 1;
    pq.push({map[0][0], {0, 0}});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!pq.empty())
    {

        auto [height, t] = pq.top();
        pq.pop();

        auto [now_x, now_y] = t;

        int way = dp[now_x][now_y];
        // cout << height << " " << now_x << " " << now_y << " " << way << "\n";

        if (now_x == X - 1 && now_y == Y - 1)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int togo_x = now_x + dx[i];
            int togo_y = now_y + dy[i];
            if (0 <= togo_x && togo_x < X && 0 <= togo_y && togo_y < Y && map[togo_x][togo_y] < height)
            {
                if (dp[togo_x][togo_y] == 0)
                {
                    pq.push({map[togo_x][togo_y], {togo_x, togo_y}});
                }
                dp[togo_x][togo_y] += way;
            }
        }
    }

    cout << dp[X - 1][Y - 1] << "\n";

    return 0;
}

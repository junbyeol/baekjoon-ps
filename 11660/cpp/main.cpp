#include <iostream>
using namespace std;

int N, M;
int dp[1025][1025];
int input[100000][4];

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int num;
            cin >> num;

            if (i == 1 & j == 1)
            {
                dp[i][j] = num;
            }
            else if (j == 1)
            {
                dp[i][j] = dp[i - 1][j] + num;
            }
            else if (i == 1)
            {
                dp[i][j] = dp[i][j - 1] + num;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + num;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        input[i][0] = x1;
        input[i][1] = y1;
        input[i][2] = x2;
        input[i][3] = y2;
    }

    for (int i = 0; i < M; i++)
    {
        int x1 = input[i][0], y1 = input[i][1], x2 = input[i][2], y2 = input[i][3];

        cout << (dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]) << "\n";
    }

    return 0;
}

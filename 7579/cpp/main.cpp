#include <iostream>
using namespace std;

#define INF 1e9

int main()
{
    int N, M;
    int bytes[100];
    int costs[100];
    int dp[100][10001];

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> bytes[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> costs[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= 10000; j++)
        {
            if (i == 0)
            {
                dp[i][j] = (j == costs[i] ? bytes[i] : 0);
                continue;
            }
            int new_record = j - costs[i] >= 0 ? dp[i - 1][j - costs[i]] + bytes[i] : 0;
            if (new_record < 0) // overflow
                new_record = INF;
            dp[i][j] = max(dp[i - 1][j], new_record);
        }
    }

    for (int j = 0; j <= 10000; j++)
    {
        if (dp[N - 1][j] >= M)
        {
            cout << j << "\n";
            break;
        }
    }

    return 0;
}

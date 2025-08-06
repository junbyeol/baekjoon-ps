#include <iostream>
#include <climits>
using namespace std;

#define INF 1e9

int main()
{
    int P, N;
    int costs[20];
    int points[20];
    cin >> P >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> costs[i] >> points[i];
    }

    int dp[20][10001];

    for (int i = 0; i < N; i++)
    {
        for (int p = 0; p <= P + 100; p++)
        {
            if (i == 0)
            {
                dp[0][p] = p % points[0] == 0 ? p / points[0] * costs[0] : INF;
            }
            else
            {
                int min_val = INT_MAX;
                for (int k = p / points[i]; k >= 0; k--)
                {
                    min_val = min(min_val, dp[i - 1][p - k * points[i]] + k * costs[i]);
                }
                dp[i][p] = min_val;
            }
        }
    }

    int min_val = INT_MAX;
    for (int p = P; p <= P + 100; p++)
    {
        min_val = min(dp[N - 1][p], min_val);
    }
    cout << min_val << "\n";
    return 0;
}

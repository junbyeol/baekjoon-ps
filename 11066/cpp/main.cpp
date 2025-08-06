#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int TC;
    cin >> TC;
    for (int tc = 0; tc < TC; tc++)
    {
        int n;
        pair<int, int> dp[500][500]; // { chapter size, cost }
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int now_size;
            cin >> now_size;
            dp[i][i] = {now_size, 0};

            for (int j = i - 1; j >= 0; j--)
            {
                /* dp[j][i] = min{2 * (dp[j][j + k] + dp[j + k + 1][i])}; */
                pair<int, int> min_cost = {0, INT_MAX};
                for (int k = 0; k <= i - j - 1; k++)
                {
                    int cost = dp[j][j + k].first + dp[j][j + k].second + dp[j + k + 1][i].first + dp[j + k + 1][i].second;
                    if (min_cost.second > cost)
                    {
                        min_cost = {dp[j][j + k].first + dp[j + k + 1][i].first, cost};
                    }
                }
                dp[j][i] = min_cost;
            }
        }

        cout << dp[0][n - 1].second << "\n";
    }

    return 0;
}

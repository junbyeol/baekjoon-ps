#include <iostream>
#include <climits>
using namespace std;

int N;
pair<int, int> mats[500];

struct mat_info
{
    pair<int, int> size;
    int to_cal;
};
mat_info dp[500][500];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        mats[i] = {x, y};
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (i == j)
                dp[i][j] = {{mats[i].first, mats[i].second}, 0};
            else
            {
                int min_val = INT_MAX;
                for (int k = 0; k <= i - j; k++)
                {
                    mat_info term2 = dp[i][i - k];
                    mat_info term1 = dp[i - k - 1][j];

                    int val = term1.to_cal + term2.to_cal + term1.size.first * term1.size.second * term2.size.second;
                    if (min_val > val)
                    {
                        min_val = val;
                        dp[i][j] = {{term1.size.first, term2.size.second}, val};
                    }
                }
            }
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = i; j >= 0; j--)
    //     {
    //         cout << "(" << dp[i][j].size.first << "," << dp[i][j].size.second << "):" << dp[i][j].to_cal << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[N - 1][0].to_cal << "\n";

    return 0;
}

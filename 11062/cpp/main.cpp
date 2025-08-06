#include <iostream>
using namespace std;

int main()
{
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++)
    {
        int N;
        int cards[1000];
        int dp[1000][1000];
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> cards[i];
        }

        for (int k = 0; k < N; k++)
        {
            for (int i = k; i < N; i++)
            {
                bool is_kw_turn = N % 2 == 1 ? k % 2 == 0 : k % 2 == 1;
                if (k == 0)
                {
                    dp[i][i] = is_kw_turn ? cards[i] : 0;
                }
                else
                {
                    dp[i - k][i] = is_kw_turn ? max(dp[i - k + 1][i] + cards[i - k], dp[i - k][i - 1] + cards[i]) : min(dp[i - k + 1][i], dp[i - k][i - 1]);
                }
            }
        }

        cout << dp[0][N - 1] << "\n";
    }
    return 0;
}

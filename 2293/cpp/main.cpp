#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    int coins[100];
    int dp[2][10001]; // i 반쩨까지의 동전을 이용하여, j원의 가격을 만드는 경우의 수 (단, i%2)

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    sort(coins, coins + N);

    for (int c = 0; c < N; c++)
    {
        int coin = coins[c]; // 가장 적은 액수의 동전부터
        for (int k = 0; k <= K; k++)
        {
            if (c == 0)
            {
                dp[c % 2][k] = (k % coin == 0 ? 1 : 0);
                continue;
            }

            int way = 0;
            for (int i = k / coin; i >= 0; i--)
            {
                int index_before = (c + 1) % 2;
                way += dp[index_before][k - coin * i];
            }
            dp[c % 2][k] = way;
        }
    }

    cout << dp[(N - 1) % 2][K] << "\n";

    return 0;
}

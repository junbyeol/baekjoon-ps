#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int dp[1000001];

    for (int i = N; i > 0; i--)
    {
        if (i == N)
            dp[N] = 0;
        else
        {
            dp[i] = dp[i + 1];
            if (i <= N / 2)
                dp[i] = min(dp[i], dp[i * 2]);
            if (i <= N / 3)
                dp[i] = min(dp[i], dp[i * 3]);

            dp[i] += 1;
        }
    }

    cout << dp[1] << "\n";

    return 0;
}

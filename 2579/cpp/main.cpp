#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int N;
    int num[300];
    int dp[300][2]; // 0은 처음 밟는 계단, 1은 한번 밟은 계단
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    dp[0][0] = num[0];
    dp[0][1] = INT_MIN;
    dp[1][0] = num[1];
    dp[1][1] = num[0] + num[1];

    for (int i = 2; i < N; i++)
    {
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + num[i];
        dp[i][1] = dp[i - 1][0] + num[i];
    }

    cout << max(dp[N - 1][0], dp[N - 1][1]) << "\n";

    return 0;
}

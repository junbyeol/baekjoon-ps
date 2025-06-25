#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int N;
    int num[10000];
    int dp[10000][3]; // 0은 안 마시고, 1은 처음으로 마시고, 2는 두번째로 마시고
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    dp[0][0] = 0;
    dp[0][1] = num[0];

    dp[1][0] = num[0];
    dp[1][1] = num[1];
    dp[1][2] = num[0] + num[1];

    for (int i = 2; i < N; i++)
    {
        dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
        dp[i][1] = max(max(dp[i - 2][0], dp[i - 2][1]), dp[i - 2][2]) + num[i];
        dp[i][2] = dp[i - 1][1] + num[i];
    }

    int sum = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        sum = max(sum, dp[i][0]);
        sum = max(sum, dp[i][1]);
        sum = max(sum, dp[i][2]);
    }

    cout << sum << "\n";

    return 0;
}

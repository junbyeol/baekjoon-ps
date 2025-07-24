#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> answers;

    for (int i = 0; i < N; i++)
    {
        int n, stickers[2][100000];
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> stickers[0][j];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> stickers[1][j];
        }

        int dp[2][100000];

        dp[0][0] = stickers[0][0];
        dp[1][0] = stickers[1][0];

        dp[0][1] = stickers[0][1] + dp[1][0];
        dp[1][1] = stickers[1][1] + dp[0][0];

        for (int j = 2; j < n; j++)
        {
            dp[0][j] = max(max(dp[1][j - 1], dp[0][j - 2]), dp[1][j - 2]) + stickers[0][j];
            dp[1][j] = max(max(dp[0][j - 1], dp[1][j - 2]), dp[0][j - 2]) + stickers[1][j];
        }

        answers.push_back(max(dp[0][n - 1], dp[1][n - 1]));
    }

    for (int answer : answers)
    {
        cout << answer << "\n";
    }

    return 0;
}

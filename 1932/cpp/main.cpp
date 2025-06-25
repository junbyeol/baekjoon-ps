#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int N;
    int num[500][500];
    int dp[500][500];
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> num[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = num[0][0];
            else if (j == 0)
                dp[i][0] = dp[i - 1][0] + num[i][0];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + num[i][j];
        }
    }

    int val = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        val = max(dp[N - 1][i], val);
    }
    cout << val << "\n";

    return 0;
}

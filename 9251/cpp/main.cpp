#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    A = '0' + A;
    B = '0' + B;
    int al = A.length(), bl = B.length();

    int dp[1001][1001];
    fill(&dp[0][0], &dp[0][0] + 1001 * 1001, 1);

    for (int i = 1; i < al; i++)
    {
        for (int j = 1; j < bl; j++)
        {
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }

    cout << dp[al - 1][bl - 1] - 1 << "\n";

    return 0;
}

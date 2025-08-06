#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int num[2001];
    bool dp[2001][2001];

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
    }

    for (int i = 1; i < N; i++)
    {
        dp[i][i] = true;
        dp[i][i + 1] = num[i] == num[i + 1];
    }
    dp[N][N] = true;

    for (int k = 2; k < N; k++)
    {
        for (int i = k + 1; i <= N; i++)
        {
            dp[i - k][i] = dp[i - k + 1][i - 1] && num[i - k] == num[i];
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << (dp[s][e] ? 1 : 0) << "\n";
    }

    return 0;
}

#include <iostream>
#include <climits>
using namespace std;

struct Item
{
    int w;
    int v;
};

int main()
{
    int N, K;
    cin >> N >> K;
    Item item[100];
    for (int i = 0; i < N; i++)
    {
        int w, v;
        cin >> w >> v;
        item[i] = {w, v};
    }

    // i번째 물건까지 넣었을때, 남은 가능 무게가 j인 배열
    int dp[100][100001];

    for (int j = 0; j < K; j++)
    {
        dp[0][j] = K - item[0].w >= j ? item[0].v : 0;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if (j + item[i].w <= K)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + item[i].w] + item[i].v);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int max_val = INT_MIN;
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < K; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < N; i++)
    {
        max_val = max(dp[N - 1][i], max_val);
    }
    cout << max_val << "\n";

    return 0;
}

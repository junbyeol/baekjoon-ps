#include <iostream>
#include <queue>
using namespace std;

bool dp[30][40001];
queue<int> avail;

int main()
{
    int M, N;
    cin >> M;

    avail.push(0);

    for (int i = 0; i < M; i++)
    {
        int beads;
        cin >> beads;

        for (int w = 1; w <= 40000; w++)
        {
            if (i == 0)
            {
                dp[0][w] = w == beads;
            }
            else
            {
                dp[i][w] = (w == beads) || dp[i - 1][w] || (w - beads > 0 && dp[i - 1][w - beads]) || (beads - w > 0 && dp[i - 1][beads - w]) || (w + beads <= 40000 && dp[i - 1][w + beads]);
            }
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int w;
        cin >> w;
        cout << (dp[M - 1][w] ? "Y" : "N") << " ";
    }

    return 0;
}

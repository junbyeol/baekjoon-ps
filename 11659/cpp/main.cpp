#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int num[100000];
    int sum[100000];

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        if (i == 0)
        {
            sum[i] = num[i];
        }
        else
        {
            sum[i] = num[i] + sum[i - 1];
        }
    }

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        if (s == 1)
        {
            cout << sum[e - 1] << "\n";
        }
        else
        {
            cout << sum[e - 1] - sum[s - 2] << "\n";
        }
    }

    return 0;
}

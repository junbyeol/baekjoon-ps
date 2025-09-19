#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    int N;
    cin >> str >> N;
    int dp[26][2000];

    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        char now = str.at(i);
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (now == c)
            {
                dp[c - 'a'][i] = i != 0 ? dp[c - 'a'][i - 1] + 1 : 1;
            }
            else
            {
                dp[c - 'a'][i] = i != 0 ? dp[c - 'a'][i - 1] : 0;
            }
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        char c;
        int s, e;
        cin >> c >> s >> e;
        cout << dp[c - 'a'][e] - (s != 0 ? dp[c - 'a'][s - 1] : 0) << "\n";
    }

    return 0;
}

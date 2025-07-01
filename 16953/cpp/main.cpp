#include <iostream>
#include <climits>
using namespace std;

long long A, B;
long long answer = -1;

void dfs(long long now, long long depth);

int main()
{
    cin >> A >> B;

    dfs(A, 1);
    cout << answer << "\n";

    return 0;
}

void dfs(long long now, long long depth)
{
    if (now > B)
        return;

    if (now == B)
    {
        answer = answer == -1 ? depth : min(answer, depth);
        return;
    }

    dfs(10 * now + 1, depth + 1);
    dfs(now * 2, depth + 1);

    return;
}
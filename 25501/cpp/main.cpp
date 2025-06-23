#include <iostream>
#include <cstring>
using namespace std;

struct RESULT
{
    int val;
    int called;
};

RESULT recursion(const char *s, int l, int r, int called)
{
    if (l >= r)

        return {1, called + 1};
    else if (s[l] != s[r])
        return {0, called + 1};
    else
        return recursion(s, l + 1, r - 1, called + 1);
}

RESULT run(const char *s)
{
    return recursion(s, 0, strlen(s) - 1, 0);
}

int main()
{
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char str[1001];
        cin >> str;

        RESULT result = run(str);
        cout << result.val << " " << result.called << endl;
    }
    return 0;
}

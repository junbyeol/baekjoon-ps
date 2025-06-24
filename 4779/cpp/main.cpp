#include <iostream>
#include <string>
using namespace std;

string cantore(int N);

int main()
{
    int N;
    while (cin >> N)
    {
        cout << cantore(N) << endl;
    }
    return 0;
}

string cantore(int N)
{
    if (N == 0)
        return "-";

    string before = cantore(N - 1);
    string empty = "";
    for (long long i = 0; i < before.length(); i++)
    {
        empty += " ";
    }

    return before + empty + before;
}
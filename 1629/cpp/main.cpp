#include <iostream>
using namespace std;

int A, B, C;
long long multiple(int mult);

int main()
{
    cin >> A >> B >> C;

    cout << multiple(B) << "\n";
    return 0;
}

long long multiple(int mult)
{
    if (mult == 1)
        return A % C;

    long long half = multiple(mult / 2);

    if (mult % 2 == 0)
    {
        return (half * half) % C;
    }

    return (((half * half) % C) * A) % C;
}

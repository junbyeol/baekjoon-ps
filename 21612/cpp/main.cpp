#include <iostream>
using namespace std;

int main()
{
    int B;
    cin >> B;
    int P = 5 * B - 400;
    cout << P << "\n"
         << (P == 100 ? 0 : P > 100 ? -1
                                    : 1)
         << "\n";
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < 2 * N - 1; i++)
    {
        int floor = i >= N ? 2 * N - 2 - i : i;
        for (int j = 0; j < floor + 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * N - 2 - 2 * floor; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < floor + 1; j++)
        {
            cout << "*";
        }
        cout << " \n";
    }
    return 0;
}

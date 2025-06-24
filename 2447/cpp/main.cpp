#include <iostream>
using namespace std;

void print_stars(int N);
bool should_print_star(int row, int col, int mod);

int main()
{
    int N;
    cin >> N;

    print_stars(N);

    return 0;
}

void print_stars(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << (should_print_star(i, j, N) ? "*" : " ");
        }
        cout << endl;
    }
}

bool should_print_star(int row, int col, int mod)
{
    if (mod == 1)
    {
        return true;
    }
    int third = mod / 3;
    int second_third = third + third;

    if (third <= row && row < second_third && third <= col && col < second_third)
    {
        return false;
    }

    return should_print_star(row % third, col % third, mod / 3);
}

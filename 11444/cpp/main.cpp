#include <iostream>
using namespace std;

typedef pair<pair<long long, long long>, pair<long long, long long>> mat;

mat mem[100];
mat mm(mat A, mat B);
mat m_powers(int power_of_twos);

int main()
{
    long long N;
    mat answer = {{1, 0}, {0, 1}};

    cin >> N;

    if (N == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 0; i < 100; i++)
    {
        mem[i] = {{-1, -1}, {-1, -1}};
    }
    mem[0] = {{1, 1},
              {1, 0}};

    int power = 0;
    while (((N - 1) >> power) > 0)
    {
        int bit = ((N - 1) >> power) % 2;

        if (bit)
        {
            answer = mm(answer, m_powers(power));
        }

        power++;
    }

    cout << answer.first.first << "\n";
    return 0;
}

mat mm(mat A, mat B)
{
    long long a_11 = (A.first.first * B.first.first) + (A.first.second * B.second.first);
    long long a_12 = (A.first.first * B.first.second) + (A.first.second * B.second.second);
    long long a_21 = (A.second.first * B.first.first) + (A.second.second * B.second.first);
    long long a_22 = (A.second.first * B.first.second) + (A.second.second * B.second.second);

    return {{a_11, a_12}, {a_21, a_22}};
}

mat m_powers(int power_of_twos)
{
    if (mem[power_of_twos].first.first != -1)
        return mem[power_of_twos];

    mat m = m_powers(power_of_twos - 1);
    mem[power_of_twos] = mm(m, m);
    return mem[power_of_twos];
}
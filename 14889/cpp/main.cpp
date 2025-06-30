#include <iostream>
#include <climits>
using namespace std;

int N;
int num[20][20];
int team_gap(int depth, char team[]);

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> num[i][j];
        }
    }

    cout << team_gap(0, {}) << "\n";

    return 0;
}

int team_gap(int depth, char team[])
{
    if (depth == N)
    {
        int teamA = 0;
        int teamB = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i != j && team[i] == team[j])
                {
                    if (team[i] == 'A')
                        teamA += num[i][j];
                    else
                        teamB += num[i][j];
                }
            }
        }
        return teamA - teamB > 0 ? teamA - teamB : teamB - teamA;
    }

    int teamAMem = 0;
    int teamBMem = 0;
    for (int i = 0; i < depth; i++)
    {
        if (team[i] == 'A')
            teamAMem++;
        else
            teamBMem++;
    }

    int cand_cnt = 0;
    int candds[20] = {};

    char teamt[20];
    for (int i = 0; i < depth; i++)
    {
        teamt[i] = team[i];
    }

    if (teamAMem < N / 2)
    {
        teamt[depth] = 'A';
        candds[cand_cnt++] = team_gap(depth + 1, teamt);
    }
    if (teamBMem < N / 2)
    {
        teamt[depth] = 'B';
        candds[cand_cnt++] = team_gap(depth + 1, teamt);
    }

    int min_val = INT_MAX;
    for (int i = 0; i < cand_cnt; i++)
    {
        min_val = min(min_val, candds[i]);
    }
    return min_val;
}

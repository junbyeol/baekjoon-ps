#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> crd;
typedef pair<crd, crd> line;
typedef crd vect;

int N;
line lines[3000];
vector<int> connections[3000];
int groups[3000];
int group_cnt = 0;
int max_group_size = 0;

bool is_crossing(line f1, line f2);
int dfs(int node);

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines[i] = {{x1, y1}, {x2, y2}};
        groups[i] = -1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << " " << j << "\n";
            if (is_crossing(lines[i], lines[j]))
            {
                cout << i << " " << j << "\n";
                connections[i].push_back(j);
                connections[j].push_back(i);
            }
        }
    }

    // cout << "\n";

    for (int i = 0; i < N; i++)
    {
        if (groups[i] == -1)
        {
            groups[i] = group_cnt++;
            max_group_size = max(max_group_size, dfs(i));
        }
    }

    // cout << "\n";

    // for (int i = 0; i < N; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < connections[i].size(); j++)
    //     {
    //         cout << connections[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";

    // for (int i = 0; i < N; i++)
    // {
    //     cout << groups[i] << " ";
    // }
    // cout << "\n";
    // cout << "\n";

    cout << group_cnt << "\n"
         << max_group_size << "\n";

    return 0;
}

int ccw(vect v1, vect v2)
{
    long long val = (long long)v1.first * (long long)v2.second - (long long)v1.second * (long long)v2.first;
    if (val == 0)
        return 0;
    return val > 0 ? 1 : -1;
}

vect to_vect(crd a, crd b)
{
    return {b.first - a.first, b.second - a.second};
}

bool is_crossing(line f1, line f2)
{
    int ccw1 = ccw(to_vect(f1.first, f1.second), to_vect(f1.first, f2.first));
    int ccw2 = ccw(to_vect(f1.first, f1.second), to_vect(f1.first, f2.second));
    int ccw3 = ccw(to_vect(f2.first, f2.second), to_vect(f2.first, f1.first));
    int ccw4 = ccw(to_vect(f2.first, f2.second), to_vect(f2.first, f1.second));

    int for_f1 = ccw1 * ccw2;
    int for_f2 = ccw3 * ccw4;

    cout << ccw1 << " " << ccw2 << " " << ccw3 << " " << ccw4 << "\n";

    if (for_f1 == 0 && for_f2 == 0)
    {
        crd p1 = f1.first < f1.second ? f1.first : f1.second;
        crd p2 = f1.first < f1.second ? f1.second : f1.first;
        crd p3 = f2.first < f2.second ? f2.first : f2.second;
        crd p4 = f2.first < f2.second ? f2.second : f2.first;

        return p4 >= p1 && p2 >= p3;
    }

    return for_f1 <= 0 && for_f2 <= 0;
}

int dfs(int node)
{
    int size = 1;
    for (int i = 0; i < connections[node].size(); i++)
    {
        int togo = connections[node][i];
        if (groups[togo] == -1)
        {
            groups[togo] = groups[node];
            size += dfs(togo);
        }
    }
    return size;
}
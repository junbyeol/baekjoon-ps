#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string str;

    cin >> str;

    if (str == "SONGDO")
        cout << "HIGHSCHOOL\n";
    else if (str == "CODE")
        cout << "MASTER\n";
    else if (str == "2023")
        cout << "0611\n";
    else if (str == "ALGORITHM")
    {
        cout << "CONTEST\n";
    }
    return 0;
}

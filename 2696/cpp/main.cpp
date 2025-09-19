#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int TC;
  cin >> TC;
  for (int t = 0; t < TC; t++) {
    priority_queue<int> sm;
    priority_queue<int, vector<int>, greater<int>> lg;
    int mid;
    vector<int> answer;

    int N;
    cin >> N;
    cin >> mid;
    answer.push_back(mid);

    for (int i = 1; i < N; i += 2) {
      if (N % 2 == 0 && i == N - 1) {
        int trash;
        cin >> trash;
        continue;
      }
      int input1, input2;
      cin >> input1 >> input2;

      if (input1 > input2) {  // always keep input1 <= input2
        int tmp = input1;
        input1 = input2;
        input2 = tmp;
      }

      if (input2 < mid) {  // input1 <= input2 < mid
        sm.push(input1);
        sm.push(input2);
        int pop2 = sm.top();
        sm.pop();
        // int pop1 = sm.top();
        // pop1 < pop2 < mid

        answer.push_back(pop2);
        lg.push(mid);
        mid = pop2;
      } else if (input1 > mid) {  //  mid < input1 <= input2
        lg.push(input1);
        lg.push(input2);
        int pop1 = lg.top();
        lg.pop();
        //   int pop2 = lg.top();
        // mid < pop1 < pop2

        answer.push_back(pop1);
        sm.push(mid);
        mid = pop1;
      } else {  // input1 <= mid <= input2
        sm.push(input1);
        lg.push(input2);
        answer.push_back(mid);
      }
    }

    cout << answer.size() << "\n";
    for (int ans : answer) {
      cout << ans << " ";
    }
    cout << "\n";
  }

  return 0;
}

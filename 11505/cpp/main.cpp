#include <iostream>
using namespace std;

#define MAX_LEN 1000001
#define MOD 1000000007
long long arr[MAX_LEN];
long long segtree[MAX_LEN * 4];

void build(int start, int end, int now) {
  //   cout << start << " " << end << " " << now << "\n";
  if (start == end) {
    segtree[now] = arr[start];
    return;
  }

  int mid = (start + end) / 2;
  build(start, mid, now * 2);
  build(mid + 1, end, now * 2 + 1);
  segtree[now] = (segtree[now * 2] * segtree[now * 2 + 1]) % MOD;
}

void update(int start, int end, int idx, long long val, int now) {
  if (start == end) {
    arr[idx] = val;
    segtree[now] = val;
    // cout << "'" << val << "'" << "\n";
    return;
  }

  int mid = (start + end) / 2;
  if (idx <= mid)
    update(start, mid, idx, val, now * 2);
  else
    update(mid + 1, end, idx, val, now * 2 + 1);
  segtree[now] = (segtree[now * 2] * segtree[now * 2 + 1]) % MOD;
}

long long query(int start, int end, int l, int r, int now) {
  //   cout << start << " " << end << "\n";
  if (r < start || end < l) return 1;
  if (l <= start && end <= r) return segtree[now];
  int mid = (start + end) / 2;
  return (query(start, mid, l, r, now * 2) *
          query(mid + 1, end, l, r, now * 2 + 1)) %
         MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  build(0, N - 1, 1);
  //   for (int i = 0; i < 4 * N; i++) {
  //     cout << segtree[i] << " ";
  //   }
  //   cout << "\n";
  //   for (int i = 0; i < 4 * N; i++) {
  //     cout << segtree[i] << " ";
  //   }

  for (int q = 0; q < M + K; q++) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      update(0, N - 1, b - 1, c, 1);
    } else /* a == 2 */ {
      cout << query(0, N - 1, b - 1, c - 1, 1) << "\n";
    }
    // cout << "\n";
    // for (int i = 0; i < 4 * N; i++) {
    //   cout << segtree[i] << " ";
    // }
  }

  return 0;
}

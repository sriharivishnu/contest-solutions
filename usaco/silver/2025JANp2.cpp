#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define FOR(i, L, R) for (int i = L; i < R; ++i)
typedef long long ll;

const int MAXN = 5e5 + 5;

ll arr[MAXN], pre[MAXN] = {};

void solve() {
  int n, m;
  cin >> n >> m;
  FOR(i, 0, n) {
    cin >> arr[i];
    arr[i] %= m;
  }

  sort(arr, arr + n);

  FOR(i, 0, n) pre[i + 1] = pre[i] + arr[i];
  ll l = 0, r = 0;
  ll ans = numeric_limits<ll>::max();
  FOR(i, 0, n) {
    ll x = arr[i];

    while (r < n && arr[r] - x < m + x - arr[r]) {
      ++r;
    }

    while (x - arr[l] > arr[l] - x + m) {
      ++l;
    }

    ll inside = pre[r] - pre[i] - x * (r - i) + x * (i - l) - (pre[i] - pre[l]);

    ll right = (x + m) * (n - r) - (pre[n] - pre[r]);
    ll left = pre[l] - (x - m) * l;
    ans = min(ans, inside + right + left);
  }
  cout << ans << endl;
}

int main() {
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}

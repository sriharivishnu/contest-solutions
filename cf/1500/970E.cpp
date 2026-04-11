#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define sz(x) ((int)x.size())
#define FOR(i, L, R) for (int i = L; i < R; ++i)

const int MAXN = 2e5 + 5;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int[26]> even(n + 1), odd(n + 1);

  FOR(i, 0, sz(s)) {
    FOR(j, 0, 26) {
      odd[i + 1][j] = odd[i][j];
      even[i + 1][j] = even[i][j];
    }
    if (i & 1)
      odd[i + 1][s[i] - 'a']++;
    else
      even[i + 1][s[i] - 'a']++;
  }

  int ans = MAXN;
  if (sz(s) & 1) {
    FOR(i, 0, sz(s)) {
      int evenb = 0, oddb = 0;
      FOR(j, 0, 26) {
        evenb = max(evenb, even[i][j] + odd[sz(s)][j] - odd[i + 1][j]);
        oddb = max(oddb, odd[i][j] + even[sz(s)][j] - even[i + 1][j]);
      }
      ans = min(ans, sz(s) - evenb - oddb);
    }
  } else {
    int evenb = 0, oddb = 0;
    FOR(j, 0, 26) {
      evenb = max(evenb, even[sz(s)][j]);
      oddb = max(oddb, odd[sz(s)][j]);
    }
    ans = sz(s) - evenb - oddb;
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

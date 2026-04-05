#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define pb push_back
#define fi first
#define se second
#define mt make_tuple
#define FOR(i, L, R) for (int i = L; i < R; ++i)
#define RFOR(i, L, R) for (int i = L; i >= R; --i)
#define BTWN(i, l, r) ((l) <= (i) && (i) <= (r))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;

const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

const int MAXN = 1e5 + 5;

void solve() {
  int n;
  cin >> n;

  FOR(i, 0, n) {
    string s;
    cin >> s;

    string ans;

    int cur = 0;
    FOR(j, 0, (int)s.length()) {
      if (isdigit(s[j]) || (s[j] == '-')) {
        int x = 0, neg = 1;
        if (s[j] == '-')
          neg = -1, ++j;
        while (j < (int)s.length() && isdigit(s[j]))
          x = x * 10 + (s[j++] - '0');
        cur += x * neg;
        --j;
      } else if (isupper(s[j])) {
        ans.pb(s[j]);
      }
    }
    ans.append(to_string(cur));
    cout << ans << endl;
  }
}

int main() {
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}

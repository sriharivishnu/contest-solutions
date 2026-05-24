#include <algorithm>
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

const int MAXN = 3e5 + 5;

ll arr[MAXN];

ll pref[MAXN] = {0}, pref2[MAXN] = {0}, counts[MAXN] = {0}, bsums[MAXN] = {0};

// find sum 0, b0 .. bx
ll query(ll n, ll x) {
  ll full_blocks =
      (lower_bound(counts + 1, counts + (n + 1), x) - (counts + 1));
  x -= counts[full_blocks];
  return bsums[full_blocks] + (pref2[x + full_blocks] - pref2[full_blocks]) -
         x * pref[full_blocks];
}

void solve() {
  int n;
  cin >> n;
  FOR(i, 0, n) cin >> arr[i];

  FOR(i, 0, n) {
    pref[i + 1] = pref[i] + arr[i];
    pref2[i + 1] = pref2[i] + pref[i + 1];
    counts[i + 1] = counts[i] + (n - i);
  }

  FOR(i, 0, n) {
    bsums[i + 1] = bsums[i] + (pref2[n] - pref2[i]) - (n - i) * pref[i];
  }

  int q;
  cin >> q;
  FOR(x, 0, q) {
    ll l, r;
    cin >> l >> r;

    cout << query(n, r) - query(n, l - 1) << endl;
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

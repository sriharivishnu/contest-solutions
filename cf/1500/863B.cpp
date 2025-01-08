/*
    Solution by: Srihari Vishnu
    Created: January 06 2025

    863B
*/

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
typedef vector<int> vi;
typedef tuple<int, int, int> tiii;

const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

const int MAXN = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    n *= 2;
    vi arr(n);
    FOR(i, 0, n) cin >> arr[i];

    sort(all(arr));
    int ans = 2e9;
    FOR(ig, 0, n) {
        FOR(gj, ig + 1, n) {
            int cur = 0;
            vi b;
            FOR(i, 0, n) {
                if (i != ig && i != gj) b.pb(arr[i]);
            }
            for (int i = 0; i < sz(b); i += 2) {
                cur += b[i + 1] - b[i];
            }
            ans = min(ans, cur);
        }
    }

    cout << ans << endl;
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
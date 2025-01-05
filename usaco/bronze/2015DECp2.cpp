/*
    Solution by: Srihari Vishnu
    Created: January 02 2025

    2015DECp2
*/

#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
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
    int n, m;
    cin >> n >> m;
    vector<tiii> limits;
    int cur = 1, ans = 0;
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y;
        limits.pb(mt(cur, cur + x - 1, y));
        cur += x;
    }
    cur = 1;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        for (const auto& [a, b, s] : limits) {
            if (a <= cur + x - 1 && b >= cur) {
                ans = max(ans, y - s);
            }
        }
        cur += x;
    }
    cout << ans << endl;
}

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
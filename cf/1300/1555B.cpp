/*
    Solution by: Srihari Vishnu
    Created: January 18 2025

    1555B
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
    int w, h;
    cin >> w >> h;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int pw, ph;
    cin >> pw >> ph;

    int ans = INF;

    if (x2 - x1 + pw <= w) {
        ans = min(max(0, pw - x1), max(0, pw - (w - x2)));
    }

    if (y2 - y1 + ph <= h) {
        ans = min({ans, max(0, ph - y1), max(0, ph - (h - y2))});
    }

    cout << (ans == INF ? -1 : ans) << endl;
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
/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2016JANp3
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
    map<pii, int> vis;
    int ans = 1e9, t = 0, x = 0, y = 0;
    vis[{0, 0}] = 0;
    int n;
    cin >> n;
    FOR(i, 0, n) {
        char c;
        int s;
        cin >> c >> s;
        int dx, dy;
        if (c == 'N')
            dx = 0, dy = 1;
        else if (c == 'S')
            dx = 0, dy = -1;
        else if (c == 'E')
            dx = 1, dy = 0;
        else
            dx = -1, dy = 0;

        FOR(j, 0, s) {
            x += dx;
            y += dy;
            ++t;
            auto it = vis.find({x, y});
            if (it != vis.end()) {
                ans = min(ans, t - it->second);
            }
            vis[{x, y}] = t;
        }
    }
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
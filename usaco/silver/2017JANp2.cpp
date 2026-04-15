/*
    Solution by: Srihari Vishnu
    Created: July 20 2025

    2017JANp2
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

    vi h(n + 1), p(n + 1), s(n + 1);
    FOR(i, 0, n) {
        char c;
        cin >> c;
        h[i+1] = h[i] + (c == 'H');
        p[i+1] = p[i] + (c == 'P');
        s[i+1] = s[i] + (c == 'S');
    }

    int ans = 0;
    FOR(i, 0, n) {
        int forwbest = max({h[i], p[i], s[i]});
        int backbest = max({h[n] - h[i], p[n] - p[i], s[n] - s[i]});

        ans = max({ans, backbest + forwbest});
    }

    cout << ans << endl;

}

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
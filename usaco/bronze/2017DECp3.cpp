/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2017DECp3
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

    int days[101][3] = {0};

    int b = 7, e = 7, m = 7;

    FOR(i, 0, n) {
        string s;
        int day, diff;
        cin >> day >> s >> diff;

        if (s == "Bessie")
            days[day][0] += diff;
        else if (s == "Elsie")
            days[day][1] += diff;
        else
            days[day][2] += diff;
    }

    int best = 7, ans = 0;
    FOR(i, 0, 101) {
        b += days[i][0];
        e += days[i][1];
        m += days[i][2];

        int mx = max(b, max(e, m));
        int cur = ((b == mx) << 2) | (e == mx) << 1 | (m == mx);
        ans += cur != best;
        best = cur;
    }
    cout << ans << endl;
}

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
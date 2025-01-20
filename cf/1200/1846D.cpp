/*
    Solution by: Srihari Vishnu
    Created: January 18 2025

    1846D
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

// y = b
// lastB + slope * dx = b
// dx = (b - lastB) / slope

void solve() {
    double n, d, h;
    cin >> n >> d >> h;

    double slope = ((double)h / (d / 2.0));

    double ans = 0;
    double lastb = -1;
    FOR(i, 0, n) {
        double b;
        cin >> b;
        ans += d * h / 2.0;

        if (i && lastb + h > b) {
            ans -= (d - 2.0 * ((b - lastb) / slope)) * (lastb + h - b) / 2.0;
        }
        lastb = b;
    }

    cout << setprecision(15) << ans << endl;
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
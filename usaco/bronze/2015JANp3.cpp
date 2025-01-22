/*
    Solution by: Srihari Vishnu
    Created: January 21 2025

    2015JANp3
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

/*

a0 + a1 * X^1 + a2 * X^2 = b0 + b1 * Y^1 + b2 * Y^2 = N

a2X^2 + a1X = N - a0
b2Y^2 + b1Y = N - b0

let c = b2Y^2 + b1Y - a0 + b0
a2X^2 + a1X - c = 0

X = (-a1 + sqrt(a1^2 - 4a2c)) / 2a2

*/

void solve() {
    ll a[3], b[3];
    string s;
    cin >> s;
    FOR(i, 0, 3) a[i] = s[i] - '0';
    cin >> s;
    FOR(i, 0, 3) b[i] = s[i] - '0';

    for (ll Y = 10; Y <= 15000; ++Y) {
        ld c = b[0] * Y * Y + b[1] * Y + b[2];
        ld X = (-a[1] + sqrt(a[1] * a[1] + 4 * a[0] * c)) / ((ld)2 * a[0]);
        if (X < 10 || X > 15000) continue;
        ll X_down = X;
        if (a[0] * X_down * X_down + a[1] * X_down + a[2] ==
            b[0] * Y * Y + b[1] * Y + b[2]) {
            cout << X_down << ' ' << Y << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    freopen("whatbase.in", "r", stdin);
    freopen("whatbase.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
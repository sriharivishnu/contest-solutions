/*
    Solution by: Srihari Vishnu
    Created: January 18 2025

    2018JANp1
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
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;
    if (ax2 <= bx1 || ax1 >= bx2 || ay2 <= by1 || ay1 >= by2) {
        cout << (ax2 - ax1) * (ay2 - ay1) << endl;
    } else {
        int rx1 = max(ax1, bx1), ry1 = max(ay1, by1), rx2 = min(ax2, bx2),
            ry2 = min(ay2, by2);

        if ((rx1 == ax1 && rx2 == ax2 && (ry1 == ay1 || ry2 == ay2)) ||
            ((ry1 == ay1 && ry2 == ay2 && (rx1 == ax1 || rx2 == ax2)))) {
            cout << (ax2 - ax1) * (ay2 - ay1) - (rx2 - rx1) * (ry2 - ry1)
                 << endl;
        } else {
            cout << (ax2 - ax1) * (ay2 - ay1) << endl;
        }
    }
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
/*
    Solution by: Srihari Vishnu
    Created: January 18 2025

    1216C
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

struct Rect {
    ll x1, y1, x2, y2;
    friend istream& operator>>(istream& is, Rect& rect) {
        return cin >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
    };

    inline ll area() { return (x2 - x1) * (y2 - y1); }

    Rect intersection(const Rect& other) {
        if (x1 <= other.x2 && x2 >= other.x1 && y1 <= other.y2 &&
            y2 >= other.y1) {
            return {
                max(x1, other.x1),
                max(y1, other.y1),
                min(x2, other.x2),
                min(y2, other.y2),
            };
        }
        return {INF, INF, INF, INF};
    }
};

void solve() {
    Rect white, b1, b2;
    cin >> white >> b1 >> b2;

    ll visible = white.area() - white.intersection(b1).area() -
                 white.intersection(b2).area() +
                 b1.intersection(b2).intersection(white).area();

    if (visible > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
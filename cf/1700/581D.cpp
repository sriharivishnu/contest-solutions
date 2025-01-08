/*
    Solution by: Srihari Vishnu
    Created: January 06 2025

    581D
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
    int x, y, w, h;
    char c;
    Rect(int x_, int y_, int w_, int h_, char c_)
        : x{x_}, y{y_}, w{w_}, h{h_}, c{c_} {}
};

bool intersects(const Rect& a, const Rect& b) {
    return a.x < b.x + b.w && a.x + a.w > b.x && a.y < b.y + b.h &&
           a.y + a.h > b.y;
}

void solve() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int area = x1 * y1 + x2 * y2 + x3 * y3;
    int n = sqrt(area);
    if (n * n != area) {
        cout << -1 << endl;
        return;
    }

    vector<Rect> cur;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            for (const Rect& r1 :
                 {Rect{i, j, x1, y1, 'A'}, Rect{i, j, y1, x1, 'A'}}) {
                if (i + r1.w >= n + 1 || j + r1.h >= n + 1) continue;
                cur.pb(r1);
                FOR(k, 0, n) {
                    FOR(l, 0, n) {
                        for (const Rect& r2 : {Rect{k, l, x2, y2, 'B'},
                                               Rect{k, l, y2, x2, 'B'}}) {
                            if (k + r2.w >= n + 1 || l + r2.h >= n + 1)
                                continue;
                            if (intersects(r1, r2)) continue;
                            cur.pb(r2);
                            FOR(a, 0, n) {
                                FOR(b, 0, n) {
                                    for (const Rect& r3 :
                                         {Rect{a, b, x3, y3, 'C'},
                                          Rect{a, b, y3, x3, 'C'}}) {
                                        if (a + r3.w >= n + 1 ||
                                            b + r3.h >= n + 1)
                                            continue;
                                        cur.pb(r3);
                                        if (!intersects(r1, r3) &&
                                            !intersects(r2, r3)) {
                                            goto found;
                                        }
                                        cur.pop_back();
                                    }
                                }
                            }
                            cur.pop_back();
                        }
                    }
                }

                cur.pop_back();
            }
        }
    }
    cout << "-1" << endl;
    return;
found:
    cout << n << endl;
    vector<string> ans(n, string(n, '.'));
    for (const Rect& rect : cur) {
        FOR(i, rect.x, rect.x + rect.w) {
            FOR(j, rect.y, rect.y + rect.h) { ans[i][j] = rect.c; }
        }
    }
    FOR(i, 0, n) cout << ans[i] << endl;
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
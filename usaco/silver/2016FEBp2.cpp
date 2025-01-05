/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2016FEBp2
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

    vector<pii> pts(n);

    FOR(i, 0, n) { cin >> pts[i].fi >> pts[i].se; }
    sort(all(pts));

    int M = pts.size();
    FOR(i, 1, n) {
        if (pts[i].fi != pts[i - 1].fi) {
            vector<pii> left(pts.begin(), pts.begin() + i);
            vector<pii> right(pts.begin() + i, pts.end());
            vector<int> cands;
            sort(all(left), [](auto a, auto b) { return a.second < b.second; });
            FOR(j, 1, sz(left)) {
                if (left[j].se != left[j - 1].se) cands.pb(left[j].se + 1);
            }

            sort(all(right),
                 [](auto a, auto b) { return a.second < b.second; });
            FOR(j, 1, sz(right)) {
                if (right[j].se != right[j - 1].se) cands.pb(right[j].se + 1);
            }
            sort(all(cands));

            int a = 0, b = 0;

            for (auto cand : cands) {
                while (a < sz(left) && cand > left[a].se) ++a;
                while (b < sz(right) && cand > right[b].se) ++b;
                M = min(M, max({b, sz(right) - b, a, sz(left) - a}));
            }
        }
    }
    cout << M << endl;
}

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
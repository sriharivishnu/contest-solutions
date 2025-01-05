/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2015FEBp1
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
    string s, t;
    cin >> s >> t;
    string res;
    res.reserve(s.size());
    for (char c : s) {
        res.push_back(c);
        int ok = 0;
        while (sz(res) >= sz(t) && !ok) {
            int j = 0;
            FOR(i, sz(res) - sz(t), sz(res)) {
                if (res[i] != t[j++]) {
                    ok = 1;
                    break;
                }
            }
            if (!ok) {
                FOR(i, 0, sz(t)) res.pop_back();
            }
        }
    }
    cout << res << endl;
}

int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
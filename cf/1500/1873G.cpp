/*
    Solution by: Srihari Vishnu
    Created: January 21 2025

    1873G
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
    string s;
    cin >> s;

    if (sz(s) == 1) {
        cout << 0 << endl;
        return;
    }

    int a = 0, b = 0, minA = INF, cur = 0, ans = 0;
    bool hasExtraB = 0;

    FOR(i, 0, sz(s) + 1) {
        if ((i >= sz(s)) || (i && s[i] != s[i - 1])) {
            if (s[i - 1] == 'A') {
                ++a;
                minA = min(minA, cur);
                ans += cur;
            } else {
                hasExtraB |= (cur > 1);
                ++b;
            }
            cur = 0;
        }
        ++cur;
    }

    if (a > b && !hasExtraB) {
        ans -= minA;
    }
    cout << ans << endl;
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
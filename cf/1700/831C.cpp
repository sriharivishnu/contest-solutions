/*
    Solution by: Srihari Vishnu
    Created: January 07 2025

    831C
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
4 1
-5 5 0 20
10

-5, 0, 0, 20

10

*/

void solve() {
    int k, n;
    cin >> k >> n;

    vi jury(k);

    map<int, int> gu;
    FOR(i, 0, k) cin >> jury[i];
    int g;
    FOR(i, 0, n) {
        cin >> g;
        gu[g]++;
    }

    set<int> cands;
    int cur = 0;
    FOR(i, 0, k) {
        cur += jury[i];
        cands.insert(g - cur);
    }
    int ans = 0;
    for (const auto& val : cands) {
        map<int, int> counts;
        cur = val;
        FOR(i, 0, k) {
            cur += jury[i];
            counts[cur]++;
        }
        bool ok = 1;
        for (const auto& [guess, num] : gu) {
            if (counts[guess] < num) ok = 0;
        }
        ans += ok;
    }
    cout << ans << endl;
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
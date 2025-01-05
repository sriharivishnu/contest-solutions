/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2018JANp2
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

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    int counts[1002] = {0};
    FOR(i, 0, n) {
        cin >> x[i] >> y[i];
        counts[x[i]]++;
        counts[y[i]]--;
    }
    int ans = 0;
    FOR(i, 0, n) {
        counts[x[i]]--;
        counts[y[i]]++;
        int cur = 0, c = 0;
        FOR(j, 0, 1002) {
            cur += counts[j];
            c += cur > 0;
        }
        ans = max(ans, c);
        counts[x[i]]++;
        counts[y[i]]--;
    }
    cout << ans << endl;
}

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
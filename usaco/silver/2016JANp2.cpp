/*
    Solution by: Srihari Vishnu
    Created: February 05 2025

    2016JANp2
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
    vi arr(n);
    FOR(i, 0, n) cin >> arr[i];

    map<int, int> last;
    int cur = 0, best = 0;
    last[0] = -1;
    FOR(i, 0, n) {
        cur = (cur + arr[i]) % 7;
        if (last.count(cur))
            best = max(best, i - last[cur]);
        else
            last[cur] = i;
    }
    cout << best << endl;
}

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
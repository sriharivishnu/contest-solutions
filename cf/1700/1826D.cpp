/*
    Solution by: Srihari Vishnu
    Created: July 26 2025

    1826D
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

    vi preMax(n), sufMax(n);
    preMax[0] = arr[0];
    sufMax[n - 1] = arr[n - 1] - (n - 1);

    FOR(i, 1, n) {
        preMax[i] = max(preMax[i - 1], arr[i] + i);
    }

    RFOR(i, n - 2, 0) {
        sufMax[i] = max(arr[i] - i, sufMax[i + 1]);
    }

    int ans = 0;

    FOR(i, 1, n - 1) {
        ans = max(ans, preMax[i - 1] + arr[i] + sufMax[i + 1]);
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
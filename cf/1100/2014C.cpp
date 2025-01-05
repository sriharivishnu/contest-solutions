/*
    Solution by: Srihari Vishnu
    Created: December 29 2024

    2014C
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

ll arr[MAXN];
void solve() {
    ll n;
    cin >> n;
    FOR(i, 0, n) cin >> arr[i];

    if (n <= 2) {
        cout << -1 << endl;
        return;
    }
    sort(arr, arr + n);
    ll s = 0;
    FOR(i, 0, n) s += arr[i];
    cout << max(0ll, (arr[n / 2] * n * 2 + 1) - s) << endl;  // >
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
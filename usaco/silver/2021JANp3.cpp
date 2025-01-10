/*
    Solution by: Srihari Vishnu
    Created: January 10 2025

    2021JANp3
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

    vector<vi> arr(n, vi(n));
    FOR(i, 0, n) FOR(j, 0, n) cin >> arr[i][j];

    // Try maximizing via rows
    int ans1 = 0;
    FOR(i, 0, n) {
        int a1 = 0, a2 = 0;
        for (int j = 0; j < n; j += 2) a1 += arr[i][j];
        for (int j = 1; j < n; j += 2) a2 += arr[i][j];
        ans1 += max(a1, a2);
    }

    // Try maximizing via cols
    int ans2 = 0;
    FOR(i, 0, n) {
        int a1 = 0, a2 = 0;
        for (int j = 0; j < n; j += 2) a1 += arr[j][i];
        for (int j = 1; j < n; j += 2) a2 += arr[j][i];
        ans2 += max(a1, a2);
    }

    cout << max(ans1, ans2) << endl;
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
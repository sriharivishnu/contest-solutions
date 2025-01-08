/*
    Solution by: Srihari Vishnu
    Created: January 08 2025

    1201G1
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

const int MAXN = 200001;

int arr[MAXN], maxes[MAXN] = {0};

void solve() {
    int n, q;
    cin >> n >> q;

    FOR(i, 0, n) cin >> arr[i];
    FOR(i, 0, n) maxes[arr[i]] = i;

    unordered_map<int, int> counts;
    int best = -1, start = 0, end = -1, ans = 0;

    FOR(i, 0, n) {
        if (end < i) {
            ans += (end - start + 1) - counts[best];
            best = -1;
            start = i;
            counts.clear();
        }
        counts[arr[i]]++;
        end = max(end, maxes[arr[i]]);
        if (counts[arr[i]] > counts[best]) best = arr[i];
    }
    ans += (end - start + 1) - counts[best];
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
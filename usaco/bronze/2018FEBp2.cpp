/*
    Solution by: Srihari Vishnu
    Created: January 08 2025

    2018FEBp2
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

//  1 5 6 7 8 9 10 11 15 20

void solve() {
    int n;
    cin >> n;

    vi arr(n);
    FOR(i, 0, n) cin >> arr[i];
    sort(all(arr));

    if (n <= 2) {
        cout << 1 << endl;
        return;
    }

    vi passTo(n, 0), passFrom(n, 0);
    FOR(i, 0, n) {
        if (i > 0 &&
            (i + 1 >= n || arr[i] - arr[i - 1] <= arr[i + 1] - arr[i])) {
            passTo[i] = i - 1;
            passFrom[i - 1]++;
        } else if (i + 1 < n &&
                   (i <= 0 || arr[i] - arr[i - 1] > arr[i + 1] - arr[i])) {
            passTo[i] = i + 1;
            passFrom[i + 1]++;
        }
    }
    int ans = 0;
    FOR(i, 0, n) {
        if (passFrom[i] == 0) ++ans;
        if (i < passTo[i] && passTo[passTo[i]] == i && passFrom[i] == 1 &&
            passFrom[passTo[i]] == 1)
            ++ans;
    }

    cout << ans << endl;
}

int main() {
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
/*
    Solution by: Srihari Vishnu
    Created: July 22 2025

    Digit Queries
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
    long k;
    cin >> k;

    long x = 1, pow10 = 1, num = 0;

    while (num + 9 * pow10 * x < k) {
        num += 9 * pow10 * x;
        ++x;
        pow10 *= 10;
    }
    k -= num;
    if (pow10 == 1) {
        cout << k << endl;
    } else {
        long i = pow10 + (k - 1) / x, j = x - ((k - 1) % x) - 1;
        while (j) {
            i /= 10;
            --j;
        }
        cout << i % 10 << endl;
    }
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
/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2017FEBp2
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
    int ans = 0;
    for (char c = 'A'; c <= 'Z'; ++c) {
        for (char d = c + 1; d <= 'Z'; ++d) {
            int a1 = s.find_first_of(c), a2 = s.find_last_of(c);
            int b1 = s.find_first_of(d), b2 = s.find_last_of(d);
            if (a1 < b1 && b1 < a2 && a2 < b2)
                ++ans;
            else if (b1 < a1 && a1 < b2 && b2 < a2)
                ++ans;
        }
    }

    cout << ans << endl;
}

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
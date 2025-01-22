/*
    Solution by: Srihari Vishnu
    Created: January 20 2025

    1624D
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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vi cnt(26, 0);
    FOR(i, 0, n) cnt[s[i] - 'a']++;

    int numTwos = 0, numOnes = 0;
    FOR(i, 0, 26) {
        if (cnt[i] & 1) {
            numOnes++;
        }
        numTwos += cnt[i] / 2;
    }

    int shortest = numTwos / k * 2;
    numOnes += (numTwos % k) * 2;
    if (numOnes >= k) shortest++;
    cout << shortest << endl;
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
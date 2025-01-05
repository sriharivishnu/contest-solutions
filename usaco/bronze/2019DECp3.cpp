/*
    Solution by: Srihari Vishnu
    Created: January 04 2025

    2019DECp3
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

    vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                           "Bella",  "Blue",      "Betsy",   "Sue"};
    sort(all(cows));

    vector<pair<string, string>> constraints;
    FOR(i, 0, n) {
        string s1, s2, tmp;
        cin >> s1;
        FOR(j, 0, 4) cin >> tmp;
        cin >> s2;
        constraints.pb({s1, s2});
    }

    do {
        bool ok = 1;
        FOR(i, 0, n) {
            int idx1 = find(all(cows), constraints[i].first) - cows.begin();
            int idx2 = find(all(cows), constraints[i].second) - cows.begin();
            if (abs(idx1 - idx2) != 1) {
                ok = 0;
                break;
            }
        }
        if (ok) break;
    } while (next_permutation(all(cows)));

    FOR(i, 0, sz(cows)) { cout << cows[i] << endl; }
}

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
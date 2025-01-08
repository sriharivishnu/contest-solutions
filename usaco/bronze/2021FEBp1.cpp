/*
    Solution by: Srihari Vishnu
    Created: January 07 2025

    2021FEBp1
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
    vector<string> arr = {"Ox",      "Tiger", "Rabbit", "Dragon",
                          "Snake",   "Horse", "Goat",   "Monkey",
                          "Rooster", "Dog",   "Pig",    "Rat"};
    map<string, int> m;
    FOR(i, 0, sz(arr)) m[arr[i]] = i;

    int n;
    cin >> n;

    map<string, int> m2, ym;
    FOR(i, 0, n) {
        string name1, s, dir, year, name2;
        cin >> name1 >> s >> s >> dir >> year >> s >> s >> name2;
        int idx1 = m[year], idx2 = ym[name2], diff;
        diff = idx1 - idx2;
        if (dir == "next" && diff <= 0) {
            diff += 12;
        } else if (dir == "previous" && diff >= 0) {
            diff -= 12;
        }
        m2[name1] = m2[name2] + diff;
        ym[name1] = m[year];
    }
    cout << abs(m2["Elsie"]) << endl;
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
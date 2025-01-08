/*
    Solution by: Srihari Vishnu
    Created: January 07 2025

    2017JANp1
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

    string cows[] = {"Bessie",    "Elsie",  "Daisy",    "Gertie",
                     "Annabelle", "Maggie", "Henrietta"};
    map<string, int> co;
    for (const auto& x : cows) co[x] = 0;

    FOR(i, 0, n) {
        string s;
        int c;
        cin >> s >> c;
        co[s] += c;
    }

    int mi = 2e9, snd = 2e9;
    string s1, s2;
    for (const auto& [name, val] : co) {
        if (val < mi) {
            snd = mi;
            mi = val;
        } else if (val != mi && val < snd) {
            snd = val;
        }
    }

    string best;
    int cnt = 0;
    for (const auto& [name, val] : co) {
        if (val == snd) {
            best = name;
            cnt++;
        }
    }

    if (cnt == 1)
        cout << best << endl;
    else
        cout << "Tie" << endl;
}

int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
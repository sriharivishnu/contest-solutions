/*
    Solution by: Srihari Vishnu
    Created: January 18 2025

    2018OPENp3
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
    string a, b;
    cin >> a >> b;

    map<string, string> par;
    FOR(i, 0, n) {
        string u, v;
        cin >> u >> v;
        par[v] = u;
    }

    vector<string> ans1, ans2;

    string cur = a;
    while (cur != "") {
        ans1.pb(cur);
        cur = par[cur];
    }
    cur = b;
    while (cur != "") {
        ans2.pb(cur);
        cur = par[cur];
    }

    if (sz(ans1) > sz(ans2)) swap(ans1, ans2), swap(a, b);
    // ans1 <= ans2
    reverse(all(ans1));
    reverse(all(ans2));
    int x = -1;
    FOR(i, 0, sz(ans2)) {
        if (ans1[i] == ans2[i]) x = i;
    }
    if (x == -1) {
        cout << "NOT RELATED" << endl;
    } else if (x == sz(ans1) - 1) {
        cout << a << " is the ";
        FOR(i, 0, (sz(ans2) - sz(ans1)) - 2) cout << "great-";
        if ((sz(ans2) - sz(ans1) > 1)) cout << "grand-";
        cout << "mother of " << b << endl;
    } else if (x == sz(ans1) - 2) {
        if (sz(ans1) == sz(ans2)) {
            cout << "SIBLINGS" << endl;
            return;
        }
        cout << a << " is the ";
        FOR(i, 0, (sz(ans2) - sz(ans1)) - 1) cout << "great-";
        cout << "aunt of " << b << endl;
    } else {
        cout << "COUSINS" << endl;
    }
}

int main() {
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
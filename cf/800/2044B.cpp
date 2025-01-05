#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    string s;
    cin >> s;
    reverse(all(s));
    for (int i = 0; i < sz(s); ++i)
        if (s[i] == 'p') s[i] = 'r';
    for (int i = 0; i < sz(s); ++i)
        if (s[i] == 'q') s[i] = 'p';
    for (int i = 0; i < sz(s); ++i)
        if (s[i] == 'r') s[i] = 'q';
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
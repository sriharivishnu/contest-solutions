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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int arr[MAX_N], lookup[27];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (s.size() != n) {
            cout << "NO" << endl;
            continue;
        }
        const int inf = 1e9 + 10;
        for (int i = 0; i < 27; ++i) lookup[i] = inf;
        bool valid = true;
        set<int> seen;
        for (int j = 0; j < s.size(); ++j) {
            if (lookup[s[j] - 'a'] != inf && lookup[s[j] - 'a'] != arr[j] ||
                lookup[s[j] - 'a'] == inf && seen.count(arr[j])) {
                valid = false;
                break;
            }

            lookup[s[j] - 'a'] = arr[j];
            seen.insert(arr[j]);
        }

        if (valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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
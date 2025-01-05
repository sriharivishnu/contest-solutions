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

int arr[MAX_N];
void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n, std::greater<int>());

    ll a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1)
            b += ((arr[i] & 1) ? arr[i] : 0);
        else
            a += ((arr[i] & 1) ? 0 : arr[i]);
    }

    if (a > b) {
        cout << "Alice" << endl;
    } else if (a < b) {
        cout << "Bob" << endl;
    } else {
        cout << "Tie" << endl;
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
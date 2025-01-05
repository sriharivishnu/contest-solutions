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

bool solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> arr[i];

    bool decreasing = true;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1])
            decreasing = false;
        else if (arr[i] < arr[i - 1] && !decreasing)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
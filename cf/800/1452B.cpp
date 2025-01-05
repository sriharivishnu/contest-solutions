#include <assert.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<std::pair<int, int>> vii;
typedef vector<vector<int>> vvi;

// IMPLEMENTATION
void solve() {
    int n;
    cin >> n;
    ll mx = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        mx = max(mx, x);
        s += x;
    }

    ll b = max(s, mx * (n - 1));
    cout << ((b + (n - 1) - 1) / (n - 1) * (n - 1)) - s << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) solve();
}

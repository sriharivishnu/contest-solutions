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

int a[101];

// IMPLEMENTATION
void solve() {
    int n, c = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c += a[i];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c -= x;
        ans += a[i] ^ x;
    }
    cout << min(ans, 1 + abs(c)) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

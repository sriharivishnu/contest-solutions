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

int solve() {
    int n, prev = 0, ans = 0;
    bool cons = false;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ans += (x != prev);
        cons = cons || (x == prev);
        if (prev + 1 < x) {
            ans += cons;
            cons = false;
        }
        prev = x;
    }
    return ans + cons;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}

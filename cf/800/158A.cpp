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

const int MAX_N = 10e5 + 1;

// IMPLEMENTATION
int solve() {
    int n, k, kth, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> kth;
        if (kth) ++ans;
    }
    if (!kth) return ans;
    for (int i = k; i < n; ++i) {
        int x;
        cin >> x;
        if (x == kth) ++ans;
    }
    return ans;
}

int main() { cout << solve() << endl; }

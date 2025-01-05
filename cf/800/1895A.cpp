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
    int x, y, k;
    cin >> x >> y >> k;

    if (x < y)
        return 2 * y - min(y, x + k);
    else
        return x;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}

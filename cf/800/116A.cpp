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
    int n, cur = 0, ans = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cur -= a;
        cur += b;
        ans = max(cur, ans);
    }
    cout << ans << endl;
}

int main() { solve(); }

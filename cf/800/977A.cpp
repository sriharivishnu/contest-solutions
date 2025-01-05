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
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
        if (n % 10)
            n--;
        else
            n /= 10;

    cout << n << endl;
}
int main() { solve(); }
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
void solve() {
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s[0] == '+' || s[s.size() - 1] == '+') {
            ++x;
        } else {
            --x;
        }
    }
    cout << x << endl;
}

int main() { solve(); }

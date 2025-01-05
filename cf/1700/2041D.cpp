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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> maze(n, vector<char>(m));

    pii start, end;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') start = {i, j};
            if (maze[i][j] == 'T') end = {i, j};
        }
    }

    vector<vector<vector<bool>>> visited(
        n, vector<vector<bool>>(m, vector<bool>(16, false)));
    queue<tuple<int, int, char, char>> que;
    que.push({start.first, start.second, 0, 0});

    const pii dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dist = 0;
    while (!que.empty()) {
        int queLen = que.size();
        while (queLen--) {
            auto [i, j, lastDir, num] = que.front();
            que.pop();

            if (end.first == i && end.second == j) return dist;

            for (int dir = 0; dir < 4; ++dir) {
                auto [di, dj] = dirs[dir];
                if (0 <= i + di && i + di < n && 0 <= j + dj && j + dj < m &&
                    maze[i + di][j + dj] != '#' &&
                    (lastDir != dir || lastDir == dir && num < 3)) {
                    int newNum = lastDir == dir ? num + 1 : 1;
                    if (!visited[i + di][j + dj][dir * 4 + newNum - 1]) {
                        visited[i + di][j + dj][dir * 4 + newNum - 1] = true;
                        que.push({i + di, j + dj, dir, newNum});
                    }
                }
            }
        }
        ++dist;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << solve() << endl;
    }
}
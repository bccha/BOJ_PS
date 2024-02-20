
#include <bits/stdc++.h>

#define ENDL    "\n"
#define Endl    ENDL
#define el      ENDL
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int W, H;
int B[1001][1001];
int visited[1001][1001];

int dyx[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},
    // {-1, -1}, {-1, 1}, {1, -1}, {1, 1},
};

vector<pair<int, int>> seed;
int target;

void bfs() {
    deque<pair<pair<int, int>, int>> q;
    int cnt = 0;
    for (auto v : seed) {
        q.push_back({v, 0});
        visited[v.first][v.second] = 1;
    }

    int ret = 0;
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cur = q.front().second;
        q.pop_front();
        ++cnt;
        ret = max(ret, cur);
        for (int i = 0; i != 4; ++i) {
            int ny = y + dyx[i][0];
            int nx = x + dyx[i][1];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
                continue;
            }
            if (B[ny][nx] != 0) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            q.push_back({{ny, nx}, cur + 1});
            visited[ny][nx] = 1;
        }
    }
    if (cnt == target) {
        cout << ret << el;
    } else {
        cout << -1 << el;
    }
}

int main() {
    fastio

    cin >> W >> H;
    for (int i = 0; i != H; ++i) {
        for (int j = 0; j != W; ++j) {
            cin >> B[i][j];
            if (B[i][j] == 1) {
                seed.push_back({i, j});
            }
            if (B[i][j] != -1) {
                ++target;
            }
        }
    }
    bfs();

    
    return 0;
}

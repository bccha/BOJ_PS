#include <bits/stdc++.h>

#define ENDL    "\n"
#define Endl    ENDL
#define el      ENDL
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint; // 0~약40억, int는 -20억~20억
typedef long long llong;
typedef unsigned long long ullong;

// 입력 / 출력
#if 0
void strToken(const string &in, vector<string> &ret) {
    stringstream ss(in);
    string t;

    while (ss >> t)
    {
        ret.push_back(t);
    }
}
#endif

#if 0
void setPrecision(int p) {
    cout << fixed;
    cout.precision(p);
}
#endif

#if 0
// 수학
// 최대공약수
inline int getGCD(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
     while (true) {
        int remain = a % b;
        if (remain == 0) {
            break;
        }
        a = b;
        b = remain;
    }
    return b;
}

// 최소공배수
inline int getLCM(int a, int b) {
    int gcd = getGCD(a, b);
    return a * b / gcd;
}

// 에라스토테네스의 체
// 반드시 return 받은 pointer를 delete 해주어야 한다.
//    auto *ps = getSieve<1000000>();
//    auto &sieve = *ps;
//    delete ps;
template<int maxVal>
inline bitset<maxVal + 1>* getSieve() {
    auto *ret = new bitset<maxVal + 1>();
    auto &r = *ret;

    r[0] = true;
    r[1] = true;

    for (int i = 2; i * i <= maxVal; ++i) {
        if (r[i]) {
            continue;
        }
        int j = i * i;
        while (j <= maxVal) {
            r[j] = true;
            j += i;
        }
    }

    return ret;
}

template <typename T>
inline T factorial(T n) {
    T ret = T(1);
    if (n <= ret) {
        return ret;
    }
    
    while (n) {
        ret *= n;
        --n;
    }

    return ret;
}

template <typename T>
inline T permutation(T n, T k) {
    if (k > n) {
        return T(0);
    }

    T ret = T(1);
    for (T i = T(0); i != k; ++i) {
        ret *= n;
        --n;
    }
    return ret;
}

template <typename T>
inline T combination(T n, T k) {
    return permutation(n, k) / factorial(k);
}

bool next_permutation(vector<int> &l) {
    int R = l.size();
    int i = R - 2;
    while (i >= 0 && l[i] >= l[i + 1]) {
        --i;
    }
    if (i < 0) {
        return false;
    }
    int target = -1;
    for (int j = R - 1; j > i; --j) {
        if (l[j] > l[i]) {
            if (target == -1 || l[target] > l[j]) {
                target = j;
            }
        }
    }
    iter_swap(l.begin() + i, l.begin() + target);
    sort(l.begin() + i + 1, l.end());
    return true;
}
#endif

#if 0
// string 반복  예) 'a' * 5
// string s = string(5, 'a');

// int to string
// to_string(5);

// string to int
// stoi(s);
#endif
int l;
int fy, fx;
int ty, tx;
int visited[301][301];

int dyx[8][2] = {
    {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
    {1, -2}, {2, -1}, {2, 1}, {1, 2},
};

vector<pair<int, int>> seed;
int target;

void bfs() {
    deque<pair<int, int>> q;
    q.push_back({fy, fx});
    visited[fy][fx] = 1;

    int ret = 0;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int cur = visited[y][x];
        q.pop_front();
        if (y == ty && x == tx) {
            cout << cur - 1 << endl;
            return;
        }
        for (int i = 0; i != 8; ++i) {
            int ny = y + dyx[i][0];
            int nx = x + dyx[i][1];
            if (ny < 0 || ny >= l || nx < 0 || nx >= l) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            q.push_back({ny, nx});
            visited[ny][nx] = cur + 1;
        }
    }
}

void solve() {
    cin >> l;
    cin >> fy >> fx;
    cin >> ty >> tx;
    memset(visited, 0, sizeof(visited));
    bfs();
}

int main() {
    fastio

    int numTC;
    cin >> numTC;
    while (numTC--) {
        solve();
    }
    
    return 0;
}

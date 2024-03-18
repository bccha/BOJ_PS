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

#define FOR(I, C) for (int I = 0; I != C; ++I)
#define FOR_1(I, C) for (int I = 1; I <= C; ++I)

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

#if 0
// basic code of DFS, BFS
int N, M, V;
vector<int> A[1001];
int visited[1001];

void dfs(int f) {
    cout << f << " ";
    for (auto n : A[f]) {
        if (visited[n]) {
            continue;
        }
        visited[n] = 1;
        dfs(n);
    }
}

void bfs(int f) {
    deque<int> q;
    visited[f] = 1;
    q.push_back(f);


    while (!q.empty()) {
        int cur = q.front();
        cout << cur << " ";
        q.pop_front();
        for (auto n : A[cur]) {
            if (visited[n]) {
                continue;
            }
            visited[n] = 1;
            q.push_back(n);
        }
    }
    cout << el;
}
#endif

#if 0
template<typename T, size_t size>
struct BinaryTreeNode {
    T v;
    int y;
    int x;
    bool root;
    BinaryTreeNode *l;
    BinaryTreeNode *r;
    static BinaryTreeNode<T, size>* cache[size + 1];

    BinaryTreeNode(T v) : v(v), l(nullptr), r(nullptr), y(0), x(0), root(true) {
        cache[v] = this;
    }

    ~BinaryTreeNode() {
        if (l) {
            delete l;
        }
        if (r) {
            delete r;
        }
    }

    BinaryTreeNode* addLeft(T v) {
        BinaryTreeNode *l = cache[v];
        if (l == nullptr) {
            l = new BinaryTreeNode(v);
        }
        l->root = false;
        this->l = l;
        return l;
    }

    BinaryTreeNode* addRight(T v) {
        BinaryTreeNode *r = cache[v];
        if (r == nullptr) {
            r = new BinaryTreeNode(v);
        }
        r->root = false;
        this->r = r;
        return r;
    }

    int calc(int h) {
        static int xx = 0;
        if (h == 0) {
            xx = 1;
        }
        y = h;
        int s = 0;
        if (l) {
            s = l->calc(h + 1);
        }
        x = xx++;

        if (r) {
            s += r->calc(h + 1);
        }
        return s + 1;
    }

#ifdef TREE_TRAVERSE
    void preorder() {
        cout << v;
        if (l) {
            l->preorder();
        }
        if (r) {
            r->preorder();
        }
    }
    void inorder() {
        if (l) {
            l->inorder();
        }
        cout << v;
        if (r) {
            r->inorder();
        }
    }
    void postorder() {
        if (l) {
            l->postorder();
        }
        if (r) {
            r->postorder();
        }
        cout << v;
    }
#endif

};

template<typename T, size_t size>
BinaryTreeNode<T, size>* BinaryTreeNode<T, size>::cache[size + 1];

#endif

#define fi first
#define se second
#define Pii pair<int, int>

int N, M, K;
string B[1001];

int visited[2][11][1001][1001];

int dyx[5][2] = {
    {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

void bfs() {
    deque<pair<Pii, Pii>> q;
    visited[0][0][0][0] = 1;
    q.push_back({{0, 0}, {0, 0}});

    while (!q.empty()) {
        auto cur = q.front();
        if (cur.fi.fi== N - 1 && cur.fi.se== M - 1) {
            cout << visited[cur.se.fi][cur.se.se][cur.fi.fi][cur.fi.se] << endl;
            return;
        }
        q.pop_front();
        FOR (i, 5) {
            int ny = cur.fi.fi + dyx[i][0];
            int nx = cur.fi.se + dyx[i][1];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
                continue;
            }

            int day = 1 - cur.se.fi;
            int k = cur.se.se;
            if (visited[day][k][ny][nx] == 0 && ((ny == cur.fi.fi && nx == cur.fi.se && B[ny][nx] == '1') || B[ny][nx] != '1')) {
                visited[day][k][ny][nx] = visited[cur.se.fi][cur.se.se][cur.fi.fi][cur.fi.se] + 1;
                q.push_back({{ny, nx}, {day, k}});
            }

            if (cur.se.fi == 0 && k < K && visited[day][k + 1][ny][nx] == 0 && B[ny][nx] == '1') {
                visited[day][k + 1][ny][nx] = visited[cur.se.fi][cur.se.se][cur.fi.fi][cur.fi.se] + 1;
                q.push_back({{ny, nx}, {day, k + 1}});
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    fastio

    cin >> N >> M >> K;
    FOR (i, N) {
        cin >> B[i];
    }

    bfs();

    return 0;
}

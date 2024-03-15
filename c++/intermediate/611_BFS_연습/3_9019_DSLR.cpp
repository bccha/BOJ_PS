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

int D(int v) {
    return (v * 2) % 10000;
}

int S(int v) {
    int ret = v - 1;
    return ret < 0 ? 9999 : ret;
}

int L(int v) {
    int m = v / 1000;
    return (v - (m * 1000)) * 10 + m;
}

int R(int v) {
    int l = v % 10;
    return (v / 10) + l * 1000;
}

int visited[10000];
char history[10000];

typedef int (*Func)(int v);

Func fn[4] = {D, S, L, R};
char fn_c[4] = {'D', 'S', 'L', 'R'};

void bfs(int f, int t) {
    visited[f] = true;
    deque<int> q;
    q.push_back(f);

    while (!q.empty()) {
        int cur = q.front();
        if (cur == t) {
            break;
        }
        q.pop_front();
        for (int i = 0; i != 4; ++i) {
            int n = fn[i](cur);
            if (visited[n] != -1) {
                continue;
            }
            visited[n] = cur;
            history[n] = fn_c[i];
            q.push_back(n);
        }
    }
    vector<char> h;
    int back = t;
    while (back != f) {
        h.push_back(history[back]);
        back = visited[back];
    }
    for (auto i = h.rbegin(); i != h.rend(); ++i) {
        cout << *i;
    }
    cout << endl;
}

int main() {
    fastio

    int numTC;
    cin >> numTC;
    cin.ignore();

    while (numTC--) {
        memset(visited, -1, sizeof(visited));
        memset(history, 0, sizeof(history));
        int f, t;
        cin >> f >> t;
        bfs(f, t);
    }

    return 0;
}

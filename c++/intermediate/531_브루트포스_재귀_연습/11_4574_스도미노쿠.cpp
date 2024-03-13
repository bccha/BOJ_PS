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

int N;
int B[10][10];
int D[10][10];

void findCandi(int y, int x, bool *candi) {
    for (int i = 0; i != 9; ++i) {
        candi[B[i][x]] = false;
    }

    for (int i = 0; i != 9; ++i) {
        candi[B[y][i]] = false;
    }

    int sy = y / 3 * 3;
    int sx = x / 3 * 3;

    for (int i = sy; i != sy + 3; ++i) {
        for (int j = sx; j != sx + 3; ++j) {
            candi[B[i][j]] = false;
        }
    }
}

bool solve(int y, int x) {
    if (y == 9) {
        return true;
    }
    int nx = x + 1;
    int ny = y;

    if (nx == 9) {
        nx = 0;
        ny += 1;
    }

/*
    cout << x << " " << y << endl;
    cout << nx << " " << ny << endl;
    for (int i = 0; i != 9; ++i) {
        for (int j = 0; j != 9; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    string l;
    //cin >> l;
    */


    if (B[y][x] != 0) {
        return solve(ny, nx);
    }

    bool candi[10] = {false, true, true, true, true, true, true, true, true, true};
    findCandi(y, x, candi);

    for (int i = 1; i <= 9; ++i) {
        if (!candi[i]) {
            continue;
        }
        if (y != 8 && B[y + 1][x] == 0) {
            bool c[10] = {false, true, true, true, true, true, true, true, true, true};
            c[i] = false;
            findCandi(y + 1, x, c);
            for (int j = 1; j <= 9; ++j) {
                if (!c[j]) {
                    continue;
                }
                if (D[i][j]) {
                    continue;
                }
                D[i][j] = D[j][i] = 1;
                B[y][x] = i;
                B[y + 1][x] = j;
                if (solve(ny, nx)) {
                    return true;
                }
                D[i][j] = D[j][i] = 0;
                B[y][x] = 0;
                B[y + 1][x] = 0;
            }
        }
        if (x != 8 && B[y][x + 1] == 0) {
            bool c[10] = {false, true, true, true, true, true, true, true, true, true};
            c[i] = false;
            findCandi(y, x + 1, c);
            for (int j = 1; j <= 9; ++j) {
                if (!c[j]) {
                    continue;
                }
                if (D[i][j]) {
                    continue;
                }
                D[i][j] = D[j][i] = 1;
                B[y][x] = i;
                B[y][x + 1] = j;
                if (solve(ny, nx)) {
                    return true;
                }
                D[i][j] = D[j][i] = 0;
                B[y][x] = 0;
                B[y][x + 1] = 0;
            }
        }
    }

    return false;
}

int main() {
    fastio

    int k = 0;
    while (true) {
        memset(B, 0, sizeof(B));
        memset(D, 0, sizeof(D));

        cin >> N;
        if (N == 0) {
            break;
        }
        for (int i = 0; i != N; ++i) {
            int U, V;
            string LU, LV;
            cin >> U >> LU >> V >> LV;
            pair<int, int> lU = {int(LU[0] - 'A'), int(LU[1] - '1')};
            pair<int, int> lV = {int(LV[0] - 'A'), int(LV[1] - '1')};

            B[lU.first][lU.second] = U;
            B[lV.first][lV.second] = V;

            D[U][V] = D[V][U] = 1;
        }

        for (int i = 0; i != 9; ++i) {
            string L;
            cin >> L;
            pair<int, int> l = {int(L[0] - 'A'), int(L[1] - '1')};

            B[l.first][l.second] = i + 1;
        }
#if 0
        for (int i = 0; i != 9; ++i) {
            for (int j = 0; j != 9; ++j) {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 1; i <= 9; ++i) {
            for (int j = 1; j <= 9; ++j) {
                cout << D[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
#endif
        if (!solve(0, 0)) {
            continue;
        }

        cout << "Puzzle " << ++k << el;

        for (int i = 0; i != 9; ++i) {
            for (int j = 0; j != 9; ++j) {
                cout << B[i][j];
            }
            cout << el;
        }
    }

    return 0;
}

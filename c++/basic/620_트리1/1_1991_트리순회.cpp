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

template<typename T>
struct BinaryTreeNode {
    T v;
    BinaryTreeNode *l;
    BinaryTreeNode *r;

    BinaryTreeNode(T v) : v(v), l(nullptr), r(nullptr) {
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
        BinaryTreeNode *l = new BinaryTreeNode(v);
        this->l = l;
        return l;
    }

    BinaryTreeNode* addRight(T v) {
        BinaryTreeNode *r = new BinaryTreeNode(v);
        this->r = r;
        return r;
    }

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

};

BinaryTreeNode<char>* cache[26];

int main() {
    fastio

    BinaryTreeNode<char> *root = new BinaryTreeNode<char>('A');
    cache[0] = root;

    int N;
    cin >> N;
    for (int i = 0; i != N; ++i) {
        char p, l, r;
        cin >> p >> l >> r;

        BinaryTreeNode<char> *cur = cache[p - 'A'];
        if (l != '.') {
            BinaryTreeNode<char> *p = cur->addLeft(l);
            cache[l - 'A'] = p;
        }
        if (r != '.') {
            BinaryTreeNode<char> *p = cur->addRight(r);
            cache[r - 'A'] = p;
        }
    }

    root->preorder();
    cout << endl;
    root->inorder();
    cout << endl;
    root->postorder();
    cout << endl;

    return 0;
}

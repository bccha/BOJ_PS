#include <bits/stdc++.h>

#define ENDL "\n"
#define Endl "\n"
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
#endif

int N;
char B[51][51];

bool change(int i1, int j1, int i2, int j2) {
    if(B[i1][j1] == B[i2][j2]) {
        return false;
    }
    swap(B[i1][j1], B[i2][j2]);
    return true;
}

void print() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << B[i][j] << " ";
        }
        cout << Endl;
    }
    cout << Endl;
}

int count() {
    int ret = 0;
    for (int i = 0; i != N; ++i) {
        int c = 0, d = 0;
        char pc = 0, pd = 0;
        for (int j = 0; j != N; ++j) {
            if (B[i][j] == pc) {
                ++c;
            } else {
                ret = max(ret, c);
                c = 1;
                pc = B[i][j];
            }

            if (B[j][i] == pd) {
                ++d;
            } else {
                ret = max(ret, d);
                d = 1;
                pd = B[j][i];
            }
        }
        ret = max(ret, max(c, d));
    }
    return ret;
}

int main() {
    fastio

    cin >> N;
    for (int i = 0; i != N; ++i) {
        cin >> B[i];
    }
    
    int ret = count();

    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != N; ++j) {
            if (j != N - 1) {
                if (change(i, j, i, j + 1)) {
                    ret = max(ret, count());
                    change(i, j, i, j + 1);
                }
            }
            if (i != N - 1) {
                if (change(i, j, i + 1, j)) {
                    ret = max(ret, count());
                    change(i, j, i + 1, j);
                }
            }
        }
    }

    cout << ret << Endl;

    return 0;
}

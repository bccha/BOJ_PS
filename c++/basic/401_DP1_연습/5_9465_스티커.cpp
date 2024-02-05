#include <bits/stdc++.h>

#define ENDL "\n"
#define Endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

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

int n;
int N[2][100'001];
int memo[3][100'001];

int main() {
    fastio

    int numTC;
    cin >> numTC;

    while (numTC--) {
        cin >> n;
        for (int k = 0; k != 2; ++k) {
            for (int i = 1; i <= n; ++i) {
                cin >> N[k][i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            memo[0][i] = max(max(memo[0][i - 1], memo[1][i - 1]), memo[2][i - 1]);
            memo[1][i] = max(memo[0][i - 1], memo[2][i - 1]) + N[0][i];
            memo[2][i] = max(memo[0][i - 1], memo[1][i - 1]) + N[1][i];
        }

        cout << max(max(memo[0][n], memo[1][n]), memo[2][n]) << Endl;
    }

    return 0;
}

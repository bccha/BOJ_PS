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
int A[1001] = {0, };
int memo[1001] = {0, };

#if 0
int solve(int cur, int prev) {
    if (cur == N + 1) {
        return 0;
    }

    if (memo[cur][prev] != -1) {
        return memo[cur][prev];
    }

    int ret1 = 0, ret2 = 0;

    if (A[cur] > A[prev]) {
        ret1 = solve(cur + 1, cur) + 1;
    }
    ret2 = solve(cur + 1, prev);
    ret2 = max(ret1, ret2);
    memo[cur][prev] = ret2;
    return ret2;
}
#endif

int main() {
    fastio

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j]) {
                memo[i] = max(memo[j] + 1, memo[i]);
            }
        }
        ret = max(ret, memo[i]);
    }

    cout << ret << Endl;

    return 0;
}


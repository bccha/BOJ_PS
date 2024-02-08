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
int C[1001][3];
int memo[1001][3];

int main() {
    fastio

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> C[i][0] >> C[i][1] >> C[i][2];
    }

    int first[3];
    memcpy(first, C[1], sizeof(first));

    int ret = 987654321;

    for (int i = 0; i != 3; ++i) {
        for (int j = 0; j != 3; ++j) {
            C[1][j] = 987654321;
        }
        C[1][i] = first[i];

        for (int j = 1; j <= N; ++j) {
            memo[j][0] = min(memo[j-1][1], memo[j-1][2]) + C[j][0];
            memo[j][1] = min(memo[j-1][0], memo[j-1][2]) + C[j][1];
            memo[j][2] = min(memo[j-1][1], memo[j-1][0]) + C[j][2];
        }

        for (int j = 0; j != 3; ++j) {
            if (i == j) {
                continue;
            }
            ret = min(ret, memo[N][j]);
        }
    }

    cout << ret << Endl;

    return 0;
}

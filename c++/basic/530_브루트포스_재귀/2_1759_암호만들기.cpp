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

void permutation() {
    int R;
    cin >> R;

    vector<int> l(R);
    
    for (int i = 1; i <= R; ++i) {
        l[i - 1] = i;
    }

    int cnt = 0;
    do {
        for (auto v : l) {
            cout << v << " ";
        }
        cout << Endl;
        ++cnt;
    } while (next_permutation(l));
    cout << cnt << Endl;

}

inline bool vowel(char a) {
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

void combination() {
    int L, C;
    cin >> L >> C;

    vector<char> ch(C);
    vector<int> l(C);
    vector<int> vo(C);

    for (int i = 0; i != C; ++i) {
        cin >> ch[i];
    }

    sort(ch.begin(), ch.end());

    for (int i = 0; i != C; ++i) {
        vo[i] += vowel(ch[i]) ? 1 : 0;
    }

    for (int i = L; i != C; ++i) {
        l[i] = 1;
    }

    int cnt = 0;
    do {
        string ret = "";
        int numV = 0;
        for (int i = 0; i != C; ++i) {
            if (l[i] == 0) {
                ret += ch[i];
                numV += vo[i];
            }
        }
        if (numV >= 1 && ret.length() - numV >= 2) {
            cout << ret << Endl;
        }
    } while (next_permutation(l));
}

int main() {
    fastio

    combination();

    return 0;
}

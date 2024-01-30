#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

// 입력 / 출력

void strToken(const string &in, vector<string> &ret) {
    stringstream ss(in);
    string t;

    while (ss >> t)
    {
        ret.push_back(t);
    }
}

void setPrecision(int p) {
    cout << fixed;
    cout.precision(p);
}

// 수학

// 최소공배수
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

// 최대공약수
inline int getLCM(int a, int b) {
    int gcd = getGCD(a, b);
    return a * b / gcd;
}

bool *getSieve(int maxVal) {
    int size = sizeof(bool) * (maxVal + 1);
    bool *ret = (bool *) malloc(size);
    fill(ret, ret + (maxVal + 1), true);

    ret[0] = false;
    ret[1] = false;

    for (int i = 2; i != maxVal; ++i) {
        if (!ret[i]) {
            continue;
        }
        int j = 2;
        while (i * j <= maxVal) {
            ret[i * j] = false;
            ++j;
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    cin >> numTC;
    cin.ignore();

    bool *sieve = getSieve(1000);

    int ret = 0;

    while (numTC--) {
        int v;
        cin >> v;

        if (sieve[v]) {
            ++ret;
        }
    }

    cout << ret << endl;

    free(sieve);

    return 0;
}

#include <bits/stdc++.h>

#define ENDL "\n"
#define Endl "\n"

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


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    cin >> numTC;

    while (numTC--) {
        int a, b;
        cin >> a >> b;
        cout << getLCM(a, b) << Endl;
    }

    return 0;
}

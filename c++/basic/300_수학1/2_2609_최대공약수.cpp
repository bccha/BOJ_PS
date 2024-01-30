#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

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

    int a, b;
    cin >> a >> b;

    cout << getGCD(a, b) << ENDL;
    cout << getLCM(a, b) << ENDL;

    return 0;
}

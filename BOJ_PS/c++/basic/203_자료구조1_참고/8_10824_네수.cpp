#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string A, B, C, D;

    cin >> A >> B >> C >> D;
    
    A += B;
    C += D;

    unsigned long long sum = strtoull(A.c_str(), nullptr, 10) + strtoull(C.c_str(), nullptr, 10);

    cout << sum << endl;

    return 0;
}

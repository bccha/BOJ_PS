#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int A, B, C;

    cin >> A >> B >> C;

    cout <<  (A+B)%C  << endl;
    cout <<  ((A%C) + (B%C))%C << endl;
    cout <<  (A*B)%C << endl;
    cout <<  ((A%C) * (B%C))%C << endl;

    return 0;
}

#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int counter[26] = {0, };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string line;

    cin >> line;

    for (auto c : line) {
        ++counter[c - 'a'];
    }

    for (auto i : counter) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}

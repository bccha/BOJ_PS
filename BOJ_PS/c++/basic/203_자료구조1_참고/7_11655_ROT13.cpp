#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string line;
    getline(cin, line);

    for (auto c : line) {
        if (isalpha(c)) {
            char offset = 'A';
            if (c >= 'a' && c <= 'z') {
                offset = 'a';
            }
            char newC = ((c - offset) + 13) % 26 + offset;
            cout << newC;
            continue;
        }
        cout << c;
    }
    cout << ENDL;

    return 0;
}

#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    string word;
    list<char> l;

    cin >> word;
    cin >> numTC;

    for (auto c : word) {
        l.push_back(c);
    }

    auto cur = l.end();

    while (numTC--) {
        char op;
        cin >> op;

        if (op == 'L') {
            if (cur != l.begin()) {
                --cur;
            }
        }
        if (op == 'D') {
            if (cur != l.end()) {
                ++cur;
            }
        }
        if (op == 'B') {
            if (cur != l.begin()) {
                --cur;
                cur = l.erase(cur);
            }
        }
        if (op == 'P') {
            char c;
            cin >> c;
            l.insert(cur, c);
        }
    }
    for (auto c : l) {
        cout << c;
    }
    cout << ENDL;
    return 0;
}

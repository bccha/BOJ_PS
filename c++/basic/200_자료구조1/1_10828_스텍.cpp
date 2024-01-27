#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    cin >> numTC;
    cin.ignore();

    stack<int> s;

    string cmd;
    int v;

    while (numTC--) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> v;
            s.push(v);
        }
        if (cmd == "pop") {
            if (s.size() == 0) {
                cout << -1 << ENDL;
                continue;
            }
            cout << s.top() << ENDL;
            s.pop();
        }
        if (cmd == "size") {
            cout << s.size() << ENDL;
        }
        if (cmd == "empty") {
            cout << ((s.size() == 0) ? 1 : 0) << ENDL;
        }
        if (cmd == "top") {
            if (s.size() == 0) {
                cout << -1 << ENDL;
                continue;
            }
            cout << s.top() << ENDL;
        }

    }
    return 0;
}

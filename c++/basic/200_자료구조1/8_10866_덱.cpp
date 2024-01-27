#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    cin >> numTC;

    deque<int> q;

    while (numTC--) {
        string op;
        int v;
        cin >> op;

        if (op == "push_front") {
            cin >> v;
            q.push_front(v);
        }
        if (op == "push_back") {
            cin >> v;
            q.push_back(v);
        }
        if (op == "pop_front") {
            if (q.empty()) {
                cout << -1 << ENDL;
            } else {
                cout << q.front() << ENDL;
                q.pop_front();
            }
        }
        if (op == "pop_back") {
            if (q.empty()) {
                cout << -1 << ENDL;
            } else {
                cout << q.back() << ENDL;
                q.pop_back();
            }
        }
        if (op == "size") {
            cout << q.size() << ENDL;
        }
        if (op == "empty") {
            cout << (q.empty() ? 1 : 0) << ENDL;
        }
        if (op == "front") {
            if (q.empty()) {
                cout << -1 << ENDL;
            } else {
                cout << q.front() << ENDL;
            }
        }
        if (op == "back") {
            if (q.empty()) {
                cout << -1 << ENDL;
            } else {
                cout << q.back() << ENDL;
            }
        }
    }
    return 0;
}

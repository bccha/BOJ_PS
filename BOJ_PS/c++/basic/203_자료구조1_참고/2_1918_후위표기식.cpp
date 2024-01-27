#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

bool checkPriority(pair<char, int> a, pair<char, int> b) {
    if (a.second > b.second) {
        return true;
    }
    if (a.second < b.second) {
        return false;
    }
    if ((a.first == '*' || a.first == '/') && (b.first == '+' || b.first == '-')) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string infix;
    cin >> infix;

    int paren = 0;
    stack<pair<char, int>> s;

    pair<int, int> a = {1, 2};
    tuple<int, string, int> b = {1, "222aa2", 3};
    cout << a.first << endl;
    cout << get<1>(b) << endl;

    for (auto c : infix) {
        if (c >= 'A' && c <= 'Z') {
            cout << c;
        } else if (c == '(') {
            ++paren;
        } else if (c == ')') {
            --paren;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!s.empty() && !checkPriority({c, paren}, s.top())) {
                cout << s.top().first;
                s.pop();
            }
            s.push({c, paren});
        }
    }

    while (!s.empty()) {
        cout << s.top().first;
        s.pop();
    }
    cout << ENDL;

    return 0;
}

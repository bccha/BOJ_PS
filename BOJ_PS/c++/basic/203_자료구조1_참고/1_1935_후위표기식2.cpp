#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int num[26];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    cin >> numTC;

    string post;
    cin >> post;

    stack<double> s;

    for (int i = 0; i != numTC; ++i) {
        cin >> num[i];
    }

    for (auto c : post) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            double v1 = s.top();
            s.pop();
            double v2 = s.top();
            s.pop();
            if (c == '+') {
                s.push(v1 + v2);
            } else if (c == '*') {
                s.push(v1 * v2);
            } else if (c == '-') {
                s.push(v2 - v1);
            } else if (c == '/') {
                s.push(v2 / v1);
            }
        } else {
            s.push(num[c - 'A']);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top() << ENDL;

    return 0;
}

#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    cin >> numTC;

    int nextVal = 1;

    stack<int> s;

    vector<char> result;

    while (numTC--) {
        int v;
        cin >> v;

        while (nextVal <= v) {
            s.push(nextVal++);
            result.push_back('+');
        }

        if (!s.empty() && s.top() == v) {
            result.push_back('-');
            s.pop();
        } else if (s.empty()) {
            cout << "NO" << ENDL;
            return 0;
        } else if (s.top() > v) {
            cout << "NO" << ENDL;
            return 0;
        }
    }

    for (auto c : result) {
        cout << c << ENDL;
    }
    return 0;
}

#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, K;

    cin >> N >> K;

    list<int> y;

    for (int i = 1; i <= N; ++i) {
        y.push_back(i);
    }

    auto cur = y.begin();

    cout << '<';
    while (!y.empty()) {
        for (int i = 0; i != K - 1; ++i) {
            ++cur;
            if (cur == y.end()) {
                cur = y.begin();
            }
        }
        cout << *cur;
        cur = y.erase(cur);
        if (cur == y.end()) {
            cur = y.begin();
        }
        if (y.empty()) {
            cout << '>' << ENDL;
        } else {
            cout << ", ";
        }
    }

    return 0;
}

#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int result[1000001] = {0, };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    cin >> numTC;
    int total = numTC;

    stack<pair<int, int>> s;

    for (int i = 0; i != numTC; ++i) {
        int v;
        cin >> v;

        if (!s.empty()) {
            while(!s.empty() && s.top().first < v) {
                result[s.top().second] = v;
                s.pop();
            }
        }

        s.push({v, i});
    }

    for (int i = 0; i != numTC; ++i) {
        if (result[i] == 0) {
            result[i] = -1;
        }
        cout << result[i] << ' ';
    }
    cout << ENDL;
    return 0;
}

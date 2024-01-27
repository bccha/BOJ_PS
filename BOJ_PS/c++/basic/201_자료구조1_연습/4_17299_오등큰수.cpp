#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int result[1000001] = {0, };
int counter[1000001] = {0, };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    cin >> numTC;
    int total = numTC;

    vector<int> input;
    stack<pair<int, int>> s;

    for (int i = 0; i != numTC; ++i) {
        int v;
        cin >> v;
        input.push_back(v);
        counter[v]++;
    }

    for (int i = 0; i != numTC; ++i) {
        int v = input[i];
        if (!s.empty()) {
            while(!s.empty() && counter[s.top().first] < counter[v]) {
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

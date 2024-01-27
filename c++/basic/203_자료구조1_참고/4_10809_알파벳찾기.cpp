#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int counter[26] = {0, };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string line;

    cin >> line;

    for (int i = 0; i != line.length(); ++i) {
        char c = line[i];
        int idx = c - 'a';
        if (counter[idx] == 0) {
            counter[idx] = i + 1;
        }
    }

    for (auto i : counter) {
        cout << (i == 0 ? -1 : i - 1) << ' ';
    }
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string line;

    cin >> line;

    int depth = 0;
    int total = 0;

    for (int i = 0; i != line.length(); ++i) {
        if (line[i] == '(') {
            ++depth;
        }
        if (line[i] == ')') {
            if (line[i - 1] == '(') {
                total += depth - 1;
                --depth;
            } else {
                total += 1;
                --depth;
            }
        }
    }

    cout << total << ENDL;

    return 0;
}

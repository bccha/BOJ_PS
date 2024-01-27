#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    while (!cin.eof()) {
        string line;
        getline(cin, line);
        if (line.length() == 0) {
            continue;
        }

        int result[4] = {0, 0, 0, 0};

        for (auto c : line) {
            if (isspace(c)) {
                result[3]++;
            } else if (isdigit(c)) {
                result[2]++;
            } else {
                if (c >= 'a' && c <= 'z') {
                    result[0]++;
                } else {
                    result[1]++;
                }
            }
        }

        for (auto v : result) {
            cout << v << ' ';
        }
        cout << ENDL;
    }

    return 0;
}

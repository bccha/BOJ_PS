#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string line;
    getline(cin, line);


    bool inTag = false;
    bool start = true;
    auto cur = line.begin();

    for (auto i = line.begin(); i != line.end(); ++i) {
        if (*i == '<') {
            inTag = true;
            if (!start) {
                reverse(cur, i);
            }
            start = false;
            continue;
        }
        if (*i == '>') {
            inTag = false;
            start = true;
            continue;
        }

        if (!inTag && start) {
            start = false;
            cur = i;
            continue;
        }
        if (!inTag && *i == ' ') {
            reverse(cur, i);
            cur = i + 1;
        }

    }
    if (!start) {
        reverse(cur, line.end());
    }

    cout << line << ENDL;

    return 0;
}

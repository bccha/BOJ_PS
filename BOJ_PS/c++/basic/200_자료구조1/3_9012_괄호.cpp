#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    cin >> numTC;

    while (numTC--) {
        string vps;
        cin >> vps;
        int val = 0;

        for (auto c : vps) {
            if (c == '(') {
                ++val;
            }
            if (c == ')') {
                --val;
            }
            if (val < 0) {
                break;
            }
        }

        cout << ((val == 0) ? "YES" : "NO") << ENDL;

    }
    return 0;
}

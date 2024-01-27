#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string line;
    cin >> line;

    vector<string> v;
    for (auto i = line.begin(); i != line.end(); ++i) {
        string s(i, line.end());
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    for (auto s : v) {
        cout << s << ENDL;
    }

    return 0;
}

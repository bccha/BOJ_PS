#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    cin >> numTC;
    cin.ignore();

    string word;

    while (numTC--) {
        getline(cin, word);
        auto start = word.begin();
        for (auto i = word.begin(); i != word.end(); ++i) {
            if (*i == ' ') {
                reverse(start, i);
                start = i + 1;
            }
        }
        reverse(start, word.end());
        cout << word << ENDL;
    }
    return 0;
}

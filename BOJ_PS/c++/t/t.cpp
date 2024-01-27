#include <bits/stdc++.h>

#define ENDL "\n"

using namespace std;

void strToken(const string &in, vector<string> &ret) {
    stringstream ss(in);
    string t;

    while (ss >> t)
    {
        ret.push_back(t);
    }
}

void setPrecision(int p) {
    cout << fixed;
    cout.precision(p);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int numTC;
    cin >> numTC;
    cin.ignore();

    while (numTC--) {

    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void sub(int i, vector<int>& ans, vector<int>& v) {
    if (i == v.size()) {
        for (auto& t : ans) {
            cout << t << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(v[i]);
    sub(i + 1, ans, v);
    ans.pop_back();
    sub(i + 1, ans, v);
}

int main() {
    vector<int> v = {3, 1, 2}; // Correct initialization
    vector<int> ans;
    sub(0, ans, v);
    return 0;
}

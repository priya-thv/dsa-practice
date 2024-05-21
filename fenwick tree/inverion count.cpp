#include <bits/stdc++.h>
using namespace std;

int sum(int i, vector<int>& b) {
    int s = 0;
    while (i > 0) {
        s += b[i];
        i -= i & (-i);
    }
    return s;
}

void update(int i, int x, vector<int>& b, int n) {
    while (i <= n) {
        b[i] += x;
        i += i & (-i);
    }
}

int inversionc(vector<int>& b, vector<int>& v, int max_val) {
    int count=0;
    for(int i=0;i<v.size();i++){
        count+=sum(max_val,b)-sum(v[i],b);
        update(v[i],1,b,max_val);
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > max_val) {
            max_val = x;
        }
        v[i] = x;
    }

    vector<int> b(max_val + 1, 0); // BIT array of size max_val + 1
    int t = inversionc(b, v, max_val);
    cout << "Number of inversions: " << t << endl;
    return 0;
}

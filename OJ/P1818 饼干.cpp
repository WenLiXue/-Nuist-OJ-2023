#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> w(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        sum += w[i];
        w[i] = sum;
    }
    
    vector<int> s(q);
    for (int i = 0; i < q; i++)
        cin >> s[i];
    
    for (int i = 0; i < q; i++) {
        auto p = lower_bound(w.begin() + 1, w.end(), s[i]);
        int temp = distance(w.begin(), p);
        cout << temp << " ";
    }
    
    return 0;
}


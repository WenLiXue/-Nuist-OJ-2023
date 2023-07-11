#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int n, m, ans;
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

void dfs(int a, int b) {
    if (a > m || b > n) {
        return;
    }
    if (a == m && b == n) {
        ans++;
        return;
    }
    dfs(a + 1, b + 2);
    dfs(a + 2, b + 1);
}

int main() {
    cin >> n >> m;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}


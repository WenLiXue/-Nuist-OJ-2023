#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4 + 5;
int a[N], f[N]; // a 存放原始数据，f 存放以 i 结尾的最大子段和

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    f[1] = a[1]; // 初始化
    int res = f[1]; // 记录最大子段和

    for (int i = 2; i <= n; i++)
    {
        f[i] = max(f[i-1] + a[i], a[i]);
        res = max(res, f[i]);
    }

    cout << res << endl;

    return 0;
}


#include <iostream>
#include <cstring>
using namespace std;

const int N = 1005;

int n, m;
int arr[N][N];
int f[N][N];

int main()
{
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> arr[i][j];

        memset(f, 0, sizeof f);
        f[1][1] = arr[1][1];

        for (int i = 2; i <= n; i++) f[i][1] = f[i-1][1] + arr[i][1];
        for (int j = 2; j <= m; j++) f[1][j] = f[1][j-1] + arr[1][j];

        for (int i = 2; i <= n; i++)
            for (int j = 2; j <= m; j++)
                f[i][j] = max(f[i-1][j], f[i][j-1]) + arr[i][j];

        cout << f[n][m] << endl;
    }

    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;
#define N 300004
int d[N];
int distance(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (pow(2, i) == n)
            return 0;
        else if (pow(2, i) > n)
            return n - pow(2, i - 1) + 1;
    }
}
int main()
{
    int n, k, j = 0, result = 0, t;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t == k)
            d[j++] = distance(i + 1); 
    }
    for (int i = 0; i < j; i++) 
    {
        if (!d[i] || d[i] < result)
            result++;
        else
            result = max(result, d[i]);
    }
    cout << result << endl;
}


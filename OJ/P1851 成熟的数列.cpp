#include <iostream>
#include <algorithm> // lower_bound function
using namespace std;

typedef long long ll;
const int N = 1e6 + 5;
int n, z;
ll num[N];

int main() {
    cin >> num[0] >> num[1];
    cin >> z;

    // Calculate the values of num[i] for i >= 2
    for (int i = 2; i <= z; i++)
        num[i] = num[i / 2] + num[i / 4];

    cin >> n;

    while (n--) {
        ll t;
        cin >> t;

        // Use lower_bound to find the position of t in the num array
        auto ans = lower_bound(num, num + z, t) - num; // Get the index

        if (num[ans] == t)
            cout << ans << endl; // Found t at position ans
        else
            cout << -1 << endl; // t not found
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int findClosestElement(const vector<int>& arr, int x) {
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return x;
        } else if (arr[mid] < x) {
            left = mid;
        } else {
            right = mid;
        }
    }
    if (abs(arr[left] - x) <= abs(arr[right] - x)) {
        return arr[left];
    } else {
        return arr[right];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int k;
        cin >> k;
        int closest = findClosestElement(arr, k);
        cout << closest << endl;
    }
    return 0;
}


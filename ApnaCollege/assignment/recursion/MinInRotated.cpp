#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& arr, int si, int ei) {

    if (si == ei) {
        return arr[si];
    }

    int mid = si + (ei - si) / 2;


    int leftMin = findMin(arr, si, mid);
    int rightMin = findMin(arr, mid + 1, ei);

    return min(leftMin, rightMin);
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int ans = findMin(arr, 0, arr.size() - 1);
    cout << "The minimum element is: " << ans << endl;

    return 0;
}

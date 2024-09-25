#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool compare(string str1, string str2) {
    int n = min(str1.size(), str2.size());
    for (int k = 0; k < n; k++) {
        char ch1 = str1[k];
        char ch2 = str2[k];
        if (ch1 < ch2) {
            return true;
        } else if (ch1 > ch2) {
            return false;
        }
    }
    return str1.size() < str2.size();
}

void merge(vector<string>& arr, int si, int ei, int mid) {
    vector<string> ans;
    int i = si;
    int j = mid + 1;

    while (i <= mid && j <= ei) {
        if (compare(arr[i], arr[j])) {
            ans.push_back(arr[i]);
            i++;
        } else {
            ans.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        ans.push_back(arr[i]);
        i++;
    }

    while (j <= ei) {
        ans.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < ans.size(); k++) {
        arr[si + k] = ans[k];
    }
}

void mergesort(vector<string>& arr, int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    // left
    mergesort(arr, si, mid);
    // right
    mergesort(arr, mid + 1, ei);
    // merge
    merge(arr, si, ei, mid);
}

int main() {
    vector<string> arr = {"sun", "earth", "mars", "mercury"};

    mergesort(arr, 0, arr.size() - 1);

    // Print the contents of the vector
    for (const string& str : arr) {
        cout << str << " ";
    }

    return 0;
}

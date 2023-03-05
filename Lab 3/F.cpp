#include <iostream>

int left_bin_search(int arr[], int value, int n) {
    int l = -1;
    int r = n;
    while (r > l + 1) {
        int mid = (r + l) / 2;
        if (arr[mid] < value) {
            l = mid;
        } else { r = mid; }
    }
    if (r < n && arr[r] == value) {
        return r+1;
    } else {
        return -1;
    }

    return 0;
}

int right_bin_search(int arr[], int value, int n) {
    int l = -1;
    int r = n;
    while (r > l + 1) {
        int mid = (r + l) / 2;
        if (arr[mid] <= value) {
            l = mid;
        } else { r = mid; }
    }
    if (l < n && arr[l] == value) {
        return l+1;
    } else {
        return -1;
    }

    return 0;
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int tmp;
        std::cin >> tmp;
        std::cout << left_bin_search(arr, tmp, n) << " ";
        std::cout << right_bin_search(arr, tmp, n) << "\n";
    }
    return 0;
};
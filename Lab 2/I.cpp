#include <stdio.h>
#include <string.h>

void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int arr[], int l, int r) {
    int v = arr[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (arr[i] < v) { i++; }
        while (arr[j] > v) { j--; }
        if (i >= j){ break; }
        swap(arr, i, j);
        i++;j--;
    }

    return j;
}

void quicksort(int arr[], int l, int r) {
    if (l < r) {
        int q = partition(arr, l, r);
        quicksort(arr, l, q);
        quicksort(arr, q + 1, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n-1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
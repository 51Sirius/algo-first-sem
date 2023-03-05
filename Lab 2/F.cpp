#include <stdio.h>
#include <stdlib.h>


int merge(int A[], int left, int right, int mid) {
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int L[len1];
    int R[len2];
    for (int i = 0; i < len1; ++i) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < len2; ++i) {
        R[i] = A[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    for (int k = left; k < right+1; ++k) {
        if ((L[i] <= R[j] && i < len1) || j >= len2) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

int merge_sort(int A[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, right, mid);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
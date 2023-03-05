#include <stdio.h>
#include <string.h>

void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void quick(int arr[], int l, int r, int k){
    while (l < r){
        int j = r;
        int i = l;
        int q = r;
        while (i <= j){
            while (arr[i] < arr[q]){
                i++;
            }
            while (arr[j] > arr[q]){
                j--;
            }
            if (i <=j){
                swap(arr, i, j);
                i++;
                j--;
            }
        }
        if (i>k){
            r = j;
        }
        if (j < k){
            l = i;
        }}

}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int A, B, C;
    int arr[n];
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &arr[0]);
    scanf("%d", &arr[1]);
    for (int i = 2; i < n; ++i) {
        arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
    }
    quick(arr, 0, n - 1, k-1);
    printf("%d", arr[k-1]);
    return 0;
}
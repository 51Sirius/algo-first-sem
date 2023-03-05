#include <stdio.h>
#include <string.h>


void swap(int arr[], int i, int j, int arr2[]) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    int tmp1 = arr2[i];
    arr2[i] = arr2[j];
    arr2[j] = tmp1;
}

void quick(int arr[], int l, int r, int arr2[]) {
    if (l < r) {
        int i = l;
        int j = r;
        int x = arr[(l + r) / 2];
        while (i <= j) {
            while (arr[i] < x) {
                i++;
            }
            while (arr[j] > x) {
                j--;
            }
            if (i <= j) {
                swap(arr, i, j, arr2);
                i++;
                j--;
            }
        }
        quick(arr, l, j, arr2);
        quick(arr, i, r,arr2);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int arr2[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        scanf("%d", &arr2[i]);
    }
    quick(arr, 0, n-1,arr2);
    int str;
    int end;
    int i=0;
    int key;
    for (int k = 0; k < n - 1; ++k) {
        str = k;
        end = k;
        while (arr[k] == arr[k + 1] && k < n - 1) {
            end = k + 1;
            k++;
        }
        if (str != end) {
            for (int j = str + 1; j < end+1; j++) {
                key = arr2[j];
                i = j - 1;
                while (i >= str && key < arr2[i]) {
                    int tmp = arr2[i + 1];
                    arr2[i + 1] = arr2[i];
                    arr2[i] = tmp;
                    int tmp1 = arr[i + 1];
                    arr[i + 1] = arr[i];
                    arr[i] = tmp1;
                    i--;
                }
                arr2[i + 1] = key;
            }
        }
    }
    str = arr[0];
    end = arr2[0];
    int count=0;
    for (i = 1; i < n; ++i) {
        if(arr[i] > end){
            count += end - str + 1;
            str = arr[i];
            end = arr2[i];
        } else{
            if (end < arr2[i]){
                end = arr2[i];
            }
        }
    }
    count += end -str + 1;
    printf("%d", count);
    return 0;
}
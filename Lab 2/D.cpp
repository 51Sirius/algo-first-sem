#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int key;
    int i;
    int flag;
    for (int j = 1; j < n; j++) {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && key < arr[i]) {
            int tmp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = tmp;
            i--;
            flag = 1;
        }
        arr[i + 1] = key;
        if (j < n && flag == 1) {
            for (int k = 0; k < n; k++) {
                printf("%d ", arr[k]);
                flag = 0;

            }
            printf("\n");
        }

    }


    return 0;
}
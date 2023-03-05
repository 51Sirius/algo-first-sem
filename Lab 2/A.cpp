#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int ind; int numb;
    int arr[n+1];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &numb);
    scanf("%d", &ind);
    int tmp = arr[ind-1];
    int tmp1;
    arr[ind-1] = numb;
    for (int i = ind; i < n+1; ++i) {
        tmp1 = arr[i];
        arr[i] = tmp;
        tmp = tmp1;
    }
    for (int i = 0; i < n+1; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}
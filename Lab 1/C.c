#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int i;
    int min1;
    int min2;
    int tmp;
    scanf("%d", &min1);
    scanf("%d", &min2);
    for (i = 0; i < N-2; i++) {
        scanf("%d", &tmp);
        if (tmp < min1 || tmp < min2) {
            if (tmp < min1) {
                if (min2>min1) {
                    min2 = tmp;
                } else {
                    min1 = tmp;
                }
            } else {
                min2 = tmp;
            }
        }
    }
    if (min1 > min2){
        tmp = min2;
        min2 = min1;
        min1 = tmp;
    }
    printf("%d", min1);
    printf(" ");
    printf("%d", min2);
    return 0;
}
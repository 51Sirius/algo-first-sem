#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int num1;
    int num2;
    int count = 0;
    int tmp;
    scanf("%d", &num1);
    scanf("%d", &num2);
    for (int i = 0; i < N - 2; i++) {
        scanf("%d", &tmp);
        if (num2 > num1 && num2 > tmp) {
            count++;
        }
        num1 = num2;
        num2 = tmp;
    }
    printf("%d", count);
    return 0;
}
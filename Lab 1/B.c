#include <stdio.h>

int main() {
    int N;
    int tmp;
    scanf("%d", &N);
    int list[N];
    int i;
    for (i=1; i<N; i++){
        scanf("%d", &tmp);
        list[i] = tmp;
    }
    scanf("%d", &tmp);
    list[0] = tmp;
    for (i=0; i<N; i++) {
        printf("%d", list[i]);
        printf(" ");
    }
    return 0;
}

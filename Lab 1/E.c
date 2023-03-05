#include <stdio.h>
#include "math.h"

int main() {
    int N;
    int numb;
    scanf("%d", &N);
    int razn=1000000;
    int list[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &list[i]);
    }
    int s_num;
    scanf("%d", &s_num);
    for (int i = 0; i < N; i++) {
        if (abs(list[i]-s_num) < razn) {
            razn = abs(list[i]-s_num);
            numb = list[i];
        }

    }
    printf("%d", numb);
    return 0;
}
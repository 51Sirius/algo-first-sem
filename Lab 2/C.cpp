#include <stdio.h>
#include <string.h>

int main() {
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);
    int co =n*m;
    int ar[co];
    for (int i = 0; i < co; ++i) {
        scanf("%d", &ar[i]);
    }

    int key;
    int i;
    for (int j = 1; j < co; j++) {
        key = ar[j];
        i = j-1;
        while (i >= 0 && key <= ar[i]) {
            int tmp = ar[i+1];
            ar[i+1] = ar[i];
            ar[i] = tmp;
            i--;
        }
    }
    int mask;
    scanf("%d", &mask);
    int masks[mask];
    for (int j = 0; j < mask; ++j) {
        scanf("%d", &masks[j]);
    }
    for (int j = 1; j < mask; j++) {
        key = masks[j];
        i = j-1;
        while (i >= 0 && key < masks[i]) {
            int tmp = masks[i+1];
            masks[i+1] = masks[i];
            masks[i] = tmp;
            i --;
        }
        masks[i+1] = key;
    }
    i=0;
    int count=0;
    for (int s = 0; s < co; ++s) {
        if (masks[i] <= ar[s]){
            count++;
            i++;
        }
    }
    printf("%d", count);
    return 0;
}
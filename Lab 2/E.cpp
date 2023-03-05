#include <stdio.h>
#include <string.h>


int main() {
    int n;
    scanf("%d", &n);
    int ids[n];
    int points[n];
    int new_points[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ids[i]);
        scanf("%d", &points[i]);
    }
    int key;
    int i;
    for (int j = 1; j < n; j++) {
        key = points[j];
        i = j - 1;
        while (i >= 0 && key > points[i]) {
            int tmp = points[i + 1];
            points[i + 1] = points[i];
            points[i] = tmp;
            int tmp1 = ids[i + 1];
            ids[i + 1] = ids[i];
            ids[i] = tmp1;
            i--;
        }
        points[i + 1] = key;
    }
    int str;
    int end;
    for (int k = 0; k < n - 1; ++k) {
        str = k;
        end = k;
        while (points[k] == points[k + 1] && k < n - 1) {
            end = k + 1;
            k++;
        }
        if (str != end) {
            for (int j = str + 1; j < end+1; j++) {
                key = ids[j];
                i = j - 1;
                while (i >= str && key < ids[i]) {
                    int tmp = ids[i + 1];
                    ids[i + 1] = ids[i];
                    ids[i] = tmp;
                    int tmp1 = points[i + 1];
                    points[i + 1] = points[i];
                    points[i] = tmp1;
                    i--;
                }
                ids[i + 1] = key;
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        printf("%d ", ids[i]);
        printf("%d\n", points[i]);
    }


    return 0;
}
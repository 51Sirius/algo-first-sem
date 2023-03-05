#include <iostream>
#include "vector"

using namespace std;

typedef struct qu {
    int head;
    int tail;
    int count;
} qu;


void siftup(vector<vector<int>> &arr, int i, int n) {
    while (arr[i][0] < arr[(i - 1) / 2][0]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void siftdown(vector<vector<int>> &arr, int i, int n) {
    while (2 * i + 1 < n) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int j = l;
        if (r < n && arr[r][0] < arr[l][0]) {
            j = r;
        }
        if (arr[i][0] <= arr[j][0]) {
            break;
        }
        swap(arr[i], arr[j]);
        i = j;
    }
}

int extractmin(vector<vector<int>> &arr, int n) {
    int m = arr[0][0];
    arr[0] = arr[n - 1];
    siftdown(arr, 0, n);
    return m;
}


int main() {
    qu queue;
    vector<vector<int>> arr(0,vector<int> (2));
    queue.head = 0;
    queue.tail = 0;
    char operation;
    int value;
    int count_op = 0;
    while (std::cin >> operation) {
        if (operation == 'p') {
            std::cin >> operation;
            std::cin >> operation;
            std::cin >> operation;
            std::cin >> value;
            count_op++;
            arr.resize(queue.tail + 1,vector<int> (2));
            arr[queue.tail][0] = value;
            arr[queue.tail][1] =  count_op;
            queue.tail++;
            siftup(arr, queue.tail - 1, 0);
        } else if (operation == 'e') {
            count_op++;
            for (int i = 0; i < 10; ++i) {
                std::cin >> operation;
            }
            if (queue.tail == 0) {
                std::cout << "*\n";
            } else {
                std::cout << extractmin(arr, queue.tail) << "\n";
                queue.tail--;
            }

        } else if (operation == 'd') {
            for (int i = 0; i < 11; ++i) {
                std::cin >> operation;
            }
            int from;
            int to;
            std::cin >> from;
            std::cin >> to;
            for (int i = 0; i < queue.tail; ++i) {
                if (arr[i][1] == from){
                    arr[i][0] = to;
                    siftup(arr, i, 0);
                    break;
                }
            }
            count_op++;
        }
    }

    return 0;
}
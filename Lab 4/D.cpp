#include <iostream>
#include "vector"

using namespace std;


int main(){
    int n;
    int m;
    int k;
    std::cin >> n;
    std::cin >> m;
    std::cin >> k;
    vector<vector<char>> arr (n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> arr[i][j];
        }

    }
    for (int f = m-1; f >m-k-1; --f) {
        int i;
        char key;
        vector<char> key_string;
        for (int j = 1; j < n; j++) {
            key_string = arr[j];
            key = arr[j][f];
            i = j-1;
            while (i >= 0 && key < arr[i][f]) {
                swap(arr[i+1], arr[i]);
                i--;
            }
            arr[i+1] = key_string;
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j];
        }
        std::cout << '\n';
    }

}
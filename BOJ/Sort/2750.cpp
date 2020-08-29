#include <iostream>

using namespace std;

void insertionSort(int* arr, int n) {
    int temp, j;

    for (int i = 1; i < n; i++) {
        temp = arr[i];
        j = i;

        while (arr[j - 1] > temp && j > 0) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}
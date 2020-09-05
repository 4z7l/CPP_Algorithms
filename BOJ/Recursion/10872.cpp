#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int factorial(int n) {
    if (n == 1 || n == 0) return 1;

    return n*factorial(n - 1);
}

int main() {

    int n;

    cin >> n; 
    

    cout << factorial(n);

    return 0;
}
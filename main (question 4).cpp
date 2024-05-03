#include <iostream>

using namespace std;

//  kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

//  kiểm tra số siêu nguyên tố
bool isSuperPrime(int n) {
    while (n > 0) {
        if (!isPrime(n)) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int a;
    cout << "Nhap a: ";
    cin >> a;

    cout << "Cac so sieu nguyen to trong doan la ";
    for (int i = 2; i <= a; i++) {
        if (isSuperPrime(i)) cout << i << " ";
    }

    return 0;
}


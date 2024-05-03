#include <iostream>
using namespace std;

int main() {
    int n;
    long S = 0;  


    do {
        cout << "\nEnter a positive integer n greater than 0: ";
        cin >> n;
        if (n <= 0) {
            cout << "\nThe number n must be greater than 0, please enter again!";
        }
    } while (n <= 0);

    cout << "The divisors of " << n << " are: ";
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << "\t";  
            S += i;             
        }
    }

    cout << "\nThe sum of the divisors of " << n << " is: " << S;

    cout << "\n-----------------------------------------\n";
}



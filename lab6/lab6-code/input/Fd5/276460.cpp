#include<iostream>
using namespace std;

int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
}

int main() {
    int num = 0;
    cin >> num;
    cout << addDigits(num);
}
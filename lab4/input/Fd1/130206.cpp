#include <iostream>
#include <cmath>
using namespace std;

int bulbSwitch(int n) {
        return sqrt(n + 0.5);
}

int main() {
    int n = 0;
    cin >> n;
    cout << bulbSwitch(n);
    return 0;
}

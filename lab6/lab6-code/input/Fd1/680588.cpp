#include <iostream>
using namespace std;
bool divisorGame(int n) {
        return !(n&1);
}

int main(){
    int n = 0;
    cin >> n;
    cout << divisorGame(n);
    return 0;
}
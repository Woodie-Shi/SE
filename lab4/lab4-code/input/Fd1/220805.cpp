#include <iostream>
#include <vector>
using namespace std;

bool divisorGame(int n) {
        vector<bool> dp(1+n, false);
        for(int i=2;i<=n;++i){
            for(int j=1;j<i;++j){
                if(i%j==0&&!dp[i-j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
}

int main() {
    int n = 0;
    cin >> n;
    cout << divisorGame(n) << endl;
}
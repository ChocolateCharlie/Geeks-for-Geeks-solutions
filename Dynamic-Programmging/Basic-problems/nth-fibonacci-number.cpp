#include <iostream>
#include <vector>

using namespace std;

vector<int> g_fibo;


// Compute n-th Fibonacci number modulo 1000000007
int getFibonacciMod(int n) {
    if (g_fibo.empty()) {
        g_fibo.push_back(1);
        g_fibo.push_back(1);
    }
    if (g_fibo.size() >= n) return(g_fibo[n - 1]);

    int f0, f1;

    while (g_fibo.size() < n) {
        f0 = g_fibo.size() - 2;
        f1 = g_fibo.size() - 1;
        g_fibo.push_back((g_fibo[f0] + g_fibo[f1]) % 1000000007);
    }

    return(g_fibo[n - 1]);
}



int main() {
    int T, n;

    cin >> T;

    while (T--) {
        cin >> n;
        cout << getFibonacciMod(n) << endl;
    }

    return(0);
}

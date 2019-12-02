#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <vector>

using boost::multiprecision::cpp_int;
using namespace std;

vector<cpp_int> cat_nbs;


// Compute n-th Catalan number
cpp_int getCatalan(int n) {
    if (cat_nbs.empty()) cat_nbs.push_back(1);
    if (cat_nbs.size() > n)    return(cat_nbs[n]);

    cpp_int next;

    while (cat_nbs.size() <= n) {
        next = 0;
        for (int i = 0; i < cat_nbs.size(); i++) {
            next += cat_nbs[i] * cat_nbs[cat_nbs.size() - i - 1];
        }
        cat_nbs.push_back(next);
    }

    return(cat_nbs[n]);
}



int main() {
    int T, n;

    cin >> T;

    while (T--) {
        cin >> n;
        cout << getCatalan(n) << endl;
    }

    return(0);
}

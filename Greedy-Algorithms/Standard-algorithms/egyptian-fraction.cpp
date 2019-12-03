#include <cmath>
#include <iostream>

using namespace std;



int main() {
    double  n, d;
    double  f;

    cout << "Egyptian Fraction Representation of: ";
    cin >> n;
    cin.ignore();   // "/" fraction symbol
    cin >> d;
    cout << "is : ";

    while (n != 0) {
        f = ceil(d / n);
        n = (n * f - d);
        d = d * f;
        cout << "1/" << f << " ";

        if (n != 0) cout << "+ ";
        else        cout << endl;
    }

    return(0);
}

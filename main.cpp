#include <iostream>
using namespace std;

int main()
{
    //Defining variables
    int n;
    double a,b;
    cout << "Dimension of matrix:";
    cin >> n;
    cout << "Diagonal element:";
    cin >> a;
    cout << "Non-diagonal element:";
    cin >> b;

    double veca[n], vecx[n]; vecu[n];
    vec[0] = a;
    double temp = b**2;

    //LU-decomposition
    for (int k=1; k<n; k++) {
        veca[k] = veca[k-1] - temp/vec[k-1];
        vecu[k] = vecu[k] - (b*vecu[k-1])/veca[k-1];
    }

    vecx[n] = veca[n];
    temp = 0;

    //backward substitution
    for (int k=n-1; k >= 0; k--) {
        temp += b*vecx[k+1];
        vecx[k] = 1.0/veca[k]*(vecu[k]-temp);
    }
}



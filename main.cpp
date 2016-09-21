#include <iostream>
using namespace std;
#include <cmath>

//getting the values for f_i
double* f(int n)
{
    double h, c, h_squared, x_i[n+1];
    double* b_i = new double[n+1];
    h = 1./(n+1);
    h_squared = h*h;
    for (int k=0;k<=n+1; k++)  {
            x_i[k] = k*h;
            c = 100*exp(-10*x_i[k]);
            b_i[k] = h_squared* c; //100*exp(-10*x_i[k]);
            //cout <<  x_i[k] <<"    " << c << endl;


    }
    return b_i;

}

int main()
{
    //Defining variables
    int n;
    int a,b;
    //double b_i;
    cout << "Dimension of matrix:";
    cin >> n;
    /*
    cout << "Diagonal element:";
    cin >> a;
    cout << "Non-diagonal element:";
    cin >> b;
    */

    double* b_i = f(n);

    a = 2;
    b = -1;

    double veca[n], vecx[n+1]; //vecu[n];
    veca[0] = a;
    double temp = b*b;

    //Gaussian elimination
    for (int k=1; k<n; k++) {
        veca[k] = veca[k-1] - temp/b_i[k-1];
        b_i[k] = b_i[k] - (b*b_i[k-1])/veca[k-1];
    }

    vecx[n+1] = 0;
    vecx[n] = veca[n];
    vecx[0] = 0;
    temp = 0;

    //backward substitution
    for (int k=n-1; k >= 0; k--) {
        temp += b*vecx[k+1];
        vecx[k] = (1.0/veca[k])*(vecx[k]-temp);
        //cout << k << endl;
    }
    for (int k=0; k<n; k++) {
        cout << vecx[k] << endl;
    }
}


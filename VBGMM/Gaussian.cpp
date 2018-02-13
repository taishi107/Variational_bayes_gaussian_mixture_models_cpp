#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Eigen/Core"
#include "Eigen/LU"

using namespace std;
using namespace Eigen;

int main(){
    int D = 2;
    double tmp,tmp2;
    Vector2f mu;
    Vector2f data;
    Vector2f s;
    Matrix2f cov;
    Matrix2f cov2;

    //mu << 0.39,2.31;
    //data << -0.337,-0.216;
    mu << 1,1;
    data << 2,-2;
    cov << 0.1,0.0,
           0.0,0.1;

    //sqrt
    tmp = pow(2*M_PI,2)*cov.determinant();
    tmp = sqrt(tmp);

    //exp

    s = data - mu;
    cov2 = cov.inverse();
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(fabs(cov2(i,j))<0.0001){
                cov2(i,j) = 0.0;
            }
        }
    }

    tmp2 = exp(-0.5*s.transpose()*cov2*s);
    cout << tmp2/tmp << endl;
    //cout << -1*0 << endl;
}

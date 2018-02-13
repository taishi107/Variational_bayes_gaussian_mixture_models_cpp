#include <iostream>
#include "Eigen/Core"

using namespace std;
using namespace Eigen;

int main(){
    /*Eigen::MatrixXf A=Eigen::MatrixXf::Zero(2,8);
    cout << A << endl;
    A(0,0)=2;
    A(1,1)=5;
    for(int i=0;i<10;i++){
      A(1,7) += 1;
    }

    cout<<A<<endl;
    Matrix2f mat[10];
    Vector2f m[10];
    for(int i=0;i<10;i++){
      //Eigen::MatrixXf mat[i]=Eigen::MatrixXf::Zero(2,2);
      mat[i] = Matrix2f::Zero();
      m[i] = Vector2f::Zero();

    }
    for(int i=0;i<10;i++){
        cout << m[i] << endl;
        cout << "-----------------" << endl;
    }*/
    Vector2f a;
    Vector2f b,c;
    a = Vector2f::Random();
    b = Vector2f::Random();
    c = Vector2f::Random();
    a << -1.1,-1.1;
    //b << 1,1;


    //std::cout << a << '\n';
    //std::cout << b << '\n';
    std::cout << a/10 << '\n';
    //std::cout << c.norm() << '\n';

}

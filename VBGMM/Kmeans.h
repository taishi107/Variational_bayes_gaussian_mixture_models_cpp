#ifndef _KMEANS_H_
#define _KMEANS_H_
#include "Eigen/Core"

using namespace Eigen;

class Kmeans
{

int K;
int N;
int count[8];
int label[2000];
Vector2f sum[8];


public:
      Vector2f cluster_centers[8];
      Vector2f data[2000];
      Kmeans();
      void Reset_param();
      void Load_data();
      void init_cal();
      void Draw(double data,double mu,int label);
      void EM_step();

};

#endif

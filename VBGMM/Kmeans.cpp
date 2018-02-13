#include "Kmeans.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include "Eigen/Core"

using namespace std;
using namespace Eigen;

Kmeans::Kmeans()
{
    K = 8;
    N = 0;
    for(int i=0;i<K;i++){
        cluster_centers[i] =  Vector2f::Zero();
    }
    Kmeans::Reset_param();
    Kmeans::init_cal();
    Kmeans::Load_data();
}

void Kmeans::init_cal(){
    /*double rand_x;
    double rand_y;
    int range = 4;
    srand((unsigned)time( NULL ));
    for(int i=0;i<K;i++){
      //for(int j=0;j<2;j++){
        rand_x = (double)rand()/((double)RAND_MAX+1);
        rand_x = rand_x*range -2;

        rand_y = (double)rand()/((double)RAND_MAX+1);
        rand_y = rand_y*range -2;

        cluster_centers[i] << rand_x,rand_y;
      //}
      */
      cluster_centers[0] << 0.025,1.89;
      cluster_centers[1] << 1.04,0.96;
      cluster_centers[2] << -1.4,1.2;
      cluster_centers[3] << 1.3,1.5;
      cluster_centers[4] << -0.26,-0.16;
      cluster_centers[5] << -1.5,0.67;
      cluster_centers[6] << -0.17,-1.7;
      cluster_centers[7] << -0.07,-0.29;
    //}
}

void Kmeans::Reset_param()
{
    for(int i=0;i<K;i++){
        count[i] = 0;
        sum[i] = Vector2f::Zero();
    }
}

void Kmeans::Load_data(){
    int i=0;
    double val;

    ifstream infile("sensor_data.csv");
    string str;
    while(getline(infile,str)){
        string tmp;
        istringstream stream(str);
        while(getline(stream,tmp,',')){
            val = atof(tmp.c_str());
            data[N][i] = val;
            i++;
        }

        i = 0;
        N++;
    }
}

void Kmeans::EM_step(){
    vector<double> nums;

    for(int i=0;i<N;i++){
      for(int j=0;j<K;j++){
        nums.push_back((cluster_centers[j] - data[i]).norm());

      }
      vector<double>::iterator iter = std::min_element(nums.begin(), nums.end());
      label[i] =  distance(nums.begin(), iter);
      count[label[i]] += 1;
      sum[label[i]] += data[i];
      nums.clear();
    }
    for(int i=0;i<K;i++){
        cluster_centers[i] << sum[i]/count[i];

    }
}

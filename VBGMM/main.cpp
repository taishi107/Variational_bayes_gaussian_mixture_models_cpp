#include "Kmeans.h"
#include <iostream>

int main(){
    Kmeans model;
    for(int i=0;i<11;i++){
        model.EM_step();
        model.Reset_param();
    }
    for(int i=0;i<8;i++){
        std::cout << model.cluster_centers[i] << '\n';
        std::cout << "--------------------------" << '\n';
      }
    return 0;
}

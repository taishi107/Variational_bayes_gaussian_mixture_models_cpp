#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double ran0() {
    double a;
    int t = 4;
    a = (double)rand()/((double)RAND_MAX+1);
    a = a*4 -2;
    return a;
}

int main() {
    int i;
    srand( (unsigned)time( NULL ) );
    for ( i=0; i<10; i++ ) {
        printf( "%f \n", ran0() );
    }
}

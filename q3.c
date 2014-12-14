/*
Final question of the final. Summation of series 1/ k^4 for k:0 ~ infinty. 
*/

#include <stdio.h>                          /*Necessary Libraries*/
#include <math.h>
#define M_PI 3.14159265358979323846


int main(void)
{
    
    float macheps = 1. ;
    float s; 
    float err, w;
    float exact = pow(M_PI, 4.)/90.;
    int n = 10;
    int nrep = 10;
    int i, k;
    
    while ( ( float ) ( 1. + macheps )!= 1. )
    {
        macheps /= 2 ;
    }
    printf ("macheps = %g\n" , macheps ) ;
    
    for(i = 0; i < nrep; i++)
    {
        s = 0.;
        for(k = n; k > 0; k--)    /*k is decreased down for better precision*/
        {    
                w = 1./k;
                s += w*w*w*w;
        }
        err = fabs(s-exact);
        printf ("%12d   %.8g   %.8g   %.8g \n", n, s, exact, err);
        n *=2;                  /*The number of terms to be added is double each time*/
    }
    return 0;
}


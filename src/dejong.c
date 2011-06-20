#include <math.h>
#include <limits.h>



double dejong1 (double *x)
{
    double result = pow(x[0] ,2.0) + pow(x[1] ,2.0) + pow(x[2] ,2.0);
    return(result);
}


double dejong2 (double *x)
{
    double sum = 0.0;
    int i;
    for (i=0; i<2; i++)
    {
        if(x[i]<-2.048 || x[i]>2.048)
        {
            sum = INFINITY;
            break;
        }
    }
    return ( 100 * pow(pow(x[0],2.0) - x[1], 2.0) + pow(1-x[0], 2.0) );
}


double dejong3 (double *x)
{
    double sum = 0.0;
    int i;
    for (i=0; i<5; i++)
    {
        sum += floor(x[i]);
        if(x[i]<-5.12 || x[i]>5.12)
        {
            sum = INFINITY;
            break;
        }
    }
    return (sum);
}






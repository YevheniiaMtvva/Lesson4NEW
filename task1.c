#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve(double a,double b, double c)
{
    float discr = b * b - 4 * a * c;

    if(discr < 0)
    {
        printf("No real roots for this equation!\n");

        return;
    }

    float x1,x2;
    
    x1 = ( (-1 * b * b) + sqrt(discr) ) / 2 * a;
    x2 = ( (-1 * b * b) - sqrt(discr) ) / 2 * a;

    if(discr == 0)
    {
        printf("x1 = x2 = %f\n",x1);

        return;
    }

    printf("x1 = %f\nx2 = %f\n",x1,x2);
}

int main(int argc, char** argv)
{
    if(argc < 4)
    {
        printf("Quadratic equations solver 0.1\n");
        printf("Usage: solv <a> <b> <c>\n");

        return EXIT_SUCCESS;
    }

    float a, b, c;
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

    solve(a, b, c);

    return EXIT_SUCCESS;
}

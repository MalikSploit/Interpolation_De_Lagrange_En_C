#include<stdio.h>
#include <stdlib.h>
#include <math.h>

/*Fonction pour évaluer Li(x)*/
//On met n+1 dans x[n+1] car n commence au degré 0;
double Li(int i, int n, double x[n+1], double X)
{
    int j;
    double prod=1; // on initialise à 1 et non à 0 car sinon tout sera nul;
    for(j=0;j<=n;j++)
    {
      if(j!=i)
      {
        prod=prod*(X-x[j])/(x[i]-x[j]);
      }
    }
    return prod;
}
 
/*Fonction pour évaluer Pn(x) où Pn est le polynôme interpolant de Lagrange de degré n*/
//On met n+1 dans x[n+1] et dans y[n+1] car n commence au degré 0;
double Pn(int n, double x[n+1], double y[n+1], double X)
{
    double sum=0;
    int i;
    for(i=0;i<=n;i++)
    {
        sum=sum+Li(i,n,x,X)*y[i];
    }
    return sum;
}

double Printf_lj(int i, int n, double x[n+1], double X)
{
    int j;
    double prod=1; // on initialise à 1 et non à 0 car sinon tout sera nul;
    for(j=0;j<=n;j++)
    {
      if(j!=i)
      {
        prod=prod*(X-x[j])/(x[i]-x[j]);
        printf("l%d(x) = %.4lf\n", j ,prod);
      }
    }
    return prod;
}

int main()
{
    int i,n;  //n est le degrée
    n=21;
    printf("Le degré de votre polynôme est : %d\n", n-1);
    double x[22]=     
     {752,
      855,
      871,
      734,
      610,
      582,
      921,
      492,
      569,
      462,
      907,
      643,
      862,
      524,
      679,
      902,
      918,
      828,
      875,
      809,
      894};
  double y[22]=   
     {85,
      83,
      162,
      79,
      81,
      83,
      281,
      81,
      81,
      80,
      243,
      84,
      84,
      82,
      80,
      226,
      260,
      82,
      186,
      77,
      223};
    double X; //on remplace la valeur x par la valeure saisie par l'utilisateur pour obtenir l'interpolation.
    printf("Saisir la valeur de x pour laquelle vous voulez effectuer l'interpolation de y(x) : ");
    scanf("%lf",&X);
    printf("La valeur interpolée est : %lf\n",Pn(n,x,y,X));
    Printf_lj(i,n,x,X);
}
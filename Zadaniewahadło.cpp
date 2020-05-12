#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "rk4.h"
void veuler(double t, double *X, double h, int n,void (* fun)(double, double *,double *), double *X1);
void rhs_fun(double t, double *X,double *F);
int main()



{
	FILE*fp;
	fp=fopen("cw.txt","w");
	int n =2;
	double t,tk,h,a0,w0;
	double *Xe,*X1e , *Xr,*Xr1;
	Xe=(double*)malloc(n*sizeof(double));
	X1e=(double*)malloc(n*sizeof(double));
	Xr=(double*)malloc(n*sizeof(double));
	Xr1=(double*)malloc(n*sizeof(double));
	tk=10.0;
	double g,l;
	g = 9.81;
	l=1.0;
	h=0.01;
	w0=0.0;
	a0=0.4;
	double m = 5;
	Xe[0] = w0;
	Xe[1] = a0;
	Xr[0]=  w0;
	Xr[1] = a0;
	
	double Em,Em1;
	printf("Energia calkowita euler\t\tEnergia calkowita RK-4\n");
	for(t=0;t<=tk; t = t+h)
	
	{

		veuler(t,Xe,h,n,rhs_fun,X1e);
		vrk4(t,Xr,h,n,rhs_fun,Xr1);
		Em = (m*1*1/2*Xe[0]*Xe[0])+(m*g*l*(1-cos(Xe[1])));
		Em1 = (m*1*1/2*Xr[0]*Xr[0])+(m*g*l*(1-cos(Xr[1])));
		printf("%lf\t\t\t%lf\n",Em,Em1);
		fprintf(fp, "%lf\n" ,t);
		Xe[0] = X1e[0];
		Xe[1] = X1e[1];
		Xr[0] = Xr1[0];
		Xr[1] = Xr1[1];
		
		
	}
	system("PAUSE");
}


void rhs_fun(double t, double *X,double *F)

{
	double g,l;
	g = 9.81;
	l = 1.0;
	F[0] = (-1.0)*g/l*sin(X[1]);
	F[1] = X[0];
}
void veuler(double t, double *X, double h, int n,void (* fun)(double, double *,double *), double *X1)

{
	double *F;
	F = (double*)malloc(n*sizeof(double));
	fun(t,X,F);
	X1[0] = X[0] + (h*F[0]);
	X1[1] = X[1] + (h*F[1]);
	free(F);
	

}

	
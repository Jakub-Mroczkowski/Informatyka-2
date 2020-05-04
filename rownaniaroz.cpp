#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rk4.h"

double funkcja(double t, double y);
double lambda;

void main()
{
	FILE *fp;
	lambda=2.0;
	double h =0.5;
	double tp=0;
	double yp=1;
	double tk=5.0;
	double ypa=1;
	double ya=1;
	double tpa=0;
	double yap=1;
	double epsilon;
	
	printf("Metoda Eulera\nt0=%lf\t\t\ty0=%lf\n" , tp,yp);
	
	for(int i = 0 ; i <(tk/h);i++)
		
	{
		tp= tp + h;
		yp = yp + h*funkcja(tp,yp);
		ya = yap * exp(lambda*(tp-tpa));
		epsilon = ((fabs(ya-yp))/fabs(ya));
		printf("t%d=\t%lf\t\ty%d=\t%lf\t\teps=\t%lf\n\n",i+1,tp,i+1,yp,epsilon);
	}
	double rk=1;
	double epsilon2;
	tp=0;
	yp=1;
	printf("Metoda R-K4\nto=%lf\t\t\tyo=%lf\n" , tp,yp);
	
	for(int i = 0 ; i <(tk/h);i++)
	{
		tp = tp+h;
		rk=rk4(tp,rk,h,funkcja);
		ya = yap * exp(lambda*(tp-tpa));
		epsilon2 = (fabs(ya-rk))/fabs(ya);
		printf("t%d=\t%lf\t\ty%d=\t%lf\t\teps=\t%lf\n\n",i+1,tp,i+1,rk,epsilon2);
	}
	
	double N;
	double rk1=1;
	double epsilone,epsilonrk;
	fp=fopen("wyn.txt","w");

	for(int i =0; i<7 ;i++)
	{
		tp=0;
		yp=1;
		rk1=1;
		N = pow(2.,i);
		printf("Euler\n\nt0=%lf\t\ty0=%lf\n",tp,yp);
			for(int j =0 ; j <N;j++)
			{
				
				h=tk/N;
				tp=tp+h;
				yp = yp+h*funkcja(tp,yp);
				ya = yap * exp(lambda*(tp-tpa));
				epsilone=((fabs(ya-yp)/fabs(ya)));
				printf("t%d=\t%lf\t\ty%d=\t%lf\t\teps=\t%lf\n\n" ,j+1, tp,j+1,yp,epsilone);
				
			}
			printf("\n\n");
		
			
		tp=0;
		yp=1;
		
		printf("R-K4\n\nt0=%lf\t\ty0=%lf\n" , tp,yp);
		for(int j=0;j<N;j++)
		{
			h = tk/N;
			tp = tp+h;
			rk1=rk4(tp,rk1,h,funkcja);
			ya = yap * exp(lambda*(tp-tpa));
			epsilonrk = (fabs(rk1-ya))/fabs(ya);
			printf("t%d=\t%lf\t\ty%d=\t%lf\t\teps=\t%lf\n\n" ,j+1,tp,j+1,rk1, epsilonrk);
		}
		
		fprintf(fp, "ilosc krokow=%lf\t\tdlugosc kroku=%lf\t\tblad eulera=%lf\t\tblad R-K4=%lf\n" , N,h,epsilone,epsilonrk);
		
		}
	
	system("PAUSE");
}

double funkcja(double t, double y)

{
	return lambda*y;
}
























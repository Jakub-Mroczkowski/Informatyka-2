#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "rk4.h"
#include "winbgi2.h"
double pi=atan(1.)*4, g=9.81 ,  Ro=1.2,vo,m;
double C = 1.5, S = pi*0.5*0.5;
void prawastrona(double t, double *x, double *dx);


	void main()
	{
		
		double alfa;
		
		printf("Prosze podac predkosc oraz kat  pod jakim wylatuja kula:\n");
		scanf("%lf %lf" , &vo ,&alfa);
		printf("Prosze podac mase kulki:\n");
		scanf("%lf" , &m);
		
		double x[4] = { 0, vo * cos(alfa*(pi/180)) , 0,vo*sin(alfa*(pi/180))};
		double xkol[4], h = 0.005, r;
		double groundtouch;
		groundtouch = -0.0001;
		int i;
		FILE *fp = fopen("wyniki.txt", "w");
		double t=0.0;
		double tk=4;
		
		graphics(800, 800);
		fprintf(fp, "%lf\t%lf\t%lf\t%lf\t%lf\n", t, x[0], x[1], x[2], x[3]);
		while (t <= tk && x[2]>=groundtouch )
		{
			vrk4(t, x, h, 4 , prawastrona, xkol);
			for (i = 0; i < 4; i++)
			{
				x[i] = xkol[i];
			}
			t = t+ h;
			fprintf(fp, "%lf\t%lf\t%lf\t%lf\t%lf\n", t, x[0], x[1], x[2], x[3]);
			animate(100);
			circle(x[0]*(15)+200, x[2]*(-15)+700, 3);
			
		}
		fclose(fp);
		wait();
		
	}




	void prawastrona(double t, double *x, double *dx)
{
	dx[0] = x[1];
	dx[1] = -1. / 2.*C*S*Ro*sqrt((x[1]+ vo*sin(t) )*(x[1] + vo*sin(t) ) + x[3] * x[3])*(x[1]+ vo*sin(t) ) / m;
	dx[2] = x[3];
	dx[3] = -1. / 2.*C*S*Ro*sqrt((x[1]+ vo*sin(t) )*(x[1] + vo*sin(t) ) + x[3] * x[3])*x[3] / m - g;
}

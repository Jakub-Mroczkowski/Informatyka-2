#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "gauss.h"
//Zadanie 2,3
/*void computeMatrix(int N , double **K);
void displayMatrix(int N , double **K);
void computeVector(int N, double *F,double *x);
void displayVector(int N , double *F);


void main()


{
	FILE* fp;
	int N;
	printf("Prosze podac wartosc N:");
	scanf("%d", &N);
	double h= 1.0/N;
	double **K;
	double *T;
	double *F;
	double *x;
	
	K = (double**)malloc((N+1)*sizeof(double*));
	for(int i = 0 ; i <=N ;i++)
	K[i] = (double*)malloc((N+1)*sizeof(double));
	for(int i = 0 ; i <=N;i++)
	{
		for(int j = 0 ; j<=N ;j++)
		{
			K[i][j] =0;
		}
	}
	F = (double*)malloc((N+1)*sizeof(double));
	x = (double*)malloc((N+1)*sizeof(double));
	T = (double*)malloc((N+1)*sizeof(double));
	
	for(int i = 0 ; i <=N;i++)
		
	{
		x[i]=h*i;
	}
	computeMatrix(N,K);
	displayMatrix(N,K);
	computeVector(N,F,x);
	displayVector(N,F);
	printf("\n\n\n");
	gauss((N+1),K,T,F);
	displayVector(N,T);
	fp = fopen("mojewyn.txt","w");

	for(int i = 0 ; i <=N;i++)
	{
		fprintf(fp, "%lf\t\t\t%lf\n" , x[i], T[i]);
	}
	fclose(fp);
	free(T);
	free(F);
	free(x);
	for(int i = 0; i<=N;i++)
	free(K[i]);
	free(K);
	system("PAUSE");
}
void computeMatrix(int N , double **K)

{
	for(int i = 1 ;i <N ; i++)
	{
		K[i][i-1] = 1.0;
		K[i][i] = -2.0;
		K[i][i+1] = 1.0;
	}
	K[0][0] = 1.0;
	K[N][N] = 1.0;
}

void displayMatrix(int N , double **K)

{
	for(int i = 0 ; i <=N;i++)
	{
		for(int j = 0 ; j <=N ; j++)
		{
			printf("%lf " , K[i][j]);

		}
		printf("\n");
	}
}

void computeVector(int N, double *F,double *x)

{
	double h = 1.0/N;
	double l = 58.0;

	for(int i =1;i<N;i++)
	{
		F[i] = -10000.0*sin(x[i]*3.14)/l*pow(h,2);

	}
	F[0]=273.0;
	F[N]=300.0;
}

void displayVector(int N , double *F)
{
	for(int i = 0 ; i <=N;i++)
	{
		printf("%lf\n" , F[i]);
	}
}


*/
//Zadanie 1
void HilbertMatrix(int N , double **H);
void displayMatrix(int N , double **H);
void computeVec(int N, double **H , double *b);
void plotVec(int N , double *v);




void main()

{
		int N; 
		printf("Prosze podac wartosc N:");
		scanf("%d" , &N);
		double **H;
		double *x;
		double *b;
		
		x = (double*)malloc(N*sizeof(double));
		b = (double*)malloc(N*sizeof(double));
		
		H = (double**)malloc(N*sizeof(double*));
		for(int i=0; i <N ; i++)
		H[i] = (double*)malloc(N*sizeof(double));
		HilbertMatrix(N,H);
		displayMatrix(N,H);
		computeVec(N,H,b);
		plotVec(N,b);
		gauss(N,H,x,b);
		printf("\n\n\n");
		plotVec(N,x);

		system("PAUSE");
		
}


void HilbertMatrix(int N , double **H)

{
		for(int i = 0 ; i <N ; i++)
		{
			for(int j=0 ; j <N ; j++)
			{
				H[i][j] = 1.0/(j+i+1.0);
			}
		}

}


void displayMatrix(int N , double **H)

{
	printf("Macierz Hilberta:\n");
	for(int i= 0 ; i <N ; i++)
	{
		for(int j = 0 ; j <N; j++)
		{
			printf("%lf " , H[i][j]);
		}
		printf("\n");
	}
}


void computeVec(int N, double **H , double *b)

{
		
		for(int i = 0 ; i <N ; i++)
		{
			double s = 0.0;
			for(int j = 0 ; j <N ;j++)
			{
				s = s + H[i][j];
			}
			b[i] = s;
		}
}


void plotVec(int N , double *v)

{
	for(int i= 0; i <N ;i++)
	{
		printf("%lf\n ", v[i]);
	}
}



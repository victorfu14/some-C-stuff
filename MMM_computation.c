#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <assert.h>


double mat1[1000][1000], mat2[1000][1000];
double res[1000][1000];

int dummy();
int R=100; 
int N;


int incre(int N){

	if (N>=10000000)return 10000000;
	if (N>=1000000) return 1000000;
	if (N>=100000)  return 100000;
	if (N>=10000)   return 10000;
	if (N>=1000)    return 1000;
	if (N>=100)     return 100;
	if (N>=10)      return 10;
	if (N>=1)       return 1;
}
 
double rtclock()
{
    struct timeval Tp;
    int stat;
    stat = gettimeofday (&Tp, NULL);
    if (stat != 0) printf("Error return from gettimeofday: %d",stat);
    return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}

int main()
{
    double t_start, t_end;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) { 
            mat1[i][j]=1.0e0; mat2[i][j]=2.0e0;
        }
	}
    for (N=1; N <= 1000; N+=incre(N)) {
    	t_start = rtclock();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			res[i][j] = 0;
            for (int k = 0; k < N; k++) {
                res[i][j] += mat1[i][k]*mat2[k][j];
            }
            // a[i]=b[i]+c[i]*d[i];
		}
		// if (a[2] < 0) dummy(a,b,c,d);
	}

    	t_end = rtclock();
    	fprintf(stdout,"%d , %7.5lf \n", N,R*N*3e0/((t_end - t_start)*1.0e6));
    }


    return 0;
}

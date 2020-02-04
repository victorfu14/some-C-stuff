#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <assert.h>


double a[10000000], b[10000000], c[10000000], d[10000000];

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
	for (int i=0; i<10000000; i++){
		a[i]=0.0e0; b[i]=1.0e0; c[i]=2.0e0; d[i]=3.0e0;
	}
    for (N=1; N <= 10000000; N+=incre(N)){
    	t_start = rtclock();

	for (int j=0; j< R; j++){
		for (int i =0; i<N; i++){
			a[i]=b[i]+c[i]*d[i];
		}
		if (a[2] < 0) dummy(a,b,c,d);
	}

    	t_end = rtclock();
    	fprintf(stdout,"%d , %7.5lf \n", N,R*N*3e0/((t_end - t_start)*1.0e6));
    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <assert.h>

double rtclock()
{
    struct timeval Tp;
    int stat;
    stat = gettimeofday (&Tp, NULL);
    if (stat != 0) printf("Error return from gettimeofday: %d",stat);
    return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}

float res[200][200],mat1[200][200],mat2[200][200];
int N;

int main()
{
    double t_start, t_end;
    FILE *fptr;
    fptr = fopen("hw8_ikj.txt", "a");
    for (int i = 0; i < 200; i++) 
    {
        for (int j = 0; j < 200; j++) 
        {
            res[i][j] = 0;
            mat1[i][j] = 1.0;
            mat2[i][j] = 2.0;
        }
    }
    for (N = 10; N <= 200; N += 10) 
    {

        t_start = rtclock();

        for (int i = 0; i < N; i++) 
        {
            for (int k = 0; k < N; k++) 
            {
                for (int j = 0; j < N; j++)
                {
                    res[i][j] += mat1[i][k]*mat2[k][j];
                }
                if (res[2][2] < 0) dummy(res, mat1, mat2);
            }
            if (res[3][3] < 0) dummy(res, mat1, mat2);
        }
         
        t_end = rtclock();
        fprintf(stdout,"N = %d: %7.5lf MFLOPS\n", N, N*N*N*3e0/((t_end - t_start)*1.0e6));
        fprintf(fptr,"N = %d: %7.5lf MFLOPS\n", N, N*N*N*3e0/((t_end - t_start)*1.0e6));
        
    }
    fprintf(fptr,"\n");
    fclose(fptr);
    return 0;
}


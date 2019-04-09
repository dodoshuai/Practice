#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

ElementType Median( ElementType A[], int N )
{
    int i,j,gap;
    for (gap=N>>1; gap; gap>>=1)
    {	printf("%d",gap);
        for (i=gap; i<N; ++i)
        {
            for (j=i-gap; j>=0&&A[j]>A[j+gap]; j-=gap)
            {
                ElementType temp=A[j];
                A[j]=A[j+gap];
                A[j+gap]=temp;
            }
        }
    }
    return A[N>>1];
}

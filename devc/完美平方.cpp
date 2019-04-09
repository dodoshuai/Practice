#include<stdio.h> 
#include<math.h> 
int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n) {
                return !!a + !!b;
            }
        }
        return 3;
    }
    int main()
    {
    	int i;
    	scanf("%d",&i);
    	
    	printf("%d",numSquares(i));
    	return 0;
    }

#include <stdio.h>
int  main()
{
    int num ,res  = 0;
    while(scanf("%d",&num)!=EOF)
    {
    res=0;
    while(num!=0)
    {
      
		res = res + num%10;
        num = num /10;
    }
    printf("%d\n",res);
	}
    return 0;
}

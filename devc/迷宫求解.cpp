#include <stdio.h>  
#include <stdlib.h>  
#define MAX 100  
  
typedef struct {  
    int x;  
    int y;  
    int d;  
}ElemType;  
  
typedef struct {  
    int x;  
    int y;  
}Mark;  
  
typedef struct {  
    ElemType *base;  
    int top;  
    int stacksize;  
}SqStack;  
  
void Initmaze(int maze[MAX][MAX], Mark &start, Mark &end){  
    int n,m,i,j;  
      
    scanf("%d%d",&n,&m);  
      
    for(i = 1; i <= n; i ++){  
        for(j = 1; j <= m ; j ++)  
            scanf("%d",&maze[i][j]);  
    }  
      
    for(i = 0; i <= m + 1 ; i ++){  
        maze[0][i] = 1;  
        maze[n + 1][i] = 1;  
    }  
      
    for(j = 0; j <= n +1 ; j ++){  
        maze[j][0] = 1;  
        maze[j][m + 1] = 1;  
    }  
      
/*  for(i = 1; i <= n; i ++){ 
        for(j = 1; j <= m; j ++) 
            printf("%2d",maze[i][j]); 
             
        putchar('\n'); 
    }   */  
    scanf("%d%d",&start.x, &start.y );  
    scanf("%d%d",&end.x, &end.y );  
}  
  
void InitStack(SqStack &S){  
    S.base = (ElemType *)malloc(MAX * sizeof(ElemType ));  
      
    if(!S.base )  
        return ;  
      
    S.top = 0;  
    S.stacksize = MAX;  
}  
  
int StackEmpty(SqStack S){  
    if(S.top == 0)  
        return 1;  
    return 0;  
}  
  
void Push(SqStack &S, ElemType elem){  
    S.base [S.top ++] = elem;  
      
}  
  
void Pop(SqStack &S, ElemType &elem){  
    elem = S.base [-- S.top ];  
}  
  
void MazePath(int maze[MAX][MAX], Mark start, Mark end, int dir[4][2]){  
    SqStack S1,S2;  
    ElemType elem;  
    int i,j,a,b,d;  
      
    InitStack(S1);  
    InitStack(S2);  
          
    elem.x = start.x ;  
    elem.y = start.y;  
    elem.d = -1;  
    maze[start.x ][start.y ] = 2;  
    //printf("%d,%d\n",start.x ,start.y);  
    //printf("%d,%d\n",elem.x ,elem.y);  
    Push(S1,elem);  
    //Pop(S1,elem);  
    //printf("<%d,%d,%d>\n\n",elem.x ,elem.y ,elem.d );  
    while(!StackEmpty(S1)){  
        Pop(S1,elem);  
          
        i = elem.x;  
        j = elem.y;  
        d = elem.d + 1;  
          
        while(d < 4){  
            a = i + dir[d][0];  
            b = j + dir[d][1];  
            //printf("<%d,%d>1\n",a,b);  
              
            if(a == end.x && b == end.y && maze[a][b] == 0){  
                elem.x = i;  
                elem.y = j;  
                elem.d = d;  
                  
                Push(S1,elem);  
                  
                elem.x = a;  
                elem.y = b;  
                elem.d = 4;  
                  
                Push(S1,elem);  
                  
                while(!StackEmpty(S1)){  
                    Pop(S1,elem);  
                    Push(S2,elem);  
                }  
                  
                while(!StackEmpty(S2)){  
                    Pop(S2,elem);  
                    printf("<%d,%d,%d>\n",elem.x ,elem.y ,elem.d );  
                }  
                    return ;  
            }  
              
             if(maze[a][b] == 0){  
                maze[a][b] = 2;  
                  
                elem.x = i;  
                elem.y = j;  
                elem.d = d;  
                  
                Push(S1,elem);  
                  
                i = a;  
                j = b;  
                d = -1;  
            }  
            d ++;  
        }     
          
    }  
    printf("没有找到可以走出迷宫的路径！");  
}  

void printmaze(int maze[MAX][MAX])
{
	int i,j;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
}
  
int main(){  
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};  
    ElemType elem;  
      
  
    Mark start,end;  
    int maze[MAX][MAX]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
		1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
		1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 0, 1, 1, 1, 1
    
	};  
      
    //Initmaze(maze,start,end);  
  
    MazePath(maze,start,end,dir);  
      printmaze(maze);
    return 0;  
} 

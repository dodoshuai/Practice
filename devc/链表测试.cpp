#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define ERROR -1
typedef enum { false , true } bool ; 
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* ??????????????? */
};

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}
List MakeEmpty()
{
	List L;
	L->Last=0;
	return &L;
}
Position Find(List L, ElementType X)
{
	int i;
	for(i=0;i<=L->Last;i++)
	{
		if(L->Data[i]==X)
		{
			return (i);
		}
	}
	return ERROR;
}
bool Insert( List L,ElementType X,Position P)
{
	int i;
	if(L->Last==(MAXSIZE-1))
	{
		printf("FULL");
		return false;
	}
	if(P<0||P>MAXSIZE-1)
	{
		printf("ILLEGAL POSITION");
		return false;
	}
	for(i=L->Last-1;i>=P;i--)
	{
		L->Data[i+1]=L->Data[i];
	}
	L->Data[i+1]=X;
	return true;
}
bool Delete( List L, Position P )
{
	int i;
	if(P<0||P>MAXSZE-1)
	{
		printf("POSITION P EMPTY");
		return false;
	}

	for(i=P;i<L->Last;i++)
	{
		L->Data[i]=L->Data[i+1];
	}
	L->Data[i]=0;
	return true;
}

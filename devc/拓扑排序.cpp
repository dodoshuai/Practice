#include<stdio.h>


typedef int Status;

Status TopologicalSort(ALGraph G);//有向图采用邻接表存储结构 


int main()
{

return 0;
} 

Status TopologicalSort(ALGraph G)
{
	FindInDegree(G,indegree);
	InitStack(S);
	for(i=0;i<0;++i)
	{
		if(!indegree[i]) Push(S,i);
		
	}
	count=0;
	while(!StackEmpty(S))
	{
		Pop(S,i); printf(i,G.vertices[i].data);++count;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc)
		{
			k=p->adjvex;
			if(!(--indegree[k])) Push(S,k);
		}
	}
	if(count<G.vexnum) return ERROR;
	else return OK;
} 

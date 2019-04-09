#include <iostream>
using namespace std;

#define MAXLEN 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} elementType;  

typedef  struct
{ elementType   data[MAXLEN+1]; 
  int   len;
} SeqList;                      

void creat(SeqList &L)
{ int i;
  cin>>L.len;
  for(i=1;i<=L.len;i++)
     cin>>L.data[i].key;   
}

int  binSearch(SeqList T, KeyType k);

int main () 
{  SeqList L;  KeyType k;
   creat(L);
   cin>>k;
   int pos=binSearch(L,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   
   return 0;
}
int  binSearch(SeqList T, KeyType k)
{
 
  int min=1;
  int max=T.len;
  while(min<=max)
  {
   
    if(T.data[min+(max-min)/2].key==k)
    return min+(max-min)/2;
    else if(T.data[min+(max-min)/2].key>k)
    max=min+(max-min)/2-1;
    else if(T.data[min+(max-min)/2].key<k)
     min=min+(max-min)/2+1;
  }
  return 0;
}
/*int  binSearch(SeqList T, KeyType k)
{
 
  int min=1;
  int max=T.len;
  while(min<max)
  {
   if(T.data[min].key==k)
    return min;
	 if(T.data[max].key==k)
    return max;
    if(T.data[min+(max-min)/2].key==k)
    return min+(max-min)/2;
    else if(T.data[min+(max-min)/2].key>k)
    max=min+(max-min)/2-1;
    else if(T.data[min+(max-min)/2].key<k)
     min=min+(max-min)/2+1;
  }
  return 0;
}
*/

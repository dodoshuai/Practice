/*#include<iostream>
#include<stdio.h>
#include<stdilb.h>

using namespace std;

struct st_task
{
uint16_t id;
uint32_t value;
uint64_t timestamp;
};

void fool()
{
st_task task = {};
uint64_t a = 0x00010001;
memcpy(&task, &a, sizeof(uint64_t));
printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
}

int main(){
	
	fool();
	
	return 0;
}*/
#include "stdio.h"
#define N 9
int x[N];
int count = 0;
void dump() {
int i = 0;
for (i = 0; i < N; i++) {
printf("%d", x[i]);
}
printf("\n");
}
void swap(int a, int b) {
int t = x[a];
x[a] = x[b];
x[b] = t;
}
void run(int n) {
int i;
if (N - 1 == n) {
dump();
count ++;
return;
}
for (i = n; i < N; i++) {
swap(n, i);
run(n + 1);
swap(n, i);
}
}
int main() {
int i;
for (i = 0; i < N; i++) {
x[i] = i + 1;
}
run(0);
printf("* Total: %d\n", count);
}



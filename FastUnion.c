#include<stdio.h>
#define N 1000000
int main()
{
  int p,q,A[N];
  int i,j,t;
  for(i=0;i<N;i++) A[i] = i;
  while(scanf("%d%d\n",&p,&q) == 2){
    for(i=p;A[i]!=i;i=A[i]);
    for(j=q;A[j]!=j;j=A[j]);
    if (i == j) continue;
    A[i] = j;
    printf("%d-%d\n",p,q);
  }
  return 0;
}

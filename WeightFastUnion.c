#include<stdio.h>
#define N 1000000
int main()
{
  int p,q,A[N],sz[N];
  int i,j,t;
  for(i=0;i<N;i++) {A[i] = i; sz[i] = 1;}
  while(scanf("%d%d\n",&p,&q) == 2){
    for(i=p;A[i]!=i;i=A[i]);
    for(j=q;A[j]!=j;j=A[j]);
    if (i == j) continue;
    if( sz[i] > sz[j] ){
      A[j] = i;
      sz[i] += sz[j];
    }
    else{
      A[i] = j;
      sz[j] += sz[i];
    }
    printf("%d-%d\n",p,q);
  }
  return 0;
}

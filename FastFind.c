//FastFind runs with input size one million of largeUF.txt
//using 46 minus to finish

//with input size 1000 of mediumUF.txt
//using 1.5 sec
#include<stdio.h>
#define N 1000000
int main()
{
  int p,q,A[N];
  int i,j,t;
  for(i=0;i<N;i++) A[i] = i;
  while(scanf("%d%d\n",&p,&q) == 2){
    if (A[p] == A[q]) continue;
    for(t=A[p],j=0;j<N;j++)
      if(A[j]==t) A[j] = A[q];
    printf("%d-%d\n",p,q);
  }
  return 0;
}

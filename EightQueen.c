#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
int Min(int x, int y);
void Print(int A[], int n);
void GEN_QUEEN(int A[], int k, int S[], int n);
int Diagonal_Chk(int A[], int k, int s);
int Abs(int x);// return absolute value for x

int COUNT=0;

int main(int argc, char *argv[])
{
  int N=MAX;
  int A[MAX + 1],S[MAX + 1],i;
  if(argc!=2){
    printf("usage: run #3. the #3 is the board size, which must suppled while starting the prog\n");
    exit(0);
  }
  else
    N = Min(atoi(argv[1]),MAX);

  for(i=1;i<=N;i++)
    S[i] = i;
  GEN_QUEEN(A,0,S,N);
  printf("------Counts %d compatable configuarations --------\n", COUNT);

  return 0;
}

void GEN_QUEEN(int A[], int k, int S[], int n)
{
  if( k==n ){
    Print(A,n);
    COUNT++;
  }
  else{
    int i;
    for(i=1;i<=n;i++){
      if(S[i]!=0 && (Diagonal_Chk(A,k,S[i]) == 0 ) ){
	k++;
	A[k] = S[i];
	S[i] = 0;
	GEN_QUEEN( A, k, S, n);
	S[i] = A[k];
	k--; 
      }
    }
  }
}

void Print(int A[], int n)
{
  int i;
  for( i=1; i<=n; i++ )
    printf("%3d",A[i]);
  putchar('\n');
}
   
int Min(int x, int y)
{
  return x<y?x:y;
}

int Diagonal_Chk(int A[], int k, int s)
{
  int i;
  for(i=1;i<=k;i++)
    if(Abs(k+1-i) == (Abs(s - A[i])))
      return 1;//conflict
  return 0;// No confilict
}

int Abs( int x )
{
  return x>0? x:(-1*x);
}

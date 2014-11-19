#include <iostream>

using namespace std;

template <class T> class MinPQ
{
public:
   MinPQ(int maxN);
   MinPQ(T a[], int n);
   bool isEmpty();
   int size();
   void insert(T v);
   T delMax();
   ~MinPQ();
   
private:
   int N;
   int maxN;
   T  *pq;
   bool more(int i, int j);
   void exch(int i, int j);
   void swim(int k);
   void sink(int k);
};


template <class T> MinPQ<T>::MinPQ(int maxN)
{
   pq = new T[maxN];
   N  = 0;
}

template <class T> MinPQ<T>::MinPQ(T a[], int n)
{
   N = 0;
   maxN = 2 * n; 
   pq = new T[maxN];
   for (int i = 0; i < n; i++)
      insert(a[i]);
}

template <class T> bool MinPQ<T>::isEmpty()
{
   return N == 0;
}

template <class T> int MinPQ<T>::size()
{
   return N;
}

template <class T> void MinPQ<T>::insert(T v)
{
   if (N == maxN) {
      T *pqNew = new T[2*N];
      for (int i = 1; i <= N; i++)
         pqNew[i] = pq[i];
      delete [] pq;
      pq = pqNew;
   }
   pq[++N] = v;
   swim(N);
}

template <class T> T MinPQ<T>::delMax()
{
   if(!isEmpty()) {
      T v = pq[1];
      exch(1, N);
      N--;
      sink(1);
      if(N < maxN / 4) {
         T *pqNew = new T[maxN/2];
         for (int i = 1; i <= N; i++)
            pqNew[i] = pq[i];
         delete [] pq;
         pq = pqNew;
      }
      return v;
   }
}
   
template <class T> bool MinPQ<T>::more(int i, int j)
{
   return pq[i] > pq[j];
}

template <class T> void MinPQ<T>::exch(int i, int j)
{
   T tmp = pq[i];
   pq[i] = pq[j];
   pq[j] = tmp;
}

template <class T> void MinPQ<T>::swim(int k)
{
   while (k > 1 && more(k/2, k)) {
      exch(k/2, k);
      k = k/2;
   }
}

template <class T> void MinPQ<T>::sink(int k)
{
   while (2*k <= N) {
      int j = 2*k;
      if (j < N && more(j, j+1)) j++;
      if (!more(k, j)) break;
      exch(k, j);
      k = j;
   }
}

template <class T> MinPQ<T>::~MinPQ()
{
   delete [] pq;
}


class Person
{
public:
   Person() {
      id = 0;
      age = 0;
   }
   Person(int x, int y) {
      id = x;
      age = y;
   }
   bool operator > (Person&);
   void print();
private:
   int id;
   int age;


};
bool Person::operator > (Person& p)
{
   return age > p.age;
}

void Person::print()
{
   cout<<"age: " << age << " id: " << id <<endl;
}

int main()
{
   int i;
   MinPQ<Person>  pq(10);
   for (i = 1; i < 1000; i++) {
      Person p(i, i);
      pq.insert(p);
   }
   
   for (i = 1; i < 1000; i++) 
      pq.delMax().print();
 
  
   return 0;

}

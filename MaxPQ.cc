#include <iostream>
#include <assert.h>
using namespace std;

template <class T> class MaxPQ
{
public:
   MaxPQ(int maxN);
   MaxPQ(T a[], int n);
   bool isEmpty();
   int size();
   void insert(T v);
   T delMax();
   ~MaxPQ();
   
private:
   int N;
   int maxN;
   T  *pq;
   bool less(int i, int j);
   void exch(int i, int j);
   void swim(int k);
   void sink(int k);
};


template <class T> MaxPQ<T>::MaxPQ(int max)
{
   pq = new T[max];
   N  = 0;
   maxN = max;
}

template <class T> MaxPQ<T>::MaxPQ(T a[], int n)
{
   N = 0;
   maxN = 2 * n; 
   pq = new T[maxN];
   for (int i = 0; i < n; i++)
      insert(a[i]);
}

template <class T> bool MaxPQ<T>::isEmpty()
{
   return N == 0;
}

template <class T> int MaxPQ<T>::size()
{
   return N;
}

template <class T> void MaxPQ<T>::insert(T v)
{
   if (N == maxN) {
      T *pqNew = new T[2*N];
      for (int i = 1; i <= N; i++)
         pqNew[i] = pq[i];
      delete [] pq;
      pq = pqNew;
      maxN *= 2;
   }
   pq[++N] = v;
   swim(N);
}

template <class T> T MaxPQ<T>::delMax()
{
   if(!isEmpty()) {
      T v = pq[1];
      exch(1, N);
      N--;
      sink(1);
   
      if(N < maxN / 4) {
         cout << "shunk with: "<< N << "for: "<< maxN<<endl;
         T *pqNew = new T[maxN/2];
         for (int i = 1; i <= N; i++)
            pqNew[i] = pq[i];
         delete [] pq;
         pq = pqNew;
         maxN /= 2;
      }
      return v;
   }
}
   
template <class T> bool MaxPQ<T>::less(int i, int j)
{
   return pq[i] < pq[j];
}

template <class T> void MaxPQ<T>::exch(int i, int j)
{
   T tmp = pq[i];
   pq[i] = pq[j];
   pq[j] = tmp;
}

template <class T> void MaxPQ<T>::swim(int k)
{
   while (k > 1 && less(k/2, k)) {
      exch(k/2, k);
      k = k/2;
   }
}

template <class T> void MaxPQ<T>::sink(int k)
{
   while (2*k <= N) {
      int j = 2*k;
      if (j < N && less(j, j+1)) j++;
      if (!less(k, j)) break;
      exch(k, j);
      k = j;
   }
}

template <class T> MaxPQ<T>::~MaxPQ()
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
   bool operator < (Person&);
   void print();
private:
   int id;
   int age;


};
bool Person::operator < (Person& p)
{
   return age < p.age;
}

void Person::print()
{
   cout<<"out: age: " << age << " id: " << id <<endl;
}

int main()
{
   int i;
   MaxPQ<Person>  pq(10);
   for (i = 1; i < 1000; i++) {
      Person p(i, i);
      pq.insert(p);
   }
   
   for (i = 1; i < 1000; i++) 
      pq.delMax().print();
 
  
   return 0;

}

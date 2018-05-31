#include <iostream>     
#include <algorithm>    
#include <conio.h>
#include <iomanip>
using namespace std;

void FillInc(int A[], int n) {
    for(int i = 0; i <n; i++)
    {	
        A[i] = i+1; 
    }
}

void SelectSort(int A[], int n){
  int i,j,k,d;
  
  for(i=0;i<n-1;i++)
  {
    k=i;
    for(j=i+1;j<n;j++)
    { 
      if(A[j]<A[k])
      k=j;
    }
    if(k!=i) {
    
    d=A[i];
    A[i]=A[k];
    A[k]=d;
	}
  }
}

long double fact(int N)
{
    if(N < 0)
        return 0; 
    if (N == 0) 
        return 1; 
    else 
        return N * fact(N - 1); 
}


template<class BidirIt>

bool next_permutation(BidirIt first, BidirIt last)
{
    if (first == last) return false;
    BidirIt i = last;
    if (first == --i) return false;
 
    while (true) {
        BidirIt i1, i2;
 
        i1 = i;
        if (*--i < *i1) {
            i2 = last;
            while (!(*i < *--i2));
            std::iter_swap(i, i2);
            std::reverse(i1, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}

void Print(int myints[], int n)
{	int a = 0; char ch; int r = 1;
	sort(myints,myints+n);
	do {
		cout<<setw(2)<<r <<") ";
		for(int i = 0; i <n;i++){
			cout<<myints[i]<<" "; 
			if(i == n-1) cout<<endl;
			a+= 1;	
		}r++;
		if(a == 10*n) 
		{
		    cout<<"next page - y/ exit - q "; 
			ch = _getch();
		    if(ch== 'y'){
				system("cls");
				a = 0;
				cout<<"Next-->"<<endl;
			}
			else if(ch == 'q') break;
		}
		
  } while ( std::next_permutation(myints,myints+n) );
  
}

int main () {
	
	int n;
	cout<<"Pls, type count :"; cin>>n; cout<<endl;
	int myints[1000];
	FillInc(myints, n);
	SelectSort(myints, n);
	int N = fact(n);
	cout<<"Count of permutations is : "<< N <<endl;
	if(N >10) cout<<"!Big count of permutations!"<<endl;
	Print(myints, n);
	
  return 0;
}

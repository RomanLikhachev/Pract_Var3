#include <iostream>     
#include <algorithm>    
#include <conio.h>
#include <iomanip>

using namespace std;

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
{	
	int a = 0, r = 1, pgcnt = 1; char ch;
	sort(myints,myints+n);
	do 
	{
		cout << setw(4) << r <<") { ";
		for(int i = 0; i < n; i++)
		{
			cout << myints[i] <<" "; 
			if(i == n-1) cout<<"}"<<endl;
			a += 1;	
		}r++;
		if(a == 10*n) 
		{
			cout<<"\n\t"<< pgcnt++ <<"-th page"<<endl;
		    cout<<"\n\tNext page -> y \n \t Exit -> q "; 
		    
			ch = _getch();
		
		    if(ch == 'y')
			{
				system("cls");
				a = 0;
			}
			else if(ch == 'q') break;
		}
		 
  } while ( std::next_permutation(myints,myints+n) );
  
}

int main () 
{
	
	int n, N, myints[1000];
	char ch;
	cout<<"Please, enter the value of the number of digits of the array :"; 
	cin>>n; 
	
	cout<<"\nEnter the values of array: ";
	for(int cnt = 0; cnt < n ; cnt++ ){
		cin>>myints[cnt];
	}
	
	SelectSort(myints, n);
	
	N = fact(n);
	cout<<"\nArray is: A = {";
	for(int e = 0; e < n; e++)
		cout<<myints[e];
	
	cout<<"}\nCount of permutations is : "<< n <<"! = " << N ;
	if(N >10) 
		cout<<"\n\n! Large number of permutations(arrays will be print on pages: 10 arr on 1 page) !\n\n";
	
	ch = _getch(); system("cls");
	Print(myints, n);
	
}

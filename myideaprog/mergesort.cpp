#include<iostream>
#include<stdio.h>
using namespace std;


void merge(int *arr,int n)
{
	int t[n],i,j,k,size,l1,h1,l2,h2,s=0,p;
	for(size=1; size < n; size=size*2 )
    {
    l1=0;
    k=0;
        while( l1+size < n)
        {
        h1=l1+size-1;
        l2=h1+1;
        h2=l2+size-1;
        //s++;
        if( h2>=n )
        h2=n-1;
    
        i=l1;
        j=l2;
         
        while(i<=h1 && j<=h2 )
        {
        	s++;
            if( arr[i] <= arr[j] )
            {
			t[k++]=arr[i++];
	
       
            }
            else
            {
			t[k++]=arr[j++];
	
            }
			
        }

        while(i<=h1)
        {
		t[k++]=arr[i++];
     
		
		}
        while(j<=h2)
        {
        t[k++]=arr[j++];
   	
		
		}
        l1=h2+1; 
      
        }
        
    for(i=l1; k<n; i++) 
    {
	t[k++]=arr[i];}
    for(i=0;i<n;i++)
    {
	arr[i]=t[i];}
 //   printf("\nSize=%d \nElements are : ",size);
 //   for( i = 0 ; i<n ; i++)
  //  printf("%d ", arr[i]);
    }
 //   cout<<endl<<" s="<<s<<endl;
}
int main()
{
int n=1024,i;

 int *arr=new int[n];
	
    for(i=0;i<n;i++)
    {

	arr[i]=rand()%n;
    }
 //cout<<"Unsorted list is : ";

//	for( i = 0 ; i<n ; i++)
//	cout<<" "<<arr[i];
    merge(arr,n);
 cout<<endl<<endl<<" Sorted list is : ";
    for( i = 0 ; i<n ; i++)
        cout<<" "<<arr[i];
   cout<<"Kol-vo perestanovok: "<<c1<<endl<<"Kol-vo sravnenii: "<<c2<<endl;
cout<<endl;
}

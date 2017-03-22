#include<iostream>
 
using namespace std;

// Function to display array after each pass
void display_Array_each_pass(int array[], int size, int count_pass)
{
        cout << "Array after pass  "<< count_pass<< "\t";
	for (int i = 0; i < size; i++)
	{
		cout <<array[i] << " ";
	}
	cout << endl;
}


int main()
{
    int size,i,j,temp;
    //array "a" being hard coded
    int a[] = {3,2,1,4,5,2,5,10,1,67,21,34,23,60,32};
    size = 15;
    cout << "Array before bubble sort is";
    
    for(i=0;i<size;i++)
        cout<<" " << a[i];
    cout << "\n";   
   
    //bubble sort
    for(i=1;i<size;i++)
    {
        for(j=0;j<(size-i);j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                
	    }
         display_Array_each_pass(a,15,i);       
	    


    }
    
    cout<<"Array after bubble sort:";
    for(i=0;i<size;i++)
        cout<<" "<<a[i];
    cout << "\n";        
    return 0;
}

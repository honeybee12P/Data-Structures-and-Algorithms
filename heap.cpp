# include <iostream>
using namespace std;

//This function helps in maintaining heap property - parent value being greatest when compared with the left and right child
void maxheap(int *array, int i, int length)
{
    int j, temp;
    temp = array[i];
    j = 2*i;
    while (j <= length)
    {
        if (j < length && array[j+1] > array[j])
            j = j+1;
        if (temp > array[j])
            break;
        else if (temp <= array[j])
        {
            array[j/2] = array[j];
            j = 2*j;
        }
    }
    array[j/2] = temp;
    return;
}

//This function helps in sorting an array in place
void heapsort(int *array, int length)
{
    int i, temp;
    for (i = length; i >= 2; i--)
    {
        temp = array[i];
        array[i] = array[1];
        array[1] = temp;
        maxheap(array, 1, i - 1);
    }
}

//This function helps in producing heap from unordered input array
void buildheaptree(int *array, int length)
{
    int i;
    for(i = length/2; i >= 1; i--)
    {
        maxheap(array, i, length);
    }
}
int main()
{
    
    int length, i;
    
    cout<<"Enter number of elements of array\n";
    cin>>length;
    if (length < 15 ) {
       cout << "Insufficient length of array. Please enter atleast 15\n";
    }    
    else {
    int array[20];
    cout << "Random numbers being generated between 1 and 100 and added into the array....\n";
    for (i = 1; i <= length; i++)
    {
        array[i] = rand() % 100 + 1;
    }

    cout<<"Array before heapify\t";
    for (i = 1; i <= length; i++)
    {
        cout<<array[i]<<"\t";
    }
    cout << "\n";

   
    buildheaptree(array,length); //converts array to tree
    
    cout<<"Array after heapify\t";
    for (i = 1; i <= length; i++)
    {
        cout<<array[i]<<"\t";
    }
    cout << "\n";

    cout<<"Array before sort\t";
    for (i = 1; i <= length; i++)
    {
        cout<<array[i]<<"\t";
    }
    cout << "\n";    
    
    heapsort(array, length); //sorts the elements 
    
    cout<<"Array after sort\t";
    
    for (i = 1; i <= length; i++)
    {
        cout<<array[i]<<"\t";
    }
    }
     
}


#include <iostream>

using namespace std;


//function template for the average of int and double
template <typename T> 
double average(T array[], int size) 
{
    double average=0;
    for(int i=0;i<size;i++)
    {
        average+=array[i];
    }
    average/=size;
    return average;
}

template <typename T> 
void show(T array[], int size) 
{
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

//template specialization for showing the string
template <>
void show<string>(string array[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<endl;
    }
}

int main() 
{ 
    int idata[10]; 
    double ddata[10]; 
    string sdata[10]; 
    
    //taking inputs from user
    cout<<"Enter 10 integers"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>idata[i];
    }
    
    cout<<endl<<"Enter 10 double values"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>ddata[i];
    }
    
    cout<<endl<<"Enter 10 strings"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>sdata[i];
    }
    cout<<endl;
    
    //Displaying the outputs
    cout<<"Showing Integer array elments"<<endl;
    show<int>(idata,10);
    cout<<endl<<"Average of Integer :: "<<average<int>(idata,10)<<endl<<endl;
    
    cout<<"Showing Double array elments"<<endl;
    show<double>(ddata,10);
    cout<<endl<<"Average of Double :: "<<average<double>(ddata,10)<<endl<<endl;
    
    cout<<"Showing String array elments";
    show<string>(sdata,10);
    
    return 0; 
}

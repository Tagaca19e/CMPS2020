#include <iostream>
//added cmath for my floor function for getting the middle value
#include <cmath>
using namespace std;

void swap(int a, int b, int array[]){
  int temp = array[a];
  array[a] = array[b];
  array[b] = temp;
}



void quickSort (int data[], int lhs, int rhs){
  if(lhs >= rhs) return;
  int length = rhs-lhs;
  if(length)

  int mid = floor((rhs-lhs)/2)+lhs;
  swap(lhs, mid, data);

  int pivot = lhs;
  int i = lhs+1;
  int j = rhs;

  while(j >= i){
    if(data[i] > data[pivot] && data[pivot] > data[j]){
      swap(i, j, data);
    }

    if(data[i] <= data[pivot]) i++;
    if(data[j] >= data[pivot]) j--;
  }
  swap(pivot, j, data);

  quickSort(data, lhs, j-1);
  quickSort(data, j+1, rhs);
};


int main() {
  int data[10] ={8,5,2,1 ,6, 5, 6,56, 89,4};
  int size = 10;
  quickSort(data, 0, 9);

  for(int i =0; i < 10; i++){
    cout << data[i] << endl;
  }
  return 0;
} 

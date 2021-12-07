#include <iostream>
#include <cmath>
using namespace std;


void swap(int i, int j, int data[]){
  int temp = data[i];
  data[i] = data[j];
  data[j] = temp;
}

void helper_func(int current, int end, int data[], int count){

  while(current <= end){
    int left = (current * 2) + 1;
    int right = (current * 2) + 2;

    bool inBound_left = 0 <= left && left <= count;
    bool inBound_right = 0 <= right && right <= count;

    int val1 = inBound_left ? data[left] : 0;
    int val2 = inBound_right ? data[right] : 0;

    int toSwap = val1 > val2 ? left : right;
    
    //Had to add inBound_toSwap and debug it since even without this bool, it works on replit.... 
    bool inBound_toSwap = 0 <= toSwap && toSwap <= count;
    if(!inBound_toSwap) return;


    if(data[current] < data[toSwap]){
      swap(current, toSwap, data);
      current = toSwap;
    } else {
      return;
    }

  }
  
}

void heapify(int data[], int count){
  //ensure that we will pass all the values inorder

  for(int i = floor((count-1-1)/2); i >= 0; i--){
    helper_func(i, count, data, count);
  }

}


void show_array(int data[], int count){
  //show the contents of our array

  for(int i = 0; i < count; i++){
    cout << data[i] << ",";
  }

}

bool is_max_heap(int data[], int count){


  for(int i = 0; i < count; i++){
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;

    bool inBound_left = 0 <= left && left <= count;
    bool inBound_right = 0 <= right && right <= count;

    int val1 = inBound_left ? data[left] : 0;
    int val2 = inBound_right ? data[right] : 0;
    

    
    if(val1 > data[i] || val2 > data[i]){
      return false;
    }
  }

   return true;
};

int main() {

  //create an array with 1000 values
  int size = 1000;
  int data[size];
  
  int count = 0;

  

  while(count < size){
    cout << "Enter all the values for the Heap - Enter '-1' to exit" << endl; 
    cin >> data[count];
    if(data[count] == -1) break;
    count++;
  } 
  
   heapify(data, count);
  show_array(data, count);

  if(is_max_heap(data, count)){
    cout << "array is a verified max-heap" << endl;
  } else {
    cout << "array is not a verified max-heap" << endl;
  }

  return 0;
} 
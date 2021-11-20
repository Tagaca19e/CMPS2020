
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
//added string
#include <string.h> 


using namespace std;

//fill the array random
void fill_array_random(int array[], int size, int lbounds, int ubounds) {

  //This will generate the random number

  for (int i = 0; i < size; i++) {
    int num = (rand() % (ubounds - lbounds)) + lbounds;
    array[i] = num;
  }

}


// fill the array increasing
void fill_array_inc(int array[], int size) {

  for (int i = 0; i < size; i++) {
    array[i] = i + 1;
  }

}

//fill the array decreasing

void fill_array_dec(int array[], int size) {
  int count = size;
  for (int i = 0; i < size; i++) {
    array[i] = size - i;
  }

}

//All three fill methods have
//Time O(n) 
//Space O(n) 
// where n is the length of our array

void swap(int left, int right, int array[]) {

  int temp;
  temp = array[left];
  array[left] = array[right];
  array[right] = temp;
}

//bubble sort

void bubble_sort(int array[], int size) {

  bool isSorted = false;

  while (!isSorted) {
    isSorted = true;

    for (int i = 1; i < size; i++) {
      if (array[i] < array[i - 1]) {

        //helper function
        swap(i, i - 1, array);
        isSorted = false;
      }

    }
  }
}
//Time O(n^2)
  

//insertion sort

void insertion_sort(int array[], int size) {
  int j = 0;
  for (int i = 1; i < size; i++) {
    j = i;

    while (array[j] < array[j - 1] && j > 0) {
      swap(j, j - 1, array);
      j--;
    }
  }
 
cout << "this is insertion" << endl;
}
//Time O(n^2)




//selection sort


void selection_sort(int array[], int size){

  for(int i = 0; i < size; i++){
    int smallest = i;
    for(int j = i+1; j < size; j++){
      if(array[smallest] > array[j]) smallest = j;
    }
    swap(smallest, i, array);
  }
}


//show the values of the array

void show(int array[], int size) {
cout << "======RESULT======" << endl;
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
}
//Time O(n)


int main() {
    srand(time(NULL));
//I know we were not suppose to add the insertion part but I just added it for functionality :D

//isWhat determines what to call : insertion or bubble.
   int arraysize, isWhat;

  cout << "What is the data size?" << endl;
  cin >> arraysize;
  cout << "ENTER: 1 for BUBBLE - 2 for INSERTION - 3 for SELECTION" << endl;
  cin >> isWhat;
  int array[arraysize];


  //Make our output dynamic for displaying what we are using to sort : the bubble was static I did not like it :(
  string hello = "";
  if(isWhat == 1) {
    hello = "BUBBLE";
  } else if(isWhat == 2){
    hello = "INSERTION";
  } else if(isWhat == 3){
    hello = "SELECTION";
  }

  cout << hello << " sort (Random) took ";

  fill_array_random(array, arraysize, 1000, 1000000);

  auto start = chrono::steady_clock::now();


  if(isWhat == 1) {
    bubble_sort(array, arraysize);
  } else if(isWhat == 2){
    insertion_sort(array, arraysize);
  } else if(isWhat == 3) {
    selection_sort(array, arraysize);
  }



  auto end = chrono::steady_clock::now();
  cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;

  cout << hello << " sort (Increasing) took ";
  fill_array_inc(array, arraysize);




  start = chrono::steady_clock::now();
  if(isWhat == 1) {
    bubble_sort(array, arraysize);
  } else if(isWhat == 2){
    insertion_sort(array, arraysize);
  } else if(isWhat == 3) {
    selection_sort(array, arraysize);
  }


  end = chrono::steady_clock::now();
  cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;

  cout << hello << " sort (Decreasing) took ";
  fill_array_dec(array, arraysize);

  start = chrono::steady_clock::now();
  if(isWhat == 1) {
    bubble_sort(array, arraysize);
  } else if(isWhat == 2){
    insertion_sort(array, arraysize);
  } else if(isWhat == 3) {
    selection_sort(array, arraysize);
  }

  end = chrono::steady_clock::now();
  cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;
  // This will show that it is sorted
  show(array, arraysize);


  return 0;

}
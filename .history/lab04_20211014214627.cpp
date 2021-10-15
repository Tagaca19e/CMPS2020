#include <iostream>

using namespace std;

void fill(int * array, int start, int end) {
  for (int i = 0; i < 100; i++) {
    if (start < end) {
      *(array + i) = i + 1;
    } else {
      *(array + i) = start - i;
    }
  }
}

int sum(int * array) {
  int result = 0;
  for (int i = 0; i < 100; i++) {
    result += array[i];
  }
  return result;
}

int gauss_sum(int * fw, int * bw) {
  int sum = 0;
  for (int i = 0; i < 100; ++i) {
    sum += fw[i] + bw[i];
  }
  return sum / 2;
}

int main() {
  int forward[100], backward[100];
  int total, gauss_total;

  // fill arrays
  fill(forward, 1, 100); // fills forward array with 1 through 100
  fill(backward, 100, 1); // fills backward array with 100 through 1

  total = sum(forward); 

  // cout << total << endl;

  gauss_total = gauss_sum(forward, backward);
  // cout << gauss_total << endl; 
  cout << "Gauss was ";
  cout << ((total == gauss_total) ? "right" : "wrong") << endl;
  return 0;
}

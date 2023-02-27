#include <iostream>
using namespace std;
void countSort(int array[], int size) {
  int aux[10];
  int freq[10];
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  
  for (int i = 0; i <= max; ++i) {
    freq[i] = 0;
  }

 
  for (int i = 0; i < size; i++) {
    freq[array[i]]++;
  }

 
  for (int i = 1; i <= max; i++) {
    freq[i] += freq[i - 1];
  }

 
  for (int i = size - 1; i >= 0; i--) {
    aux[freq[array[i]] - 1] = array[i];
    freq[array[i]]--;
  }

 
  for (int i = 0; i < size; i++) {
    array[i] = aux[i];
  }
}
int main() {
  int *array;
  int n;
  cout<<"Enter size of array"<<endl;
  cin>>n;
  cout<<"Enter elements"<<endl;
  array=(int*)malloc(n*sizeof(int));
  for (int i = 0; i < n; i++)
    cin>>array[i];
  countSort(array, n);
  cout<<"After count sort"<<endl;
  for (int i = 0; i < n; i++)
    cout << array[i] << " ";
  cout << endl;
}

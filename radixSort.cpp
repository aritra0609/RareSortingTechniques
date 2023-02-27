#include <iostream>
using namespace std;
void countSort(int array[], int size,int pos) {
  int aux[10];
  int freq[10];
  
  for (int i = 0; i < 10; ++i) {
    freq[i] = 0;
  }
  
  for (int i = 0; i < size; i++) {
    freq[(array[i]/pos)%10]++;
  }
  
  for (int i = 1; i <10; i++) {
    freq[i] += freq[i - 1];
  }
  
  for (int i = size - 1; i >= 0; i--) {
    aux[--freq[(array[i]/pos)%10]] = array[i];
  }
  
  for (int i = 0; i < size; i++) {
    array[i] = aux[i];
  }
  
}
void radixSort(int array[], int size){
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  
  for (int pos=1;max/pos>0;pos*=10) {
    countSort(array,size,pos);
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
  radixSort(array, n);
  cout<<"After count sort"<<endl;
  for (int i = 0; i < n; i++)
    cout << array[i] << " ";
  cout << endl;
}

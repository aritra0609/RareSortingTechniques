#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bucketSort(float *array, int size) {
   vector<float> bucket[size];
   for(int i = 0; i<size; i++) { 
      bucket[int(size*array[i])].push_back(array[i]);
   }
   for(int i = 0; i<size; i++) {
      sort(bucket[i].begin(), bucket[i].end()); 
   }
   int index = 0;
   for(int i = 0; i<size; i++) {
      while(!bucket[i].empty()) {
         array[index++] = *(bucket[i].begin());
         bucket[i].erase(bucket[i].begin());
      }
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   float arr[n]; 
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: "<<endl;
    for(int i = 0; i<n; i++)
      cout << arr[i] <<endl;
   cout << endl;
   bucketSort(arr, n);
   cout << "Array after Sorting: "<<endl;
    for(int i = 0; i<n; i++)
      cout << arr[i] <<endl;
   cout << endl;
}

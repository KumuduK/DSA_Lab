#include <iostream>
#include <bits/stdc++.h>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root){
   // build heapify
   int top = root; 
   int left = 2*root + 1; 
   int right = 2*root + 2;

   if (left < n && arr[left] > arr[top])
      top = left;

   if (right < n && arr[right] > arr[top])
      top = right;

   if (top != root) {
      swap(arr[root], arr[top]);
      heapify(arr, n, top);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n){
   // build heap
   for (int j=n/2 - 1; j>=0; j--)
      heapify(arr, n, j);

   for (int k=n-1; k>=0; k--) {
      swap(arr[0], arr[k]);
      heapify(arr, k, 0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   clock_t time_req;
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   time_req = clock();
   heapSort(heap_arr, n);
   time_req = clock() - time_req;
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);

   cout << "Time taken is : " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
}

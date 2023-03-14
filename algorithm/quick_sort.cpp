#include <stdio.h>

/**
  QuickSort
*/
void QuickSort(int arr[], int left, int right) {
  
  int i,j;

  if(left < right) {

    // 取基点
    int pivot = arr[left];
    i = left - 1;
    j = right + 1;

    while(i < j) {

      do { i++; } while(arr[i] < pivot); 
      do { j--; } while(arr[j] > pivot);

      if(i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }

    }

    QuickSort(arr, left, j);
    QuickSort(arr, j + 1, right);

  }
}

void printfArr(int arr[], int arrLength) {

  int i;
  for( i = 0; i < arrLength; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  printf("\n");
} 

int main() {

  int arr[] = {9,8,7,6,5,4,3,2,1};
  int arr2[] = {1,1,1,1,1,1,1,1,1};
  int arr3[] = {1,2,3,3,2,1};

  int arrLength = sizeof(arr)/4;
//  int arrLength2 = sizeof(arr2)/4;
//  int arrLength3 = sizeof(arr3)/4;

  
  QuickSort(arr, 0, arrLength-1);
//  QuickSort(arr2, 0, arrLength2-1);
//  QuickSort(arr3, 0, arrLength3-1);


  printfArr(arr, arrLength);
//  printfArr(arr2, arrLength2);
//  printfArr(arr3, arrLength3);
  
}
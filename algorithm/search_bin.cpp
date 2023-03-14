#include <stdio.h>

int Search_Bin(int arr[], int key, int arrLength) {
  
  int low, high;

  low = 1;
  high = arrLength;

  while(low <= high) {
    int mid;
		mid = (low + high) / 2;
    if(arr[mid] == key) {
      return mid;
    } else if(key < arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return 0;
}

// 递归
int Search_Bin_2(int arr[], int key, int low, int high) {

  if(low > high) return 0;
  int mid;

  mid = (low + key) / 2;
  if(key == arr[mid]) {
    return mid;
  } else if( key > arr[mid]) {
    Search_Bin_2(arr, key, mid + 1, high);
  } else {
    Search_Bin_2(arr, key, low, mid - 1);
  }

}

int main() {

  int arr[] = {0,1,2,3,4,5,6,7,8,9};

  int i = Search_Bin_2(arr,4,0,10);
  printf("%d", i);
}
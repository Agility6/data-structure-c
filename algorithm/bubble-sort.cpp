#include <stdio.h>


void printfArr(int arr[], int arrLength) {

  int i;
  for( i = 0; i < arrLength; i++) {
    printf("arr[%d] = %d ", i, arr[i]);
  }

  printf("\n");
}

/**
  1. 第一个for循环是确定比较的次数
  2. 第二个for循环是进行比较

  例子：4,3,2,1
  第一轮：
  3 4 2 1
  3 2 4 1
  3 2 1 4
*/
void BubbleSort(int arr[], int arrLength) {

  int i,j;

  for( i = 0; i < arrLength; ++i) {
    for( j = 0; j < arrLength - i - 1; ++j) {
      // printf("%d -- %d\n", arr[j] , arr[j+1]);
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

}

int main() {

  int arr[] = {9,8,7,6,5,4,3,2,1};
  int arr2[] = {1,1,1,1,1,1,1,1,1};
  int arr3[] = {1,2,3,3,2,1};

  int arrLength = sizeof(arr)/4;
  int arrLength2 = sizeof(arr2)/4;
  int arrLength3 = sizeof(arr3)/4;

  
  BubbleSort(arr, arrLength);
  BubbleSort(arr2, arrLength2);
  BubbleSort(arr3, arrLength3);

  printfArr(arr, arrLength);
  printfArr(arr2, arrLength2);
  printfArr(arr3, arrLength3);

}
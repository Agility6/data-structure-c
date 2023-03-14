#include <stdio.h>

/**
  选择排序
  1. 第一层循环记录下标的数视为为最小(minIndex)
  2. 第二层循环找到数组后面最小的数字
  3. 如果minIndex发生改变说明产生最小的数
*/
void swap(int *i, int *j);
void SelectSort(int arr[], int arrLength) {

  int i, j;
  int minIndex;

  for( i = 0; i < arrLength; i++) {
    minIndex = i;
    for( j = i + 1; j < arrLength; j++) {
      if(arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    if(i != minIndex) {
      swap(&arr[i], &arr[minIndex]);
//      int temp = arr[i];
//      arr[i] = arr[minIndex];
//      arr[minIndex] = temp;
    }
  }
}

/**
  交换函数
  swap
*/
void swap(int *i, int *j) {
  
  int temp = *i;
  *i = *j;
  *j = temp;

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
  int arrLength2 = sizeof(arr2)/4;
  int arrLength3 = sizeof(arr3)/4;

  
  SelectSort(arr, arrLength);
  SelectSort(arr2, arrLength2);
  SelectSort(arr3, arrLength3);

  printfArr(arr, arrLength);
  printfArr(arr2, arrLength2);
  printfArr(arr3, arrLength3);

}
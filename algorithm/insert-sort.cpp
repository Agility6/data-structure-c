#include <stdio.h>


/**
  1.循环如果前面的值大于后面的值(取出小的数)
    - 再次循环与当前循环前面的数比较
*/
void insertSort(int arr[], int arrLength) {

  int i, j;

  // 这里从1开始防止越界
  for( i = 1; i < arrLength; i++ ) {
    if( arr[i-1] > arr[i]) {
      int temp = arr[i];
      // 第二次与i之前的数比较
      for( j = i - 1; j >= 0; j--) {
        if(arr[j] > temp) {
          arr[j+1] = arr[j];
          arr[j] = temp;
        }
      }
    }
  }

}

/**
  插入算法的递归实现
*/
void insertSort_2(int arr[], int index, int arrLength) {

  if(index >= 0 && index < arrLength) {
    if(arr[index] < arr[index-1]) {
      int temp = arr[index];
      arr[index] = arr[index - 1];
      arr[index - 1] = temp;
      // 相当于第二层for循环
      insertSort_2(arr, index-1, arrLength);
    }
    // 相当于第一层for循环
    insertSort_2(arr, index + 1, arrLength);
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
  int arrLength2 = sizeof(arr2)/4;
  int arrLength3 = sizeof(arr3)/4;


 insertSort(arr, arrLength);
 insertSort(arr2, arrLength2);
 insertSort(arr3, arrLength3);

  // 递归版
  // insertSort_2(arr, 1, arrLength);
  // insertSort_2(arr2, 1, arrLength2);
  // insertSort_2(arr3, 1, arrLength3);

  printfArr(arr, arrLength);
  printfArr(arr2, arrLength2);
  printfArr(arr3, arrLength3);


}
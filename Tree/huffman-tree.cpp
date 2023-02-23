#include <stdio.h>
#include <stdlib.h>


typedef struct {
  int weight;
  int parent, lch, rch;
} HTNode, *HuffmanTree;

/**
  InitHuffmanTree
  n: treeNodeSum
*/
InitHuffmanTree(HuffmanTree &HT, int n) {

  int i;

  if(n<=1) return;

  m = 2 * n - 1;
  // 分配空间m+1(从1开始存)
  HT = (HTNode*)malloc(sizeof(HTNode)*(m+1));

  for ( i = 1; i <= m; i++) {
    // 初始化lch、rcj、parent都为零
    HT[i].lch = 0;
    HT[i].rch = 0;
    HT[i].parent = 0;
  } 
  
  // 输入weight的值
  for( i = 1; i <= n; i++) {
    scanf("%d", HT[i].weight);
  }

}

/**
  CreatHuffman
*/
CreatHuffman(HuffmanTree &HT, int n) {
  

  // 哈夫曼树的进行初始化
  InitHuffmanTree(HT, n);

   int i; 
  // 循环(2 * n - 1)次，
  for( i = 0; i < (2*n-1); i++) {
    // 寻找两个最小的组成一个新树
    Select(HT, i-1, s1, s2);
    // 相当于从原删除 
    HT[s1].parent = i;
    HT[s2].parent = i;

    // s1,s2分别作为i的左右孩子的
    HT[i].lch = s1;
    HT[i].rch = s2;

    // i的权值为左右孩子权值之和
    HT[i].weight = HT[s1].weight + HT[s2].weight;
  }
  
}


int main() {}
//selection sort
#include<stdio.h>
int swap(int A[],int a,int b){
  int temp;
  temp= A[a];
  A[a]=A[b];
  A[b]=temp;
}
int main(){
    int A[]={8,3,5,9,4,2};
    int n= sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n ;i++){
      int target= A[i];
      int min=i;
      for(int j=i+1;j<n;j++){
        if(A[j]<A[min]){
           min=j;
        }
      }
      if(min != i){
        swap(A,i,min);
      }
    }
    printf("sorted array ");
    printf("[ ");
    for(int i=0;i<n;i++){
      printf("%d ",A[i]);
    }
    printf("]");
}
#include<stdio.h>
int main(){
    int A[]={5,2,4,6,1,3};
    int n= sizeof(A)/sizeof(A[0]);
    


    printf("sorted array ");
    printf("[ ");
    for(int i=0;i<n;i++){
      printf("%d ",A[i]);
    }
    printf("]");
}
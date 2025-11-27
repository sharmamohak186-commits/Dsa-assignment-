#include<stdio.h>
int main(){
    int A[]={5,2,4,6,1,3};
    int n= sizeof(A)/sizeof(A[0]);
    for(int j=0;j<n;j++){
        for(int i=1;i<n-j;i++){
            if(A[i]<A[i-1]){
                int temp;
               temp=A[i];
              A[i]=A[i-1];
             A[i-1]=temp;
            }
    }
}
    printf("sorted array ");
    printf("[ ");
    for(int i=0;i<n;i++){
      printf("%d ",A[i]);
    }
    printf("]");
}
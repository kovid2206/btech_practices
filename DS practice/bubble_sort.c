#include <stdio.h>

// Newton School Online C compiler to run C online.
// Write C code in this online editor and run it.

int main() {
    int a[]={100,16,8,7,9,10,4,0},i,n,j,c;
    n=sizeof(a)/sizeof(a[0]);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(a[j]>a[j+1])
            {
                c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

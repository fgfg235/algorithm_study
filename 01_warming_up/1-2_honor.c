/*
    호너(Horner)법

    자세한 풀이과정 및 설명은 티스토리 블로그에서 확인바랍니다.
*/
#include <stdio.h>

long fn(int, int *, int);

int main(){
    static int a[] = {1,2,3,4,5};
    int x = 2;
    if(x==0){
       printf("fn(%d) = %d\n",x,a[0]);
    } else {
       printf("fn(%d) = %ld\n",x,fn(x,a,4));
    }
}

long fn(int x, int a[], int n) {
    long p;

    p = a[n];
    for(int i = n-1; i >=0; i--) {
        p = p*x+a[i];
    }
    return p;
}
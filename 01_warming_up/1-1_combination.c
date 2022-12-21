/*
    점화식 nCr 계산

    nCr = n! / r!(n-r)!

    위 공식을 적용할 경우 16비트에서는 int 타입 사용 시 10 팩토리얼 이상에서 오버플로우를 발생하므로
    16비트의 마이크로프로세서에서 사용할 경우 long타입을 사용할 것

    nCr (n >= r > 0)
        nCr = n! / r!(n-r)!
                nPr은 n!/(n-r)! 이므로 아래 공식으로 변환할 수 있다.
            = nPr / r! 
            = n * (n-1) * ... * (n-r+1) * (n-r) * (n-r-1) * ... * 3 * 2 * 1
              -------------------------------------------------------------
                          (n-r) * (n-r-1) * .... * 3 * 2 * 1
              -------------------------------------------------------------
                              r * (r-1) * (r-2) * 3 * 2 * 1
            
            =     n * (n-1) * ... * (n-r+1)
              ----------------------------------
                r * (r-1) * (r-2) * 3 * 2 * 1
            
            = (n-r+1)/r * nC(r-1)
        
    nCr (r = 0)
        nCr = 1
*/
#include <stdio.h>

long combination(int,int);

main() {
    int n = 5;
    int r = 4;

    printf("%d C %d = %ld",n,r,combination(n,r));
}

long combination(int n, int r) {
    long p = 1; // 32비트 이상의 프로세서에서는 int 타입을 사용해도 무관
    for(int i = 1; i <= r; i++){
        p=p*(n-i+1)/i;
    }
    return p;
}

/*
    도수분포(히스토그램)

    0~100 사이의 점수를 10점 간격으로 나누어 (0~9, 10~19, ... , 90~99, 100 의 11등급) 각 등급의 도수분포를 구하라
*/
#include <stdio.h>

main(){
    int num = 0;
    int rank, histo[11];

    // num 변수를 입력받아 score 배열 생성
    printf("점수의 개수 : ");
    scanf("%d",&num);

    int score[num];

    // 배열 초기화
    for(int i = 0; i < sizeof(score) / sizeof(int); i++){
        score[i] = 0;
    }
    for(int i = 0; i <= 10; i++){
        histo[i] = 0;
    }

    // score 배열 값 입력
    for(int i = 0; i < sizeof(score) / sizeof(int); i++){
        printf("%d번 째 점수를 입력하시오", i+1);
        scanf("%d", &score[i]);
        if(score[i] < 0 || score[i] > 100) {
            printf("0~100 사이의 숫자를 입력하시오");
            scanf("%d", &score[i]);
        }
    }

    //등급 도수분포를 구해 매핑
    for(int i = 0; i < sizeof(score) / sizeof(int); i++){
        rank = score[i] / 10;
        histo[rank]++;
    }

    // 출력
    for(int i = 0; i <= 10; i++){
        printf("%d - : %d\n", i*10, histo[i]);
    }
}
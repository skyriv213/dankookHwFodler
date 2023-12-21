#include <stdio.h>
#include <string.h>

void problem3_1(){
    int n;
    char p[50];
    printf("3-1 문제입니다\n");
    printf("3-1을 해결하기 위한 훈련장 크기를 입력하시오");
    scanf("%d",&n);
    printf("3-1의 스윙기록을 입력하시오");
    scanf("%s",p);
    // 기존 좌표 및 훈련장 설정 
    int x =0;
    int y =0;

    // 방향 정의
    int dx[4]={0,0,-1,1}; // 아래 x+1, 위 x-1, 우 y+1 좌 y-1
    int dy[4]={1,-1,0,0};
    char move[4]={'R','L','U','D'};
    // 문자열의 크기만큼 for 반복문 시행
    for(int i = 0;i<strlen(p);i++){
        // 문자열을 진행하면서 해당 명령에 맞는 방향 찾기
        // char s = p[i];
        // 방향을 찾으면서(for 반복, 4번의 방향체크) 방향의 결과값이 
        int nx;
        int ny;
        for(int j =0;j<4;j++){
            if(p[i]==move[j]){
               nx =x+dx[j];
               ny = y+dy[j];
            }   
        }
        // 훈련장의 크기를 벗어나면 무효
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
        }else{
            x=nx;
            y=ny;

        }
        // 시작점은 1,1이지만 배열은 0,0부터 시작하므로 최종 결과값에 +1씩 더해서 출력
}
    printf("(%d,%d)\n",x+1,y+1);
}

typedef struct{
    char *word; 
    int row;
    int col;
}arr;

void problem3_2(){
    int n,m;
   
    printf("단어 개수 n을 입력하시오 \n");
    scanf("%d",&n);

    char word[n][100];
    
    printf("단어 목록을 입력하시오 \n");
    for (int i = 0; i < n; i++) {
        scanf("%s", word[i]);
    }

    printf("문서 갯수를 입력하시오\n");
    scanf("%d", &m);  // 문서 개수
    int doc[n][m];

    for(int i =0; i<n;i++){
        for(int j =0;j<m;j++){
        scanf("%d", &doc[i][j]);
        }
    }

    for(int i = 0 ;i<n;i++){
        for(int j =0;j<m;j++){
            if(doc[i][j]!=0){
                printf("%s 문서%d %d\n", word[i], j + 1, doc[i][j]);
            }
        }
    }

}

int main(){
    printf("3-1 문제입니다");
    problem3_1();
    printf("3-2 문제입니다");
    problem3_2();
}
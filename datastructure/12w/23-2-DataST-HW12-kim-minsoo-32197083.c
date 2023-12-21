#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TREE_SIZE 100
#define N 10
#define CALCULATE_M(n) (pow(2, (n + 1)) - 1)

// 일반 트리의 노드 구조체 정의
struct Node {
    int data;
    struct Node* firstChild; // 첫 번째 자식 노드
    struct Node* nextSibling; // 형제 노드
};

// 이진 트리의 노드 구조체 정의
struct BinaryNode {
    int data;
    struct BinaryNode* left; // 왼쪽 자식 노드 (첫 번째 자식)
    struct BinaryNode* right; // 오른쪽 자식 노드 (형제 노드)
};

// 일반 트리의 노드를 이진 트리의 노드로 변환하는 함수
struct BinaryNode* convertToBinary(struct Node* root) {
    if (root == NULL)
        return NULL;

    // 새로운 이진 트리 노드 생성
    struct BinaryNode* newNode = (struct BinaryNode*)malloc(sizeof(struct BinaryNode));
    newNode->data = root->data; // 데이터 복사

    // 첫 번째 자식 노드를 왼쪽 자식 노드로 설정
    newNode->left = convertToBinary(root->firstChild);

    // 형제 노드를 오른쪽 자식 노드로 설정
    newNode->right = convertToBinary(root->nextSibling);

    return newNode;
}

void problem_12_1() {
    // 배열기반 트리
    int n, k, i;
    printf("나무의 가지 단계 n과 울음소리 k 입력: ");
    scanf("%d %d", &n, &k);

    // n이 2보다 작은 경우 1 1 1 1 1 1 1 0 0 1 1 0 0 0 1
    if (n < 2) {
        printf("n은 2보다 커야 합니다.\n");
        return;
    }

    // 가지에 대한 정보가 입력되지 않은 경우
    if (k > CALCULATE_M(n)) {
        printf("울음소리 k는 나무의 가지 단계 n보다 작거나 같아야 합니다.\n");
        return;
    }

    int m = CALCULATE_M(n);

    int *tree = (int *)malloc(m * sizeof(int));
    printf("가지에 대한 정보 m개 입력: ");
    tree[0]= 0;
    for (i = 1; i <= m; i++) {
        scanf("%d", &tree[i]);
    }

    i = 1;
    while (i <= CALCULATE_M(k)) {
        if (tree[i * 2] == 0) {
            if (tree[i * 2 + 1] == 0) {
                printf("%d ", i);
                i+=1;
            } else {
                i += 1;
            }
        } else {
            i += 1;
        }
    }

    free(tree);
}


void problem_12_3(){

}

void problem_12_4(){
 
}

int main() {
    problem_12_1();
    printf("\n");
    // problem_12_2();
    // printf("\n");
    // problem_12_3();
    // printf("\n");
    // problem_12_4();
    return 0;
}

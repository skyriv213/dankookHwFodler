#include <stdio.h>
#include <stdlib.h>

// 구조체 정의: 이진 트리 노드
typedef struct BinaryTreeNode {
    char data; // 노드 데이터
    struct BinaryTreeNode* leftChild; // 왼쪽 자식 노드를 가리키는 포인터
    struct BinaryTreeNode* rightSibling; // 오른쪽 형제 노드를 가리키는 포인터
} BinaryTreeNode;

// 구조체 정의: 일반 트리 노드
typedef struct TreeNode {
    char data; // 노드 데이터
    struct TreeNode* firstChild; // 첫 번째 자식 노드를 가리키는 포인터
    struct TreeNode* nextSibling; // 형제 노드를 가리키는 포인터
} TreeNode;

// 트리 초기화 함수
TreeNode* initializeTree(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

// 일반 트리를 이진 트리로 변환하는 함수
BinaryTreeNode* convertToBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    // Create a new binary tree node using the data from the root of the general tree
    BinaryTreeNode* binaryRoot = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    binaryRoot->data = root->data;
    binaryRoot->leftChild = convertToBinaryTree(root->firstChild);

    // Connect the siblings in the binary tree
    BinaryTreeNode* binarySibling = binaryRoot->leftChild;

    while (root->nextSibling != NULL) {
        binarySibling->rightSibling = convertToBinaryTree(root->nextSibling);
        binarySibling = binarySibling->rightSibling;
        root = root->nextSibling;
    }

    return binaryRoot;
}

// 이진 트리를 시계 방향으로 45도 회전하는 함수 (출력용)
void rotateBinaryTree(BinaryTreeNode* root, int level) {
    if (root == NULL) {
        return;
    }

    rotateBinaryTree(root->rightSibling, level + 1);

    for (int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("%c\n", root->data);

    rotateBinaryTree(root->leftChild, level + 1);
}

// 트리 출력 함수 (시계 방향으로 45도 회전)
void printTree(BinaryTreeNode* root) {
    if (root == NULL) {
        return;
    }

    rotateBinaryTree(root, 0);
}

int main() {
    // 예제 트리 생성
    TreeNode* root = initializeTree('A');
    root->firstChild = initializeTree('B');
    root->firstChild->firstChild = initializeTree('E');
    root->firstChild->firstChild->nextSibling = initializeTree('F');
    root->firstChild->nextSibling = initializeTree('C');
    root->firstChild->nextSibling->firstChild = initializeTree('G');
    root->firstChild->nextSibling->nextSibling = initializeTree('D');
    root->firstChild->nextSibling->nextSibling->firstChild = initializeTree('H');
    root->firstChild->nextSibling->nextSibling->firstChild->nextSibling = initializeTree('I');
    root->firstChild->nextSibling->nextSibling->firstChild->nextSibling->nextSibling = initializeTree('J');
    root->firstChild->firstChild->nextSibling->firstChild = initializeTree('K');
    root->firstChild->firstChild->nextSibling->firstChild->nextSibling = initializeTree('L');


    


    // 일반 트리 출력
    printf("General Tree:\n");
    printTree(root);

    // 일반 트리를 이진 트리로 변환
    BinaryTreeNode* binaryRoot = convertToBinaryTree(root);

    // 이진 트리 출력
    printf("\nBinary Tree:\n");
    printTree(binaryRoot);

    return 0;
}


// A는 루트 노드이다
// A는 B,C,D라는 자식 노드를 가지고 있다
// B는 E,F라는 자식 노드를 가지고 있다
// C는 G라는 자식 노드를 가지고 있다
// D는 H,I,J라는 자식 노드를 가지고 있다
// F는 K,L의 자식 노드를 가지고 있다

// 변환과정은 다음과 같다, 
// 기존의 일반 트리에서 각 노드의 첫번째 자식 노드 간선만 남기고 나머지 간선을 제거한다.
// 그러고 난 뒤에 형제 노드끼리 간선을 연결한다.
// 간선의 정리작업이 다 끝난 트리를 시계방향으로 45도 회전 시키면 이진트리가 된다.

// E는 루트노드이다
// E는 B,F를 자식 노드로 가지고 있다.
// B는 A와 C를 자식 노드로 가지고 있다.
// F는 K를 자식 노드로 가지고 있다.
// K는 L을 자식노드로 가지고 있다.
// C는 G, D의 자식 노드를 가지고 있다.
// D는 H라는 자식 노드를 가지고있다.
// H는 I라는 자식 노드를 가지고있다.
// I는 J라는 자식 노드를 가지고있다.
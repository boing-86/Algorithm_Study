#include <stdio.h>
#include <stdlib.h>

// 트리 노드 정의
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// 새로운 트리 노드 생성
TreeNode* createNode(int data) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 이진 탐색 트리에 값 삽입
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// 전위 순회 배열을 사용하여 BST 생성
TreeNode* constructBST(int preorder[], int size) {
    if (size == 0) return NULL;

    TreeNode* root = createNode(preorder[0]);
    for (int i = 1; i < size; ++i) {
        insert(root, preorder[i]);
    }
    return root;
}

// 후위 순회를 수행하는 함수
void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d\n", root->data);
}

int main() {
    int preorder[10000];
    int size = 0;

    // 입력 받기
    while (scanf("%d", &preorder[size]) != EOF) {
        size++;
    }

    // BST 생성
    TreeNode* root = constructBST(preorder, size);

    // 후위 순회 결과 출력
    postorderTraversal(root);

    return 0;
}

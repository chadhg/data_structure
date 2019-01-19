#include"nolinear_include/binarytree.h"

/***************从前序、中序遍历推出整个二叉树***************/
void ReBuild(char *pPreOrder, char *pInOrder, int nTreeLen, BinaryTreeNode<char>** pRoot){
    if(pPreOrder == nullptr || pInOrder == nullptr)     // 检查边界条件
        return;
    BinaryTreeNode<char> *temp = new BinaryTreeNode<char>(*pPreOrder);  // 获取前序遍历的第一个结点(根结点)
    if(*pRoot == nullptr) *pRoot = temp;                // 如果结点为空，把当前结点复制到根结点
    if(nTreeLen == 1) return;                           // 如果当前树长为1，那么已经是最后一个结点
    // 寻找子树长度
    char* pOrgInOrder = pInOrder;
    char* pLeftEnd = pInOrder;
    int nTempLen = 0;
    // 找到左子树的结尾
    while (*pPreOrder != *pLeftEnd) {
        if(pPreOrder == nullptr || pLeftEnd == nullptr)
            return;
        // 记录临时长度，以免溢出
        nTempLen++;
        if(nTempLen > nTreeLen) break;
        pLeftEnd++;
    }
    int nLeftLen = static_cast<int>(pLeftEnd - pOrgInOrder);    // 寻找左子树长度
    int nRightLen = nTreeLen - nLeftLen - 1;    // 寻找右子树长度
    if(nLeftLen > 0){                           // 重建左子树
        BinaryTreeNode<char> *left = (*pRoot)->getLeftNode();
        ReBuild(pPreOrder+1, pInOrder, nLeftLen, &left);
    }
    if(nLeftLen > 0){                           // 重建右子树
        BinaryTreeNode<char> *right = (*pRoot)->getRightNode();
        ReBuild(pPreOrder+nLeftLen+1, pInOrder+nLeftLen+1, nRightLen, &right);
    }
}

#include<iostream>
using namespace std;

/***************二叉树的线性表示***************/
template<typename DataType> class SeqBT{
public:
    SeqBT(int nodes){
        if(nodes > 0){
            maxNode = nodes;
            data = new DataType{maxNode};
        }
    }
    ~SeqBT(){
        delete [] data;
    }
private:
    int maxNode;
    DataType *data;
};


template<typename DataType> class BinaryTree;
/***************二叉树结点定义***************/
template<class DataType> class BinaryTreeNode{
public:
    friend class BinaryTree<DataType>;
    /**********构建空结点**********/
    BinaryTreeNode(){
        data = NULL;
        lChild = NULL;
        rChild = NULL;
    }
    /**********构建一个指定数据域的结点**********/
    BinaryTreeNode(DataType newData){
        data = newData;
        lChild = rChild = NULL;
    }
    /**********获取数据域**********/
    DataType getData(){
        if(data != NULL)
            return data;
        return NULL;
    }
    /**********获取左子树**********/
    BinaryTreeNode<DataType>* getLeftNode(){
        return lChild;
    }
    /**********获取右子树**********/
    BinaryTreeNode<DataType>* getRightNode(){
        return rChild;
    }
private:
    DataType data;              // 数据域
    BinaryTreeNode *lChild;     // 左子树指针
    BinaryTreeNode *rChild;     // 右子树指针
};
/***************二叉树定义***************/
template<typename DataType> class BinaryTree{
public:
    BinaryTree(){
        root = new BinaryTreeNode<DataType>();
    }
    ~BinaryTree(){
        BinaryTreeNode<DataType> *node = root;
        if(node != NULL){
            destroyBT(node->lChild);
            destroyBT(node->rChild);
            delete node;
        }
        delete root;
    }
    void preOrder(BinaryTreeNode<DataType> *node);      // 先序遍历
    void inOrder(BinaryTreeNode<DataType> *node);       // 中序遍历
    void postOrder(BinaryTreeNode<DataType> *node);     // 后序遍历
    void layOrder(BinaryTreeNode<DataType> *node);      // 层序遍历
    BinaryTreeNode<DataType>* parentNode(BinaryTreeNode<DataType> *node);   // 求父结点
    BinaryTreeNode<DataType>* brotherNode(BinaryTreeNode<DataType> *node);  // 求兄弟结点
    int getDepth(int numberofNodes);                    // 求深度
    void insertSubBT(BinaryTree<DataType> *bt, BinaryTreeNode<DataType> *node); // 插入子二叉树
    void deleteNodes(BinaryTreeNode<DataType> *node);   // 删除所有结点
    bool deleteSubTree(BinaryTreeNode<DataType> *node, int i);  // 删除子树,i为选择数,1为左子树,2为右子树,3为左右子树
    void destroyBT(BinaryTreeNode<DataType> *node);     // 销毁二叉树
    int getDepthofNode(DataType i);                     // 求结点i的深度
private:
    BinaryTreeNode<DataType> *root;
};

/***************先序遍历（根-左-右）***************/
template<typename DataType> void BinaryTree<DataType>::preOrder(BinaryTreeNode<DataType> *node){
    if(node != NULL){
        cout << node->getData() << endl;
        preOrder(node->getLeftNode());
        preOrder(node->getRightNode());
    }
}
/***************中序遍历（左-根-右）***************/
template<typename DataType> void BinaryTree<DataType>::inOrder(BinaryTreeNode<DataType> *node){
    if(node != NULL){
        inOrder(node->getLeftNode());
        cout << node->getData() << endl;
        inOrder(node->getRightNode());
    }
}
/***************后序遍历（左-右-根）***************/
template<typename DataType> void BinaryTree<DataType>::postOrder(BinaryTreeNode<DataType> *node){
    if(node != NULL){
        postOrder(node->getLeftNode());
        postOrder(node->getRightNode());
        cout << node->getData() << endl;
    }
}
/***************层序遍历（广度优先）***************/
template<typename DataType> void BinaryTree<DataType>::layOrder(BinaryTreeNode<DataType> *node){
    int max = 50;                               // 队列大小，不知道树的大小之前尽量设置大一点
    int front, rear;                            // 设置队首队尾
    BinaryTreeNode<DataType> *current;          // 设置指向当前结点的指针
    int count = 0;                              // 队列中的元素个数
    if(node != NULL){                           // 判断初始结点是否为空
        DataType *queue = new DataType[max];    // 为队列申请空间
        front = rear = 0;                       // 初始化队列指针
        queue[rear] = node;                     // 将初始根节点入队
        rear++;                                 // 队尾指针后移
        count++;                                // 元素个数+1
        while (count != 0) {                    // 判断队列元素是否完全出队
            current = queue[front];             // 队首元素出队，设置为当前结点
            cout << current->getData() << endl; // 输出队首元素
            if(current->getLeftNode() != NULL){ // 判断出队元素的左子结点是否为空，若不为空，则入队
                queue[rear] = current->getLeftNode();
                rear = (rear+1) % max;
                count++;
            }
            if(current->getRightNode() != NULL){ // 判断出队元素的右子结点是否为空，若不为空，则入队
                queue[rear] = current->getRightNode();
                rear = (rear+1) % max;
                count++;
            }
            front = (front+1) % max;
            count--;
        }
    }
}
/***************求父结点***************/
template<typename DataType> BinaryTreeNode<DataType>* BinaryTree<DataType>::parentNode(BinaryTreeNode<DataType> *node){
    if(node == NULL || node == root)
        return NULL;
    int max = 50;                               // 队列大小，不知道树的大小之前尽量设置大一点
    int front, rear;                            // 设置队首队尾
    BinaryTreeNode<DataType> *current, *child;  // 设置指向当前结点的指针和指向孩子结点的指针
    int count = 0;                              // 队列中的元素个数
    if(node != NULL){                           // 判断初始结点是否为空
        DataType *queue = new DataType[max];    // 为队列申请空间
        front = rear = 0;                       // 初始化队列指针
        queue[rear] = node;                     // 将初始根节点入队
        rear++;                                 // 队尾指针后移
        count++;                                // 元素个数+1
        while (count != 0) {                    // 判断队列元素是否完全出队
            current = queue[front];             // 队首元素出队，设置为当前结点
            cout << current->getData() << endl; // 输出队首元素
            if(current->getLeftNode() != NULL){ // 判断出队元素的左子结点是否为空，若不为空，则入队
                child = current->getLeftNode();
                if(child == node)               // 比较出队结点的左孩子结点与指定结点
                    return current;             // 若相等，则返回出队结点
                queue[rear] = child;
                rear = (rear+1) % max;
                count++;
            }
            if(current->getRightNode() != NULL){ // 判断出队元素的右子结点是否为空，若不为空，则入队
                child = current->getRightNode();
                if(child == node)               // 比较出队结点的右孩子结点与指定结点
                    return current;             // 若相等，则返回出队结点
                queue[rear] = child;
                rear = (rear+1) % max;
                count++;
            }
            front = (front+1) % max;
            count--;
        }
        return NULL;
    }
}
/***************求兄弟结点***************/
template<typename DataType> BinaryTreeNode<DataType>* BinaryTree<DataType>::brotherNode(BinaryTreeNode<DataType> *node){
    if(node == NULL)
        return NULL;    // 判断指定结点是否为空
    BinaryTreeNode<DataType> *parent = BinaryTree<DataType>::parentNode(node);
    if(parent == NULL)
        return NULL;
    if(parent->lChild == node)
        return parent->rChild;
    if(parent->rChild == node)
        return parent->lChild;
}
/***************求深度***************/
template<typename DataType> int BinaryTree<DataType>::getDepth(int numberofNodes){    // 参数是设计的栈的大小，一般设为二叉树的结点数
    BinaryTreeNode<DataType> *nodeStack = new BinaryTreeNode<DataType>[numberofNodes];  // 设置存储二叉树结点的栈
    int depthStack[numberofNodes];      // 存储深度的栈
    int currentDepth, maxDepth=0;       // 当前深度，最大深度
    int top = -1;                       // 栈的游标指针初始值
    BinaryTreeNode<DataType> *node = root;  // 设置当前访问结点指针并初始化为根结点
    if(node != NULL){
        currentDepth = 1;                   // 初始化当前深度为1，根结点为第1层
        /**********循环遍历整棵树，将访问的结点入栈**********/
        // 不断反复查找最长路径
        do{
            while (node != NULL) {
                nodeStack[++top] = node;            // 不为空入栈，空结点停止
                depthStack[top] = currentDepth;     // 相应深度入栈
                node = node->lChild;                // 继续访问当前结点的左孩子
                currentDepth++;                     // 当前深度加1
            }
            node = nodeStack[top];                  // 一条路径走到尽头时，弹出栈顶元素，尝试新路径
            currentDepth = depthStack[top--];
            if(node->lChild == NULL && node->rChild == NULL){       // 判断是否叶子结点
                if(currentDepth > maxDepth)         // 更新最大深度
                    maxDepth = currentDepth;
            }
            node = node->rChild;                    // 访问出栈结点的右子树
            currentDepth++;
        }while (!(node == NULL && top == -1));
    }
    return maxDepth;
}
/***************插入子二叉树***************/
template<typename DataType> void BinaryTree<DataType>::insertSubBT(BinaryTree<DataType> *bt, BinaryTreeNode<DataType> *node){
    if(node == NULL)
        return;
    if(bt->root == NULL)
        return;
    if(node->lChild == NULL)
        node->lChild = bt->root;
    else if (node->rChild == NULL)
        node->rChild = bt->root;
    else{
        BinaryTreeNode<DataType> *p = node->lChild;
        node->lChild = bt->root;
        delete p;
    }
}
/***************删除所有结点***************/
template<typename DataType> void BinaryTree<DataType>::deleteNodes(BinaryTreeNode<DataType> *node){
    if(node != NULL){
        deleteNodes(node->lChild);
        deleteNodes(node->rChild);
        delete node;
    }
}
/***************删除子树***************/
template<typename DataType> bool BinaryTree<DataType>::deleteSubTree(BinaryTreeNode<DataType> *node, int i){
    if(node == NULL)
        return false;
    BinaryTreeNode<DataType> *p;
    switch (i) {
    case 1:
        p = node->lChild;
        deleteNodes(p);
        node->lChild = NULL;
        return true;
    case 2:
        p = node->rChild;
        deleteNodes(p);
        node->rChild = NULL;
        return true;
    case 3:
        p = node->lChild;
        deleteNodes(p);
        node->lChild = NULL;
        p = node->rChild;
        deleteNodes(p);
        node->rChild = NULL;
        return true;
    }
    return false;
}
/***************销毁二叉树***************/
template<typename DataType> void BinaryTree<DataType>::destroyBT(BinaryTreeNode<DataType> *node){
    if(node != NULL){
        destroyBT(node->lChild);
        destroyBT(node->rChild);
        delete node;
    }
    root = NULL;
}
/***************求结点i的深度***************/
template<typename DataType> int BinaryTree<DataType>::getDepthofNode(DataType i){
    const int stackSize = 50;
    BinaryTreeNode<DataType> *nodeStack = new BinaryTreeNode<DataType>[stackSize];  // 设置存储二叉树结点的栈
    int flagStack[stackSize];       // 存储每个结点的状态
    int flag = 0;                   // flag表示每个结点的访问状态，0表示访问一次，1表示访问两次
    int top = -1;                   // 栈的游标指针初始值
    BinaryTreeNode<DataType> *node = root;  // 设置当前访问的结点指针并初始化为根结点
    /**********循环后序遍历树，将访问的结点入栈**********/
    // 检验是否访问的结点就是待求结点
    do{
        while (node != NULL) {
            nodeStack[++top] = node;        // 将访问到的不为空的结点入栈，直至遇到空结点停止
            flagStack[top] = 0;             // 将相应结点访问状态入栈，第一次访问状态为0
            node = node->lChild;            // 继续访问当前结点的左孩子
        }
        node = nodeStack[top];              // 一条路径走到尽头时，出栈栈顶元素尝试新路径
        flag = flagStack[top--];            // 获取结点的访问状态
        if(flag == 0){
            nodeStack[++top] = node;        // 将第一次访问的结点再次入栈
            flagStack[top] = 1;             // 改变相应的访问状态
            node = node->rChild;
        }
        else {
            if(node->data == i)             // 如果结点第2次访问则判断其是否为待求结点
                return top+2;               // 如果找到该结点，则其深度为栈中元素个数+1，即栈顶指针+2
            node = NULL;                    // 如果不是该结点，则继续出栈
        }
    }while(!(node == NULL && top == -1));   // 访问结点为空且栈空时循环结束
}

/*
* 链表
*/
#ifndef LINKLIST_H
#define LINKLIST_H

#include<iostream>

using namespace std;

template <typename DataType> class ListNode;
template <typename DataType> class LinkList     // 链表结构类
{
public:
    LinkList(){     // 无参数构造函数
        head = new ListNode<DataType>();
    }
    LinkList(ListNode<DataType> *firstnode){   // 有参数构造函数
        head = firstnode;
    }
    ~LinkList(){
        delete head;
    }
    bool insertNode(int index, DataType newData);       // 在第index个结点后插入结点
    bool insertNode(DataType newData);                  // 在表尾插入结点
    bool removeNode(ListNode<DataType> *q);             // 删除结点，使head的指针域为空，head的数据域还存在
    ListNode<DataType>* findNode(DataType value);
    void cleanLink();
    DataType getNodeData(const int index);

private:
    ListNode<DataType> *head;
};

template <typename DataType> class ListNode     // 链表结点类
{
public:
    ListNode(){         // 无参数构造函数
        next = NULL;
    }
    ListNode(DataType item, ListNode<DataType> *nextNode=NULL){
        data = item;
        next = nextNode;
    }
    ~ListNode(){
        next = NULL;
    }
    DataType getData(){         // 获取结点内的数据
        return data;
    }
    ListNode* getNext(){        // 获取指针域
        return next;
    }

private:
    friend class LinkList<DataType>;
    DataType *next;
    DataType data;
};


template <typename DataType> bool LinkList<DataType>::insertNode(int i, DataType newData){
    ListNode<DataType> *p = head;       // 初始化游标指针为头结点指针
    int j;
    for(j=0; j<i; j++){
        p = p->next;
        if(p == NULL)       // 如果指针为空，则不存在该结点或者已到表尾
            break;
    }
    if(p == NULL && j<i-1){
        // 指针为空且没有到第i个位置
        cout << "插入位置无效！" << endl;
    }
    ListNode<DataType> *node = new ListNode<DataType>(newData);     // 建立新结点node
    node->next = p->next;
    p->next = node;
    return true;
}
template <typename DataType> bool LinkList<DataType>::insertNode(DataType newData){
    ListNode<DataType> *p = head;
    ListNode<DataType> *node = new ListNode<DataType>(newData);
    if(node == NULL)        // 给新结点分配内存失败
        return false;
    while (p->next != NULL)
        p = p->next;
    p->next = node;
    return true;
}

template <typename DataType> bool LinkList<DataType>::removeNode(ListNode<DataType> *q){
    if(q == NULL){
        cout << "待删除结点不存在！" << endl;
        return false;
    }
    ListNode<DataType> *tempPointer = head;
    while (tempPointer->next != q) {
        tempPointer = tempPointer->next;
    }
    tempPointer->next = q->next;
    delete q;
    return true;
}

template <typename DataType> ListNode<DataType>* LinkList<DataType>::findNode(DataType value){
    ListNode<DataType> *currentPointer = head;
    while (currentPointer != NULL && currentPointer->data != value) {
        currentPointer = currentPointer->next;
    }
    if(currentPointer == NULL){
        cout << "没有找到该结点！程序异常退出！" <<endl;
        exit(1);
    }
    else{
        return currentPointer;
    }
}

template <typename DataType> DataType LinkList<DataType>::getNodeData(const int index){
    ListNode<DataType> *current = head;
    while (head->next != NULL) {
        current = head->next;
        head->next = current->next;
        delete current;
    }
}

#endif // LINKLIST_H

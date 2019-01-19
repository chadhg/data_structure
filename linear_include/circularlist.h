/*
* 循环链表
*/
#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include<iostream>

template<typename DataType> class CircularList;
template<typename DataType> class CircularListNode
{
public:
    friend class CircularList<DataType>;
    CircularListNode(){
        m_next = NULL;
    }
    CircularListNode(DataType data, CircularListNode* nextOne=NULL){
        m_data = data;
        m_next = nextOne;
    }
    ~CircularListNode(){
        m_next = NULL;
    }
    DataType getData();
private:
    CircularListNode* m_next;
    DataType m_data;
};

template<typename DataType> DataType CircularListNode<DataType>::getData(){
    return this->m_data;
}


template<typename DataType> class CircularList
{
public:
    CircularList(){
        head = new CircularListNode<DataType>();
        head->next = head;
    }
    ~CircularList(){
        cleanUp();
        delete head;
    }
    void cleanUp();         // 清空列表
    int getLength();        // 获取循环链表的长度
    CircularListNode<DataType>* findNode(int i, DataType value);    // 查询具有value的第i个元素，并返回其指针
    bool inserNode(DataType data);  // 在链表的尾部插入元素
    bool deleteNode(DataType value);    // 删除具有value值的所有元素
    DataType getValue(CircularListNode<DataType>* node);    // 获取指定元素的值
private:
    CircularListNode<DataType>* head;
};

template<typename DataType> void CircularList<DataType>::cleanUp(){
    CircularListNode<DataType> *p;        // 设置指示删除结点的指针
    while (head->m_next != head) {
        p=head->m_next;                 // 初始化指示指针
        head->m_next = p->m_next;       // 将头指针指向下一个结点的下一个节点
        delete p;                       // 回收空间
    }
}
template<typename DataType> int CircularList<DataType>::getLength(){
    int length = 0;
    CircularListNode<DataType>* p = head;
    while (p->m_next != head) {
        p = p->m_next;
        length++;
    }
    return length;
}
template<typename DataType> CircularListNode<DataType>* CircularList<DataType>::findNode(int i, DataType value){
    int count = 0;
    CircularListNode<DataType>* p = head;
    while (count != i) {
        p = p->m_next;
        if(p->m_data == value){
            count++;    // 记录这是第几个符合条件的结点
        }
        if(p == head){
            return NULL;    // 链表中没有符合条件的结点
        }
    }
    return p;
}
template<typename DataType> bool CircularList<DataType>::inserNode(DataType data){
    CircularListNode<DataType>* p = head;
    CircularListNode<DataType>* node = new CircularListNode<DataType>(data, NULL);
    if(node == NULL){
        return false;
    }
    while (p->m_next != head) {     // 寻找尾结点
        p=p->m_next;
    }
    node->m_next = head;
    p->m_next = node;
    return true;
}
template<typename DataType> bool CircularList<DataType>::deleteNode(DataType value){
    int count = 0;
    CircularListNode<DataType> *p = head->m_next, *l=head;
    while (p != head) {
        if(p->m_data == value){
            l->next = p->m_next;
            delete p;
            count++;
            p=l->m_next;
        }
        else{
            l=p;
            p=p->m_next;
        }
    }
    if(count == 0)
        return false;
    else
        return true;
}
#endif // CIRCULARLIST_H

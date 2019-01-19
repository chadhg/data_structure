/*
* 双向链表
*/
#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include<iostream>
using namespace std;

template<typename DataType> class DoubleList;
template<typename DataType> class DoubleListNode
{
public:
    DataType getData();
private:
    friend class DoubleList<DataType>;
    DoubleListNode():m_pprior(NULL),m_pnext(NULL){}     // 无参构造函数
    DoubleListNode(const DataType item, DoubleListNode<DataType> *prior=NULL, DoubleListNode<DataType> *next=NULL)
        :m_data(item), m_pprior(prior), m_pnext(next){}     // 有参数构造函数
    ~DoubleListNode(){
        m_pprior = NULL;
        m_pnext = NULL;
    }
    DataType m_data;
    DoubleListNode* m_pprior;
    DoubleListNode* m_pnext;
};

template<typename DataType>DataType DoubleListNode<DataType>::getData(){
    return this->m_data;
}


template<typename DataType> class DoubleList
{
public:
    DoubleList(){
        head = new DoubleListNode<DataType>();
    }
    ~DoubleList(){
        cleanDoubleLink();
        delete head;
    }
public:
    void cleanDoubleLink();                         // 清空链表
    int getLength();                                // 获取链表长度
    DoubleListNode<DataType> *findNode(int n=1);    // 寻找第i个结点
    DoubleListNode<DataType> *findData(DataType item);  // 寻找具有给定值数据的结点
    bool insertNode(DataType item, int i=0);            // 在第i个结点之后插入新结点
    bool removeNode(int i=0);                           // 删除第i个结点
    DataType getData(int n=1);                          // 获取第i个结点的数据
private:
    DoubleListNode<DataType> *head;
};

template<typename DataType> void DoubleList<DataType>::cleanDoubleLink(){
    // 清空链表（和销毁链表不一样）
    DoubleListNode<DataType> *pmove = head->m_pnext, *pdel;
    while (pmove!=NULL) {
        pdel = pmove;
        pmove = pdel->m_pnext;
        delete pdel;
    }
    head->m_pnext = NULL;
}
template<typename DataType> int DoubleList<DataType>::getLength(){
    int count = 0;
    DoubleListNode<DataType> *pmove = head->m_pnext;
    while (pmove!=NULL) {
        pmove = pmove->m_pnext;
        count++;
    }
    return count;
}
template<typename DataType> DoubleListNode<DataType>* DoubleList<DataType>::findNode(int n){
    if(n<1){
        cout << "索引位置无效！" << endl;
        return NULL;
    }
    DoubleListNode<DataType> *pmove = head->m_pnext;
    for(int i=1; i<n; i++){
        pmove = pmove->m_pnext;
        if(pmove==NULL){
            cout << "不存在指定结点！" << endl;
            return NULL;
        }
    }
    return pmove;
}
template<typename DataType> DoubleListNode<DataType>* DoubleList<DataType>::findData(DataType item){
    DoubleListNode<DataType> *pmove = head->m_pnext;
    if(pmove == NULL){
        cout << "链表是空表！程序异常退出！" << endl;
        exit(1);
    }
    while(pmove->getData() != item){
        pmove = pmove->m_pnext;
        if(pmove == NULL){
            cout << "没有查找的结点！" << endl;
            exit(1);
        }
    }
    return pmove;
}
template<typename DataType> bool DoubleList<DataType>::insertNode(DataType item, int n){
    if(n<1){
        cout << "插入位置无效！" << endl;
        return 0;
    }
    DoubleListNode<DataType> *newnode = new DoubleListNode<DataType>(item), *pmove=head->m_pnext;
    if(newnode == NULL){
        cout << "内存分配失败，新结点无法创建！" << endl;
        return 0;
    }
    for(int i=1; i<n; i++){
        // 找到插入位置
        pmove = pmove->m_pnext;
        if(pmove==NULL && i<n-1){
            cout << "超出链表长度，插入位置无效！" << endl;
            return 0;
        }
    }
    newnode->m_pnext = pmove->m_pnext;
    if(pmove->m_pnext != NULL){     // 判断是否在尾部添加新结点
        pmove->m_pnext->m_pprior = newnode;
    }
    newnode->m_pprior = pmove;
    pmove->m_pnext = newnode;
    return 1;
}
template<typename DataType> bool DoubleList<DataType>::removeNode(int n){
    if(n<1 || n > getLength()){
        cout << "索引位置无效！" << endl;
        return 0;
    }
    DoubleListNode<DataType> *pmove = head->m_pnext, *pdel;
    for(int i=1; i<n; i++){
        // 找到删除位置
        pmove = pmove->m_pnext;
    }
    pdel = pmove;
    if(pdel->m_pnext!=NULL){        // 判断是否在尾部删除新结点
        pmove->m_pprior->m_pnext = pdel->m_pnext;
        pmove->m_pnext->m_pprior = pdel->m_pprior;
    }
    else {
        pmove->m_pprior->m_pnext = NULL;
    }
    delete pdel;
    return 1;
}
template<typename DataType> DataType DoubleList<DataType>::getData(int n){
    if(n<1 || n > getLength()){
        cout << "索引位置无效！程序异常退出！" << endl;
        exit(1);
    }
    DoubleListNode<DataType> *pmove = head->m_pnext;
    for(int i=1; i<=n; i++){
        pmove = pmove->m_next;
        if(pmove==NULL){
            cout << "指定结点不存在！" << endl;
            return NULL;
        }
    }
    return pmove->m_data;
}
#endif // DOUBLELIST_H

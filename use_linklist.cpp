#include<iostream>
#include"linklist.h"
using namespace std;

/*
 * 求出单链表的倒数第m个结点，不得求出链表长度，不得对链表进行逆转
 * 找到就返回它的地址，否则返回NULL
 *
 * 方法：设置指针p=head，从头指针开始循环执行p=p->next
 * 再设置指针q，并且比指针p落后m-1步，p到链表尾部时q就是倒数第m个
*/
ListNode<int>* searchNodeM(LinkList<int>* link, int m)
{
    ListNode<int>* p = link->getNode(1);    // p初始化为链表第一个结点
    if(p != nullptr && m > 0){
        for(int i=1; i<m; i++){             // 移动p到第m个结点
            p = p->getNext();
            if(p == nullptr)                   // 如果p不存在则返回nullptr
            {
                cout << "该链表没有倒数第m个结点" << endl;
                return nullptr;
            }
        }
    }
    ListNode<int>* q = link->getNode(1);
    while(p->getNext() != nullptr)
    {
        p = p->getNext();
        q = q->getNext();
    }
    return q;
}


/*
 * 判断链表是否有环
 *
 * 方法：追逐法
 * 设置两个指针，一个每次移动一步，一个每次移动两步，有环则两个指针会有相同的时刻
*/
bool isCricleLink(ListNode<int>* head){
    if(head == nullptr)
        return false;
    ListNode<int> *p, *q;
    p = q = head;
    while(q != nullptr && q->getNext() != nullptr){
        p = p->getNext();
        p = q->getNext()->getNext();
        if(p == q)
            break;
    }
    if(p == q && p != nullptr)
        return true;
    return false;
}

/*
 * 找出链表环的起始位置
 *
 * 方法：碰撞点到连接点的距离=头指针到连接点的距离
*/
ListNode<int>* circleStart(ListNode<int> *head){
    if(head == nullptr)
        return nullptr;
    ListNode<int> *p, *q;
    p = q = head;
    while(q != nullptr && q->getNext() != nullptr){
        p = p->getNext();
        q = q->getNext()->getNext();
        if(p == q)
            break;
    }
    if(p == q && p != nullptr){
        q = head;
        while (p != q) {
            p = p->getNext();
            q = q->getNext();
        }
        return p;
    }
    else {
        return nullptr;
    }
}

/*
 * 判断两个链表是否相交
 *
 * 方法：两个链表相交，尾结点也将相同
*/
bool isCrossLink(ListNode<int>* headA, ListNode<int>* headB){
    if(headA == nullptr || headB == nullptr)
        return false;
    ListNode<int> *p, *q;
    p = headA;
    q = headB;
    while (p->getNext() != nullptr) {
        p = p->getNext();
    }
    while (q->getNext() != nullptr) {
        q = q->getNext();
    }
    if(p == q)
        return true;
    else
        return false;
}

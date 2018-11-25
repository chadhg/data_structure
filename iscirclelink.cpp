/*
 * 判断链表是否有环
 *
 * 方法：追逐法
 * 设置两个指针，一个每次移动一步，一个每次移动两步，有环则两个指针会有相同的时刻
*/

#include<iostream>
#include"linklist.h"
using namespace std;

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

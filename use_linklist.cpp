/*
 * 求出单链表的倒数第m个结点，不得求出链表长度，不得对链表进行逆转
 * 找到就返回它的地址，否则返回NULL
 *
 * 方法：设置指针p=head，从头指针开始循环执行p=p->next
 * 再设置指针q，并且比指针p落后m-1步，p到链表尾部时q就是倒数第m个
*/
#include<iostream>
#include"linklist.h"
using namespace std;

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

#ifndef QUEUE_EG1_H
#define QUEUE_EG1_H

#include<iostream>
#include"linear_include/stack_init.h"
using namespace std;

/*
 * 利用栈实现队列功能
 */
template<class T> class QueueFromStack{
public:
    QueueFromStack(int size=10){
        s1 = new Stack<T>(size);
        s2 = new Stack<T>(size);
    }
    ~QueueFromStack(){
        s1->~Stack();
        s2->~Stack();
    }
    bool push(T data);
    T pop();
private:
    Stack<T> *s1;            // 执行入列操作的栈s1
    Stack<T> *s2;            // 执行出列操作的栈s2
    int size;               // 队列大小
};
template<class T> bool QueueFromStack<T>::push(T data){
    if(s2->isEmpty())
        return s1->push(data);      // s2为空，直接入队
    else if (s1->eleNumber() < (size-s2->eleNumber()))
        return s1->push(data);      // 如果s2不为空，s1只能入队size-s2->eleNumber个元素
    else {
        cout << "队列满！" << endl;  // 否则入队失败
        return false;
    }
}
template<class T> T QueueFromStack<T>::pop(){
    T temp;
    if(!s2->isEmpty())
        return s2->pop();           // 如果s2不为空，直接s2出队
    else{
        while (!s1->isEmpty() && s1->eleNumber() > 1) {
            temp = s1->pop();       // 倒入eleNumber-1个元素
            s2->push(temp);         // 倒入s2中
        }
        return s1->pop();           // 将s1中剩下的一个元素弹出
    }
}

#endif // QUEUE_EG1_H

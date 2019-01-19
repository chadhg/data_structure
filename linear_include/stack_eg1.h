#ifndef STACK_EG1_H
#define STACK_EG1_H

#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

/*
* 对栈结构添加一个min()函数，能得到栈的最小元素，满足函数的时间复杂度都是O(1)
* push()存差值，pop()弹出时要加上最小值
*/

template<typename T> class Stack_eg1{
public:
    vector<T> value;            // 定义栈结构，用vector存储元素
    T m_min;                    // 存储最小值
public:
    const T& min();             // 声明min()函数
    void pop();
    void push(const T& n);
    void printValue();          // 获取栈顶元素值
    bool isEmpty();             // 判断栈是否为空
};
template<typename T> const T& Stack_eg1<T>::min(){
    assert(!value.empty());     // 如果栈空，则推出
    return m_min;
}
template<typename T> void Stack_eg1<T>::push(const T &n){
    if(value.empty())           // 如果栈空，则更新最小值
        m_min=n;
    T diff=n-m_min;             // 计算入栈元素与最小值的差值
    value.push_back(diff);      // 差值入栈
    if(diff<0)
        m_min=n;                // 如果差值小于零，则更新最小值
}
template<typename T> void Stack_eg1<T>::pop(){
    assert(!value.empty());     // 如果栈为空，则退出
    T top=value.back();         // 获取栈顶值
    if(top<0)                   // 如果栈顶值为负，则更新最小值
        m_min-=top;
    value.pop_back();           // 弹出元素
}
template<typename T> void Stack_eg1<T>::printValue(){
    assert(!value.empty());
    T originValue;
    T top=value.back();
    if(top<0)
        originValue=m_min;
    else
        originValue=(top)+m_min;
    cout << originValue;
}
template<typename T> bool Stack_eg1<T>::isEmpty(){
    if(value.empty())
        return true;
    else
        return false;
}

#endif // STACK_EG1_H

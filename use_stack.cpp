#include<iostream>
#include"stack.h"
using namespace std;

/*
 * 有一个整数集合{23, 56, 11, 4, 87, 98}，将他们依次输入，要求输出的顺序为11,4,56,98,87,23
*/
int printStack(){
    Stack<int> s = Stack<int>(6);
    int temp = 0;
    s.push(23);
    s.push(56);
    s.push(11);
    temp = s.pop();
    cout << temp << " ";
    s.push(4);
    temp = s.pop();
    cout << temp << " ";
    temp = s.pop();
    cout << temp << " ";
    s.push(87);
    s.push(98);
    temp = s.pop();
    cout << temp << " ";
    temp = s.pop();
    cout << temp << " ";
    temp = s.pop();
    cout << temp << " ";
    return 0;
}

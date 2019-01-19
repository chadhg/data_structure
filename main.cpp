#include <QCoreApplication>
#include "linear_include/seqlist.h"
#include "linear_src/use_linklist.cpp"
#include "linear_include/linklist.h"
#include "linear_src/use_stack.cpp"
#include "linear_src/use_queue.cpp"
#include "linear_src/use_hashtable.cpp"

void use_seqlist();
void use_linklist();
void use_stack();
void use_queue();
void use_hashtable();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    use_seqlist();
//    use_linklist();
//    use_stack();
//    use_queue();
    use_hashtable();
    return 0;
//    return a.exec();
}

void use_seqlist(){
    SeqList<int> list(10);
    for(int i=0; i<10; i++)                     // 插入数据
        list.insertElement(i*10);

    for(int i=0; i<list.getLength(); i++)       // 输出顺序表
        cout << list.getElement(i) << " ";
    cout << endl;

    list.deleteElement(3);                      // 删除数据

    list.changeElement(4, 44);                  // 修改数据

    for(int i=0; i<list.getLength(); i++)       // 输出修改后的顺序表
        cout << list.getElement(i) << " ";
    cout << endl;
}
void use_linklist(){
    LinkList<int> linklist;
    for(int i=0; i<10; i++)                     // 插入数据
        linklist.insertNode(i*10);
    for(int i=1; i<=linklist.getLength(); i++)      // 输出顺序表
        cout << linklist.getNodeData(i) << " ";
    cout << endl;
    ListNode<int>* search = searchNodeM(&linklist, 3);  // 找倒数第三个
    cout << search->getData() << endl;
}
void use_stack(){
//    printStack();
    Stack_Eg1();
}
void use_queue(){
//    printQueue();
    StackQueue();
}
void use_hashtable(){
    printhashtable();
}

#include <QCoreApplication>
#include "seqlist.h"

void use_seqlist();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    use_seqlist();
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


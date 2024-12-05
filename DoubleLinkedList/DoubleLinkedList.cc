#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

void test0(){
    DoubleLinkedList<int> s1;
    s1.addToHead(20);
    s1.addToTail(10);
    s1.addToHead(3);
    s1.print();
    cout<<"---------"<<endl;
    s1.addToHead(2);
    s1.print();
    cout<<"delete tail"<<endl;
    cout<<s1.deleteFromTail()<<endl;
    s1.print();
    cout<<"delete 20"<<endl;
    s1.deleteNode(20);
    s1.print();
    cout<<"delete head"<<endl;
    cout<<s1.deleteFromHead()<<endl;
    s1.print();
}

int main()
{
    test0();
    return 0;
}


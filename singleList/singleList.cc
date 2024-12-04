#include <iostream>
#include "singleList.h"

using namespace std;

singleList::~singleList(){
    for(Node* p;!isEmpty();){
        p = head->next;
        delete head;
        head = p;
    }
}

//头插法
void singleList::addToHead(int el){
    head = new Node(el,head);
    if(tail == 0) tail = head;
}

//尾插法
void singleList::addToTail(int el){
    if(tail != 0){//判断是否有结点
        tail->next = new Node(el);
        tail = tail->next;
    }else
        head = tail = new Node(el);
}

//删除头结点并返回其值
int singleList::delFromHead(){
    int el = head->info;
    Node *tmp = head;
    if(head == tail) head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;
}

//删除尾结点并返回其值
int singleList::delFromTail(){
    int el = tail->info;
    if(head == tail){
        delete head;
        head = tail = 0;
    }else{
        Node* tmp;
        for(tmp = head;tmp->next != tail;tmp = tmp->next);
        delete tail;
        tail = tmp;
        tail->next = 0;
    }
    return el;
}

//删除值为el的结点
void singleList::delNode(int el){
    if(head != 0){
        if(head == tail && el == head->info){//如果只有一个结点且值为想要删除的元素
            delete head;
            head = tail = 0;
        }else if(el = head->info){
            Node *pred,*tmp;
            for(pred = head,tmp = head->next;
                tmp != 0 && !(tmp->info == el);
                pred = pred->next,tmp = tmp->next);
            if(tmp != 0){
                pred->next =tmp->next;
                if(tmp = tail) tail = pred;
                delete tmp;
            }
        }
    }
}

//判断链表内是否有指定值的结点
bool singleList::isSingleList(int el) const{
    Node* tmp;
    for(tmp = head;tmp !=0 && !(tmp->info == el);tmp = tmp->next);
    return tmp != 0;

}

//打印链表信息
void singleList::print() const{
    if(head == 0){
        cout<<"This is a empty List"<<endl;
    }else{
        Node* tmp = head;
        for(tmp;tmp != tail;tmp = tmp->next){
            cout<<"num:"<<tmp->info<<endl;
        }
    }
}

void test0(){
    singleList s1;
    s1.addToHead(1);
    s1.addToHead(2);
    s1.addToHead(3);
    s1.addToHead(4);
    s1.addToHead(5);
    s1.addToHead(1);
    s1.addToHead(6);
    s1.addToHead(6);
    s1.addToHead(7);
    s1.print();
    cout<<s1.isSingleList(8)<<endl;;
    cout<<s1.isSingleList(3)<<endl;;
}

int main()
{
    test0();
    return 0;
}


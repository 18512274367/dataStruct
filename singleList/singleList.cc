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

void singleList::addToHead(int el){
    head = new Node(el,head);
    if(tail == 0) tail = head;
}

void singleList::addToTail(int el){
    if(tail != 0){
        tail->next = new Node(el);
        tail = tail->next;
    }else
        head = tail = new Node(el);
}

int singleList::delFromHead(){
    int el = head->info;
    Node *tmp = head;
    if(head == tail) head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;
}

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

void singleList::delNode(int el){
    if(head != 0){
        if(head == tail && el == head->info){
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

bool singleList::isSingleList(int el) const{
    Node* tmp;
    for(tmp = head;tmp !=0 && !(tmp->info == el);tmp = tmp->next);
    return tmp != 0;

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
    cout<<s1.isSingleList(8)<<endl;;
    cout<<s1.isSingleList(3)<<endl;;
}

int main()
{
    test0();
    return 0;
}


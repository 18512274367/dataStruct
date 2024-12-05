/*
 *
 * 双向链表的实现，结点包含指向前驱结点与后继结点的指针以及数据部分
 * 采用模板的方式实现
 * 这样可以使链表存储的元素类型不拘泥于单一类型
 *
 */

#ifndef _DoubleLinkedList_H_
#define _DoubleLinkedList_H_
#include <iostream>

using namespace std;

template<class T>
class Node{
public:
    Node(){
        next = prev = 0;
    }

    Node(const T& el,Node *n = 0,Node *p = 0)
    :info(el)
    ,next(n)
    ,prev(p){}


public:
    T info;
    Node *next,*prev;
};

template<class T>
class DoubleLinkedList
{
public:
    DoubleLinkedList() { head = tail = 0; }
    
    bool isEmpty(){ return head != 0; }  //判空函数
    void addToHead(const T&);
    void addToTail(const T&);
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(T);
    bool isDoubleLinkedList(T) const;
    void print() const;
    ~DoubleLinkedList() {
        for (Node<T> *p;!isEmpty();){
            p = head->next;
            delete head;
            head = p;
        }
    }

private:
    Node<T> *head,*tail;

};

//头插法
template<class T>
void DoubleLinkedList<T>::addToHead(const T& el){
    if(head != 0){  //判空
        head = new Node<T>(el,head,0);
        head->next->prev = head;
    }else head = tail = new Node<T>(el);
}

//尾插法
template<class T>
void DoubleLinkedList<T>::addToTail(const T& el){
    if(tail != 0){  //判空
        tail = new Node<T>(el,0,tail);
        tail->prev->next = tail;
    }else head = tail = new Node<T>(el);
}

//删除尾结点
template<class T>
T DoubleLinkedList<T>::deleteFromHead(){
    T el = head->info;
    if(head == tail){  //此时只有一个结点
        delete head;
        head = tail = 0;
    }else{  //多个结点
        head = head->next;
        delete head->prev;
        head->prev = 0;
    }
    return el;
}

//删除尾结点
template<class T>
T DoubleLinkedList<T>::deleteFromTail(){
    T el = tail->info;
    if(tail == head){
        delete tail;
        head = tail = 0;
    }else{
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
    return el;
}

//删除指定结点
template<class T>
void DoubleLinkedList<T>::deleteNode(T el){
    if(head == tail && el == head->info){ //仅有一个结点且满足条件时
        delete head;
        head = tail = 0;
    }
    Node<T> *tmp = head;
    for(tmp;tmp == tail;tmp = tmp->next){  //遍历链表删除对应结点
        if(tmp->info == el){
           tmp->prev->next = tmp->next;
           tmp->next->prev = tmp->prev;
           delete tmp;
           tmp->next = tmp->prev = 0;
        }
    }
}

template<class T>
bool DoubleLinkedList<T>::isDoubleLinkedList(T el) const{
    Node<T>* tmp;
    for(tmp = head;tmp != 0 && !(tmp->info == el);tmp = tmp->next);
    return tmp != 0;
}

template<class T> 
void DoubleLinkedList<T>::print() const{
    Node<T>* tmp;
    for(tmp = head;tmp != 0;tmp = tmp->next){
        cout<<"info:"<<tmp->info<<endl;
    }
}

#endif


#ifndef _singleList_H_
#define _singleList_H_

class Node{
public:
    Node(){
        next = 0;
    }
    Node(int info,Node* ptr = 0) : info(info),next(ptr){}

public:
    int info;
    Node* next;
};

class singleList
{
public:
    singleList() { head = tail = 0; }
    ~singleList();
    int isEmpty(){
        return head == 0;
    }

    void addToHead(int);
    void addToTail(int);
    int delFromHead();
    int delFromTail();
    void delNode(int);
    bool isSingleList(int) const;

private:
    Node *head,*tail;

};

#endif


#ifndef __WJKSTRA_STACK_H_
#define __WJKSTRA_STACK_H_
//一个简单栈的实现
//
//

#include <vector>

class stack
{
public:
    stack();
    bool empty() const;  //判空
    bool full() const;  //判满
    //push() return false if stack already is full,true otherwise
    void push (const int & el);  //元素入栈
    //pop() return false if stack already is empty,true otherwise
    void pop ();  //元素出栈
    int top() const; //获取栈顶元素
private:
    int flag;
    std::vector<int> el;
    static const int MAX_SIZE = 100;
};
#endif


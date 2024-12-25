#include <iostream>
#include "stack.h"

stack::stack(){
    flag = -1;
    el.reserve(MAX_SIZE);
}

bool stack::empty() const{
    return flag == -1;
}

bool stack::full() const{
    return flag == MAX_SIZE - 1;
}

void stack::push(const int & item){
    if(flag >= MAX_SIZE - 1){
        std::cout<<"Stack is full"<<std::endl;
        return;
    }
    el.push_back(item);
    flag++;
}

void stack::pop(){
    if(flag == -1){
        std::cout<<"Stack is empty"<<std::endl;
        return ;
    }    
    el.pop_back();
    flag--;
}

int stack::top() const{
    if(flag == -1){
        std::cerr<<"Stack is empty"<<std::endl;
        return flag;
    }
    return el[flag];
}

int main()
{
    stack st;
    if(st.empty()){
        std::cout<<"Stack is empty\n";
    }else{
        std::cout<<"Stack is not empty\n";
    }

    for(int i = 1;i < 120;++i){
        st.push(i);
    }

    if(st.full()){
        std::cout<<"Stack is full\n";
    }else{
        std::cout<<"Stack is not full\n";
    }

    std::cout<<"top: "<<st.top()<<std::endl;
    for(int i= 0;i <= 100;i++) st.pop();

    return 0;
}


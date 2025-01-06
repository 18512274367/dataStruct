#include <iostream>
#include "QuickSort.h"
#include "../random/random.h"

using namespace std;

void display(int data[]){
    for(int i = 0;i < 20;i++){
        cout<<data[i]<<" ";
    } 
    cout<<endl;
}

void test0(){
    int data[20];
    for(int i = 0;i < 20;i++){
        data[i] = randomNum();
    }

    display(data);

    quickSort(data,0,19);
    display(data);
    for(int i = 0;i < 20;i++){
        data[i] = randomNum();
    }
    display(data);

    quickSort(data,20);
    display(data);

}

int main(int argc,char* argv[])
{
    test0();
    return 0;
}


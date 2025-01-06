#include <algorithm>

#ifndef _QuickSort_H_
#define _QuickSort_H_

template<class T>
void quickSort(T data[],int first,int last){
    int lower = first + 1,upper = last;
    std::swap(data[first],data[(first + last) / 2]);
    T bound = data[first];
    while (lower <= upper){
        while (data[lower] < bound) lower++;
        while (bound < data[upper]) upper--;
        if(lower < upper) std::swap(data[lower++],data[upper--]);
        else lower++;
    }
    std::swap(data[upper],data[first]);
    if(first < upper - 1) quickSort(data,first,upper - 1);
    if(upper + 1 < last) quickSort(data,upper + 1,last);
}

template<class T>
void quickSort(T data[],int n){
    int max;
    if(n < 2) return;
    for(int i = 1,max = 0;i < n;i++){
        if(data[max] < data[i])
            max = i;
        std::swap(data[n - 1],data[max]);
        quickSort(data,0,n  - 2);
    }
}

#endif


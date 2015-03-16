#include "Queue.h"
#include <cstdlib>
#include <cstdio>
#include <cmath>
int main()
{
    Queue <int> intQueue;
    Queue <double> doubleQueue;
    for(int i=0 ; i<8 ; i++)
    {
        
        int suc = intQueue.forcePush(i);
        if(suc)
            printf("pushed %d in intQueue\n",i);
        else
            printf("intQueue is full!\n");
           
        suc = doubleQueue.push(i*M_PI);
        if(suc)
            printf("pushed %f in doubleQueue\n",i*M_PI);
        else
            printf("doubleQueue is full!\n");

    }
    
    for(int i=0 ; i<6 ; i++)
    {
        int data; 
        int suc = intQueue.pop(&data);
        if(suc)
            printf("poped %d\n",data);
        else
            printf("queue is empty!\n");
    }
    
    for(int i=0 ; i<6 ; i++)
    {
        double data; 
        int suc = doubleQueue.pop(&data);
        if(suc)
            printf("poped %f\n",data);
        else
            printf("queue is empty!\n");
    }
    return 0;
}

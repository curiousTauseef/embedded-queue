#include <cstdio>
#ifndef QUEUE_H
#define QUEUE_H
#define FifoSize 4 /* Note to define one cell more than than the capacity you want */
template <class T> class Queue
{
private:
    T *PUTPT;    /* Pointer of where to put next */
    T *GETPT;    /* Pointer of where to get next */
    T Fifo[FifoSize]; /* The statically allocated fifo data */
    int lenght;
public:
    Queue()
    {
        lenght = 0 ;
        PUTPT=GETPT=&Fifo[0]; /* Empty when PUTPT=GETPT */
    }
    int push(T data);
    int pop(T *datapt);
    int forcePush(T data);
    int size(){ return lenght; };
    T &operator[](int i)
    {
        if(PUTPT > GETPT)
        {
            return GETPT[i];
        }
        else
        {
            if(i > (&Fifo[FifoSize] - GETPT))
            {
                return Fifo[i - (&Fifo[FifoSize] - GETPT)];
            }
            else
            {
                return GETPT[i];
            }
        }
    }
};
template <class T> int Queue<T>::forcePush(T data){
    int suc = push(data);
    if(!suc)
    {
        T temp;
        pop(&temp);
        push(data);
    }
    return (-1);
}
template <class T> int Queue<T>::push(T data) {
    T *Ppt; /* Temporary put pointer */
    Ppt=PUTPT; /* Copy of put pointer */
    *(Ppt++)=data; /* Try to put data into fifo */
    if (Ppt == &Fifo[FifoSize]) Ppt = &Fifo[0]; /* Wrap */
    if (Ppt == GETPT ){
        return(0);}   /* Failed, fifo was full */
    else{
        PUTPT=Ppt;
        lenght++; 
        return(-1);   /* Successful */
    }
}
template <class T> int Queue<T>::pop(T *datapt) {
    if (PUTPT== GETPT){
        return(0);}   /* Empty if PUTPT=GETPT */
    else{
        *datapt=*(GETPT++);
        if (GETPT == &Fifo[FifoSize])
            GETPT = &Fifo[0];
        lenght--;
        return(-1); /* Successful */
    }
}
#endif

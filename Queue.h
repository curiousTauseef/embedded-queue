#include <cstdio>
#include <cstdlib>
#ifndef QUEUE_H
#define QUEUE_H
 /* Note to define one cell more than than the capacity you want */
template <class T> class Queue
{
private:
    T *PUTPT;    /* Pointer of where to put next */
    T *GETPT;    /* Pointer of where to get next */
    T *Fifo; /* The dinamically allocated fifo data */
    int lenght;
    int FifoSize;
public:
    Queue(int n )
    {
        FifoSize = n;
        lenght = 0;
        Fifo = (T *) malloc(FifoSize * sizeof(T));
        PUTPT = GETPT=&Fifo[0]; /* Empty when PUTPT=GETPT */
    }
    ~Queue()
    {
        free(Fifo);
    }
    int push(T data);
    int pop(T *datapt);
    int forcePush(T data);
    int size(){ return lenght; };
    T &operator[](int i)
    {
        /*
        if(PUTPT = GETPT)
            return GETPT[0]; //This never should happen because it means size() is zero and you're calling it
*/
        if(PUTPT > GETPT)
        {
            return GETPT[i];
        }
        else
        {
            if(i >= (&Fifo[FifoSize] - GETPT))
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

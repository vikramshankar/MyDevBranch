#include <iostream>
#include "pthread.h"
using namespace std;

void* Fun(void* a)
{
    int* b = static_cast<int*>(a);
    cout<<"Thread created "<<*b<<endl;
}


int main()
{
    pthread_t thread1;
    pthread_t thread2;
    size_t size;
    pthread_attr_t attr1;
    pthread_attr_t attr;
    int detachstate = 9;
    pthread_attr_init(&attr);
    pthread_attr_init(&attr1);
    int i = 9;
    void* status;
    pthread_attr_setdetachstate (&attr,PTHREAD_CREATE_JOINABLE);
    pthread_attr_setdetachstate (&attr1,PTHREAD_CREATE_JOINABLE);
    int ret = pthread_attr_getstacksize(&attr, &size);
    ret = pthread_create(&thread1,&attr,Fun,&i);
    ret = pthread_create(&thread2,&attr1,Fun,&i);
    int ret1 = pthread_join(thread1,&status);
     ret1 = pthread_join(thread2,&status);
     
    cout<<"ret "<<ret<<" ret1 = "<<ret1<<endl<<"stack size is "<<size;
    size = (883666 + 0x4000);
    pthread_attr_setstacksize(&attr, size);
    pthread_attr_getstacksize(&attr, &size);
    cout<<"reassigned stack size :"<<size<<endl;
    pthread_attr_destroy(&attr);
}

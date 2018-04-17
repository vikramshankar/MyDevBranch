
#include<iostream>
using namespace std;

void* fun(void *)
{
   std::cout<<"thread created";
}

int main()
{
  pthread_t thread1;
  void* status;
  int ret = pthread_create(&thread1,NULL,fun,NULL);
  ret = pthread_join(thread1,&status);
  cout<<" ret "<<status;
}

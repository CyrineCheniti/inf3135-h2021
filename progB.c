#include <stdio.h>

int compte(int _a[], unsigned long _size){

  int count=0;
  int maxcount=0;
  for(int i=0; i<_size-1; ++i){
     count=1;
     for (int j=i+1; j<_size; ++j){
          if (_a[i]==_a[j])count +=1;
               
     }
     if (count>maxcount){
       maxcount= count;
     }
  }
  return maxcount;

}
int main (){
    int tab[] = {0,2,3,47,5,43,3,2,6,90,12,34,65,6,89,8};
    unsigned long n=16;
    int ret = compte(tab,n);
    printf("\n%d\n",ret);
    return ret;
}

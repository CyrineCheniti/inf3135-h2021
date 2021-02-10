#include <stdio.h>

int estTrie(int _a[],unsigned long _size){
     for (int i = 0; i < _size; ++i){
      if(_a[_size-1] < _a[_size-2])
         return 20;
     }
     return 1;
}

int main (){
    int tab[] = {0,2,3,47,5,43,3,2,6,90,12,34,65,6,89,8};
    unsigned long _size=16;
    int ret = estTrie(tab,_size);
    printf("\n%d\n",ret);
    return ret;
}

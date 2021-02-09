#include <stdio.h>

int estTrie(int _a[],int n){
     for (int i = 0; i < n; ++i){
      if(_a[n-1] < _a[n-2])
         return -1;
     }
     return 1;
}

int main (){
    int tab[] = {0,2,3,47,5,43,3,2,6,90,12,34,65,6,89,8};
    int n=16;
    int ret = estTrie(tab,n);
    printf("\n%d\n",ret);
}

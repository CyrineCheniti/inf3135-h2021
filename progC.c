#include <stdio.h>

unsigned char inverse(unsigned char _a[], unsigned long _size)
{
  int t;

  for (int i = 0; i < _size/2; i++) {
    t = _a[i];                  
    _a[i] = _a[_size-i-1];

    _a[_size-i-1] = t;
  }

  return _a[0];

}
int main (){
    unsigned char tab[] = {0,2,3,47,5,43,3,2,6,90,12,34,65,6,89,8};
    unsigned long n=16;
    unsigned char ret = inverse(tab,n);
    printf("\n%u\n",ret);
    return (ret);

}

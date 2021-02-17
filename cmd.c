#include <stdio.h>
#include <string.h>
//fonction utile pour exempleC
void reverser(const char *str, size_t taille )
{
  const char *pt=str+taille;
  while (pt>str)
     putchar(*--pt);
}

int main( int argc , char **argv) {
  //exempleA
  int i=0;
  for(i=0; i<argc; i++){
      printf("argv[%d] : %s\n", i, argv[i]);
  }
  printf("\n");
  //exempleB
  for(i=argc; i-- > 1;){
      printf("%s ", argv[i]);
  }
  printf("\n\n");
  //exempleC
  for (int i=1; i<argc; i++){
       if(i !=1)
        putchar(' ');
       reverser(argv[i], strlen(argv[i]));
  }
  putchar('\n');
  return 0;
}

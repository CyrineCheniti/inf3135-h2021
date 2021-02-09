# Makefile pour INF3135 / atelier4

progA: progA.c
	gcc  -std=c11 -Wall -pedantic -o progA progA.c

progB: progB.o
	gcc -std=c11 -Wall -pedantic -c  progB.c
	gcc -std=c11 -Wall -pedantic -o progB progB.o
   
progC: progC.o
	gcc  -std=c11 -Wall -pedantic -o progC progC.c

clean:
	rm -rf  *.o progA progB progC

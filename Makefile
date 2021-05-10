CFLAG= -Wall -Werror=vla -pedantic -std=c11 

default: tp2

tp2: tp2.o  
	gcc -o tp2 tp2.o -L -liboutil3
	
tp2s: tp2.c 
	gcc -static $(CFLAG) -o $@ -fPIC  $^  

librairie: outil3.c
	gcc -c outil3.c
	gcc outil3.o -shared -o liboutil3.so 
	gcc -c tp2.c -o tp2.o
	ar -cvq liboutil3.a tp2.o

.PHONY: clean indices quote

clean:
	@rm -f *.o *.a *.so tp2s tp2

indices:
	@mkdir -p ./data
	@echo "K\nBCE\nBNS\nBLU\nBMO" > data/indices.txt

quote:
	@chmod +x getQuote.sh
	@./getQuote.sh

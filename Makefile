CFLAG= -Wall -Werror=vla -pedantic -std=c11 -Werror -O2


tp2: tp2.c outil3.c 
	gcc -shared $(CFLAG) -Wl,-rpath=./liboutil3.so -o $@ -fPIC $^

tp2s: tp2.c 
	gcc -static $(CFLAG) -o $@ -fPIC $^ 

librairie: tp2.c
	gcc -c -fPIC tp2.c -o tp2.o  
	#ar -cvq liboutil3.a tp2.o
	gcc tp2.o -shared -o liboutil3.so   

.PHONY: clean indices quote

clean:
	@rm -f *.o *.so *.a tp2s tp2

indices:
	@mkdir -p ./data
	@echo "K\nBCE\nBNS\nBLU\nBMO" > data/indices.txt

quote:
	@chmod +x getQuote.sh
	@./getQuote.sh

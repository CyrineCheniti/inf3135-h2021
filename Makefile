CFLAG= -O2 -Wall -Wextra -Werror=vla -pedantic

all_atelier_build: atelier_07_1 atelier_07_2 atelier_07_3 atelier_07_4

atelier_07_1: atelier_07_1.c
	gcc $(CFLAG) -o $@ $^

atelier_07_2: atelier_07_2.c
	gcc $(CFLAG) -o $@ $^
	@./atelier_07_2 > out.txt 2> err.txt

atelier_07_3: atelier_07_3.c
	gcc $(CFLAG) -o $@ $^

atelier_07_4: atelier_07_4.c
	gcc -o $@ $^

all_atelier_test: all_atelier_build, test_atelier_07_1, test_atelier_07_2, test_atelier_07_3, test_atelier_07_4  

test_atelier_07_1:
	./atelier_07_1

test_atelier_07_2:
	./atelier_07_2

test_atelier_07_3:
	./atelier_07_3

test_atelier_07_4:
	./atelier_07_4

.PHONY: clean
clean:
	@rm -f *.o
	@rm -f atelier_07_1 atelier_07_2 atelier_07_3 atelier_07_4
	@rm -f out.txt err.txt

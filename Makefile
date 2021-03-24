CFLAG= -O2 -Wall -Wextra -Werror=vla -pedantic

all_atelier_build: atelier_07_1 atelier_07_3 atelier_07_4

atelier_07_1: atelier_07_1.c
	gcc -o $@ $^

atelier_07_3: atelier_07_3.c
	gcc -o $@ $^

atelier_07_4: atelier_07_4.c
	gcc -o $@ $^

all_atelier_test: all_atelier_build

.PHONY: clean
clean:
	@rm -f *.o
	@rm -f atelier_07_1 atelier_07_3 atelier_07_4

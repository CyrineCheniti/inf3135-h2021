CFLAG= -O2 -Wall -Wextra -Werror=vla -pedantic

atelier_08_2a2: setA_number.c
	gcc $(CFLAG) -o $@ $^

atelier_08_2a1: setU_number.c
	gcc $(CFLAG) -o $@ $^ 

atelier_08_2b1: setU_string.c
	gcc $(CFLAG) -o $@ $^

atelier_08_2b2: setA_string.c
	gcc $(CFLAG) -o $@ $^

all_atelier_build: atelier_08_2a2 atelier_08_2a1 atelier_08_2b1 atelier_08_2b2

.PHONY: clean
clean:
	@rm -f *.o
	@rm -f atelier_08_2a2 atelier_08_2a1 atelier_08_2b1 atelier_08_2b2

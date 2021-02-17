CFLAG= -O2 -Wall -Wextra -Werror=vla -pedantic

cmd: cmd.c
	gcc $(CFLAG) -o $@ $^

.PHONY: clean
clean:
	rm -f *.o 
	rm -f cmd

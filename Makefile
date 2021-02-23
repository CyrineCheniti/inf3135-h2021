CFLAG= -O2 -Wall -Wextra -Werror=vla -pedantic

cmdline: cmdline.c
	gcc $(CFLAG) -o $@ $^

.PHONY: clean
clean:
	rm -f *.o
	rm -f cmdline

CFLAG= -Wall -Werror=vla -pedantic -std=c11 -Werror -O2

tp2: tp2.c
	gcc $(CFLAG) -o $@ $^

.PHONY: clean indices quote

clean:
	@rm -f *.o
	@rm -f tp1

indices:
	@mkdir -p ./data
	@echo "K\nBCE\nBNS\nBLU\nBMO" > data/indices.txt

quote:
	@chmod +x getQuote.sh
	@./getQuote.sh

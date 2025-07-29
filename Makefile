assembler: main.c
	gcc -Wall -Wextra -g -o assembler main.c

clean:
	rm -f assembler
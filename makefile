all: main

main: main.o tas_huffman.o tas.o content.o
	gcc -g -lm -Wall -Wextra *.o -o main

main.o: main.c
	gcc -g -Wall -Wextra main.c -c -o main.o

tas_huffman.o: tas_huffman.c
	gcc -g -Wall -Wextra tas_huffman.c -c -o tas_huffman.o

tas.o: tas.c
	gcc -g -Wall -Wextra tas.c -c -o tas.o

content.o: content.c
	gcc -g -Wall -Wextra content.c -c -o content.o

clean:
	rm -f main *.o

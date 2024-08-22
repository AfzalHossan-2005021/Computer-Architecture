main:
	./a.out code.asm GHCIAFEBJKDPLNOM
	g++ -o code hex_to_array.cpp
	./code
	rm -f parser.tab.c parser.tab.h lex.yy.c a.out code out.bin hex.txt

full:
	bison -d parser.y
	flex lexer.lex
	g++ -o a.out lex.yy.c parser.tab.c
	./a.out code.asm GHCIAFEBJKDPLNOM
	g++ -o code hex_to_array.cpp
	./code
	rm -f parser.tab.c parser.tab.h lex.yy.c a.out code out.bin hex.txt
all:
	yacc -d TAC.y -Wno-conflicts-sr
	flex TAC.l
	g++ -std=c++14 -Wno-write-strings lex.yy.c y.tab.c -ll -o TAC
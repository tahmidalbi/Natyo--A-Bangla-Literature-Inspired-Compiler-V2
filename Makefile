CC = gcc

all: lexer_app

lexer_app: lex.yy.c src/lexer_main.c
	$(CC) lex.yy.c src/lexer_main.c -o lexer_app

lex.yy.c: src/lexer.l src/token_debug.h
	flex -o lex.yy.c src/lexer.l

run-valid: lexer_app
	./lexer_app tests/phase2_valid.nt

run-invalid: lexer_app
	./lexer_app tests/phase2_invalid.nt

clean:
	rm -f lex.yy.c lexer_app
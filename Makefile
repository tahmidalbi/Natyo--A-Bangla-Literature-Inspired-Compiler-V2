CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Isrc

BISON = win_bison
FLEX = win_flex

TARGET = natyo

all: $(TARGET)

$(TARGET): lex.yy.c parser.tab.c src/symbol_table.c src/ast.c src/interpreter.c src/utils.c
	$(CC) $(CFLAGS) lex.yy.c parser.tab.c src/symbol_table.c src/ast.c src/interpreter.c src/utils.c -o $(TARGET) -lm

parser.tab.c parser.tab.h: src/parser.y
	$(BISON) -d -o parser.tab.c src/parser.y

lex.yy.c: src/lexer.l parser.tab.h
	$(FLEX) -o lex.yy.c src/lexer.l

clean:
	del /Q lex.yy.c parser.tab.c parser.tab.h $(TARGET).exe history_log.txt 2>nul || exit 0

run:
	$(TARGET).exe tests/phase4_valid.nt
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Isrc

BISON = win_bison
FLEX = win_flex

TARGET = natyo

all: $(TARGET).exe

$(TARGET).exe: lex.yy.c parser.tab.c src/symbol_table.c src/ast.c src/interpreter.c src/utils.c src/optimizer.c src/tac.c
	$(CC) $(CFLAGS) lex.yy.c parser.tab.c src/symbol_table.c src/ast.c src/interpreter.c src/utils.c src/optimizer.c src/tac.c -o $(TARGET).exe -lm

parser.tab.c parser.tab.h: src/parser.y
	$(BISON) -d -o parser.tab.c src/parser.y

lex.yy.c: src/lexer.l parser.tab.h
	$(FLEX) -o lex.yy.c src/lexer.l

run:
	.\$(TARGET).exe tests\phase4_valid.nt

clean:
	del /Q lex.yy.c parser.tab.c parser.tab.h $(TARGET).exe history_log.txt tac_output.txt 2>nul || exit 0
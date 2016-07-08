CC = gcc 
CFLAGS = -g -O3 -Wall -Wextra -Wconversion -Wfloat-equal -Wundef -Wshadow -Wpointer-arith\
		 -ftrapv -std=c99 
FILES = main.c 
OUT_EXE = main
build:
	$(CC) $(CFLAGS) -o $(OUT_EXE) $(FILES)

test: build
	valgrind ./$(OUT_EXE)

print:
	a2ps $(FILES) --pro=color --line-numbers=1 --columns=2 -E -o $(OUT_EXE).ps
	ps2pdf $(OUT_EXE).ps

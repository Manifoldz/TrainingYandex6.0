CC=gcc
CFLAGS=-std=c11 -pedantic -Wall -Werror -Wextra
SANFLAG=#-fsanitize=address -g
COVFLAGS=-fprofile-arcs -ftest-coverage

C_TEST=test1.c
OUT_TEST=$(subst .c,.out,$(C_TEST))

C_TARGET=main.c
OUT_TARGET=$(subst .c,.out,$(C_TARGET))

# Флаги для библиотеки чек
OS=$(shell uname)
PROC=$(shell uname -m)
CHECKFLAGS=-lcheck

ifeq ($(OS)_$(PROC),Darwin_arm64)
# Для M процессоров мака доп флаг
	CHECKFLAGS += -Wno-gnu-zero-variadic-macro-arguments
else ifneq ($(OS), Darwin)
# Для Линукс доп флаги свои
	CHECKFLAGS += -lsubunit -lpthread
endif


build:
	$(CC) $(CFLAGS) $(SANFLAG) $(COVFLAGS) $(C_TARGET) $(CHECKFLAGS) -o $(OUT_TARGET)

test:
	$(CC) $(CFLAGS) $(SANFLAG) $(COVFLAGS) $(C_TEST) $(CHECKFLAGS) -o $(OUT_TEST)
	./$(OUT_TEST)

gcov_report:
	gcov *.c

clean:
	rm -rf *.out *gc*
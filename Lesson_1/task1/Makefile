CC=gcc
CFLAGS=-std=c11 -pedantic -Wall -Werror -Wextra
SANFLAG=#-fsanitize=address -g
COVFLAGS=-fprofile-arcs -ftest-coverage

C_TEST=test1.c
TEST_NAME=$(subst .c,,$(C_TEST))
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
	$(CC) $(CFLAGS) $(SANFLAG) $(COVFLAGS) $(C_TARGET) -o $(OUT_TARGET) $(CHECKFLAGS)
	@echo "\n=== Input from tests.txt file ===\n"
	./$(OUT_TARGET) < tests.txt

test:
	$(CC) $(CFLAGS) $(SANFLAG) $(COVFLAGS) $(C_TEST) -o $(OUT_TEST) $(CHECKFLAGS)
	./$(OUT_TEST)

gcov_report:
	@mv $(OUT_TEST)-$(TEST_NAME).gcda $(TEST_NAME).gcda
	@mv $(OUT_TEST)-$(TEST_NAME).gcno $(TEST_NAME).gcno
	gcov $(C_TEST)
	@echo ""
	lcov -t "test" -o report.info -c -d .
	genhtml -o report report.info
	open report/index.html


clean:
	rm -rf *.out *gc* *report*
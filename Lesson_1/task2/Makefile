CC=gcc
CFLAGS=-std=c11 -pedantic -Wall -Werror -Wextra
SANFLAG=#-fsanitize=address -g
COVFLAGS=-fprofile-arcs -ftest-coverage

C_TEST=test2.c
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

cpp:
	g++ -O2 -lm -fno-stack-limit -std=c++20 -x c++ for_platform.cc -o executable
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	--log-file=leaks_log.txt ./executable < tests.txt; vim leaks_log.txt

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

# Докер и валгринд
NAME = test
docker:
	docker build -t $(NAME):v1 .
	docker run -it --name $(NAME) $(NAME):v1 /bin/bash

renew_docker: clean
	docker start $(NAME)
	docker exec $(NAME) rm -rf /code
	docker cp . $(NAME):/code
	docker exec -it $(NAME) /bin/bash

delete_docker:
	docker stop $(NAME)
	docker rm $(NAME)
	docker rmi $(NAME):v1


valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
		--log-file=leaks_log.txt ./$(OUT_TEST); vim leaks_log.txt

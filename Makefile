compile:
	@echo =========COMPILING=============
	mkdir -p build
	gcc $(wildcard src/*.c) -o build/fj -Wall -Werror -ggdb

ass: compile
	gcc $(wildcard src/*.c) -o build/fj.s -Wall -Werror -S

run: compile
	@echo =========RUNNING===============
	build/fj

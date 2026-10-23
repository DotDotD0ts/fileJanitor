compile:
	@echo =========COMPILING=============
	mkdir -p build
	gcc $(wildcard src/*.c) -o build/fj -Wall -Werror -ggdb -std=c23

ass: compile
	gcc $(wildcard src/*.c) -o build/fj.s -Wall -Werror -S -std=c23

run: compile | build
	@echo =========RUNNING===============
	cd build && ./fj

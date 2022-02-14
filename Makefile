all: build
	gcc -lraylib -Iinclude -g -o build/main src/main.c src/core/*.c src/characters/*.c src/utils/linked_list.c src/graphics/*.c src/weapon/*.c

build:
	mkdir build
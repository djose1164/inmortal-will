all:
	gcc -lraylib -Iinclude -o build/main src/main.c src/core/*.c src/characters/*.c src/utils/linked_list.c src/graphics/*.c

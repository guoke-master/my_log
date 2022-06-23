DirInc = ./include
DirSrc = ./src
DirObj = ./obj
DirBin = ./bin
DirLib = ./lib

Src = $(wildcard $(DirSrc)/*.c)
Obj = $(patsubst %.c, $(DirObj)/%.o, $(notdir $(Src)))
Lib = $(wildcard $(DirLib)/*.a)

Target = test

BinTarget := $(DirBin)/$(Target)

CC = gcc
CFLAGS = -g -Wall -I$(DirInc)

$(BinTarget): $(Obj)
	$(CC) $(Obj) $(Lib) -o $@
	ar crv $(DirObj)/libmy_log.a $(DirObj)/my_log.o

$(DirObj)/%.o: $(DirSrc)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm $(DirObj)/* $(DirBin)/* -rf

CC = gcc
CCFLAGS = -O3 -L./lib/

ifeq ($(OS),Windows_NT)
	CCFLAGS += -lraylibwin
else
	UNAME_S = $(shell uname -s)

	ifeq ($(UNAME_S),Linux)
		CCFLAGS += -lrayliblin
	endif

	ifeq ($(UNAME_S),Darwin)
		CCFLAGS += -lraylibmac
	endif
endif

main: main.c
	$(CC) main.c $(CCFLAGS) -o bin/csnake
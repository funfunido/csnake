CC = clang
CCFLAGS = -O3 -L./lib/ -rpath @executable_path
DYNLIB = librayliblin.so

ifeq ($(OS),Windows_NT)
	CCFLAGS += -lraylibwin
	DYNLIB = libraylibwin.dll
else
	UNAME_S = $(shell uname -s)

	ifeq ($(UNAME_S),Linux)
		CCFLAGS += -lrayliblin
	endif

	ifeq ($(UNAME_S),Darwin)
		CCFLAGS += -lraylibmac
		DYNLIB = libraylibmac.dylib
	endif
endif

main: main.c
	$(CC) main.c $(CCFLAGS) -o bin/csnake
	$(shell cp lib/$(DYNLIB) bin/$(DYNLIB))
CC = clang
CCFLAGS = -O3 -L./lib/
DYNLIB = librayliblin.so
OTHER_POST_COMS = mv bin/librayliblin.so bin/libraylib.550.so

ifeq ($(OS),Windows_NT)
	CCFLAGS += -lraylibwin
	DYNLIB = not_important.txt
else
	UNAME_S = $(shell uname -s)

	ifeq ($(UNAME_S),Linux)
		CCFLAGS += -lrayliblin
		DYNLIB = librayliblin.so
	endif

	ifeq ($(UNAME_S),Darwin)
		CCFLAGS += -rpath @executable_path -lraylibmac
		DYNLIB = libraylibmac.dylib
		OTHER_POST_COMS = mv bin/libraylibmac.dylib bin/libraylib.550.dylib
	endif
endif

main: main.c
	$(CC) main.c $(CCFLAGS) -o bin/csnake
	$(shell cp lib/$(DYNLIB) bin/$(DYNLIB))
	$(shell $(OTHER_POST_COMS))
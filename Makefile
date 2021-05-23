CC 				:= gcc
CFLAGS			:= -std=c11
O 				:= obj

OBJS = \
	$(O)/node0.o \
	$(O)/node1.o \
	$(O)/node2.o \
	$(O)/node3.o \
	$(O)/main.o

.PHONY: run build obj clean

obj: node0.c node1.c node2.c node3.c main.c
	@$(CC) -c node0.c -o $(O)/node0.o $(CFLAGS)
	@$(CC) -c node1.c -o $(O)/node1.o $(CFLAGS)
	@$(CC) -c node2.c -o $(O)/node2.o $(CFLAGS)
	@$(CC) -c node3.c -o $(O)/node3.o $(CFLAGS)
	@$(CC) -c main.c  -o $(O)/main.o  $(CFLAGS)

build: obj
	@$(CC) $(OBJS) -o $(O)/main $(CFLAGS)

run :build
	@./$(O)/main 

clean:
	@rm -rf $(O)/*


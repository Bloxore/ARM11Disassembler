CC=gcc
DIR=src
DEPS=$(DIR)/main.c $(DIR)/helpers.c
BDIR=./bin
INCLUDE=./include

reg: $(DEPS)
		mkdir -p $(BDIR)
		$(CC) -o $(BDIR)/app.out $(DEPS) -I $(INCLUDE)

clean:
		rm -rf $(BDIR)




.PHONY: clean strip

COMPILER = connect4
PRODUCTS = $(COMPILER)
default: $(PRODUCTS)

SRCS = connect4_functions.c connect4.c

OBJS = $(patsubst %.c, %.o, $(filter %.c, $(SRCS)))

JUNK = *.o

CC = gcc
LD = gcc

CFLAGS = -g -Wall -std=c99

.c.o: $*.c
	$(CC) $(CFLAGS) -c -o $@ $*.c

$(COMPILER) : $(OBJS)
	$(LD) -o $@$(OBJS) $(LIBS)

strip : $(PRODUCTS)
	strip $(PRODUCTS)
	rm -rf $(JUNK)

depend:
	makedepend -- $(CFLAGS) -- $(SRCS)

clean:
	rm -f $(JUNK) $(PRODUCTS)

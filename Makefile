CC=gcc

PROGRAM=twitter
OBJS=twitter.o
SRCS=$(OBJS:%.o=%.c)
CFLAGS=-Wall -std=gnu99 -g
DBGFLAGS=-D_DEBUG_
LDFLAGS=-loauth -lcurl -lyajl

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROGRAM) $(OBJS) $(LDLIBS)

debug: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(DBGLAGS) -o $(PROGRAM) $(OBJS) $(LDLIBS)

clean:
	rm -f $(PROGRAM)
	rm -f $(OBJS)

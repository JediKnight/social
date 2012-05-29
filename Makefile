CC=gcc

PROGRAM=twitter
OBJS=twitter.o
SRCS=$(OBJS:%.o=%.c)
CFLAGS=-Wall -loauth -lcurl -ljson -std=gnu99 -g
LDFLAGS=

DPROGRAM=debug_twitter
DOBJS=twitter.o
DSRCS=$(DOBJS:%.o=%.c)
DCFLAG=-Wall -D_DEBUG_ -loauth -lcurl -ljson -std=gnu99 -g
DLDFLAGS=

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROGRAM) $(OBJS) $(LDLIBS)

debug:$(OBJS)
	$(CC) $(DCFLAG) $(DLDFLAGS) -o $(DPROGRAM) $(DOBJS) $(DLDLIBS)

clean:
	rm -f $(PROGRAM)
	rm -f $(OBJS)
	rm -f $(DPROGRAM)
	rm -f $(DOBJS)


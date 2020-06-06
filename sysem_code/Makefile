src=$(wildcard *.c )
obj=$(patsubst %.c,%,$(src))

all:$(obj)

CFLAGS= -Wall -g

$(obj):%:%.c
	gcc $< -o $@ $(CFLAGS)

clean:
	-rm -rf $(obj)

.PHONY:clean all











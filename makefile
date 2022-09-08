CC=gcc
LD=$(CC)
RM=rm -rf
MKDIR=mkdir -p

NS=cusobject
SO=lib$(NS).so
SRC=$(wildcard src/*.c)
HDR=$(wildcard src/*.h)
OBJ=$(subst src/,bin/,$(SRC:.c=.o))

CFLAGS=-c -DBULIDING_CUSOBJECT_API -Wall -Wextra -Wno-long-long -fPIC -DPIC
LDFLAGS=-shared -Wl,-soname,$(SO)

.SILENT:
.PHONY: all clean new

all: $(SO)

clean:
	echo cleaning
	$(RM) bin $(SO)

new: clean all

$(SO): $(OBJ)
	echo linking $(SO)
	$(LD) $(LDFLAGS) $(OBJ) -o$(SO)

bin/%.o: src/%.c
	echo compiling $<
	$(MKDIR) bin
	$(CC) $(CFLAGS) $< -o$@

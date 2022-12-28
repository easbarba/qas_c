# qas - Easily manage multiple FLOSS repositories.
# See LICENSE file for license details.

TARGET     = qas

C          = gcc
CFLAGS     = -std=c17 \
             -Wall -Wextra -Werror \
             -pedantic-errors -pedantic \
             -Os

LD         = gcc -o
LDFLAGS    = -Wall -pedantic

SOURCES   := $(wildcard *.c)
INCLUDES  := $(wildcard *.h)
OBJECTS   := $(SOURCES:%.c=%.o)

RM         = rm -f

$(TARGET): $(OBJECTS)
	@$(LD) $@ $(LDFLAGS) $(OBJECTS)

$(OBJECTS): %.o : %.c
	@$(C) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJECTS)

remove: clean
	@$(RM) $(TARGET)

all: options dwm

options:
	@echo dwm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

run:
	$(BINDIR)/$(TARGET) 

grab:
	$(BINDIR)/$(TARGET) --grab

archive:
	$(BINDIR)/$(TARGET) --archive meh,foo,bar

.PHONY: all options clean dist install uninstall archive grab run remove

CC = gcc

EXENAME = biblioUnisa-curses

LDFLAGS = -lncurses -lcurl
DFLAGS = -DDEBUG
CFLAGS_EXTRA = -std=c17

# auto variables

SRCDIR  = src
DISTDIR = build/dist
COMPDIR = build/files
EXEPATH = $(DISTDIR)/$(EXENAME)
TREE    = $(SRCDIR) $(DISTDIR) $(COMPDIR)

CFLAGS = $(LDFLAGS) $(DFLAGS) $(CFLAGS_EXTRA) $(CFLAGS_CONFIGURE)

src = $(shell find src -name *.c)
obj = $(src:.c=.o)
#obj = $(subst $(SRCDIR),$(COMPDIR),$(src:.c=.o))
dep = $(obj:.o=.d)

# PHONY targets

.PHONY: build tree dep run clean cleandep purge

build: $(EXEPATH)

tree:
	helpers/maketree.sh

run:
	$(EXEPATH)

clean:
	rm -f $(obj) $(EXEPATH)

cleandep:
	rm -f $(dep)

purge:
	rm -rf $(obj) $(dep)

# explicit rules

$(EXEPATH): $(obj)
	$(CC) -o $@ $^ $(CFLAGS)

# Implicit rules

%.d: %.c
	@$(CC) $< -MM -MT $(@:.d=.o) > $@

# include

-include $(dep)

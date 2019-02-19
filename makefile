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

.PHONY: build tree dep run clean cleandep purge validate

build: $(EXEPATH)

tree:
	helpers/maketree.sh

run:
	$(EXEPATH)

cleanobj:
	rm -f $(obj)

cleandep:
	rm -f $(dep)

cleanbuild:
	rm -r $(DISTDIR)

cleanall: clean cleandep

validate:
	deno-license-checker

# explicit rules

$(EXEPATH): $(obj)
	$(CC) -o $@ $^ $(CFLAGS)

# Implicit rules

%.d: %.c
	@$(CC) $< -MM -MT $(@:.d=.o) > $@

# include

-include $(dep)

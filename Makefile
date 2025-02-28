SRCDIR = src
OBJDIR = obj
BINDIR = bin

BINS := echo \
		true \
		false 

CC = cc
CPPFLAGS = -D_POSIX_C_SOURCE=1
CFLAGS = -std=c89 -O2 -g -Wall -Wextra -ffunction-sections -fdata-sections

LD = $(CC)

ifdef $(POSIXLY_CORRECT)
CPPFLAGS += -DPOSIXLY_CORRECT
endif

.PHONY: all clean
.PRECIOUS: $(OBJDIR)/%.o

all: $(BINS)

$(BINS): $(BINS:%=$(BINDIR)/%)

$(BINDIR)/%: $(OBJDIR)/%.o $(OBJDIR)/common.o | $(BINDIR)
	$(LD) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(BINDIR) $(OBJDIR):
	@mkdir -p $@

clean:
	$(RM) $(BINS:%=$(BINDIR)/%) $(OBJDIR)/*.o
BIN ?= myinfo

OBJDIR := $(CURDIR)/obj

SRC := myinfo.c

OBJ := \
	$(foreach src,$(SRC), \
		$(OBJDIR)/$(patsubst %.c,%.o,$(src)))

DEFAULT_CFLAGS := -Wall -Wextra -std=gnu99 -pedantic
CFLAGS ?= $(DEFAULT_CFLAGS)

.PHONY: all
all: $(BIN)


$(OBJDIR)/%.o: name = $*
$(OBJDIR)/%.o:
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $(name).c $(CFLAGS)

$(BIN): $(OBJ)
	$(CC) -o $@ $(filter %.o, $^) $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(BIN)
	rm -rf $(OBJDIR)

# vim:ts=4

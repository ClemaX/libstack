NAME = libstack.a

# Compiler and archiver
CC = clang
AR = ar

# Paths
SRCDIR=src
INCDIR=include

OBJDIR=obj
BINDIR=.

# Sources
SRCS = $(addprefix $(SRCDIR)/,\
	stack_iter.c\
	stack_load.c\
	stack_push.c\
	stack_reverse_rotate.c\
	stack_rotate.c\
	stack_swap.c\
	stack.c\
)

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)

# Flags
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)
DFLAGS = -MT $@ -MMD -MP -MF $(OBJDIR)/$*.d
# r: Replace or add archived object, c: Silence archive creation,
# u: Update only if newer, s: Index objects
ARFLAGS = rcus

# Compiler commands
COMPILE.c = $(CC) $(DFLAGS) $(CFLAGS) -c
COMPILE.o = $(AR) $(ARFLAGS)

all: $(BINDIR)/$(NAME)

# Directories
$(OBJDIR) $(BINDIR):
	@echo "MK $@"
	mkdir -p "$@"

# Objects
$(OBJS): $(OBJDIR)/%.o: $(SRCDIR)/%.c $(OBJDIR)/%.d | $(OBJDIR)
	@mkdir -p '$(@D)'
	@echo "CC $<"
	$(COMPILE.c) $< -o $@

# Dependencies
$(DEPS): $(OBJDIR)/%.d:
include $(wildcard $(DEPS))

# Binaries
$(BINDIR)/$(NAME): $(OBJS) | $(BINDIR)
	@echo "AR $@ $?"
	$(COMPILE.o) $@ $?

# Remove temporary objects
clean:
	@echo "RM $(OBJDIR)"
	rm -rf "$(OBJDIR)"

# Remove all binaries
fclean: clean
	@echo "RM $(BINDIR)/$(NAME)"
	rm -f "$(BINDIR)/$(NAME)"
	@rmdir "$(BINDIR)" 2>/dev/null && echo "RM $(BINDIR)" || :

# Remove all binaries and rebuild
re: fclean all

.PHONY: clean fclean re

# Assign a value to VERBOSE to enable verbose output
$(VERBOSE).SILENT:

# VARIABLES #
INCDIR = ./inc
OBJDIR = ./obj
BINDIR = ./bin
SRCDIR = ./src

TARGET = ./$(BINDIR)/out
OBJS   = ./$(OBJDIR)/Alphabet.o

CFLAGS = -Wall -I$(INCDIR)

# REGLAS #
$(TARGET) : $(OBJS)
	@mkdir -p $(BINDIR)
	gpp $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	gcc -c -MD $(CFLAGS) $< -o $@

-include $(OBJDIR)/*.d

# CLEAN #
.PHONY : clean

clean :
	@rm -r $(OBJDIR) $(BINDIR)
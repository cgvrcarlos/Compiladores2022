# VARIABLES #
INCDIR = inc
OBJDIR = obj
BINDIR = bin
SRCDIR = src

TARGET = $(BINDIR)/out

OBJS   = $(OBJDIR)/main.o       \
         $(OBJDIR)/Alphabet.o   \
		 $(OBJDIR)/Transition.o

CFLAGS = -Wall -I$(INCDIR)

# REGLAS #
$(TARGET) : $(OBJS)
	@mkdir -p $(BINDIR)
	g++ $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	g++ -c -MD $(CFLAGS) $< -o $@

-include $(OBJDIR)/*.d

# CLEAN #
.PHONY : clean

clean :
	rm -r $(OBJDIR) $(BINDIR)
CXX = g++ 
CFLAGS =	-std=c++14 -Wall -g -Wextra -pedantic 
OBJDIR = bin
OBJS =	$(addprefix $(OBJDIR)/, $(patsubst $(SRC)/%.cpp, %.o, $(wildcard $(SRC)/*.cpp)))
INC = -Iinclude -I../util/include -I../model/include -I../view/include
SRC = src

LIBS = -lcurses


.PHONY: all clean

all: $(OBJDIR) $(OBJS)
	@echo Done Building...	

$(OBJDIR):
	@echo Making bin directory
	@mkdir $(OBJDIR)

$(OBJDIR)/%.o:	$(SRC)/%.cpp
	@echo Building $@
	@$(CXX) $(CFLAGS) $(LDFLAGS) -c $(INC) $< -o $@	$(LIBS)
	@echo Done Building $@

clean:
	@echo Cleaning $(OBJDIR) $(TARGET) $(wildcard *.o)...
	@rm -f $(TARGET) $(wildcard *.o)
	@rm -rf $(OBJDIR)
	@echo Done Cleaning...

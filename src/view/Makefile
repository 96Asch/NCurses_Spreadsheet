CXX = g++ 
CFLAGS = -std=c++14 -Wall -fPIC -g -Wextra -pedantic
OBJDIR = bin
LIBDIR = ../lib


OBJS =	$(addprefix $(OBJDIR)/, $(patsubst $(SRC)/%.cpp, %.o, $(wildcard $(SRC)/*.cpp)))
INC = -Iinclude -I../util/include -I../model/include	
SRC = src
LIBS = -lcurses

.PHONY: all clean

all: $(OBJDIR) link
	@echo Done Building...	
	

$(OBJDIR):
	@echo Making $(OBJDIR) directory
	@mkdir $(OBJDIR)

$(OBJDIR)/%.o:	$(SRC)/%.cpp
	@echo Building $@
	@$(CXX) $(CFLAGS) -c  $(INC) $< -o $@
	@echo Done Building $@

link:	$(OBJS)
	@echo Linking files... 
	@$(CXX) -shared $(CFLAGS) -o $(LIBDIR)/libview.so $(OBJS) $(LIBS)
  

clean:
	@echo Cleaning $(OBJDIR) $(TARGET) $(wildcard *.o)...
	@rm -f $(TARGET) $(wildcard *.o)
	@rm -rf $(OBJDIR)
	@echo Done Cleaning...

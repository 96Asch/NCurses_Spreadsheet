
CFLAGS = -std=c++14 -Wall -fPIC -g -Wextra -pedantic
OBJDIR = bin
CURRDIR = $(shell pwd)
LIBDIR = ../lib

CXX = g++ 
OBJS =	$(addprefix $(OBJDIR)/, $(patsubst $(SRC)/%.cpp, %.o, $(wildcard $(SRC)/*.cpp)))
INC = -Iinclude -I../util/include
SRC = src

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
	@$(CXX) -shared $(CFLAGS) -o $(LIBDIR)/libmodel.so $(OBJS)
  

clean:
	@echo Cleaning $(OBJDIR) $(TARGET) $(wildcard *.o)...
	@rm -f $(TARGET) $(wildcard *.o)
	@rm -rf $(OBJDIR)
	@echo Done Cleaning...

CXX = g++ 
CFLAGS =	-std=c++14 -Wall -g -Wextra -pedantic 
OBJDIR = bin
OBJS =	$(addprefix $(OBJDIR)/, $(patsubst $(SRC)/%.cpp, %.o, $(wildcard $(SRC)/*.cpp)))
INC = include
SRC = src
LIB = 
TARGET = spreadsheet
DEPS = $(wildcard $(INC)/*.h)


.PHONY: all clean

all: clean $(OBJDIR) $(TARGET)
	@echo Done Building...	

$(OBJDIR):
	@echo Making bin directory
	@mkdir $(OBJDIR)

$(OBJDIR)/%.o:	$(SRC)/%.cpp
	@echo Building $@
	@$(CXX) $(CFLAGS) -c -I$(INC) $< -o $@	
	@echo Done Building $@
	
    
$(TARGET):	$(OBJS) $(DEPS)
	@echo Building executable $@
	@$(CXX) $(CFLAGS) -o $@ $^

run:
	@./$(TARGET)

check:
	

clean:
	@echo Cleaning $(OBJDIR) $(TARGET) $(wildcard *.o)...
	@rm -f $(TARGET) $(wildcard *.o)
	@rm -rf $(OBJDIR)
	@echo Done Cleaning...

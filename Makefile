CXX = g++ 
CFLAGS =	-std=c++14 -Wall -g -Wextra -pedantic 
OBJDIR = bin
OBJS =	$(addprefix $(OBJDIR)/, $(patsubst $(SRC)/%.cpp, %.o, $(wildcard $(SRC)/*.cpp)))
INC = include
SRC = src
LIB = curses
BOOST_LIBS =  -lboost_unit_test_framework
BOOST_CXXFLAGS = -I/vol/share/groups/liacs/scratch/pt2018/include -DBOOST_TEST_DYN_LINK
LDFLAGS = -L/vol/share/groups/liacs/scratch/pt2018/lib
TARGET = spreadsheet
DEPS = $(wildcard $(INC)/*.h)


.PHONY: all clean

all: $(OBJDIR) $(TARGET)
	@echo Done Building...	

$(OBJDIR):
	@echo Making bin directory
	@mkdir $(OBJDIR)

$(OBJDIR)/%.o:	$(SRC)/%.cpp
	@echo Building $@
	@$(CXX) $(CFLAGS) $(BOOST_CXXFLAGS) $(LDFLAGS) -c -I$(INC) $< -o $@	
	@echo Done Building $@
	
    
$(TARGET):	$(OBJS) $(DEPS)
	@echo Building executable $@
	@$(CXX) $(CFLAGS) -o $@ $^ -l$(LIB)

run:
	@./$(TARGET)

check:
	

clean:
	@echo Cleaning $(OBJDIR) $(TARGET) $(wildcard *.o)...
	@rm -f $(TARGET) $(wildcard *.o)
	@rm -rf $(OBJDIR)
	@echo Done Cleaning...

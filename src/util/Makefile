
CFLAGS = -std=c++14 -Wall -fPIC -g -Wextra -pedantic
OBJDIR = bin
CURRDIR = $(shell pwd)
LIBDIR = ../lib
CXX = g++ 
OBJS =	$(addprefix $(OBJDIR)/, $(patsubst $(SRC)/%.cpp, %.o, $(wildcard $(SRC)/*.cpp)))
INC = -Iinclude
SRC = src
BOOST_LIBS =  -lboost_unit_test_framework
BOOST_CXXFLAGS = -I/vol/share/groups/liacs/scratch/pt2018/include -DBOOST_TEST_DYN_LINK

.PHONY: all clean

all: $(OBJDIR) link
	@echo Done Building...	

$(OBJDIR):
	@echo Making $(OBJDIR) directory
	@mkdir $(OBJDIR)

$(OBJDIR)/%.o:	$(SRC)/%.cpp
	@echo Building $@
	@$(CXX) $(CFLAGS) -c $(BOOST_CXXFLAGS) $(INC) $< -o $@ $(BOOST_LIBS)
	@echo Done Building $@

link:	$(OBJS)
	@echo Linking files... 
	$(CXX) -shared $(CFLAGS) -o $(LIBDIR)/libutil.so $(OBJS)

clean:
	@echo Cleaning $(OBJDIR) $(TARGET) $(wildcard *.o)...
	@rm -f $(TARGET) $(wildcard *.o)
	@rm -rf $(OBJDIR)
	@echo Done Cleaning...

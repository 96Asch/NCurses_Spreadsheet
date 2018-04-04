MAKE = make
SRC = src
MODEL = $(SRC)/model
VIEW = $(SRC)/view
CONTROL = $(SRC)/controller
UTIL = $(SRC)/util

CURRDIR = $(shell pwd)
CXX = g++ 
CFLAGS = -std=c++14 -Wall -g -Wextra -pedantic 
OBJDIR = bin
LIBDIR = src/lib
INC = -I$(UTIL)/include -I$(MODEL)/include #-I$(VIEW)/include $-I(CONTROL)/include

LIBS = -lcurses -lmodel -lutil
BOOST_LIBS =  -lboost_unit_test_framework
BOOST_CXXFLAGS = -I/vol/share/groups/liacs/scratch/pt2018/include -DBOOST_TEST_DYN_LINK
LDFLAGS = -L$(LIBDIR) -L/vol/share/groups/liacs/scratch/pt2018/lib

TARGET = spreadsheet

.PHONY: all clean

all: $(LIBDIR) obj $(TARGET)
	@echo Done Building...	

$(OBJDIR):
	@echo Making bin directory
	@mkdir $(OBJDIR)

$(LIBDIR):
	@echo Making $(LIBDIR) directory
	@mkdir $(LIBDIR)
	
obj: 
	@echo Make $(MODEL) object
	@+$(MAKE) -C $(UTIL)
	@+$(MAKE) -C $(MODEL)
#	@echo Make $(VIEW) object
#	@+$(MAKE) -C $(VIEW)
#	@echo Make $(CONTROL) object
#	@+$(MAKE) -C $(CONTROL)

    
$(TARGET):	src/main.cpp
	@echo Building executable $@
	$(CXX) $(CFLAGS) $(LDFLAGS) $(INC) -o $@ $^ $(LIBS)
	
#	export LD_LIBRARY_PATH="src/lib"

clean:
	@echo Cleaning $(OBJDIR) $(LIBDIR) $(TARGET) $(wildcard *.o)...
	@rm -f $(TARGET) $(wildcard *.o)
	@+$(MAKE) -C $(UTIL) $@
	@+$(MAKE) -C $(MODEL) $@
	@+$(MAKE) -C $(VIEW) $@
	@+$(MAKE) -C $(CONTROL) $@
	@rm -rf $(OBJDIR) $(LIBDIR)
	@echo Done Cleaning...

MAKE = make

SRC = src
MODEL = $(SRC)/model
VIEW = $(SRC)/view
CONTROL = $(SRC)/controller
UTIL = $(SRC)/util

CXX = g++ 
CFLAGS = -std=c++14 -Wall -g -Wextra -pedantic 
OBJDIR = bin
LIBDIR = src/lib
TESTDIR = src/test

INC = -I$(UTIL)/include -I$(MODEL)/include #-I$(VIEW)/include $-I(CONTROL)/include

LIBS = -lcurses -lmodel -lutil
BOOST_LIBS =  -lboost_unit_test_framework
BOOST_CXXFLAGS = -I/vol/share/groups/liacs/scratch/pt2018/include -DBOOST_TEST_DYN_LINK
LDFLAGS = -L$(LIBDIR) -L/vol/share/groups/liacs/scratch/pt2018/lib

TARGET = spreadsheet
TESTERS = modeltest
.PHONY: all clean

all: build $(TARGET)
	@echo Done Building...	

build: $(LIBDIR) obj 

$(LIBDIR):
	@echo Making $(LIBDIR) directory
	@mkdir $(LIBDIR)

$(TEST):
	@echo Making test directory
	@mkdir $(TEST)
	
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
	@$(CXX) $(CFLAGS) $(LDFLAGS) $(INC) -o $@ $^ $(LIBS)

check: $(TEST) build $(TESTERS)
	@./maintest

$(TESTERS):	$(SRC)/modeltest.cpp
	@$(CXX) $(CFLAGS) $(LDFLAGS) $(INC) -o maintest $^ $(LIBS)
	
dist: clean
	tar -czvf opdracht2-s1913999-s1437267-s1551973-s1453440.tar.gz src/ Makefile README.MD --exclude=".*"

clean:
	@echo Cleaning $(OBJDIR) $(LIBDIR) $(TARGET) $(wildcard *.o)...
	@rm -f $(TARGET) $(wildcard *.o)
	@+$(MAKE) -C $(UTIL) $@
	@+$(MAKE) -C $(MODEL) $@
	@+$(MAKE) -C $(VIEW) $@
	@+$(MAKE) -C $(CONTROL) $@
	@rm -rf $(LIBDIR) $(TEST)
	@echo Done Cleaning...

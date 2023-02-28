CPPSRCS := $(wildcard *.cpp)
CPPBINS := $(patsubst %.cpp,%,$(CPPSRCS))
CSRCS := $(wildcard *.c)
CBINS := $(patsubst %.c,%,$(CSRCS))

CC := /usr/local/opt/llvm/bin/clang
CXX := $(CC)++

CFLAGS := $(CFLAGS) -fsanitize=address
CXXFLAGS := $(CXXFLAGS) -std=c++11
CXXFLAGS := $(CXXFLAGS) -fsanitize=address

all: $(CPPBINS) $(CBINS)

$(CPPBINS):

$(CBINS):

clean:
	rm -f $(CPPBINS) $(CBINS)
	rm -rf $(patsubst %.cpp,%.dSYM,$(CPPSRCS))

CPPSRCS := $(wildcard *.cpp)
CPPBINS := $(patsubst %.cpp,%,$(CPPSRCS))
CSRCS := $(wildcard *.c)
CBINS := $(patsubst %.c,%,$(CSRCS))

# Depends on the environment and requirements
# CC := /usr/local/opt/llvm/bin/clang
# CXX := $(CC)++
# CXXFLAGS := $(CXXFLAGS) -std=c++11

CFLAGS := $(CFLAGS) -fsanitize=address
CXXFLAGS := $(CXXFLAGS) -fsanitize=address
# Build symbols
CFLAGS := $(CFLAGS) -g
CXXFLAGS := $(CXXFLAGS) -g

all: $(CPPBINS) $(CBINS)

$(CPPBINS):

$(CBINS):

clean:
	rm -f $(CPPBINS) $(CBINS)
# Xcode
#	rm -rf $(patsubst %.cpp,%.dSYM,$(CPPSRCS))

CC=g++
CFLAGS=-Wall -pedantic -Werror -std=c++17 -g
LDFLAGS=-lm

SRCDIR=src
OBJDIR=obj
BINDIR=bin

SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(patsubst %.cpp,%.o,$(subst $(SRCDIR)/,,$(SOURCES)))
TARGET=main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(BINDIR)/$@ $(foreach o,$^,$(OBJDIR)/$(o)) $(LDFLAGS)

%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$@

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/$< -o $(OBJDIR)/$@

run: all
	$(BINDIR)/$(TARGET) ./test_data/matrix_3_3_p5.txt ./test_data/rhs_3_p5.txt

test: all
	$(BINDIR)/$(TARGET) ./test_data/matrix_5_4_frac.txt ./test_data/rhs_5_frac.txt
	$(BINDIR)/$(TARGET) ./test_data/matrix_4_4_frac.txt ./test_data/rhs_4_frac.txt
	$(BINDIR)/$(TARGET) ./test_data/matrix_5_4.txt ./test_data/rhs_5.txt

clean:
	rm -rf $(BINDIR)/*
	rm -rf $(OBJDIR)/*

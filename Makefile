CXX=g++
CXXFLAGS=-O2 -std=c++17 -flto

SRC=main.cpp
BIN=sudo-kaomoji

PREFIX=/usr/local

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

install:
	cp $(BIN) $(DESTDIR)$(PREFIX)/bin/$(BIN)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(BIN)

clean:
	rm -f $(BIN)

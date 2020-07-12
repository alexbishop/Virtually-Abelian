CC=g++
CFLAGS=--std=c++17 -I ./inc -O2
BINARY=bin/geodesic_growth
SOURCE=src/*.cpp ./src/**/*.cpp
OUTPUT_DIR=output

.PHONY: all clean run

all:
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(BINARY) $(SOURCE)

clean:
	rm -f $(BINARY)
	rmdir --ignore-fail-on-non-empty bin

run:
	mkdir -p $(OUTPUT_DIR)
	cd $(OUTPUT_DIR) && ../$(BINARY)


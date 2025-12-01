CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -O0
TARGET = a.exe
SOURCES = main.c 
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q $(OBJECTS) $(TARGET)

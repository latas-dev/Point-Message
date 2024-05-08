CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11
TARGET  = ./bin/Point-Message

all: $(TARGET)

$(TARGET): main.o message.o
    $(CC) $(CFLAGS) -o $(TARGET) main.o message.o

main.o: main.c message.h
    $(CC) $(CFLAGS) -c main.c

message.o: message.c message.h
    $(CC) $(CFLAGS) -c message.c

clean:
    rm -f $(TARGET) *.o
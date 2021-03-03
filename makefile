CC=gcc
CFLAGS=-c -Wall - Werror
SOURCES= geometry/main.c geometry/geometry.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=geom.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf */*.o
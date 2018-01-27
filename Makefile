CC=clang++
CPPFLAGS=-std=c++17 -I.
LDFLAGS=-lpthread
SOURCES = image.cpp lucy.cpp main.cpp my_stream.cpp person.cpp
OBJS = $(SOURCES:.cpp=.o)
MAIN = lucy

$(MAIN): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(MAIN) $(OBJS) $(LDFLAGS)

.cpp.o:
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(MAIN)

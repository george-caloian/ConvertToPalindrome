CC=gcc
CXXFLAGS= -g
build: joc evaluare

joc: joc.c
	$(CC) $(CXXFLAGS) -o $@ $^

evaluare: evaluare.c
	$(CC) $(CXXFLAGS) -o $@ $^

run-p1:
	./joc && cat joc.out

run-p2:
	./evaluare && cat evaluare.out

clean:
	rm joc evaluare
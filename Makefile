CC ?= cc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -o
SRC = 2.c
X = b2q b2o b2x o2b o2q o2x d2b d2q d2o d2x x2b x2q x2o

.PHONY: all clean install

all: $X

install: all
	@mv $X /bin

clean:
	@rm -f $X; rm -f $(patsubst %, /bin/%, $X)

b2q: $(SRC)
	@$(CC) $(CFLAGS) $@ -D B2 -D Q $(SRC)

b2o: $(SRC)
	@$(CC) $(CFLAGS) $@ -D B2 -D O $(SRC)

b2x: $(SRC)
	@$(CC) $(CFLAGS) $@ -D B2 -D X $(SRC)

q2b: $(SRC)
	@$(CC) $(CFLAGS) $@ -D Q2 -D B $(SRC)

q2o: $(SRC)
	@$(CC) $(CFLAGS) $@ -D Q2 -D O $(SRC)

q2x: $(SRC)
	@$(CC) $(CFLAGS) $@ -D Q2 -D X $(SRC)

o2b: $(SRC)
	@$(CC) $(CFLAGS) $@ -D O2 -D B $(SRC)

o2q: $(SRC)
	@$(CC) $(CFLAGS) $@ -D O2 -D Q $(SRC)

o2x: $(SRC)
	@$(CC) $(CFLAGS) $@ -D O2 -D X $(SRC)

d2b: $(SRC)
	@$(CC) $(CFLAGS) $@ -D B $(SRC)

d2q: $(SRC)
	@$(CC) $(CFLAGS) $@ -D Q $(SRC)

d2o: $(SRC)
	@$(CC) $(CFLAGS) $@ -D O $(SRC)

d2x: $(SRC)
	@$(CC) $(CFLAGS) $@ -D X $(SRC)

x2b: $(SRC)
	@$(CC) $(CFLAGS) $@ -D X2 -D B $(SRC)

x2q: $(SRC)
	@$(CC) $(CFLAGS) $@ -D X2 -D Q $(SRC)

x2o: $(SRC)
	@$(CC) $(CFLAGS) $@ -D X2 -D O $(SRC)

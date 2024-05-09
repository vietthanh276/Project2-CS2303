register: register.o coffee_shop.o
	gcc -g -Wall coffee_shop.o register.o -lm -o register 

register.o: register.h register.c
	gcc -g -Wall -c register.c

coffee_shop.o: register.h coffee_shop.c
	gcc -g -Wall -c coffee_shop.c

clean:
	rm -f register.o coffee_shop.o register

all: register
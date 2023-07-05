# Dylan Schultz
# SE 3800 Assignment 2

# makefile for calendar code

all: calendar calendar_test

test: calendar_test
	./calendar_test

calendar.o: calendar.h calendar.cpp
	g++ -std=c++14 -Wall -c calendar.cpp

calendar_test.o: calendar.h calendar_test.cpp
	g++ -std=c++14 -Wall -c calendar_test.cpp

main.o: calendar.h main.cpp
	g++ -std=c++14 -Wall -c main.cpp

calendar: calendar.o main.o
	g++ -std=c++14 -Wall calendar.o main.o -o calendar

calendar_test: calendar.o calendar_test.o
	g++ -pthread -std=c++14 -Wall calendar.o calendar_test.o -lgtest_main -lgtest -lpthread -o calendar_test

clean:
	rm -f *.o calendar calendar_test

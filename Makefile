QueueDemo: main.o QueueTester.o
	g++ -g -Wall -std=c++11 main.o Queue.o QueueTester.o -o QueueDemo

main.o: main.cpp QueueTester.h
	g++ -g -std=c++11 -c main.cpp

QueueTester.o: QueueTester.h QueueTester.cpp
	g++ -g -std=c++11 -c QueueTester.cpp

clean:
	rm main.o *.*~QueueDemo

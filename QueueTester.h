#ifndef QUEUE_TESTER_H
#define QUEUE_TESTER_H

#include "Queue.h"
#include <iostream>
#include <stdlib.h> //srand,rand
#include <time.h> //time
using namespace std;

class QueueTester
{
  public:
    QueueTester();
    ~QueueTester(){};
    //run all the test methods
    void runTests();
    int enqueueTest3Num = 0;
  private:
    void constructorTest();
    void isEmptyTest1();
    void isEmptyTest2();
    void isEmptyTest3();
    void enqueueTest1();
    void enqueueTest2();
    void enqueueTest3();
    void enqueueTest4();
    void enqueueTest5();
    void enqueueTest6();
    void dequeueTest1();
    void dequeueTest2();
    void valgrindTest();
    void test13();
    void test14();
    void test15();


};
#endif

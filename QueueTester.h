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
    int test6Num = 0;
  private:
  //isEmpty() TESTS:
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
    void test6();
    void test7();
    void test8();
    void test9();
    void test10();
    void test11();
    void test12();
    void test13();
    void test14();
    void test15();


};
#endif

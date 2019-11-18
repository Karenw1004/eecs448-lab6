#include "QueueTester.h"

QueueTester::QueueTester(){
  runTests();
}
void QueueTester::runTests(){
  // cout << "Queue() TEST\n";
  // constructorTest();
  // cout << "\nisEmpty() TEST \n";
  // isEmptyTest1();
  // isEmptyTest2(); // 1 leak
  // isEmptyTest3();
  cout << "\nEnqueue() TEST\n";
  enqueueTest1(); // 1 leak
  enqueueTest2();
  enqueueTest3(); //randomnum + 1 leak
  enqueueTest4(); // 3 leak
  enqueueTest5(); // 3 leak
  enqueueTest6(); // 3 leak
  cout << "\nDeqeue() TEST\n";
  dequeueTest1();
  dequeueTest2(); // 1 leak
  cout << "\n~Queue() MANUAL TEST WIH VALGRIND\n";
  valgrindTest();
}
void QueueTester::constructorTest(){
  Queue myQueue;
  cout << "Test #1: Creates an empty queue";
  if (myQueue.isEmpty()){ cout << " PASSED\n";}
  else { cout << " FAILED\n";  }
  cout << "Test #2: Check peekFront() throws an error";
  try{
    cout << myQueue.peekFront();
    cout << " FAILED\n";
  }catch(runtime_error& e){
    cout << " PASSED\n";
  }
  cout << "Test #3: Check dequeue() throws an error";
  try{
    myQueue.dequeue();
    cout << " FAILED\n";
  }catch(runtime_error& e){
    cout << " PASSED\n";
  }
}

void QueueTester::isEmptyTest1(){
  Queue myQueue;
  cout << "Test #1: An empty Queue is empty";
  if (myQueue.isEmpty()){ cout << " PASSED\n";}
  else { cout << " FAILED\n";  }
}
void QueueTester::isEmptyTest2(){
  Queue myQueue;
  cout << "Test #2: Add one node to a empty Queue returns false ";
  srand (time(NULL));
  int randomNum = rand()%101; // range 0-100
  myQueue.enqueue(randomNum);
  if (myQueue.isEmpty()) cout << " FAILED\n";
  else cout << " PASSED\n";
}
void QueueTester::isEmptyTest3(){
  Queue myQueue;
  cout << "Test #3: Remove the added one node to a Queue with one node returns true ";
  srand (time(NULL));
  int randomNum = rand()%101; // range 0-100
  myQueue.enqueue(randomNum);
  myQueue.dequeue();
  if (myQueue.isEmpty()){ cout << " PASSED\n";}
  else { cout << " FAILED\n";  }
}

void QueueTester::enqueueTest1(){
  Queue myQueue;
  cout << "Test #1: Add 1 to an Empty Queue, check peekFront() == 1 ";
  myQueue.enqueue(1);
  if (myQueue.peekFront() == 1){ cout << " PASSED\n";}
  else { cout << " FAILED\n";  }
}
void QueueTester::enqueueTest2(){
  Queue myQueue;
  cout << "Test #2: Enqueue 1(first),2 and 3(back)  and check peekFront() == 1 ";
  myQueue.enqueue(1); //1
  myQueue.peekFront(); // output = 1 expect = 1
  myQueue.enqueue(2); //[1,2]
  myQueue.peekFront(); // output = 2 expect = 1
  myQueue.enqueue(3); //[1,2,3]
  cout << myQueue.peekFront(); // output = 3 expect = 1
  if (myQueue.peekFront() == 1){ cout << " PASSED\n";}
  else if (myQueue.peekFront() == 3){
    cout << " FAILED (returns the back 3)\n";
    cout << " BUG: peekFront() returns the m_back not m_front \n";
 }
  else {cout << " FAILED \n";}
}
void QueueTester::enqueueTest3(){
  Queue myQueue;
  cout << "Test 3: Enqueue 1(first),2 and 3(back)  and check peekFront() == 1 ";
  myQueue.enqueue(1); //[1]
  myQueue.dequeue(); // []
  myQueue.enqueue(2); //[2]
  myQueue.peekFront(); // output = 2 expect = 2
  myQueue.enqueue(3); //[2,3]
  cout << myQueue.peekFront(); // output = 3 expect = 2
  myQueue.dequeue(); //[3]
  cout << myQueue.peekFront(); //output = 2 expect 3

}
void QueueTester::enqueueTest4(){

}
void QueueTester::enqueueTest5(){
  Queue myQueue;
  cout << "Test #5: Enqueue 1,2,3 , do peekFront(), check if peekFront() change the queue with isEmpty()  ";
  srand (time(NULL));
  int randomNum = rand()%101; // range 0-100
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  myQueue.peekFront();
  if (myQueue.isEmpty()) {cout << "FAILED\n";}
  else {cout << "PASSED\n";}
}
void QueueTester::enqueueTest6(){
  Queue myQueue;
  cout << "Test #6: Enqueue 1,2,3 , do peekFront(), check if peekFront() change the queue with isEmpty()  ";
  srand (time(NULL));
  int randomNum = rand()%101; // range 0-100
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  myQueue.peekFront();
  if (myQueue.isEmpty()) {cout << "FAILED\n";}
  else {cout << "PASSED\n";}
}
void QueueTester::dequeueTest1(){
  Queue myQueue;
  cout << "Test #1: Create an Empty Queue and check if Dequeue throws error ";
  try{
    myQueue.dequeue();
    cout << " FAILED\n";
  }catch(runtime_error& e){
    cout << " PASSED\n";
  }
}
void QueueTester::dequeueTest2(){
  Queue myQueue;
  cout << "Test #2: Enqueue 1,2,3 ,dequeue twice and check peekFront() == 3 ";
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  // myQueue.enqueue(4);
  // myQueue.enqueue(5);
  myQueue.dequeue();
  myQueue.dequeue();
  if (myQueue.peekFront() == 3){ cout << "  PASSED\n";}
  else if (myQueue.peekFront() == 1) {
    cout << "  FAILED (return 1)\n";
    cout << "  BUG: dequeue() delete the m_back not the m_front!\n";
  }

}
void QueueTester::valgrindTest(){
  Queue myQueue;
  cout << "Test #12: ~Queue() no memory leak FAILED \n";
  cout << ">>TEST2: 1 LEAK\n";
  cout << ">>TEST4: 1 LEAK\n";
  cout << ">>TEST6: "<< enqueueTest3Num << "+1 LEAK\n";
  cout << ">>TEST7: 3 LEAK\n";
  cout << ">>TEST8: 3 LEAK\n";
  cout << ">>TEST9: 3 LEAK\n";
  cout << ">>TEST11: 1 LEAK\n";
  int memoryLeak = 1+1+enqueueTest3Num+1+3+3+3+1;
  cout << "HAVE NOT FREE " << memoryLeak << " MEMORY LEAK IN THE HEAP USAGE\n";
  cout << "BUG: ~Queue is likely to be empty\n";
}

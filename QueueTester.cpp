#include "QueueTester.h"

QueueTester::QueueTester(){
  runTests();
}
void QueueTester::runTests(){
  cout << "Queue() TEST\n";
  cout << "@post Creates an empty queue\n";
  constructorTest();
  cout << "\nisEmpty() TEST \n";
  cout << "@return True if the queue is empty, false otherwise\n";
  isEmptyTest1();
  isEmptyTest2();
  isEmptyTest3();
  isEmptyTest4();
  cout << "\nEnqueue() TEST\n";
  cout << "@post Entry added to back of queue\n";
  cout << "@param newEntry The object to be added as a new entry\n";
  enqueueTest1(); //
  enqueueTest2();
  enqueueTest3(); //
  enqueueTest4(); //
  enqueueTest5(); //
  cout << "\nDeqeue() TEST\n";
  cout << "@throw std::runtime_error if queue is empty\n";
  dequeueTest1();
  cout << "@post Front of the queue is removed\n";
  dequeueTest2(); //
  dequeueTest3(); //
  cout << "@return The value of the entry at the front of the queue\n";
  cout << "No test for this (dequeue should not return anything since it is void)\n";
  cout << "\n~Queue() MANUAL TEST WIH VALGRIND\n";
  cout << "@post Deletes all entries in the queue\n";
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
  myQueue.enqueue(1);
  myQueue.dequeue();
  if (myQueue.isEmpty()){ cout << " PASSED\n";}
  else { cout << " FAILED\n";  }
}
void QueueTester::isEmptyTest4(){
  Queue myQueue;
  cout << "Test #4: Enqueue multiple times,check if Queue is not empty ";
  srand (time(NULL));
  for (int i = 0; i < 7; i++){
    myQueue.enqueue(7);
  }
  if (myQueue.isEmpty()){ cout << " FAILED\n";}
  else { cout << " PASSED\n";  }
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
  myQueue.peekFront(); // output = 3 expect = 1
  if (myQueue.peekFront() == 1){ cout << " PASSED\n";}
  else if (myQueue.peekFront() == 3){
    cout << " FAILED (returns the back 3)\n";
 }
  else {cout << " FAILED \n";}
}
void QueueTester::enqueueTest3(){
  Queue myQueue;
  cout << "Test #3: Enqueue 1,dequeue, Enqueue 2(first)and 3(back) and check peekFront() == 2";
  myQueue.enqueue(1); //[1]
  myQueue.dequeue(); // []
  myQueue.enqueue(2); //[2]
  myQueue.peekFront(); // output = 2 expect = 2
  myQueue.enqueue(3); //[2,3]
  myQueue.peekFront(); // output = 3 expect = 2
  myQueue.dequeue(); //[3]
  if (myQueue.peekFront() == 2)  //output = 2 expect 3
  {
    cout<< " PASSED\n";
  } else {
    cout << " FAILED\n";
  }
}
void QueueTester::enqueueTest4(){
  Queue myQueue;
  cout << "Test #4: Enqueue, peekFront(), check if peekFront() change the queue with isEmpty()  ";
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  myQueue.peekFront();
  if (myQueue.isEmpty()) {cout << "FAILED\n";}
  else {cout << "PASSED\n";}
}
void QueueTester::enqueueTest5(){
  Queue myQueue;
  cout << "Test #5: Add 1,peek,add 2,peek,add 3. Peek three times will be 1 1 1\n";
  int firstNum , secondNum ,thirdNum ;
  myQueue.enqueue(1); //[1]
  firstNum = myQueue.peekFront() ; //output is 1 expect is 1
  myQueue.enqueue(2); //[1,2]
  secondNum = myQueue.peekFront() ; //2 expect is 1
  myQueue.enqueue(3); //[1,2,3]
  thirdNum = myQueue.peekFront() ;// 3 expect is 1
  cout << "\t\t\t\t      ";
  cout << "Output is " << firstNum << " " << secondNum << " " << thirdNum ;
  cout << "  FAILED\n";


}

void QueueTester::dequeueTest1(){
  Queue myQueue;
  cout << "Test #1: Dequeue an Empty queue throws error ";
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
  myQueue.dequeue();
  myQueue.dequeue();
  if (myQueue.peekFront() == 3){ cout << "  PASSED\n";}
  else if (myQueue.peekFront() == 1) {
    cout << "  FAILED \n";
  }
}
void QueueTester::dequeueTest3(){
  Queue myQueue;
  cout << "Test #3: Enqueue 1,2,3 dequeue 3 times ,check isEmpty is true ";
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  myQueue.dequeue();
  myQueue.dequeue();
  myQueue.dequeue();
  if (myQueue.isEmpty()){ cout << "  PASSED\n";}
  else { cout << "  FAILED \n";}
}
void QueueTester::valgrindTest(){
  Queue myQueue;
  cout << "Test #1: ~Queue() no memory leak FAILED \n";
}

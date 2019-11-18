#include "QueueTester.h"

QueueTester::QueueTester(){
  runTests();
}
void QueueTester::runTests(){
  cout << "isEmpty() TEST \n";
  test1();
  test2(); // 1 leak
  test3();
  cout << "Enqueue() TEST\n";
  test4(); // 1 leak
  cout << "Enqueue()+peekFront() TEST\n";
  test5();
  test6(); //randomnum + 1 leak
  test7(); // 3 leak
  test8(); // 3 leak
  test9(); // 3 leak
  cout << "Deqeue() TEST\n";
  test10();
  test11(); // 1 leak
  cout << "~Queue() MANUAL TEST WIH VALGRIND\n";
  test12();
}
void QueueTester::test1(){
  Queue myQueue;
  cout << "Test #1: An empty Queue is empty";
  if (myQueue.isEmpty()){ cout << " PASSED\n";}
  else { cout << " FAILED\n";  }
}
void QueueTester::test2(){
  Queue myQueue;
  cout << "Test #2: Add one node(type:int) to a empty Queue returns false ";
  srand (time(NULL));
  int randomNum = rand()%101; // range 0-100
  myQueue.enqueue(randomNum);
  if (myQueue.isEmpty()) cout << " FAILED\n";
  else cout << " PASSED\n";
}
void QueueTester::test3(){
  Queue myQueue;
  cout << "Test #3: Remove the added one node(type:int) to a Queue with one node returns true ";
  srand (time(NULL));
  int randomNum = rand()%101; // range 0-100
  myQueue.enqueue(randomNum);
  myQueue.dequeue();
  if (myQueue.isEmpty()){ cout << " PASSED\n";}
  else { cout << " FAILED\n";  }

}
void QueueTester::test4(){
  Queue myQueue;
  cout << "Test #4: Add 1 (type:int) to an Empty Queue, check m_front with peekFront() ";
  srand (time(NULL));
  int randomNum = rand()%101; // range 0-100
  myQueue.enqueue(randomNum);
  if (myQueue.peekFront() == randomNum){ cout << " PASSED\n";}
  else { cout << " FAILED\n";  }
}
void QueueTester::test5(){
  Queue myQueue;
  cout << "Test #5: Create an empty Queue and check if peekFront throws error ";
  try{
    cout << myQueue.peekFront();
    cout << " FAILED\n";
  }catch(runtime_error& e){
    // cout << e.what();
    cout << " PASSED\n";
  }
}
void QueueTester::test6(){
  Queue myQueue;
  cout << "Test #6: Enqueue random time [Ex: randNum=5],add randomNum+i [5,6,7,8,9] and check peekFront() == randomNum [5] ";
  srand (time(NULL));
  test6Num = rand()%101; // range 0-100
  myQueue.enqueue(test6Num);
  for (int i=0; i < test6Num ; i++){
    myQueue.enqueue(test6Num+i);
  }
  if (myQueue.peekFront() == test6Num){ cout << " PASSED\n";}
  else { cout << " FAILED\n";  }
  cout << "RANDNUM IS " << test6Num << endl;
}
void QueueTester::test7(){
  Queue myQueue;
  cout << "Test #7: Enqueue 1(first),2 and 3(back)  and check peekFront() == 1 ";
  srand (time(NULL));
  int randomNum = rand()%101; // range 0-100
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  if (myQueue.peekFront() == 1){ cout << " PASSED\n";}
  else if (myQueue.peekFront() == 3){
    cout << " FAILED (returns the back 3)\n";
    cout << " BUG: peekFront() returns the m_back not m_front \n";
 }
  else {cout << " FAILED \n";}
}
void QueueTester::test8(){
  Queue myQueue;
  cout << "Test #8: Enqueue 1,2,3 , do peekFront(), check if peekFront() change the queue with isEmpty()  ";
  srand (time(NULL));
  int randomNum = rand()%101; // range 0-100
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  myQueue.peekFront();
  if (myQueue.isEmpty()) {cout << "FAILED\n";}
  else {cout << "PASSED\n";}
}
void QueueTester::test9(){
  Queue myQueue;
  cout << "Test #9: Enqueue 1,2,3 , do peekFront(), check if peekFront() change the queue with isEmpty()  ";
  srand (time(NULL));
  int randomNum = rand()%101; // range 0-100
  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  myQueue.peekFront();
  if (myQueue.isEmpty()) {cout << "FAILED\n";}
  else {cout << "PASSED\n";}
}
void QueueTester::test10(){
  Queue myQueue;
  cout << "Test #10: Create an Empty Queue and check if Dequeue throws error ";
  try{
    myQueue.dequeue();
    cout << " FAILED\n";
  }catch(runtime_error& e){
    cout << " PASSED\n";
  }
}
void QueueTester::test11(){
  Queue myQueue;
  cout << "Test #11: Enqueue 1,2,3 ,dequeue twice and check peekFront() == 3 ";
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
void QueueTester::test12(){
  Queue myQueue;
  cout << "Test #12: ~Queue() no memory leak FAILED \n";
  cout << ">>TEST2: 1 LEAK\n";
  cout << ">>TEST4: 1 LEAK\n";
  cout << ">>TEST6: "<< test6Num << "+1 LEAK\n";
  cout << ">>TEST7: 3 LEAK\n";
  cout << ">>TEST8: 3 LEAK\n";
  cout << ">>TEST9: 3 LEAK\n";
  cout << ">>TEST11: 1 LEAK\n";
  int memoryLeak = 1+1+test6Num+1+3+3+3+1;
  cout << "HAVE NOT FREE " << memoryLeak << " MEMORY LEAK IN THE HEAP USAGE\n";
  cout << "BUG: ~Queue is likely to be empty\n";
}

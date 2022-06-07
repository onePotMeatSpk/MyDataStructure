using namespace std;
#include"MyHeap.h"
int main()
{

	MyHeap heap(0);

	heap.push(1);
	cout << "after push 1: " << heap.top() << endl;
	heap.print();

	heap.push(5);
	cout << "after push 5: " << heap.top() << endl;
	heap.print();
	heap.push(10);
	cout << "after push 10: " << heap.top() << endl;
	heap.print();
	heap.push(15);
	cout << "after push 15: " << heap.top() << endl;
	heap.print();
	heap.push(20);
	cout << "after push 20: " << heap.top() << endl;
	heap.print();
	heap.push(25);
	cout << "after push 25: " << heap.top() << endl;
	heap.print();
	heap.push(30);
	cout << "after push 30: " << heap.top() << endl;
	heap.print();
	heap.push(-1);
	cout << "after push -1: " << heap.top() << endl;
	heap.print();
	heap.push(-5);
	cout << "after push -5: " << heap.top() << endl;
	heap.print();
	heap.push(-10);
	cout << "after push -10: " << heap.top() << endl;
	heap.print();
	heap.push(-15);
	cout << "after push -15: " << heap.top() << endl;
	heap.print();
	heap.push(-20);
	cout << "after push -20: " << heap.top() << endl;
	heap.print();
	heap.push(-25);
	cout << "after push -25: " << heap.top() << endl;
	heap.print();
	heap.push(-30);
	cout << "after push -30: " << heap.top() << endl;
	heap.print();



	heap.pop();
	cout << "after pop: " << heap.top() << endl;
	heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl;
	heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl;
	heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl;
	heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl; heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl; heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl; heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl; heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl; heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl; heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl; heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl; heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl; heap.print();
	heap.pop();
	cout << "after pop: " << heap.top() << endl; heap.print();
	return 0;
}
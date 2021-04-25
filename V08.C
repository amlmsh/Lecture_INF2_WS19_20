/*
 * V08.C
 *
 *  Created on: 23.06.2018
 *      Author: aml
 */

#include "V08.H"

namespace V08{


/**
 *
 * test if an instantiated stack
 * object is empty
 *
 */
bool TestStack::unitTest0(){
	Stack<int> stack;

	if(!stack.isEmpty()){
		return false; // stack should be empty
	};

	stack.push(1);
	if(stack.isEmpty()){
		return false; // stack shouldn't be empty
	}

	stack.pop();
	if(!stack.isEmpty()){
		return false; // stack should be empty again
	}

	return true;
}



/**
 *
 * test exception throwing when reading
 * the empty stack
 *
 */
bool TestStack::unitTest1(){
	Stack<int> stack;
	try{
		stack.pop();
		return false;
	}catch(...){
		return true;
	}
}


/**
 *
 * test exception throwing when reading
 * when stack is again empty after one
 * reading
 *
 */
bool TestStack::unitTest2(){
	Stack<int> stack;
	try{
		stack.push(11);
		stack.pop();
	}catch(...){
		return false;
	}

	try{
		stack.pop();
		return false;
	}catch(...){
		return true;
	}

}


/**
 *
 * test the elements when reading
 * in and out
 *
 */
bool TestStack::unitTest3(){
	Stack<int> stack;

	int a,b,c, tmp;
	a = 1;
	b = 11;
	c = 111;

	try{
		stack.push(a);
		stack.push(b);
		stack.push(c);
	}catch(...){
		cout << "unknown error while inserting\n"; cout.flush();
		return false;
	}

	try{
		tmp = stack.pop();
		if(tmp != c){cout << tmp << " != " << c << endl ;return false;}
		tmp = stack.pop();
		if(tmp != b){cout << tmp << " != " << b << endl ;return false;}
		tmp = stack.pop();
		if(tmp != a){cout << tmp << " != " << a << endl ;return false;}

		return true;
	}catch(string msg){
		cout << msg << endl; cout.flush();
		return false;
	}catch(...){
		cout << "unknown error while removing\n"; cout.flush();
		return false;
	}
}


/**
 *
 * test insertion and removing of a lot of elements
 *
 */
bool TestStack::unitTest4(){
	Stack<int> stack;
	int n = 9999999;
	int t;
	try{
		for(int i=0; i<n; i++){
			stack.push(i);
		}
		for(int i=0; i<n; i++){
			t = stack.pop();
		}

		if(stack.isEmpty()){
			return true;
		}else{
			return false;
		}
	}catch(...){
		return false;
	}
}





/**
 *
 * test if an instantiated queue
 * object is empty
 *
 */
bool TestQueue::unitTest0(){
	Queue<int> q;

	if(!q.isEmpty()){
		return false; // stack should be empty
	};



	q.enqueue(1);
	if(q.isEmpty()){
		return false; // stack shouldn't be empty
	}



	q.dequeue();
	if(!q.isEmpty()){
		return false; // stack should be empty again
	}

	return true;
}



/**
 *
 * test exception throwing when reading
 * the empty queue
 *
 */
bool TestQueue::unitTest1(){
	Queue<int> q;
	try{
		q.dequeue();
		return false;
	}catch(...){
		return true;
	}
}


/**
 *
 * test exception throwing when reading
 * when queue is again empty after one
 * reading
 *
 */
bool TestQueue::unitTest2(){
	Queue<int> q;
	try{
		q.enqueue(11);
		q.dequeue();
	}catch(...){
		return false;
	}

	try{
		q.dequeue();
		return false;
	}catch(...){
		return true;
	}

}


/**
 *
 * test the elements when reading
 * in and out
 *
 */
bool TestQueue::unitTest3(){
	Queue<int> q;

	int a,b,c, tmp;
	a = 1;
	b = 11;
	c = 111;

	try{
		q.enqueue(a);
		q.enqueue(b);
		q.enqueue(c);
	}catch(...){
		cout << "unknown error while inserting\n"; cout.flush();
		return false;
	}

	try{
		tmp = q.dequeue();
		if(tmp != a){cout << tmp << " != " << c << endl ;return false;}
		tmp = q.dequeue();
		if(tmp != b){cout << tmp << " != " << b << endl ;return false;}
		tmp = q.dequeue();
		if(tmp != c){cout << tmp << " != " << a << endl ;return false;}

		return true;
	}catch(string msg){
		cout << msg << endl; cout.flush();
		return false;
	}catch(...){
		cout << "unknown error while removing\n"; cout.flush();
		return false;
	}
}


/**
 *
 * test insertion and removing of a lot of elements
 *
 */
bool TestQueue::unitTest4(){
	Queue<int> q;
	int n = 9999999;
	int t;
	try{
		for(int i=0; i<n; i++){
			q.enqueue(i);
		}
		for(int i=0; i<n; i++){
			t = q.dequeue();
		}

		if(q.isEmpty()){
			return true;
		}else{
			return false;
		}
	}catch(...){
		return false;
	}
}



/**
 *
 * test if an instantiated list
 * object is empty
 *
 */
bool TestList::unitTest0() {
	List<int> list;
	List<int> list1;

	if (!list.isEmpty()) {
		cout << "1:list should be empty\n";
		return false; // list should be empty
	};

	list.prepend(1);
	if (list.isEmpty()) {
		cout << "2:list shouldn't be empty\n";
		return false; // list shouldn't be empty
	}

	list.removeFirst();
	if (!list.isEmpty()) {
		cout << "3:list should be empty\n";
		return false; // list should be empty again
	}

	list1.append(1);
	if (list1.isEmpty()) {
		cout << "4:list shouldn't be empty\n";
		return false; // list shouldn't be empty
	}

	list1.removeFirst();
	if (!list1.isEmpty()) {
		cout << "5:list should be empty\n";
		return false; // list should be empty again
	}

	list1.append(1);
	list1.append(2);
	list1.append(3);
	list1.removeFirst();
	list1.removeFirst();
	list1.removeFirst();
	if (!list1.isEmpty()) {
		cout << "6:list should be empty\n";
		return false; // list should be empty
	}


	list1.append(1);
	list1.append(2);
	list1.append(3);
	list1.removeLast();
	list1.removeLast();
	list1.removeLast();
	if (!list1.isEmpty()) {
		cout << "7:list should be empty\n";
		return false; // list should be empty
	}

	return true;
}

/**
 *
 * test exception throwing when reading
 * the empty stack
 *
 */
bool TestList::unitTest1() {
	List<int> list;
	try {
		list.removeFirst();
		return false;
	} catch (...) {
		;
	}

	try {
		list.removeLast();
		return false;
	} catch (...) {
		;
	}
	return true;
}

/**
 *
 * test exception throwing when reading
 * when stack is again empty after one
 * reading
 *
 */
bool TestList::unitTest2() {
	List<int> list;
	try {
		list.prepend(11);
		list.removeFirst();
	} catch (...) {
		return false;
	}

	try {
		list.removeFirst();
		return false;
	} catch (...) {
		return true;
	}

}

/**
 *
 * test the elements when reading
 * in and out
 *
 */
bool TestList::unitTest3() {
	List<int> list;

	int a, b, c, tmp;
	a = 1;
	b = 11;
	c = 111;

	try {
		list.prepend(a);
		list.prepend(b);
		list.prepend(c);
	} catch (...) {
		cout << "unknown error while inserting\n";
		cout.flush();
		return false;
	}

	try {
		tmp = list.removeFirst();
		if (tmp != c) {
			cout << tmp << " != " << c << endl;
			return false;
		}
		tmp = list.removeFirst();
		if (tmp != b) {
			cout << tmp << " != " << b << endl;
			return false;
		}
		tmp = list.removeFirst();
		if (tmp != a) {
			cout << tmp << " != " << a << endl;
			return false;
		}

	} catch (string msg) {
		cout << msg << endl;
		cout.flush();
		return false;
	} catch (...) {
		cout << "unknown error while removing\n";
		cout.flush();
		return false;
	}

	try {
		list.prepend(a);
		list.prepend(b);
		list.prepend(c);
	} catch (...) {
		cout << "unknown error while inserting\n";
		cout.flush();
		return false;
	}

	try {
		tmp = list.removeLast();
		if (tmp != a) {
			cout << tmp << " != " << a << endl;
			return false;
		}
		tmp = list.removeLast();
		if (tmp != b) {
			cout << tmp << " != " << b << endl;
			return false;
		}
		tmp = list.removeLast();
		if (tmp != c) {
			cout << tmp << " != " << c << endl;
			return false;
		}

	} catch (string msg) {
		cout << msg << endl;
		cout.flush();
		return false;
	} catch (...) {
		cout << "unknown error while removing\n";
		cout.flush();
		return false;
	}


	try {
		list.append(a);
		list.append(b);
		list.append(c);
	} catch (...) {
		cout << "unknown error while inserting\n";
		cout.flush();
		return false;
	}

	try {
		tmp = list.removeFirst();
		if (tmp != a) {
			cout << tmp << " != " << a << endl;
			return false;
		}
		tmp = list.removeFirst();
		if (tmp != b) {
			cout << tmp << " != " << b << endl;
			return false;
		}
		tmp = list.removeFirst();
		if (tmp != c) {
			cout << tmp << " != " << c << endl;
			return false;
		}

	} catch (string msg) {
		cout << msg << endl;
		cout.flush();
		return false;
	} catch (...) {
		cout << "unknown error while removing\n";
		cout.flush();
		return false;
	}


	try {
		list.append(a);
		list.append(b);
		list.append(c);
	} catch (...) {
		cout << "unknown error while inserting\n";
		cout.flush();
		return false;
	}

	try {
		tmp = list.removeLast();
		if (tmp != c) {
			cout << tmp << " != " << c << endl;
			return false;
		}
		tmp = list.removeLast();
		if (tmp != b) {
			cout << tmp << " != " << b << endl;
			return false;
		}
		tmp = list.removeLast();
		if (tmp != a) {
			cout << tmp << " != " << a << endl;
			return false;
		}

	} catch (string msg) {
		cout << msg << endl;
		cout.flush();
		return false;
	} catch (...) {
		cout << "unknown error while removing\n";
		cout.flush();
		return false;
	}

	return true;
}

/**
 *
 * test insertion and removing of a lot of elements
 *
 */
bool TestList::unitTest4() {
	List<int> list;
	int n = 9999999;
	int t;
	try {
		for (int i = 0; i < n; i++) {
			list.prepend(i);
		}
		for (int i = 0; i < n; i++) {
			t = list.removeFirst();
		}

		if (list.isEmpty()) {
			;;
		} else {
			return false;
		}


		for (int i = 0; i < n; i++) {
			list.append(i);
		}
		for (int i = 0; i < n; i++) {
			t = list.removeLast();
		}

		if (list.isEmpty()) {
			;;
		} else {
			return false;
		}

		return true;

	} catch (...) {
		return false;
	}
}


}


void demoV08_00() {
	V08::List<int>  l;
	V08::Queue<int> q;
	V08::Stack<int> s;

	l.append(32);
	l.removeLast();
	s.push(1);
	s.pop();
	q.enqueue(12);


	s.print();



	V08::TestList  testList;
	V08::TestStack testStack;
	V08::TestQueue testQueue;

	testList.test();
	testStack.test();
	testQueue.test();

	l.append(1);
	l.append(2);
	l.prepend(3);

	l.print();

}

/*
 * V07.C
 *
 *  Created on: 23.06.2018
 *      Author: aml
 */

#include "V07.H"

namespace V07 {

/**
 *
 * test if an instantiated stack
 * object is empty
 *
 */
bool TestStack::unitTest0() {
	Stack<int> stack;

	if (!stack.isEmpty()) {
		return false; // stack should be empty
	};

	stack.in(1);
	if (stack.isEmpty()) {
		return false; // stack shouldn't be empty
	}

	stack.out();
	if (!stack.isEmpty()) {
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
bool TestStack::unitTest1() {
	Stack<int> stack;
	try {
		stack.out();
		return false;
	} catch (...) {
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
bool TestStack::unitTest2() {
	Stack<int> stack;
	try {
		stack.in(11);
		stack.out();
	} catch (...) {
		return false;
	}

	try {
		stack.out();
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
bool TestStack::unitTest3() {
	Stack<int> stack;

	int a, b, c, tmp;
	a = 1;
	b = 11;
	c = 111;

	try {
		stack.in(a);
		stack.in(b);
		stack.in(c);
	} catch (...) {
		cout << "unknown error while inserting\n";
		cout.flush();
		return false;
	}

	try {
		tmp = stack.out();
		if (tmp != c) {
			cout << tmp << " != " << c << endl;
			return false;
		}
		tmp = stack.out();
		if (tmp != b) {
			cout << tmp << " != " << b << endl;
			return false;
		}
		tmp = stack.out();
		if (tmp != a) {
			cout << tmp << " != " << a << endl;
			return false;
		}

		return true;
	} catch (string msg) {
		cout << msg << endl;
		cout.flush();
		return false;
	} catch (...) {
		cout << "unknown error while removing\n";
		cout.flush();
		return false;
	}
}

/**
 *
 * test insertion and removing of a lot of elements
 *
 */
bool TestStack::unitTest4() {
	Stack<int> stack;
	int n = 99999999;
	int t;
	try {
		for (int i = 0; i < n; i++) {
			stack.in(i);
		}
		for (int i = 0; i < n; i++) {
			t = stack.out();
		}

		if (stack.isEmpty()) {
			return true;
		} else {
			return false;
		}
	} catch (...) {
		return false;
	}
}



/**
 *
 * test if an instantiated queue
 * object is empty
 *
 */
bool TestQueue::unitTest0() {
	Queue<int> q;

	if (!q.isEmpty()) {
		return false; // stack should be empty
	};

	q.in(1);
	if (q.isEmpty()) {
		return false; // stack shouldn't be empty
	}

	q.out();
	if (!q.isEmpty()) {
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
bool TestQueue::unitTest1() {
	Queue<int> q;
	try {
		q.out();
		return false;
	} catch (...) {
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
bool TestQueue::unitTest2() {
	Queue<int> q;
	try {
		q.in(11);
		q.out();
	} catch (...) {
		return false;
	}

	try {
		q.out();
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
bool TestQueue::unitTest3() {
	Queue<int> q;

	int a, b, c, tmp;
	a = 1;
	b = 11;
	c = 111;

	try {
		q.in(a);
		q.in(b);
		q.in(c);
	} catch (...) {
		cout << "unknown error while inserting\n";
		cout.flush();
		return false;
	}

	try {
		tmp = q.out();
		if (tmp != a) {
			cout << tmp << " != " << c << endl;
			return false;
		}
		tmp = q.out();
		if (tmp != b) {
			cout << tmp << " != " << b << endl;
			return false;
		}
		tmp = q.out();
		if (tmp != c) {
			cout << tmp << " != " << a << endl;
			return false;
		}

		return true;
	} catch (string msg) {
		cout << msg << endl;
		cout.flush();
		return false;
	} catch (...) {
		cout << "unknown error while removing\n";
		cout.flush();
		return false;
	}
}

/**
 *
 * test insertion and removing of a lot of elements
 *
 */
bool TestQueue::unitTest4() {
	Queue<int> q;
	int n = 99999;
	int t;
	try {
		for (int i = 0; i < n; i++) {
			q.in(i);
		}
		for (int i = 0; i < n; i++) {
			t = q.out();
		}

		if (q.isEmpty()) {
			return true;
		} else {
			return false;
		}
	} catch (...) {
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
		return false; // list should be empty
	};

	list.prepend(1);
	if (list.isEmpty()) {
		return false; // list shouldn't be empty
	}

	list.removeFirst();
	if (!list.isEmpty()) {
		return false; // list should be empty again
	}

	list1.append(1);
	if (list1.isEmpty()) {
		cout << "list shouldn't be empty\n";
		return false; // list shouldn't be empty
	}

	list1.removeFirst();
	if (!list1.isEmpty()) {
		cout << "list should be empty\n";
		return false; // list should be empty again
	}

	list1.append(1);
	list1.append(2);
	list1.append(3);
	list1.removeFirst();
	list1.removeFirst();
	list1.removeFirst();
	if (!list1.isEmpty()) {
		cout << "list shouldn't be empty\n";
		return false; // list shouldn't be empty
	}


	list1.append(1);
	list1.append(2);
	list1.append(3);
	list1.removeLast();
	list1.removeLast();
	list1.removeLast();
	if (!list1.isEmpty()) {
		cout << "list shouldn't be empty\n";
		return false; // list shouldn't be empty
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
	int n = 999;
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



}  // end namespace V07





void demoV07_00() {
	V07::TestStack testStack;
	testStack.test();

	V07::TestQueue testQueue;
	testQueue.test();

	V07::Queue<string> s;

	s.in("der");
	s.print();
	cout << endl;
	s.in("mond");
	s.print();
	cout << endl;
	s.in("ist");
	s.print();
	cout << endl;
	s.in("aufgegangen");
	s.print();
	cout << endl;

	try {
		cout << s.out() << endl;
		s.print();
		cout << endl;
		cout << s.out() << endl;
		s.print();
		cout << endl;
		cout << s.out() << endl;
		s.print();
		cout << endl;
		cout << s.out() << endl;
		s.print();
		cout << endl;
		cout << s.out() << endl;
		s.print();
		cout << endl;
	} catch (...) {
		;;
	}

}







namespace NSP01{
	class A{
		public:
		char out(){return 'A';};
	};

	class B : public A{
		public :
		char out(){return 'B';};
	};

	class C : public A{
		public :
		char out(){return 'C';};
	};

}


namespace NSP02{
	class A{
		public:
		virtual char out(){return 'A';};
	};

	class B : public A{
		public :
		char out(){return 'B';};
	};

	class C : public A{
		public :
		char out(){return 'C';};
	};

}


namespace NSP03{
	class A{
		public:
		char out(){return 'A';};
	};

	class B : public A{
		public :
		virtual char out(){return 'B';};
	};

	class C : public A{
		public :
		virtual char out(){return 'C';};
	};

}


namespace Bsp4{
	class A{
		public:
		void out(){cout << "A\n";};
	};

	class B : public A{
		public :
		void out(){cout << "B\n";};
	};

	class C : public B{
		public :
		void out(){cout << "C\n";};
	};

	class D : public C{
		public :
		void out(){cout << "D\n";};
	};
}


namespace Bsp5{
	class A{
		public:
		void out(){cout << "A\n";};
	};

	class B {
		public :
		void out(){cout << "B\n";};
	};

	class C : public A, public B{
		public :
		void out(){cout << "C\n";};
	};

	class D : public B, public C{
		public :
		void out(){cout << "D\n";};
	};
}


namespace Bsp6{
	class A{
		public:
		void out(){cout << "A\n";};
	};

	class B {
		public :
		void out(){cout << "B\n";};
	};

	class C {
		A a_;
		public :
		void out(){cout << "C\n";};
	};

	class D : public C{
		B b_;
		public :
		void out(){cout << "D\n";};
	};
}

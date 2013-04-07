class Base
{
	public:
		typedef int (*CalcFunc)(const Base&);
		Base(int x,CalcFunc func);
		Base();
		virtual ~Base();
		virtual void mf1()=0;
		virtual void mf1(int x);
		virtual void mf2();
		void mf3();
		void mf3(double x);
		void fun();
	private:
		int x;
		CalcFunc pfunc;
		virtual void nvi();
	protected:
		int  n;
	};

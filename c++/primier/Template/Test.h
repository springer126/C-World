#ifndef _TEST_H_
#define  _TEST_H_

template <typename Type>
class Test
{
public:
	Test(Type t);
	~Test();
	void PrintSelf();
private:
	Type t;
};
#endif


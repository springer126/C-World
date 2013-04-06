#include <iostream>
template <class T>
class LinerList
{
private:
	int length;
	int MaxSize;
	T *element;
public:
	LinerList(int MaxSize =10);
	LinerList(const LinerList<T> &L);
	~LinerList(){delete []element;}
	bool IsEmpty() const{return length ==0;}
	int Length() const{return length};
	bool Find(int k,T &x) const;
	int Search(const T& x) const;
	LinerList<T>& Delete(int k,T &x);
	LinerList<T>& Insert(int k,const T &x);
	void Output(std::ostream &out) const;

};
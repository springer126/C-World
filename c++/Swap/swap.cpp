#include <iostream>
#include <string>
namespace WidgetStuff
{
	class Widget
	{
	public:
		Widget(std::string n):name(n){}
		void swap(Widget &w)
		{
			using std::swap;
			std::cout << "SWAP METHOD" << std::endl;
			swap(this->name,w.name);
		}
		void PrintSelf()
		{
			std::cout << name << std::endl;
		}
	private:
		std::string  name;
	};
	
	class PanelWidget:public Widget
	{
	public:
		PanelWidget(std::string str,int i):Widget(str),n(i){}
	private:
		int n;
	};
	
	void swap(Widget &w1,Widget &w2)
	{
		std::cout << "NO MEMBER SWAP" << std::endl;
		w1.swap(w2);
	}
}

namespace std
{
	using namespace WidgetStuff;
	template<>
	void swap<Widget>(Widget &w1,Widget &w2)
	{
		std::cout << "SPECIFIC IN STD" << std::endl;
		w1.swap(w2);
	}
};

int main()
{
	WidgetStuff::Widget w1("wenhui");
	w1.PrintSelf();
	WidgetStuff::Widget w2("meiling");
	w2.PrintSelf();
	
	using namespace WidgetStuff;
	using namespace std;
	std::swap(w1,w2);
	
	w1.PrintSelf();
	w2.PrintSelf();
	
	PanelWidget pw1("akka",12);
	PanelWidget *ppw1 = &pw1;
	Widget *pppw1 = &pw1;
	std::cout << ppw1 << pppw1 << std::endl;
}

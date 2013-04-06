#pragma once
#include "Term.h"
#include <limits>
#include <iostream>
#include <math.h>
#include <memory>
using namespace  std;
class TPolynomial
{
	friend ostream& operator<<(ostream &out,TPolynomial &p);
public:
	TPolynomial(void):degree(0)
	{
		head = new Term();
		head->data = 0;
		head->power = -1;
		head->next = head;
		tail = head;
	}

	virtual ~TPolynomial(void)
	{
		Term *t;
		while (head->next!=head)
		{
			t = head->next;
			head->next = t->next;
			delete t;
		}
	}

	void Input()
	{
		int number;
		int degree = INT_MAX;
		if(cin>>number && number > 0)
		{
			while (number--)
			{
				float data;
				int power;
				if(cin>> data >> power)
				{
					if(power < degree)
					{				
						Term *t = new Term(data,power);
						tail->next = t;
						tail = t;
						t->next = head;
						degree = power;
					}
					else
					{
						std::cout << "ÃÝÊäÈë´íÎó" << std::endl;
						break;
						return;
					}
				}
				else
				{
					std::cout << "ÊäÈë´íÎó" << std::endl;
					break;
					return;			
				}
			}
		}
	}

	int Degree()
	{
		Term *first = head->next;
		if(first != head)
			return first->power;
		else
			return -1;
	}
	
	TPolynomial& Add(TPolynomial &t)
	{
		Term *p = head;
		Term *first = head->next;
		Term *afirst = t.head->next;
		if(Degree()==-1)
		{
			while (afirst->next!=t.head->next)
			{
				Term *t = new Term(afirst->data,afirst->power);
				auto_ptr<Term> ap(t);
				tail->next = t;
				t->next = head;
				tail = t;
			}
		}
		else
		{
			while (afirst->next!=t.head->next)
			{
				while (afirst->power < first->power && first->next!=head->next)
				{
					p = first;
					first = first->next;
				}	
				if(first->power == afirst->power)
				{
					first->data += afirst->data;
				}
				else
				{
					Term *t = new Term(afirst->data,afirst->power);
					t->next = first;
					p->next = t;
					p = t;
				}
				afirst = afirst->next;
			}	
		}
		return *this;
	}
	
	TPolynomial& Subtract(TPolynomial &t)
	{}

	TPolynomial& Multiply(TPolynomial &t)
	{}

	TPolynomial& Divide(TPolynomial &t)
	{}

	double Value(float x)
	{
		double result = 0;
		Term *first = head->next;
		while (first->next!=head->next)
		{
			result += first->data*pow(x,first->power);
			first = first->next;
		}
		return result;
	}

private:
	int degree;
	Term *head;
	Term *tail;
};

#pragma once
#ifndef _H_TERM_H_
#define  _H_TERM_H_

#include <iostream>
using namespace  std;
class Term
{
	friend class TPolynomial;
	friend ostream& operator<<(ostream &out,Term &t);
	friend ostream& operator<<(ostream &out,TPolynomial &p);
public:
	Term(void):data(0),power(0),next(0){}
	Term(float f,int p):data(f),power(p),next(0){}
	virtual ~Term(void){}
private:
	float data;
	int power;
	Term *next;
};

#endif

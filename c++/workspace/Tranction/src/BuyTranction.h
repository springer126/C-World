/*
 * BuyTranction.h
 *
 *  Created on: 2013-3-25
 *      Author: wenhui
 */

#ifndef BUYTRANCTION_H_
#define BUYTRANCTION_H_

#include "Tranction.h"

class BuyTranction: public Tranction {
public:
	BuyTranction();
	virtual ~BuyTranction();
	virtual void logTRanction();
};

#endif /* BUYTRANCTION_H_ */

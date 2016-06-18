#ifndef CBLOCK_H
#define CBLOCK_H

#include <time.h>
#include "IObject.h"


class CBlock : public IObject {
private:
	int nLife;
public:
	CBlock();
	void Set();
	void Move();

	void setNLife(int nLife);
	int getNLife();
};

#endif
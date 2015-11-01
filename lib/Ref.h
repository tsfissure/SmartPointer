#pragma once

#include "FissureDefinition.h"

//////////////////////////////////////////////////////////////////////////
//所有需要智能指针的基类
class Ref {

public:
	Ref();
	virtual		~Ref();

public:
	void		retain();
	void		release();
	unsigned int	getRefCount() const;

private:
	unsigned int	refCount;
};

#include "Ref.h"
#include <iostream>
#include <assert.h>

Ref::Ref() :refCount(1) {}

Ref::~Ref() {
	release();
}

void Ref::retain() {
	assert(refCount > 0);
	++refCount;
}

void Ref::release() {
	if (--refCount < 1)
		delete(this);
}

unsigned int Ref::getRefCount() const {
	return refCount;
}

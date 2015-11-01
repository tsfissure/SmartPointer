#pragma once

typedef unsigned int uInt;
typedef long long LLONG;
typedef unsigned long long uLLONG;

#define  TS_SAFE_RETAIN(ptr)				do { if (ptr) ptr->retain(); } while (0);
#define  TS_SAFE_RELEASE(ptr)						do { if (ptr) ptr->release(); } while (0);
#define  TS_SAFE_RELEASE_NULL(ptr)			do { if (ptr) ptr->release(); ptr = nullptr; } while (0);

#define  TS_NULL_RETURN(ptr)				do { if (!ptr) return; } while (0);
#define	 TS_NULL_RETURN_BOOL(ptr)			do { if (!ptr) return false; } while (0);
#define	 TS_NULL_RETURN_VALUE(ptr,v)		do { if (!ptr) return v; } while (0);
#define  TS_CONDITION_RETURN(c)				do { if (c) return; } while (0);
#define  TS_CONDITION_RETURN_BOOL(c)		do { if (c) return false; } while (0);
#define  TS_CONDITION_RETURN_VALUE(c,v)		do { if (c) return v; } while (0);

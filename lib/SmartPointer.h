#pragma once

/************************************************************************/
/* SmartPointer*/
/*模板的定义与类有区别，建议放在一个文件里面，如果在cpp实现，*/
/*用的时候要include cpp*/
/*特别地：在重载等于符号的时候返回值如果是在类之后实现，是SmartPointer<T>&,*/
/*如果在声明时实现,就是SmartPointer即可(why?)*/
/************************************************************************/

template<typename T>
class SmartPointer {
public:
	SmartPointer(T* p = nullptr);
	SmartPointer(const SmartPointer &ref);
	~SmartPointer();

public:
	T*		getRefObject()const;
	bool		isNull();

public:
	SmartPointer<T>&	operator = (const SmartPointer &rkNode);
	bool			operator==(const SmartPointer &rkNode);
	T*			operator->()const;
	T&			operator()()const;
	T&			operator*()const;

private:
	T*			m_pkRefObject;
};



//////////////////////////////////////////////////////////////////////////
//模板的实现.
template<typename T>
SmartPointer<T>::SmartPointer(T* p /*= nullptr*/) {
	m_pkRefObject = p;
	TS_SAFE_RETAIN(p);
}

template<typename T>
SmartPointer<T>::SmartPointer(const SmartPointer &ref) {
	TS_CONDITION_RETURN(this == ref);
	m_pkRefObject = ref.getRefObject();
}

template<typename T>
SmartPointer<T>::~SmartPointer() {
	TS_SAFE_RELEASE_NULL(m_pkRefObject);
}

template<typename T>
T* SmartPointer<T>::operator->() const {
	return m_pkRefObject;
}

template<typename T>
T* SmartPointer<T>::getRefObject() const {
	return m_pkRefObject;
}

template<typename T>
bool SmartPointer<T>::isNull() {
	return !m_pkRefObject;
}

template<typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer &rkNode) {
	TS_CONDITION_RETURN_VALUE(this == &rkNode, *this);

	TS_SAFE_RELEASE_NULL(m_pkRefObject);
	m_pkRefObject = rkNode.getRefObject();
	TS_SAFE_RETAIN(m_pkRefObject);

	return *this;
}

template<typename T>
bool SmartPointer<T>::operator==(const SmartPointer<T> &rkNode) {
	return m_pkRefObject == rkNode.getRefObject();
}

template<typename T>
T& SmartPointer<T>::operator*() const {
	assert(m_pkRefObject);
	return *m_pkRefObject;
}

template<typename T>
T& SmartPointer<T>::operator()() const {
	assert(m_pkRefObject);
	return *m_pkRefObject;
}

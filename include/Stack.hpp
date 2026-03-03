#pragma once
#include <iostream>
#include <stdexcept>

template <class T> class Stack
{
  private:
	T *pMem_;
	size_t sz_;
	int head_;

  public:
	Stack(size_t size) : sz_(size), head_(-1)
	{
		pMem_ = new T[sz_];
	}
	Stack(const Stack &s) : sz_(s.sz_), head_(s.head_)
	{
		pMem_ = new T[sz_];
		for (int i = 0; i <= head_; i++)
		{
			pMem_[i] = s.pMem_[i];
		}
	}
	Stack(Stack &&s) : sz_(s.sz_), head_(s.head_), pMem_(s.pMem_)
	{
		s.sz_ = 0;
		s.head_ = -1;
		s.pMem_ = nullptr;
	}
	~Stack()
	{
		delete[] pMem_;
	}
	Stack &operator=(const Stack &s)
	{
		if (this == &s)
			return *this;
		sz_ = s.sz_;
		head_ = s.head_;
		T *tmp = new T[sz_];
		for (int i = 0; i <= head_; i++)
		{
			tmp[i] = s.pMem_[i];
		}
		delete[] pMem_;
		pMem_ = tmp;
		return *this;
	}
	Stack &operator=(Stack &&s)
	{
		if (this == &s)
			return *this;
		delete[] pMem_;
		pMem_ = s.pMem_;
		head_ = s.head_;
		sz_ = s.sz_;

		s.head_ = -1;
		s.sz_ = 0;
		s.pMem_ = nullptr;
		return *this;
	}

	bool isEmpty()
	{
		return head_ == -1;
	}
	bool isFull()
	{
		return head_ == (sz_ - 1);
	}

	T pop()
	{
		if (isEmpty())
			throw std::out_of_range("Stack is empty");
		return pMem_[head_--];
	}
	const T &top()
	{
		if (isEmpty())
			throw std::out_of_range("Stack is empty");
		return pMem_[head_];
	}
	void push(const T &item)
	{
		if (isFull())
			throw std::out_of_range("Stack is full");
		pMem_[++head_] = item;
	}
	void push(T &&item)
	{
		if (isFull())
			throw std::out_of_range("Stack is full");
		pMem_[++head_] = std::move(item);
	}

	size_t size()
	{
		return sz_;
	}
};
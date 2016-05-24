#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<class T>
class Array
{
private:
	

	T* m_array;

	int m_count;

	int m_max_count;

	const static int increase_factor = 2;

	void init();

	void increase_array_size();

public:

	Array();

	Array(int);

	Array(const Array<T>& rhs);

	~Array();


	void operator=(const Array<T>& rhs);

	
	inline friend Array<T> operator+(const Array<T>& lhs, const Array<T>& rhs)
	{	

		Array<T> tmp;

		if(lhs.size() == rhs.size())
		{
		
			for(int i = 0; i < lhs.size(); i++)
			{
				tmp.add(lhs.value_at(i) + rhs.value_at(i));
			}

		}

		return tmp;
	}

	
	inline friend bool operator==(const Array<T>& lhs, const Array<T>& rhs)
	{
		if(lhs.size() != rhs.size())
				return false;

		bool equal = true;
		int i = 0;

		while(equal)
		{
			equal = (lhs.value_at(i) == rhs.value_at(i));
			i++;
		}

		return equal;
	}

	
	inline friend bool operator !=(const Array<T>& lhs, const Array<T>& rhs){ return !(operator==(lhs,rhs));}

	inline int size() const { return m_count; }

	
	friend std::ostream &operator<<(std::ostream &out, const Array<T> &rhs)
	{
		out << "Array: " << std::endl;
		for(int i = 0; i < rhs.size(); i++)
		{
			out << i << ": " << rhs.value_at(i) << std::endl;
		}

		return out;
	}

	T value_at(int i) const;

	void add(T);

	void set_value(int i, T value);


};

template<class T>
Array<T>::Array() : m_max_count(10) 
{
	init();
}

template<class T>
Array<T>::Array(int max_count) : m_max_count(max_count)
{
	init();
}

template<class T>
Array<T>::Array(const Array<T>& rhs)
{
	*this = rhs;
}

template<class T>
Array<T>::~Array()
{
	delete [] m_array;
}

template<class T>
void Array<T>::init()
{
	m_array = new T[m_max_count];
	m_count = 0;
}

template<class T>
void Array<T>::increase_array_size()
{
	T* tmp = new T[increase_factor * m_max_count];

	for(int i = 0; i < m_count; i++)
	{
		tmp[i] = m_array[i];
	}

	delete m_array;
	m_max_count = increase_factor * m_max_count;
	m_array = tmp;
}

template <class T>
void Array<T>::operator=(const Array<T>& rhs)
{
	if(this != &rhs)
	{	

		delete [] m_array;

		init();

		for(int i = 0; i < rhs.size(); i++)
			this->add(rhs.value_at(i));
	}
}

template<class T>
void Array<T>::add(T value)
{
	if(m_count < m_max_count)
	{
		m_array[m_count] = value;
		m_count++;
	}
	else
	{
		increase_array_size();
		m_array[m_count] = value;
		m_count++;
	}
}

template<class T>
void Array<T>::set_value(int i, T value)
{
	if(i < m_count)
	{
		m_array[i] = value;

	}
}

template<class T>
T Array<T>::value_at(int i) const
{
	if(i < m_count)
		return m_array[i];

	return 0;
}

#endif // ARRAY_H

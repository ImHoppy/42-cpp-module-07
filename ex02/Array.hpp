#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <string>

template < typename T >
class Array
{

	public:
/* ------------------------------- CONSTRUCTOR ------------------------------ */

		Array() : _array(new T[0]), _size(0) {};

		Array( Array const & src )
		{
			this->_size = src.size();
			this->_array = new T[this->_size];
			for (size_t i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		};

		Array( unsigned int n ) : _array(new T[n]), _size(static_cast<size_t>(n)) {};

/* ------------------------------- DESTRUCTOR ------------------------------- */

		~Array()
		{
			delete[] _array;
		};


/* -------------------------------- OVERLOAD -------------------------------- */

		Array &		operator=( Array const & rhs )
		{
			if ( this != &rhs )
			{
				size_t	max = rhs.size();

				if (this->size() != max)
				{
					delete[] _array;
					this->_array = new T[max];
				}

				for (size_t i = 0; i < max; i++)
					this->_array[i] = rhs._array[i];

				this->_size = max;
				
			}
			return *this;
		}

		T &	operator[](int index)
		{
			if (static_cast<size_t>(index) >= this->_size || index < 0)
				throw std::runtime_error("Index out of range.");

			return (this->_array[index]);
		}


/* -------------------------------- METHODS --------------------------------- */


/* -------------------------------- ACCESSOR -------------------------------- */

		size_t	size() const
		{
			return (this->_size);
		}

	private:
		T *		_array;
		size_t	_size;
};

#endif /* ARRAY_TPP */
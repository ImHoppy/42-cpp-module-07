#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template<typename T, typename S>
void	iter( T table[], S const size, void(f)(T &) )
{
	for (S i = 0; i < size; i++)
		f(table[i]);
}

#endif /* ITER_HPP */
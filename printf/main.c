#include "ft_printf.h"
#include <limits.h>
int main()
{
	ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
}
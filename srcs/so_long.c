#include "so_long.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (parsing_map(av) == 1)
	{
		write(2, "error\n", 6);
		return (0);
	}
	write(1, "All Good\n", 9);
}

#include <unistd.h>
#include <stdio.h>
#define SEP(x) (x == ' ' || x == '\t')

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	char	*str;
	char	*start;
	char	*end;

	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	str = av[1];
	while (SEP(*str) && *str)
		str++;
	start = str;
	while (!SEP(*str) && *str)
		str++;
	end = str;
	while (SEP(*str) && *str)
		str++;
	if (*str != *end)
	{
		while (*str)
		{
			if (SEP(*str))
			{
				while (SEP(*str))
					str++;
				if (*str)
					ft_putchar(' ');
			}
			else
			{
				ft_putchar(*str);
				str++;
			}
		}
	}
	ft_putchar(' ');
	while (!SEP(*start) && *start)
		ft_putchar(*start++);
	ft_putchar('\n');
	return (0);
}

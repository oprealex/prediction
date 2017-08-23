#include <stdio.h>
#include <stdlib.h>

void	ft_printdes(unsigned int x)
{
	unsigned int i;
	unsigned int aux;

	i = 2;
	aux = x;
	while (i < (x / 2))
	{
		if (aux % i == 0 && aux != i)
		{
			printf("%d*", i);
			aux = aux / i;
		}
		else if (aux == i)
		{
			printf("%d", i);
			i++;
		}
		else
			i++;
	}
}

int		ft_nrprime(unsigned int x)
{
	unsigned int	i;
	int				ok;

	i = 2;
	ok = 1;
	while (i < (x / 2))
	{
		if (x % i == 0)
			ok = 0;
		i++;
	}
	return (ok);
}

int		main(int argc, char **argv)
{
	unsigned int	x;
	int				ok;

	if (argc != 2)
		printf("\n");
	else
	{
		x = atoi(argv[1]);
		ok = ft_nrprime(x);
		if (ok == 1)
			printf("%d", x);
		else
			ft_printdes(x);
		printf("\n");
	}
	return (0);
}


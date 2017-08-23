#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_lit(char **argv, int i, int j)
{
	if ((argv[i][j] >= 'a') && (argv[i][j] <= 'z'))
		return (0);
	if ((argv[i][j] >= 'A') && (argv[i][j] <= 'Z'))
		return (0);
	return (1);
}

void	ft_int_word(char **argv, int i, int j)
{
	if ((argv[i][j] >= 'a') && (argv[i][j] <= 'z'))
		ft_putchar(argv[i][j]);
	else if ((argv[i][j] >= 'A') && (argv[i][j] <= 'Z'))
		ft_putchar(argv[i][j] + 32);
	else if (argv[i][j] != ' ')
		ft_putchar(argv[i][j]);
}

int		ft_print_word(char **argv, int i, int j)
{
	if (((argv[i][j] >= 'a') && (argv[i][j] <= 'z')
			&& (argv[i][j - 1] == ' ')) || ((j == 0)
			&& (argv[i][j] >= 'a') && (argv[i][j] <= 'z')))
	{
		ft_putchar(argv[i][j] - 32);
		j++;
	}
	else if (((argv[i][j] >= 'A') && (argv[i][j] <= 'Z')
			&& (argv[i][j - 1] == ' ')) || ((j == 0)
			&& (argv[i][j] >= 'A') && (argv[i][j] <= 'Z')))
	{
		ft_putchar(argv[i][j]);
		j++;
	}
	while (!(ft_lit(argv, i, j)))
	{
		ft_int_word(argv, i, j);
		j++;
	}
	return (j);
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_lit(argv, i, j))
			{
				ft_putchar(argv[i][j]);
				j++;
			}
			else
				j = ft_print_word(argv, i, j);
		}
		i++;
		ft_putchar('\n');
	}
	if (argc == 1)
		ft_putchar('\n');
	return (0);
}


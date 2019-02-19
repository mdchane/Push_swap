#include "libft/libft.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int	res=0;
	int	nbr=0;

	if (argc || argv)
		;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		res += ft_atoi(line);
		free(line);
		nbr++;
	}
	res = res / nbr;
	printf("%d\n", res);
	close(fd);
	return (0);
}

#include <stdio.h>
#include "../libft/libft.h"

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"
#define A "\033[31m"
#define B "\033[32m"
#define C "\033[33m"
#define D "\033[34m"
#define E "\033[35m"
#define F "\033[36m"
#define G "\033[37m"
#define H "\033[38m"
#define I "\033[39m"
#define J "\033[40m"
#define K "\033[41m"
#define L "\033[42m"
#define M "\033[43m"
#define N "\033[44m"
#define O "\033[45m"
#define P "\033[46m"
#define Q "\033[47m"
#define R "\033[48m"
#define S "\033[19m"
#define U "\033[20m"
#define V "\033[21m"
#define W "\033[22m"
#define X "\033[23m"
#define Y "\033[24m"


int			main(int c, char **v)
{
	printf("%sYELLOW TEXT%s\n",    YELLOW, RESET);
	ft_putstr(RED);
	ft_putstr("RED TEXT\n");
	ft_putstr(A);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	ft_putstr(B);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	
	ft_putstr(C);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	ft_putstr(D);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	
	ft_putstr(E);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	ft_putstr(F);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	
	ft_putstr(G);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	ft_putstr(H);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	
	ft_putstr(I);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	ft_putstr(J);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	
	ft_putstr(K);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	ft_putstr(L);
	ft_putstr("TEXT\n");
	ft_putstr(RESET);
	

	ft_putstr(RESET);
	return (0);
}

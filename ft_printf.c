#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void ft_putstr(char *str, int *count)
{
	int i = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*count) = (*count)+ 6;
		return ;
	}
	while(str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void ft_putnbr(long long num, int *count)
{
	if (num < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(num * -1, count);
	}
	else
	{
		if (num > 9)
			ft_putnbr(num / 10, count);
		ft_putchar(num % 10 + '0', count);
	}

}

void ft_puthex(unsigned int hex, int *count)
{
	if(hex >= 16)
		ft_puthex(hex / 16, count);
	ft_putchar("0123456789abcdef"[hex % 16], count);
}

void check_format(char c, va_list args, int *count)
{
	if (c == '%')
		ft_putchar('%',count);
	else if(c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if(c == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if(c == 'x')
		ft_puthex(va_arg(args, unsigned int), count);


}

int ft_printf(const char *str, ... )
{
	va_list list;
	int i = 0;
	int count = 0;

	va_start(list, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			i++;
			check_format(str[i], list,  &count);
			i++;
		}
		else
		{
			ft_putchar(str[i], &count);
			i++;
		}
	}
	va_end(list);
	return(count);
}
/*
int main()
{
	char *name= "Daiana";
	char *nullstr = NULL;
	int max = 2147483647;
	int min = - 2147483648;
	int zero = 0;
	unsigned int hex = 0x2aaaaa;
	ft_printf("%s\n", nullstr);
//	printf("%s\n", nullstr);
	printf("COUNT: %d\n", ft_printf("%s\n",nullstr));
	ft_printf("HI %s max: %d min %d\n", name, max, min);
	printf("HI %s max: %d min %d\n", name, max, min);	
	printf("COUNT= %d\n",ft_printf("HI %s max: %d min %d\n", name, max, min));
	
	ft_printf("zero: %d and hex: %x\n", zero, hex);
	printf("zero: %d and hex: %x\n", zero, hex);
	return(0);

}*/

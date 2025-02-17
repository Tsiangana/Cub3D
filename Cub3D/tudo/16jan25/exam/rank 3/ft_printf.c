#include <unistd.h>
#include <stdarg.h>

void	put_str(char *s, int *len)
{
	if(!s)
		s = "(null)";
	while(*s)
		*len += write(1, s++, 1);
}

void	put_digit(long long int nb, int base, int *len)
{
	char	*hexa = "0123456789abcdef";

	if(nb < 0)
	{
		nb *= -1;
		*len += write(1, "-", 1);
	}
	if(nb >= base)
		put_digit((nb / base), base, len);
	*len += write(1, &hexa[nb % base], 1);
}

int	ft_printf(const char *f, ...)
{
	int	len = 0;
	va_list	p;

	va_start(p, f);
	while(*f)
	{
		if(*f == '%' && *(f + 1))
		{
			f++;
			if(*f == 's')
				put_str(va_arg(p, char *), &len);
			else if (*f == 'd')
				put_digit((long long int)va_arg(p, int), 10, &len);
			else if(*f == 'x')
				put_digit((long long int)va_arg(p, unsigned int), 16, &len);
		}
		else
			len += write(1, f, 1);
		f++;
	}
	return(va_end(p), len);
}

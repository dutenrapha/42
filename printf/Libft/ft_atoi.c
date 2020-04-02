
int ft_atoi(const char *nptr)
{
        int i;
        long int unidade;
        int sinal;

        i = 0;
        while (*(nptr + i) == ' ' || *(nptr + i) == '\n' || *(nptr + i) == '\t' || *(nptr + i) == '\v' || *(nptr + i) == '\f' || *(nptr + i) == '\r')
        {
                i++;
        }

        sinal = 1;
        if(*(nptr + i) == '-' || *(nptr + i) == '+' )
        {
                if(*(nptr + i) == '-')
                {
                  sinal = -1;
                }
		i += 1;
	}

        unidade = 0;

        while(*(nptr + i) >= 48 && *(nptr + i) <= 57)
        {
                unidade = unidade*10 + *(nptr + i) - 48;
        
		if (unidade > 2147483648 && sinal == 1)
			return (-1);
		else if (unidade > 2147483648 && sinal == -1)
			return (0);
	
	
		i++;
        }

        return(unidade*sinal);
}

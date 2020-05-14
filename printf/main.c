/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 22:01:52 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/14 15:32:43 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
int main()
{
	int obtido;
    int esperado;
    int d;
    int i;
    int u_1;
    int u_2;
    char c;
    char *s;
    int *n;

    s = "A casa é de beira rio";
    c = 'a';
    d = 10;
    i = 42;
    u_1 = 10;
    u_2 = -10;

    /*Teste printar frase sem flags ou variáveis*/
    printf("**Teste printar frase sem flags ou variáveis**\n");
    esperado = printf("123456789\n");
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("123456789\n");
    printf("Tamanho obtido %d\n", obtido);
    
    printf("\n");

    /*Teste printar o sinal de %*/
    printf("**Teste printar o sinal de %%**\n");
    esperado = printf("123456789 10%%0\n");
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("123456789 10%%0\n");
    printf("Tamanho obtido %d\n", obtido);
    printf("\n");
    esperado = printf("123%%456789 10%%0\n");
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("123%%456789 10%%0\n");
    printf("Tamanho obtido %d\n", obtido);

    printf("\n");

    /*Teste printar variável d*/
    printf("**Teste printar variável d**\n");
    esperado = printf("%d\n", d);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%d\n", d);
    printf("Tamanho obtido %d\n", obtido);
    printf("\n");
    esperado = printf("O valor esperado é %d, de %d\n", d, d);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("O valor esperado é %d, de %d\n", d, d);
    printf("Tamanho obtido %d\n", obtido);

    printf("\n");
  
    /*Teste printar variável i*/
    printf("**Teste printar variável i**\n");
    esperado = printf("%i\n", i);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%i\n", i);
    printf("Tamanho obtido %d\n", obtido);
    printf("\n");
    esperado = printf("O valor esperado é %i, de %i\n", i, i);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("O valor esperado é %i, de %i\n", i, i);
    printf("Tamanho obtido %d\n", obtido);

    printf("\n");
    
    /*Teste printar variável c*/
    printf("**Teste printar variável c**\n");
    esperado = printf("%c\n", c);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%c\n", c);
    printf("Tamanho obtido %d\n", obtido);
    printf("\n");
    esperado = printf("Esse é o caractere da sorte %c e este é igual %c\n", c, c);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("Esse é o caractere da sorte %c e este é igual %c\n", c, c);
    printf("Tamanho obtido %d\n", obtido);

    printf("\n");

    /*Teste printar variável s*/
    printf("**Teste printar variável s**\n");
    esperado = printf("%s\n", s);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%s\n", s);
    printf("Tamanho obtido %d\n", obtido);
    printf("\n");
    esperado = printf("começo%smeio\n", s);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("começo%smeio\n", s);
    printf("Tamanho obtido %d\n", obtido);

    printf("\n");

    /*Teste printar variável x*/
    printf("**Teste printar variável x**\n");
    esperado = printf("%x\n", i);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%x\n", i);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%x\n", u_1);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%x\n", u_1);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%x\n", u_2);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%x\n", u_2);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%x\n", 0);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%x\n", 0);
    printf("Tamanho obtido %d\n", obtido);

    printf("\n");

    /*Teste printar variável X*/
    printf("**Teste printar variável X**\n");
    esperado = printf("%X\n", i);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%X\n", i);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%X\n", u_1);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%X\n", u_1);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%X\n", u_2);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%X\n", u_2);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%X\n", 0);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%X\n", 0);
    printf("Tamanho obtido %d\n", obtido);

    printf("\n");
    
    n = NULL;

    /*Teste printar variável p */
    printf("**Teste printar variável p**\n");
    esperado = printf("%p\n", &i);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%p\n", &i);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%p\n", &u_1);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%p\n", &u_1);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%p\n", &u_2);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%p\n", &u_2);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%p\n", &n);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%p\n", &n);
    printf("Tamanho obtido %d\n", obtido);

   	printf("\n");

	/*Teste printar variável u*/
    printf("**Teste printar variável u**\n");
    esperado = printf("%u\n", i);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%u\n", i);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%u\n", u_1);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%u\n", u_1);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%u\n", u_2);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%u\n", u_2);
    printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%u\n", 0);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("%u\n", 0);
    printf("Tamanho obtido %d\n", obtido);

   	printf("\n");
	/*este flag width*/
    printf("**Teste flag width**\n");

	esperado = printf("E%40cA\n", c);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("E%40cA\n", c);
	printf("Tamanho obtido %d\n", obtido);
	
	esperado = printf("E%40sA\n", s);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("E%40sA\n", s);
	printf("Tamanho obtido %d\n", obtido);
	
	esperado = printf("E%40pA\n", &s);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("E%40pA\n", &s);
	printf("Tamanho obtido %d\n", obtido);
	
	esperado = printf("E%40dA\n", d);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("E%40dA\n", d);
	printf("Tamanho obtido %d\n", obtido);

	esperado = printf("E%40iA\n", i);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("E%40iA\n", i);
	printf("Tamanho obtido %i\n", obtido);

	esperado = printf("E%40uA\n", u_2);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("E%40uA\n", u_2);
	printf("Tamanho obtido %d\n", obtido);
	
	esperado = printf("E%40xA\n", u_2);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("E%40xA\n", u_2);
	printf("Tamanho obtido %d\n", obtido);
	
	esperado = printf("E%40XA\n", u_2);
    printf("Tamanho esperado %d\n", esperado);
    obtido = ft_printf("E%40XA\n", u_2);
	printf("Tamanho obtido %d\n", obtido);
/*
	printf("\n");
	printf("\n");
	printf("\n");

    printf("E%40cA\n", c);
	printf("E%40sA\n", s);
	printf("E%40pA\n", &u_2);
    printf("E%40dA\n", u_2);
	printf("E%40iA\n", u_2);
	printf("E%40uA\n", u_2);
	printf("E%40xA\n", u_2);
	printf("E%40XA\n", u_2);


    printf("E%-20uA\n", u_2);
    printf("E%020uA\n", u_2);
    printf("E%.0sA\n", s);
    printf("E%.1sA\n", s);
	printf("E%.3sA\n", s);
	
	printf("E%30.0sA\n", s);
    printf("E%30.1sA\n", s);
	printf("E%30.3sA\n", s);
	printf("E%30.50sA\n", s);

	printf("E%-30.0sA\n", s);
    printf("E%-30.1sA\n", s);
	printf("E%-30.3sA\n", s);
	printf("E%-30.50sA\n", s);
*/
    return (0);
}

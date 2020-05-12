/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 22:01:52 by rdutenke          #+#    #+#             */
/*   Updated: 2020/05/11 19:00:49 by raphael          ###   ########.fr       */
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
    char *teste;
    teste = ft_itoa_base(42, 16);
    printf("%s\n", teste);
    printf("%x\n", 42);

    /*Teste printar variável x*/
   /* printf("**Teste printar variável x**\n");
    esperado = printf("%x\n", i);
    printf("Tamanho esperado %d\n", esperado);
    //obtido = ft_printf("%x\n", i);
    //printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%x\n", u_1);
    printf("Tamanho esperado %d\n", esperado);
    //obtido = ft_printf("%x\n", u_1);
    //printf("Tamanho obtido %d\n", obtido);
    esperado = printf("%x\n", u_2);
    printf("Tamanho esperado %d\n", esperado);
    //obtido = ft_printf("%x\n", u_2);
    //printf("Tamanho obtido %d\n", obtido);
    
    */
    return (0);
}

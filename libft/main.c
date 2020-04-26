/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:41:38 by rdutenke          #+#    #+#             */
/*   Updated: 2020/03/14 12:48:51 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <ctype.h>
#include <bsd/string.h>
#include <locale.h>


int main(void)
{
	/*Função ft_strlen*/
	size_t len_test1;
	size_t len_true1;
	size_t len_test2;
	size_t len_true2;
	
	/*Teste 1 função strlen string com uma palavra */
	len_test1 = ft_strlen("abc");
	len_true1 = strlen("abc");
	/*Teste 2 função strlen string com espaços*/
	len_test2 = ft_strlen("casa casa casa");
        len_true2 = strlen("casa casa casa");

	printf("\nFunção ft_strlen\n");
	printf("Teste 1 - valor obtido:  %zu, valor esperado: %zu\n", len_test1, len_true1);
        printf("Teste 2 - valor obtido: %zu, valor esperado: %zu\n", len_test2, len_true2);




	/*Função ft_strrchr*/
	const char str[] = "http://www.tutorialspoint.com";
	const char str2[] ="k";
	char *ret_test1;
	char *ret_true1;
        char *ret_test2;
        char *ret_true2;
	char *ret_test3;
	char *ret_true3;
	char *ret_test4;
	char *ret_true4;
        char *ret_test5;
        char *ret_true5;
        char *ret_test6;
        char *ret_true6;

	/*Teste 1 função strrchr com duas ocorrencias do caractere c*/
	ret_test1 = ft_strrchr(str,'.');
	ret_true1 =  strrchr(str, '.');
	/*Teste 2 função strrchr com zero correncias do caractere c*/
        ret_test2 = ft_strrchr(str,'z');
        ret_true2 =  strrchr(str, 'z');
        /*Teste 3 função strrchr com uma correncias do caractere c no inicio*/
        ret_test3 = ft_strrchr(str,'h');
        ret_true3 =  strrchr(str, 'h');
	/*Teste 4 função strrchr com uma correncias do caractere c no fim*/
        ret_test4 = ft_strrchr(str,'m');
        ret_true4 =  strrchr(str, 'm');
        /*Teste 5 função strrchr com uma correncias do caractere c em um string de um caractere*/
        ret_test5 = ft_strrchr(str2,'k');
        ret_true5 =  strrchr(str2, 'k');
        /*Teste 6 função strrchr com zero correncias do caractere c em um string de um caractere*/
        ret_test6 = ft_strrchr(str2,'v');
        ret_true6 =  strrchr(str2, 'v');


	char *srccc = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	char *dd1 = strrchr(srccc, '\0');
	char *dd2 = ft_strrchr(srccc, '\0');




        printf("\nFunção ft_strrchr\n");
        printf("Teste 1 - valor obtido:  %s, valor esperado: %s\n", ret_test1, ret_true1);
        printf("Teste 2 - valor obtido: %s, valor esperado: %s\n", ret_test2, ret_true2);
	printf("Teste 3 - valor obtido: %s, valor esperado: %s\n", ret_test3, ret_true3);
        printf("Teste 4 - valor obtido: %s, valor esperado: %s\n", ret_test4, ret_true4);
        printf("Teste 5 - valor obtido: %s, valor esperado: %s\n", ret_test5, ret_true5);
        printf("Teste 6 - valor obtido: %s, valor esperado: %s\n", ret_test6, ret_true6);
	printf("Teste 7 - valor obtido: %s, valor esperado: %s\n", dd2, dd1);


	/*Função ft_memset*/
        char str3[] = "http://www.tutorialspoint.com";
        char str4[] = "http://www.turorialspoint.com";
	char str5[] = "s";
	char str6[] = "s";
	char str7[] = "yy";
	char str8[] = "yy";
	
	ft_memset(str3,'$',7); 
     	memset(str4,'$',7);

	ft_memset(str5,'#',1);
	memset(str6,'#',1);

	ft_memset(str7,'k',3);
        memset(str8,'k',3);
       
	printf("\nFunção ft_memset\n");
	printf("Teste 1 - valor obtido:  %s, valor esperado: %s\n", str3, str4);
        printf("Teste 2 - valor obtido:  %s, valor esperado: %s\n", str5, str6);
        printf("Teste 3 - valor obtido:  %s, valor esperado: %s\n", str7, str8);
        



        /*Função ft_bzero*/
        char str9[] = "http://www.tutorialspoint.com";
        char str10[] = "http://www.turorialspoint.com";

        ft_bzero(str9,7);
        bzero(str10,7);

        printf("\nFunção ft_bzero\n");
        printf("Teste 1 - valor obtido:  %s, valor esperado: %s\n", str9, str10);
 



	/*Função ft_memcpy*/
   	const char str11[50] = "http://www.tutorialspoint.com";
   	char str12[50];
        const char str13[50] = "http://www.tutorialspoint.com";
        char str14[50];

   	strcpy(str12,"Heloooo!!");
	strcpy(str14,"Heloooo!!");
   	memcpy(str12, str11, 4);
 	ft_memcpy(str14,str13, 4);

	printf("\nFunção ft_memcpy\n");
        printf("Teste 1 - valor obtido:  %s, valor esperado: %s\n", str14, str12);



        /*Função ft_memccpy*/
        const char str15[50] = "http://www.tutorialspoint.com";
        char str16[50];
        const char str17[50] = "http://www.tutorialspoint.com";
        char str18[50];
	char srcc[] = "test basic du memccpy !";
        char *r1;
	char *r2;
	char buff1[22];


	r1 = memccpy("", srcc, 'm', 0);
	r2 = ft_memccpy("", srcc, 'm', 0);


	char *rr1 = memccpy(buff1, srcc, 'm', 22);
	char *rr2 = ft_memccpy(buff1, srcc, 'm', 22);

	
	strcpy(str16,"oooooooooooo");
        strcpy(str18,"oooooooooooo");
	memccpy(str16, str15, 46, 15);
        ft_memccpy(str18, str17, 46, 15);
        printf("\nFunção ft_memccpy\n");

        printf("Teste 1 - valor obtido:  %s, valor esperado: %s\n", str18, str16);
	printf("Teste 2 - valor obtido:  %s, valor esperado: %s\n", r2, r1);
	printf("Teste 3 - valor obtido:  %s, valor esperado: %s\n", rr2, rr1);




	/*Função ft_memmove*/
      const char str19[50] = "http://www.tutorialspoint.com";
        char str20[50];
        const char str21[50] = "http://www.tutorialspoint.com";
        char str22[50];


        strcpy(str20,"Heloooo!!");
        strcpy(str22,"Heloooo!!");
        memmove(str20, str19, 12);
        ft_memmove(str22, str21,12);
        printf("\nFunção ft_memmove\n");
        printf("Teste 1 - valor obtido:  %s, valor esperado: %s\n", str22, str20);

        int size = 128;
	unsigned char *dst = (unsigned char *)malloc(sizeof(unsigned char) * size);
        unsigned char *data = (unsigned char *)malloc(sizeof(unsigned char) * size);
        memset(data, 'A', size);
	ft_memmove(dst, data, size);



	printf("Teste 2 - valor obtido:  %s, valor esperado: %s\n", dst, data);




        /*Função ft_memchr*/
	const char str23[] = "http://www.tutorialspoint.com";
   	char *ret_test7;
	char *ret_true7;
        char *ret_test8;
        char *ret_true8;

   	ret_test7 = ft_memchr(str23,'.', strlen(str23));
	ret_true7 = memchr(str23,'.',strlen(str23));
        ret_test8 = ft_memchr(str23,'z', strlen(str23));
        ret_true8 = memchr(str23,'z',strlen(str23));

        printf("\nFunção ft_memchr\n");
	printf("Teste 1 - valor obtido: %s, valor esperado: %s\n", ret_test7, ret_true7);
        printf("Teste 2 - valor obtido: %s, valor esperado: %s\n", ret_test8, ret_true8);
                                      



	/*Função ft_memcmp*/
	char str24[] = "\xff\xaa\xde\x12WXYZ";
	char str25[] = "\xff\xaa\xde\x12MACOSX";
	int ret_test9;
	int ret_true9;
        int ret_test10;
        int ret_true10;
        int ret_test11;
        int ret_true11;

        ret_test9 = ft_memcmp(str24, str24, 7);
        ret_true9 = memcmp(str24, str24, 7);
        ret_test10 = ft_memcmp(str24, str25, 7);
        ret_true10 = memcmp(str25, str25, 7);
        ret_test11 = ft_memcmp(str25, str24, 7);
        ret_true11 = memcmp(str25, str24, 7);
  
        printf("\nFunção ft_memcmp\n");
        printf("Teste 1 - valor obtido: %i, valor esperado: %i\n", ret_test9, ret_true9);
        printf("Teste 2 - valor obtido: %i, valor esperado: %i\n", ret_test10, ret_true10);
        printf("Teste 3 - valor obtido: %i, valor esperado: %i\n", ret_test11, ret_true11);




        /*Função ft_strlcpy*/
	char *fstr = "BBBB";
	char fbuff1[0xF00];
	char fbuff2[0xF00];
	size_t fr1;
	size_t fr2;

	memset(fbuff1, 'A', 20);
	memset(fbuff2, 'A', 20);
	fr1 = strlcpy(fbuff1, fstr, 5);
	
	fr2 = ft_strlcpy(fbuff2, fstr, 5);


    	printf("\nFunção ft_strlcpy\n");
	printf("Teste 1 - valor obtido: %li, %s, valor esperado: %li, %s\n", fr2, fbuff2, fr1, fbuff1);





	/*Função ft_strlcat*/
/*	char str30[] = "5611";
	char str31[] = "2939";
        char str32[] = "5611";
        char str33[] = "2939";
        int ret_test13;
        int ret_true13;

        ret_test13 = ft_strlcat(str30, str31, 2);
        ret_true13 = strlcat(str32, str33, 2);

        printf("\nFunção ft_strlcat\n");
        printf("Teste 1 - valor obtido: %i, %s, valor esperado: %i, %s\n", ret_test13, str31, ret_true13, str33);
*/


	char ss1[4] = "";
	char ss2[4] = "";



/*	char *rstr = "the cake is a lie !\0I'm hidden lol\r\n";
	char rbuff1[0xF00] = "there is no stars in the sky";
	char rbuff2[0xF00] = "there is no stars in the sky";
*/	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
	size_t rrr1 = strlcat(ss1, "thx to ntoniolo for this test !", 4);
	size_t rrr2 = ft_strlcat(ss2, "thx to ntoniolo for this test !", 4);


	 printf("\nFunção ft_strlcat\n");
	printf("%li\n", max);
	printf("Teste 1 - valor obtido: %li, %s, valor esperado: %li, %s\n", rrr2, ss2, rrr1, ss1);







	/*Função ft_strchr*/
	char str34[] = "http://www.tutorialspoint.com";
        char *ret_test14;
        char *ret_true14;
        char *ret_test15;
        char *ret_true15;

	char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	char *d1 = strchr(src, '\0');
	char *d2 = ft_strchr(src, '\0');


	ret_test14 = ft_strchr(str34, '/');
	ret_true14 = strchr(str34, '/');
        ret_test15 = ft_strchr(str34, 'z');
        ret_true15 = strchr(str34, 'z');

        printf("\nFunção ft_strchr\n");
        printf("Teste 1 - valor obtido: %s, valor esperado: %s\n", ret_test14, ret_true14);
        printf("Teste 2 - valor obtido: %s, valor esperado: %s\n", ret_test15, ret_true15);
	printf("Teste 3 - valor obtido: %s, valor esperado: %s\n", d2, d1);



	/*Função ft_strnstr*/
	char big[] = "Foo Bar Baz";
	char little[] = "Bar";
	char little2[] = "gvg";
	char little3[] = "Foo";
	char little4[] = "Baz";

        printf("\nFunção ft_strnstr\n");
        printf("Teste 1 - valor obtido: %s, valor esperado: %s\n", ft_strnstr(big, little, 4), strnstr(big, little, 4));
	printf("Teste 2 - valor obtido: %s, valor esperado: %s\n", ft_strnstr(big, little, 6), strnstr(big, little, 6));
	printf("Teste 3 - valor obtido: %s, valor esperado: %s\n", ft_strnstr(big, little, 7), strnstr(big, little, 7));
	printf("Teste 4 - valor obtido: %s, valor esperado: %s\n", ft_strnstr(big, little2, 4), strnstr(big, little2, 4));
	printf("Teste 5 - valor obtido: %s, valor esperado: %s\n", ft_strnstr(big, little3, 9), strnstr(big, little3, 9));
	printf("Teste 6 - valor obtido: %s, valor esperado: %s\n", ft_strnstr(big, little4, 10), strnstr(big, little4, 10));
	printf("Teste 7 - valor obtido: %s, valor esperado: %s\n", ft_strnstr(big, little4, 11), strnstr(big, little4, 11));




	/*Função ft_strncmp*/
        char str35[] = "AAAAAAAAA1";
        char str36[] = "AAAAAAAAA2";
        int ret_test16;
        int ret_true16;


        ret_test16 = ft_strncmp(str35, str36, 3);
        ret_true16 = strncmp(str35, str36, 3);

        printf("\nFunção ft_strncmp\n");
        printf("Teste 1 - valor obtido: %i, valor esperado: %i\n", ret_test16, ret_true16);




	/*Função ft_atoi*/
	printf("\nFunção ft_atoi\n");
	printf("Teste 1 - valor obtido: %i, valor esperado: %i\n", ft_atoi("1254de568"), atoi("1254de568"));
	printf("Teste 2 - valor obtido: %i, valor esperado: %i\n", ft_atoi("ee1254de568"), atoi("ee1254de568"));
	printf("Teste 3 - valor obtido: %i, valor esperado: %i\n", ft_atoi("\n"), atoi("\n"));
	printf("Teste 4 - valor obtido: %i, valor esperado: %i\n", ft_atoi("00011/2254de568"), atoi("00011/2254de568"));
	printf("Teste 5 - valor obtido: %i, valor esperado: %i\n", ft_atoi("0"), atoi("0"));
     	printf("Teste 6 - valor obtido: %i, valor esperado: %i\n", ft_atoi("a"), atoi("a"));
	printf("Teste 7 - valor obtido: %i, valor esperado: %i\n", ft_atoi("02"), atoi("02"));
	printf("Teste 8 - valor obtido: %i, valor esperado: %i\n", ft_atoi("1"), atoi("1"));



        /*Função ft_isalpha*/
        printf("\nFunção ft_isalpha\n");
	printf("Teste 1 - valor obtido: %i, valor esperado: %i\n", ft_isalpha(0), isalpha(0));
        printf("Teste 2 - valor obtido: %i, valor esperado: %i\n", ft_isalpha(200), isalpha(200));
        printf("Teste 3 - valor obtido: %i, valor esperado: %i\n", ft_isalpha(-2), isalpha(-2));
        printf("Teste 4 - valor obtido: %i, valor esperado: %i\n", ft_isalpha(1), isalpha(1));
        printf("Teste 5 - valor obtido: %i, valor esperado: %i\n", ft_isalpha(65), isalpha(65));
        printf("Teste 5 - valor obtido: %i, valor esperado: %i\n", ft_isalpha(90), isalpha(90));
        printf("Teste 6 - valor obtido: %i, valor esperado: %i\n", ft_isalpha(97), isalpha(97));
	printf("Teste 7 - valor obtido: %i, valor esperado: %i\n", ft_isalpha(112), isalpha(112));



	/*Função ft_isdigit*/
        printf("\nFunção ft_isdigit\n");
        printf("Teste 1 - valor obtido: %i, valor esperado: %i\n", ft_isdigit(0), isdigit(0));
        printf("Teste 2 - valor obtido: %i, valor esperado: %i\n", ft_isdigit(5), isdigit(5));
        printf("Teste 3 - valor obtido: %i, valor esperado: %i\n", ft_isdigit(9), isdigit(9));
        printf("Teste 1 - valor obtido: %i, valor esperado: %i\n", ft_isdigit(48), isdigit(48));
        printf("Teste 2 - valor obtido: %i, valor esperado: %i\n", ft_isdigit(55), isdigit(55));
        printf("Teste 3 - valor obtido: %i, valor esperado: %i\n", ft_isdigit(57), isdigit(57));




        /*Função ft_isalnum*/
	printf("\nFunção ft_isalnum\n");
        printf("Teste 1 - valor obtido: %i, valor esperado: %i\n", ft_isalnum(0), isalnum(0));
        printf("Teste 2 - valor obtido: %i, valor esperado: %i\n", ft_isalnum(5), isalnum(5));
        printf("Teste 3 - valor obtido: %i, valor esperado: %i\n", ft_isalnum(9), isalnum(9));
        printf("Teste 4 - valor obtido: %i, valor esperado: %i\n", ft_isalnum(48), isalnum(48));
        printf("Teste 5 - valor obtido: %i, valor esperado: %i\n", ft_isalnum(55), isalnum(55));
        printf("Teste 6 - valor obtido: %i, valor esperado: %i\n", ft_isalnum(57), isalnum(57));
	printf("Teste 7 - valor obtido: %i, valor esperado: %i\n", ft_isalnum(65), isalnum(65));
        printf("Teste 8 - valor obtido: %i, valor esperado: %i\n", ft_isalnum(90), isalnum(90));
        printf("Teste 9 - valor obtido: %i, valor esperado: %i\n", ft_isalnum(97), isalnum(97));
        printf("Teste 10 - valor obtido: %i, valor esperado: %i\n", ft_isalnum(112), isalnum(112));




        /*Função ft_isascii*/
        printf("\nFunção ft_isascii\n");
        printf("Teste 1 - valor obtido: %i, valor esperado: %i\n", ft_isascii(-1), isascii(-1));
        printf("Teste 2 - valor obtido: %i, valor esperado: %i\n", ft_isascii(0), isascii(0));
        printf("Teste 3 - valor obtido: %i, valor esperado: %i\n", ft_isascii(9), isascii(9));
        printf("Teste 4 - valor obtido: %i, valor esperado: %i\n", ft_isascii(127), isascii(127));
        printf("Teste 5 - valor obtido: %i, valor esperado: %i\n", ft_isascii(555), isascii(555));






        /*Função ft_isprint*/
        printf("\nFunção ft_isprint\n");
        printf("Teste 1 - valor obtido: %i, valor esperado: %i\n", ft_isprint(-1), isprint(-1));
        printf("Teste 2 - valor obtido: %i, valor esperado: %i\n", ft_isprint(31), isprint(31));
        printf("Teste 3 - valor obtido: %i, valor esperado: %i\n", ft_isprint(32), isprint(32));
        printf("Teste 4 - valor obtido: %i, valor esperado: %i\n", ft_isprint(50), isprint(50));
        printf("Teste 5 - valor obtido: %i, valor esperado: %i\n", ft_isprint(126), isprint(126));
        printf("Teste 6 - valor obtido: %i, valor esperado: %i\n", ft_isprint(127), isprint(127));
        printf("Teste 7 - valor obtido: %i, valor esperado: %i\n", ft_isprint(555), isprint(555));




        /*Função ft_toupper*/

	char c;
	char C;

	c = 'c';
	C = 'C';
        printf("\nFunção ft_toupper\n");
        printf("Teste 1 - valor obtido: %c, valor esperado: %c\n", ft_toupper(c), toupper(c));
        printf("Teste 2 - valor obtido: %c, valor esperado: %c\n", ft_toupper(C), toupper(C));
	printf("Teste 3 - valor obtido: %c, valor esperado: %c\n", ft_toupper(41), toupper(41));
        printf("Teste 4 - valor obtido: %c, valor esperado: %c\n", ft_toupper(120), toupper(120));
        printf("Teste 5 - valor obtido: %i, valor esperado: %i\n", ft_toupper(1), toupper(1));





        /*Função ft_tolower*/

        c = 'c';
        C = 'C';
        printf("\nFunção ft_tolower\n");
        printf("Teste 1 - valor obtido: %c, valor esperado: %c\n", ft_tolower(c), tolower(c));
        printf("Teste 2 - valor obtido: %c, valor esperado: %c\n", ft_tolower(C), tolower(C));
        printf("Teste 3 - valor obtido: %c, valor esperado: %c\n", ft_tolower(41), tolower(41));
        printf("Teste 4 - valor obtido: %c, valor esperado: %c\n", ft_tolower(120), tolower(120));
        printf("Teste 5 - valor obtido: %i, valor esperado: %i\n", ft_tolower(1), tolower(1));




	/*Função ft_calloc*/
	int *a_test;
	int *a_true;
	int loop;

	a_test = (int *)ft_calloc(10, sizeof(int));
	a_true = (int *)calloc(10, sizeof(int));

        printf("\nFunção ft_calloc\n");
	
	loop = 0;
	while(loop < 10)
	{
		a_test[loop]=loop;
		a_true[loop]=loop;
		printf("Teste %i - valor obtido: %d, valor esperado: %d\n", loop, a_test[loop], a_true[loop]);
		loop++;
	}



	/*ft_strdup*/
	char source[] = "lol"; 
  	char* target_test = ft_strdup(source);
        char* target_true = strdup(source);
	
	printf("\nFunção ft_strdup\n");
   	printf("Teste 1 - valor obtido: %s, valor esperado: %s\n", target_test, target_true);
	char *fstrff;
	char *ftmp = "";

	fstrff = ft_strdup(ftmp);
	printf("%i\n",strcmp(fstrff, ftmp));

        printf("Teste 2 - valor obtido: %s, valor esperado: %s\n", ftmp, fstrff);




	/*ft_substr*/
	char* target_test2 = ft_substr(source, 3, 3);
	char* target_test3 = ft_substr(source, 3, 1);
	char* target_test4 = ft_substr(source, 3, 4);
        char* target_test5 = ft_substr(source, 3, 0);
        char* target_test6 = ft_substr(source, 3, 100);
        char* target_test7 = ft_substr(source, 3, -1);
 	char* target_test8 = ft_substr(source, 300, 9);
	char* target_test9 = ft_substr(source, 8, 9);
	char* target_test10 = ft_substr(source, 0, 1);
        char* target_test11 = ft_substr(source, 3, 0);
        char* target_test12 = ft_substr(source, 9, 9);



        printf("\nFunção ft_substr\n");
        printf("Teste 1 - valor obtido: %s, valor esperado: 456\n", target_test2);
	printf("Teste 2 - valor obtido: %s, valor esperado: 4\n", target_test3);
	printf("Teste 3 - valor obtido: %s, valor esperado: 4567\n", target_test4);
        printf("Teste 4 - valor obtido: %s, valor esperado: (null)\n", target_test5);
        printf("Teste 5 - valor obtido: %s, valor esperado: 456789\n", target_test6);
        printf("Teste 6 - valor obtido: %s, valor esperado: (null)\n", target_test7);
        printf("Teste 7 - valor obtido: %s, valor esperado: (null)\n", target_test8);
        printf("Teste 8 - valor obtido: %s, valor esperado: 9\n", target_test9);
        printf("Teste 9 - valor obtido: %s, valor esperado: 1\n", target_test10);
        printf("Teste 10 - valor obtido: %s, valor esperado: (null)\n", target_test11);
	printf("Teste 11 - valor obtido: %s, valor esperado: (null)\n", target_test12);


	char *sff = "malloc protection !";

	char *retff = ft_substr(sff, 0, 5);
        printf("Teste 12 - valor obtido: %s, valor esperado:mallo\n", retff);




        /*Função ft_strjoin*/
        char const str38[] = "5611";
        char const  str39[] = "2939";
        char const str38a[] = "a";
        char const  str39a[] = "b";
        char *strjoin;
        char *strjoin2;

	strjoin = ft_strjoin(str38, str39);
        strjoin2 = ft_strjoin(str38a, str39a);

	printf("\nFunção ft_strjoin\n");
        printf("Teste 1 - valor obtido: %s, valor esperado: 56112939\n", strjoin);
	printf("Teste 2 - valor obtido: %s, valor esperado: ab\n", strjoin2);




       /*Função ft_strtrim*/
        char const str40[] = "     123     ";
        char const str41[] = "aaaaaaaaaaaaaa123aaaaa";
        char const str42[] = "0000000123000";
        char const str43[] = "  aaa0000000123000 ";
	char const str44[] = "rrr123rrr";
	char const unico[] = "-";
	char const teste323[] = "casado";


	char const set[] = " 0a"; 
        char const sett[] = "-";

	char* target_test13 = ft_strtrim(str40, set);
        char* target_test14 = ft_strtrim(str41, set);
        char* target_test15 = ft_strtrim(str42, set);
        char* target_test16 = ft_strtrim(str43, set);
        char* target_test17 = ft_strtrim(str44, set);
	char* target_unico = ft_strtrim(unico, sett);
	char* target_unico_323 = ft_strtrim(teste323, set);

        printf("\nFunção ft_strtrim\n");
        printf("Teste 1 - valor obtido: %s, valor esperado:123\n", target_test13);
        printf("Teste 2 - valor obtido: %s, valor esperado:123\n", target_test14);
        printf("Teste 3 - valor obtido: %s, valor esperado:123\n", target_test15);
        printf("Teste 4 - valor obtido: %s, valor esperado:123\n", target_test16);
        printf("Teste 5 - valor obtido: %s, valor esperado:rrr123rrr\n", target_test17);
        printf("Teste 6 - valor obtido: %s, valor esperado:(null)\n", target_unico);
	printf("Teste 7 - valor obtido: %s, valor esperado:casado\n", target_unico_323);





	/*Função ft_split*/
	char const *str45 = {"casa1 casa2 casa3"};
	char const *str46 = {"-patos1-patos2-patos3-"};
	char const *str47 = {"      split       this for   me  !       "};
	char **resp_45;
	char **resp_46;
	char **resp_47;

	resp_45 = ft_split(str45, ' ');
	resp_46 = ft_split(str46, '-');
	resp_47 = ft_split(str47, ' ');

  	printf("\nFunção ft_split\n");
	printf("Teste 1/1 - valor obtido: %s, valor esperado:casa1\n", *(resp_45));
	printf("Teste 1/2 - valor obtido: %s, valor esperado:casa2\n", *(resp_45 + 1));
	printf("Teste 1/3 - valor obtido: %s, valor esperado:casa3\n", *(resp_45 + 2));


	printf("Teste 2/1 - valor obtido: %s, valor esperado:patos1\n", *(resp_46));
	printf("Teste 2/2 - valor obtido: %s, valor esperado:patos2\n", *(resp_46 + 1));
	printf("Teste 2/3 - valor obtido: %s, valor esperado:patos3\n", *(resp_46 + 2));
	
      	printf("Teste 3/1 - valor obtido: %s, valor esperado:split\n",*(resp_47));
	printf("Teste 3/2 - valor obtido: %s, valor esperado:this\n",*(resp_47 + 1));
	printf("Teste 3/3 - valor obtido: %s, valor esperado:for\n",*(resp_47 + 2));
	printf("Teste 3/4 - valor obtido: %s, valor esperado:me\n",*(resp_47 + 3));
	printf("Teste 3/5 - valor obtido: %s, valor esperado:!\n",*(resp_47 + 4));


	/*Função ft_itoa*/
	char *resp_48;
	char *resp_49;
	char *resp_50;
	char *resp_51;
	char *resp_52;


	printf("\nFunção ft_itoa\n");
        resp_48 = ft_itoa(-123456789);
        resp_49 = ft_itoa(123456789);
        resp_50 = ft_itoa(0);
	resp_51 = ft_itoa(-1);
	resp_52 = ft_itoa(9);

	printf("Teste 1 - valor obtido: %s, valor esperado:-123456789\n", resp_48);
	printf("Teste 2 - valor obtido: %s, valor esperado:123456789\n", resp_49);
	printf("Teste 3 - valor obtido: %s, valor esperado:0\n", resp_50);
	printf("Teste 4 - valor obtido: %s, valor esperado:-1\n", resp_51);
	printf("Teste 5 - valor obtido: %s, valor esperado:9\n", resp_52);
	
	
	
	/*Função ft_strmapi*/
        printf("\nFunção ft_strmapi\n");

	char const *palavra1 = {"a"};
 	char const *palavra2 = {"aa"};
        char const *palavra3 = {"aaa"};
        char const *palavra4 = {"aaaa"};

	
	char *resp_1;
	char *resp_2;
 	char *resp_3;
 	char *resp_4;
        char *resp_1_2;
        char *resp_2_2;
        char *resp_3_2;
        char *resp_4_2;


	resp_1 = ft_strmapi(palavra1, ft_shift);
	resp_2 = ft_strmapi(palavra2, ft_shift);
	resp_3 = ft_strmapi(palavra3, ft_shift);
  	resp_4 = ft_strmapi(palavra4, ft_shift);


	resp_1_2 = ft_strmapi(palavra1, ft_shift2);
        resp_2_2 = ft_strmapi(palavra2, ft_shift2);
        resp_3_2 = ft_strmapi(palavra3, ft_shift2);
        resp_4_2 = ft_strmapi(palavra4, ft_shift2);

  
 	printf("Teste 1 - valor obtido1: %s, valor obtido2:%s, valor esperado1:a, valor esperado2:b\n", resp_1, resp_1_2);
	printf("Teste 2 - valor obtido1: %s, valor obtido2:%s, valor esperado1:ab, valor esperado2:bc\n", resp_2, resp_2_2);
        printf("Teste 3 - valor obtido1: %s, valor obtido2:%s, valor esperado1:abc, valor esperado2:bcd\n", resp_3, resp_3_2);
        printf("Teste 4 - valor obtido1: %s, valor obtido2:%s, valor esperado1:abcd, valor esperado2:bcde\n", resp_4, resp_4_2);



        /*Função ft_putchar_fd*/
        printf("\nFunção ft_putchar_fd\n");
	
	ft_putchar_fd('a',1);
	printf("\n");
	ft_putchar_fd('b',1);
	printf("\n");


	/*Função ft_putstr_fd*/
        printf("\nFunção ft_putstr_fd\n");

        ft_putstr_fd("aaaaa",1);
        printf("\n");
        ft_putstr_fd("bbbbb",1);
        printf("\n");



        /*Função ft_putstr_fd*/
        printf("\nFunção ft_putendl_fd\n");

	ft_putendl_fd("cccc",1);
        ft_putendl_fd("dddd",1);

        /*Função ft_putnbr_fd*/
        printf("\nFunção ft_putnbr_fd\n");

        ft_putnbr_fd(0,1);
        printf("\n");
        ft_putnbr_fd(-5,1);
        printf("\n");
	ft_putnbr_fd(-57,1);
        printf("\n");
        ft_putnbr_fd(-987441,1);
        printf("\n");
 	ft_putnbr_fd(-2147483648,1);
        printf("\n");

	return(0);
}

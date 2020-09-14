/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 00:03:10 by memilio           #+#    #+#             */
/*   Updated: 2020/09/14 16:25:01 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#define OK printf("\033[38;5;46m[OK]\033[0m\t")
#define KO printf("\033[38;5;160m[KO]\033[0m\t")

int		ft_strlen(char const *str);
char	*ft_strcpy(char *dst, char const *src);
int		ft_strcmp(char *s1, char *s2);

static void	strcmp_test(char *s1, char *s2)
{
	int		ft;
	int		or;

	ft = ft_strcmp(s1, s2);
	or = strcmp(s1, s2);
	if (ft == or)
		OK;
	else
		KO;
}

static void strcpy_test(const char *src)
{
	char	dest1[200];
	char	dest2[200];

	bzero(dest1, 200);
	bzero(dest2, 200);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	if (!strcmp(dest1, dest2))
		OK;
	else
		KO;
}

static void	strlen_test(const char *s)
{
	int	or;
    int	ft;

    or = strlen(s);
    ft = ft_strlen(s);
    if (or == ft)
        OK;
    else
        KO;
}

int			main(void)
{
	printf("\t\t\t\033[38;5;226m===LIBASM TEST===\033[0m\n");
	printf("FT_STRLEN:\t");
	strlen_test("Hello world");
	strlen_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
	strlen_test("");
	strlen_test("\n");
	strlen_test("\n\n");
	strlen_test("111+}Te'st!wi/th*[<<As:c2ii3");
	printf("\n");
	printf("FT_STRCPY:\t");
	strcpy_test("Hello world");
	strcpy_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate.");
	strcpy_test("");
	strcpy_test("\n");
	strcpy_test("111+}Te'st!wi/th*[<<As:c2ii3");
	strcpy_test("FIZZ\0BUZZ");
	strcpy_test("\x12\xff");
	printf("\n");
	printf("FT_STRCMP:\t");
	strcmp_test("Hello world", "Hello world");
	strcmp_test("Hello world", "");
	strcmp_test("\200", "\0");
	strcmp_test("111+}Te'st!wi/th*[<<As:c2ii3", "111+}Te'st!wi/th*[<<As:c2ii");
	strcmp_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate.");
	strcmp_test("FIZZ\0BUZZ", "FIZZ\0");
	printf("\n");
	return (0);
}

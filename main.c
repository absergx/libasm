/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 00:03:10 by memilio           #+#    #+#             */
/*   Updated: 2020/09/02 00:48:00 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strlen(char const *str);
char	*ft_strcpy(char *dst, char const *src);

static void strcpy_test(const char *src)
{
	char	dest1[200];
	char	dest2[200];

	bzero(dest1, 200);
	bzero(dest2, 200);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	if (!strcmp(dest1, dest2))
		printf("OK\t");
	else
		printf("KO\t");
}

static void	strlen_test(const char *s)
{
	int	or;
    int	ft;

    or = strlen(s);
    ft = ft_strlen(s);
    if (or == ft)
        printf("OK\t");
    else
        printf("KO\t");
}

int			main(void)
{
	printf("\t\t\t===LIBASM TEST===\n");
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
	return (0);
}

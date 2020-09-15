/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 00:03:10 by memilio           #+#    #+#             */
/*   Updated: 2020/09/15 12:35:07 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include "libasm.h"

#define OK printf("\033[38;5;46m[OK]\033[0m\t")
#define KO printf("\033[38;5;160m[KO]\033[0m\t")

static void	write_test(char *filename)
{
	int		ft_fd;
	int		or_fd;
	int		ft;
	int		or;
	int		ft_errno;
	int		or_errno;
	char	*buf;

	buf = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate.";
	or_fd = open(filename, O_RDWR);
	or = write(or_fd, buf, 63);
	or_errno = errno;
	if (or_fd > 0)
		close(or_fd);
	ft_fd = open(filename, O_RDWR);
	ft = ft_write(ft_fd, buf, 63);
	ft_errno = errno;
	if (ft_fd > 0)
		close(ft_fd);
	(or == ft) ? OK : KO;
	if (ft == -1 || or == -1)
		(ft_errno == or_errno) ? OK : KO;
}

static void	read_test(char *filename)
{
	int		or_fd;
	int		ft_fd;
	int		or;
	int		ft;
	int		or_errno;
	int		ft_errno;
	char	or_buf[256];
	char	ft_buf[256];

	bzero(ft_buf, 256);
	bzero(or_buf, 256);
	or_fd = open(filename, O_RDONLY);
	or = read(or_fd, or_buf, 255);
	or_errno = errno;
	if (or_fd > 0)
		close(or_fd);
	ft_fd = open(filename, O_RDONLY);
	ft = ft_read(ft_fd, ft_buf, 255);
	ft_errno = errno;
	if (ft_fd > 0)
		close(ft_fd);
	(or == ft && !strcmp(or_buf, ft_buf)) ? OK : KO;
	if (ft == -1 || or == -1)
		(ft_errno == or_errno) ? OK : KO;
}

static void	strdup_test(const char *str)
{
	char	*or;
	char	*ft;

	or = strdup(str);
	ft = ft_strdup(str);
	(!strcmp(or, ft)) ? OK : KO;
}

static void	strcmp_test(char *s1, char *s2)
{
	int		ft;
	int		or;

	ft = ft_strcmp(s1, s2);
	or = strcmp(s1, s2);
	(ft == or) ? OK : KO;
}

static void strcpy_test(const char *src)
{
	char	dest1[200];
	char	dest2[200];

	bzero(dest1, 200);
	bzero(dest2, 200);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	(!strcmp(dest1, dest2)) ? OK : KO;
}

static void	strlen_test(const char *s)
{
	int	or;
    int	ft;

    or = strlen(s);
    ft = ft_strlen(s);
    (or == ft) ? OK : KO;
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
	printf("FT_STRDUP:\t");
	strdup_test("FIZZ\0BUZZ");
	strdup_test("Hello world");
	strdup_test("");
	strdup_test("\x12\xff");
	strdup_test("\n\n");
	strdup_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate.");
	printf("\n");
	printf("FT_READ:\t");
	read_test("test1.txt");
	read_test("test2.txt");
	read_test("not_valid");
	int fd = open("test3.txt", O_CREAT, 0000);
	close(fd);
	read_test("test3.txt");
	printf("\n");
	printf("FT_WRITE:\t");
	write_test("test1.txt");
	write_test("test2.txt");
	write_test("test3.txt");
	write_test("not_valid");
	printf("\n");
	return (0);
}

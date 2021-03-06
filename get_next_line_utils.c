#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	register size_t	len;

	len = ZERO;
	while ('\0' != s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t num_items, size_t size_item)
{
	register char	*new;
	register size_t	bytes;
	register size_t	x;

	bytes = num_items * size_item;
	new = (char *) malloc(bytes);
	if (NULL != new)
	{
		x = ZERO;
		while (x < bytes)
		{
			new[x] = '\0';
			x++;
		}
	}
	return ((void *) new);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len, int flag)
{
	t_gnl_substr	data;

	if (NULL == s)
		return (NULL);
	if ('\0' == *s || start > ft_strlen(s))
		return ((char *) ft_calloc(TRUE, sizeof(char)));
	data.start = s;
	s += start;
	data.sub_start = s;
	data.size = TRUE;
	while ('\0' != *(s++) && ZERO != len--)
		data.size++;
	data.new = (char *) ft_calloc(data.size + 1, sizeof(char));
	if (NULL != data.new)
	{
		while (ZERO < data.size--)
			data.new[data.size] = data.sub_start[data.size];
	}
	if (TRUE == flag)
		free((void *) data.start);
	return (data.new);
}

char	*ft_strjoin_f1_f2(char *s1, char *s2)
{
	register char	*nw_str;
	register char	*start;
	register char	*to_free_s1;
	register char	*to_free_s2;

	if (!s1 || !s2)
		return (NULL);
	nw_str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (NULL == nw_str)
		return (NULL);
	start = nw_str;
	to_free_s1 = s1;
	to_free_s2 = s2;
	while ('\0' != *s1)
		*(nw_str++) = *(s1++);
	while ('\0' != *s2)
		*(nw_str++) = *(s2++);
	free(to_free_s1);
	to_free_s1 = NULL;
	free(to_free_s2);
	to_free_s2 = NULL;
	return (start);
}

int	gnl_isnl(char *str)
{
	register int	index;

	index = -1;
	while (++index < BUFFER_SIZE && '\0' != str[index])
		if ('\n' == str[index] || '\r' == str[index])
			return (index);
	return (-1);
}

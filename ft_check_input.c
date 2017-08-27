/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:27:46 by vrudenko          #+#    #+#             */
/*   Updated: 2016/12/05 15:24:50 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem-in.h"

void ft_free_str_array(char **line)
{
	int i;

	i = 0;

	while (line[i] != 0)
	{
		free(line[i]);
		i++;
	}
	free(line);
}



int ft_is_number(char *num)
{
	int i;

	i = 0;

	while (num[i] != '\0')
	{
		if (!ft_isdigit(num[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int ft_is_comment(char *line)
{
	if (line[0] == '#')
	{
		return (1);
	}
	return (0);
}

int ft_is_number_of_ants(char *line)
{
	int i;

	i = 0;
	if (strlen(line) == 0)
	{
		return (0);
	}
	if (!ft_is_number(line))
	{
		return (0);
	}
	return (1);
}

int ft_is_rooms(char *line)
{
	char	**room;

	room = ft_strsplit(line, ' ');
	if (count_str_array(room) != 3)
	{
		ft_free_str_array(room);
		return (0);
	}

//	printf("%d\n", count_str_array(room));
//	printf("[%s]\n", room[0]);
//	printf("[%s]\n", room[1]);
//	printf("[%s]\n", room[2]);
//
	if(room[0][0] == '#' || room[0][0] == 'L')
	{
		ft_free_str_array(room);
		return (0);
	}

	if (!ft_is_number(room[1]))
	{
		ft_free_str_array(room);
		return (0);
	}
	if (!ft_is_number(room[2]))
	{
		ft_free_str_array(room);
		return (0);
	}
	ft_free_str_array(room);
	return (1);
}

int ft_is_links(char *line)
{
	char **link;

	link = ft_strsplit(line, '-');

//	printf("%d\n", count_str_array(link));
//	printf("[%s]\n", link[0]);
//	printf("[%s]\n", link[1]);



	if (count_str_array(link) != 2)
	{
		ft_free_str_array(link);
		return (0);
	}
	ft_free_str_array(link);
	if (ft_countchars(line, '-') != 1)
	{
//		printf("%d\n", ft_countchars(line, '-'));
		return (0);
	}
	return (1);
}

int ft_is_start(char * line)
{
//	printf("tut start\n");
	if (!ft_strcmp(line, "##start"))
	{
		return (1);
	}
	return (0);
}

int ft_is_end(char * line)
{
	if (!ft_strcmp(line, "##end"))
	{
		return (1);
	}
	return (0);
}


int ft_find_number_of_ants(char **input)
{
	int i;
	int number_of_ants;

	i = 0;

	while (input[i] != 0)
	{
		if (ft_is_comment(input[i]))
		{
			i++;
		}
		else if (ft_is_number_of_ants(input[i]))
		{
			number_of_ants = ft_atoi(input[i]);
			input[i][0] = '#';
			return (number_of_ants);
		}
		else
		{
			ft_error();
		}
	}
	return 0;
}

int ft_determ_number_of_rooms(char **input)
{
	int i;
	int rooms;

	i = 0;
	rooms = 0;
	while (!ft_is_links(input[i]))
	{
		if (ft_is_start(input[i]) || ft_is_end(input[i]))
		{
			i++;
		}
		else if (ft_is_comment(input[i]))
		{
			i++;
		}
		else if (ft_is_rooms(input[i]))
		{
			i++;
			rooms++;
		}
		else
		{
			ft_error();
		}
	}
	return (rooms);
}

char *ft_add_room(char *src, char *dst)
{
	int letters;
	char **line;

	line = ft_strsplit(dst, ' ');

	letters = ft_strlen(line[0]);

	src = ft_strnew(letters);

	src = ft_strcpy(src, dst);
	dst[0] = '#';

	ft_free_str_array(line);
//	printf("%p\n", src);

	return (src);
}

char **ft_find_rooms(char **input)
{
	int i;
	int number_of_rooms;
	char **rooms;
	int k;

	i = 0;
	k = 2;

	number_of_rooms = ft_determ_number_of_rooms(input);

	rooms = (char**)malloc(sizeof(char**) * (number_of_rooms + 1));
	while (i <= number_of_rooms)
	{
		rooms[i] = 0;
		i++;
	}
	i = 0;


//	printf("%d\n", number_of_rooms);

	while (!ft_is_links(input[i]))
	{
//		printf("[%d]\n", ft_is_start(input[i]));
		if (ft_is_start(input[i]))
		{
			i++;
			if (ft_is_rooms(input[i]))
			{
				if (!rooms[0])
				{
					rooms[0] =	ft_add_room(rooms[0], input[i]);
//					printf("strat %s\n", rooms[0]);
				}
				else
				{
					rooms[k] =	ft_add_room(rooms[k], input[i]);
//					printf("?? %s\n", rooms[k]);
					k++;
				}
			}
		}
		else if (ft_is_end(input[i]))
		{
			i++;
			if (ft_is_rooms(input[i]))
			{
				if (!rooms[1])
				{
					rooms[1] =	ft_add_room(rooms[1], input[i]);
//					printf("end %s\n", rooms[1]);
				}
				else
				{
					rooms[k] = ft_add_room(rooms[k], input[i]);
//					printf("?? %s\n", rooms[k]);
					k++;
				}
			}
		}
		else if (ft_is_rooms(input[i]))
		{
			rooms[k] = ft_add_room(rooms[k], input[i]);
//			printf("lol%s\n", rooms[k]);
			k++;
		}
		i++;
//		printf("%s\n", rooms[k-]);
	}

//	printf("SUKABLA\n");
//	i = 0;
//	while (rooms[i])
//	{
//		printf("%s\n", rooms[i]);
//		i++;
//	}

	return (rooms);
}



int ft_determ_number_of_links(char **input)
{
	int i;
	int links;

	i = 0;
	links = 0;
	while (input[i] != 0)
	{
		if (ft_is_start(input[i]) || ft_is_end(input[i]))
		{
			i++;
		}
		else if (ft_is_comment(input[i]))
		{
			i++;
		}
		else if (ft_is_links(input[i]))
		{
			i++;
			links++;
		}
		else
		{
			ft_error();
		}
	}
	return (links);
}

char *ft_add_link(char *src)
{
	int letters;
	char	*new_link;

	letters = ft_strlen(src);
	new_link = ft_strnew(letters);
	new_link = ft_strcpy(new_link, src);
	src[0] = '#';

	return new_link;

}


char **ft_find_links(char **input)
{
	int		i;
	char	**links;
	int		number_of_links;
	int		k;

	i = 0;
	k = 0;

	number_of_links = ft_determ_number_of_links(input);

//	printf("%d\n", number_of_links);

	links = (char**)malloc(sizeof(char**) * (number_of_links + 1));
	while (i <= number_of_links)
	{
		links[i] = 0;
		i++;
	}
	i = 0;

	while (input[i] != 0)
	{
		if (ft_is_comment(input[i]))
		{

		}
		else if (ft_is_links(input[i]))
		{
			links[k] = ft_add_link(input[i]);
			k++;
		}
		else
		{
			ft_error();
		}
		i++;
	}



	return (links);
}


void ft_check_input(char **input)
{
	int i;
	int num_of_ants;
	char **rooms;
	char **links;
	i = 0;

	num_of_ants = ft_find_number_of_ants(input);
	rooms = ft_find_rooms(input);
	links = ft_find_links(input);


//	printf("%d\n", ft_is_links("    asdf   -   23       32        "));


//	printf("%d\n", num_of_ants);






	printf("////////LINKS///////////\n");
	i = 0;
	while (links[i] != 0)
	{
		printf("%s\n", links[i]);
		i++;
	}
//
  i = 0;
	printf("/////////ROMS//////////\n");
	while (rooms[i] != 0)
	{
		printf("%s\n", rooms[i]);
		i++;
	}

	i = 0;

//	printf("///////////////////\n");


//	while (input[i] != 0)
//	{
//		printf("%s\n", input[i]);
//		i++;
//	}

}
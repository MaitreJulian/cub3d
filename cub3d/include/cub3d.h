/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:50:15 by jvenkata          #+#    #+#             */
/*   Updated: 2025/11/18 11:49:24 by jvenkata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		*ceiling;
	int		*floor;
}	t_textures;

typedef struct s_map
{
	int			fd;
	int			size;
	char		**tab;
	int			pos_p_x;
	int			pos_p_y;
	t_textures	*texture;
}	t_map;

//ERROR
int		ft_error(char c);

//CHECK_FILE
int		check_name(char *file);

//INIT_MAP
int		check_map(t_map *map);
void	extract_map(t_map *map, char *line);
void	init_map(t_map *map, char *file);
t_map	*parse_map(char **argv);

//TEXTURES
void	find_texture(t_map *map, char *line);
char	*init_texture(t_map *map);

//GNL
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
void	ft_bzero(void *s, size_t len);
void	*ft_calloc(size_t elementCount, size_t elementSize);
size_t	ft_strlen(const char *str);

//UTILS
void	print_textures(t_textures *text);
void	print_map(char **map_tab);
int		only_01(char *line);
char	**copy_map(char **map);

#endif
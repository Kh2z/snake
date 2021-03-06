/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 00:36:26 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/25 02:46:50 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H
# include <stdlib.h>
# include <unistd.h>
# include <curses.h>
# include <time.h>
# ifdef true
#  undef true
# endif
# ifdef false
#  undef false
# endif
# define CHARACTER 'o'
# define UP 65
# define DOWN 66
# define RIGHT 67
# define LEFT 68
# ifndef WIN_X
#  define WIN_X 26
# endif
# ifndef WIN_Y
#  define WIN_Y 90
# endif

typedef enum		e_head
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}					t_head;
typedef enum		e_bool
{
	false,
	true
}					t_bool;
typedef struct		s_coords
{
	int x;
	int y;
}					t_coords;
typedef struct		s_list
{
	t_head			head;
	int				pos_x;
	int				pos_y;
	struct s_list	*next;
}					t_list;

/*
** main
*/

int					get_elems(t_list **snake, t_coords *bonus,
t_head face, double *speed);
t_coords			generate_bonus(void);
void				display_elems(t_list *snake, t_coords bonus, WINDOW *game);
int					get_direction(t_head prev);
int					get_next_pos(t_list **snake, t_coords bonus,
t_head new_head);
void				get_next_head(t_list **snake);
void				add_member(t_list **snake);
int					show_leaderboard(void);
int					choose_option(void);
int					check_pos(t_list *snake_head);
int					pause_menu(void);
void				init_game(t_list *snake, WINDOW *game);
void				death_animation(t_list *snake, WINDOW *game);

/*
** utils
*/

t_list				*ft_lstnew(int x, int y, t_head head);
int					ft_atoi(const char *str);
void				ft_fputs(int fd, char *s);
t_bool				ft_kbhit(void);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstclear(t_list **lst);
void				ft_wait(double seconds);
int					ft_lstsize(t_list *lst);
#endif

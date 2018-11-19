/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:16:33 by dalauren          #+#    #+#             */
/*   Updated: 2018/07/18 17:50:20 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define L lem
# define END lem->name_end
# define ROOM lem->lst_room
# define START lem->name_start

typedef struct				s_parse_connex
{
	char					**tab;
	struct s_parse_connex	*next;
}							t_parse_connex;

typedef struct				s_lists
{
	char					*name;
	struct s_lists			*next;
}							t_lists;

typedef struct				s_ant
{
	char					*position;
	int						id;
	int						moved;
	struct s_ant			*next;
}							t_ant;

typedef struct				s_map
{
	char					**tab;
	struct s_map			*next;
}							t_map;

typedef struct				s_room
{
	int						start;
	int						visited;
	int						distance;
	int						end;
	char					*name;
	int						ant;
	int						connex;
	int						x;
	int						y;
	char					**neigh;
	struct s_room			*next;
}							t_room;

typedef struct				s_lem
{
	int						nb_ant;
	int						nb_room;
	int						distance_from_start;
	int						turn;
	int						start;
	int						found_start;
	int						found_end;
	int						end;
	int						way_out;
	int						nb_comment;
	int						way_in;
	int						x;
	int						y;
	char					*name_start;
	char					*name_end;
	t_map					*tmp2;
	t_ant					*ant;
	t_room					*lst_room;
	t_map					*map;
	t_parse_connex			*con;
}							t_lem;

int							main_algo(t_lem *lem);
int							comment_or_unknowed_commend(char *str);
int							check_nb_ant(t_lem *lem, char *str);
int							check_value(char *str, t_lem *lem, int i, int j);
int							parse_room(t_lem *lem, char *str);
int							check_tab(char **tab, t_lem *lem);
int							check_same_name_room(t_lem *lem, char **tab);
int							get_parse_2(t_lem **lem, char *str);
int							start_getting_data(t_lem **lem);
int							check_data_room(t_lem *lem, char *str);
int							check_connexion(t_lem *lem, char *str);
int							size_tab(char **tab);
int							get_connexion(t_lem *lem);
int							start_algo(t_lem **lem);
int							check_name_end(t_lem *lem);
int							got_connexion(t_room *room);
int							do_algo(t_lem *lem, t_room *start);
int							nb_connex(t_room *room);
int							find_road(t_lem *lem, t_room *room,
							t_lists **list_move);
int							get_road(t_lem *lem);
int							move_list(t_lem *lem, t_room *room,
							t_lists **list_move);
int							check_name_and_double_connexion(t_lem *lem,
							char **tab);
int							check_double_connexion(t_lem *lem, char **tab);
int							check_same_name_connexion(char **tab);
int							move_ant(t_lists **list, t_lem *lem);
void						free_tab(char **tab);
void						lst_push_back(t_room **begin_list, char *str, int x,
							int y);
void						lst_push_front(t_room **begin_list, char *str,
							int x, int y);
void						lst_push_front_map(t_map **begin_list, char **tab);
void						lst_push_back_map(t_map **begin_list, char **tab);
void						free_node(t_lists **begin);
void						lst_push_back_l(t_lists **begin_list, char *name);
void						lst_push_front_l(t_lists **begin_list, char *name);
void						free_all(t_lem **lem);
void						free_ant(t_ant *ant);
void						free_tab_neigh(char **tab);
void						free_lists(t_lists *list);
void						lst_push_front_con(t_parse_connex **begin_list,
							char **tab);
void						lst_push_back_con(t_parse_connex **begin_list,
							char **tab);
void						lst_push_back_a(t_ant **begin_list, char *name,
							int id);
char						*find_voisin_name(t_room *room);
char						**cpy_tab(char **tab);
t_map						*create_elem_map(char **tab);
t_room						*create_elem(char *str, int x, int y);
t_room						*find_node(t_lem *lem, char *name);
t_lists						*create_elem_l(char *name);
t_ant						*create_elem_a(char *name, int id);
t_parse_connex				*create_elem_con(char **tab);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cw.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 09:54:29 by yholub            #+#    #+#             */
/*   Updated: 2018/08/17 09:54:29 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_CW_H
# define VM_CW_H


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

# include "../ft_printf/ft_printf/ft_printf.h"
# include "op.h"

# define SIZE_DEC (16 + PROG_NAME_LENGTH + COMMENT_LENGTH)

typedef struct					s_flags
{
	int 						v;
	int							dump;
	int				 			cycle;
}								t_flags;

typedef struct 					s_player
{
  	t_header					*head;
 	int 						p_n;
	unsigned char				code[CHAMP_MAX_SIZE + 1];
  	int							fd;
}								t_player;

typedef struct 					s_area
{
  	unsigned char				val;
  	unsigned int				col;
  	int							player;
}								t_area;

typedef struct					s_karetka
{
	unsigned int 				reg[16];
	int 						pos;
   	int 						carry;
  	int 						live;
  	int 						player;
  	unsigned char 				com;
  	int 						cycles;
  	struct s_karetka			*next;
}								t_kar;

typedef struct					s_vm
{
	t_player					*p;
  	t_area						ar[MEM_SIZE + 1];
  	t_kar						*kar;
	int 						cou_pl;
}								t_vm;

void				print_result(t_vm *v, t_flags *fl);
t_flags				*init_flags(void);
t_vm				*init_vm_struct(char **argv, int argc);
void				ft_parse_args(t_flags *fl, t_vm *v, char **argv, int argc);
int					count_corf(char **argv, int argc);
int 				is_cor_format(char *str);
int					num_size(int src);
void				vm_grap_pl_infp(t_vm *v);
void				get_magic_head(t_player pl);
void				get_size_of_bot(t_player pl);
void				print_usage(void);
void				exit_prog_err(void);
void				set_players(t_vm *v);


#endif

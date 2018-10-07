#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_ssl{
	int player;
	int player_name;
	int karetka;
	int k;
	struct s_ssl *next;

}				t_ssl;

void make_player_and_karetka(t_ssl *lst)
{
	if (lst->k >= 0 && lst->k <= 255)
		lst->player = 1;
	else if (lst->k >= 1023 && lst->k <= 1279)
		lst->player = 2;
	else if (lst->k >= 2047 && lst->k <= 2304)
		lst->player = 3;
	else if (lst->k >= 3071 && lst->k <= 3327)
		lst->player = 4;
	else
		lst->player = 9;

	if (lst->k % 1024 == 0)
		lst->karetka = 1;
}

t_ssl *structura(t_ssl *name)
{
	static int k;
	t_ssl* fst;
	t_ssl *new = (t_ssl *)malloc(sizeof(t_ssl));
	if (!name)
	{
		new->k = k++;
		fst = new;
		name = new;
		name->next = NULL;
	}
	else
	{
		fst = name;
		while (name->next != NULL)
			name = name->next;
		new->k = k++;
		name->next = new;
		new->next = NULL;
	}
		make_player_and_karetka(new);
	return (fst);
}

WINDOW	*create_win()
{
	int max_y; 
	int max_x;

	getmaxyx(stdscr, max_y, max_x);
	WINDOW *win = newwin(max_y - 3, max_x - 2, 1, 1);
	box(win, 0, 0);
	refresh();
	wrefresh(win);
	return (win);
}


void 	make_color(WINDOW *win, t_ssl* lst)
{
	static int n;
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);

	lst->karetka == 1 ? wattron(win, A_STANDOUT) : wattroff(win, A_STANDOUT);
	if (n == 1023 && ((n = 0) || 1))
		return ;
	else if (n < 256)
	{
		if (lst->player == 1)
			wattron(win, COLOR_PAIR(lst->player));
		else if (lst->player == 2)
			wattron(win, COLOR_PAIR(lst->player));
		else if (lst->player == 3)
			wattron(win, COLOR_PAIR(lst->player));
		else if (lst->player == 4)
			wattron(win, COLOR_PAIR(lst->player));
	}
	else
		wattroff(win, COLOR_PAIR(lst->player));
	n++;
}

void set_position(int *x, int *y)
{
	*x += 3;
	if (*x == 193)
	{
		*x = 1;
		(*y)++;
	}
}


void set_menu2(WINDOW *win, t_ssl *lst, int x, int y)
{
	
	mvwprintw(win, y + 8, x, "PLAYER 3 :");
	mvwprintw(win, y + 8, x + 11, "name player 3");
	mvwprintw(win, y + 9, x + 2, "Last live: ");
	mvwprintw(win, y + 9, x + 13, "#last live#");
	mvwprintw(win, y + 10, x + 2, "Lives in current period: ");
	mvwprintw(win, y + 10, x + 27, "#input period#");

	mvwprintw(win, y + 12, x, "PLAYER 4 :");
	mvwprintw(win, y + 12, x + 11, "name player 4");
	mvwprintw(win, y + 13, x + 2, "Last live: ");
	mvwprintw(win, y + 13, x + 13, "#last live#");
	mvwprintw(win, y + 14, x + 2, "Lives in current period: ");
	mvwprintw(win, y + 14, x + 27, "#input period#");

	mvwprintw(win, y + 16, x, "|-------------------------------------------------|");

	mvwprintw(win, y + 18, x, "CYCLE:");
	mvwprintw(win, y + 18, x + 15, "#cycle#");
	mvwprintw(win, y + 19, x, "PROCESSES:");
	mvwprintw(win, y + 19, x + 15, "#processes#");

	mvwprintw(win, y + 21, x, "CYCLE_TO_DIE:");
	mvwprintw(win, y + 21, x + 15, "#cycle to die#");
	mvwprintw(win, y + 23, x, "CYCLE_DELTA:");
	mvwprintw(win, y + 23, x + 15, "#processes#");
	mvwprintw(win, y + 25, x, "NBR_LIVE:");
	mvwprintw(win, y + 25, x + 15, "#nbr live#");
	mvwprintw(win, y + 27, x, "MAX_CHECKS:");
	mvwprintw(win, y + 27, x + 15, "#max checks#");
}

void set_menu(WINDOW *win, t_ssl *lst)
{
	int x;
	int y;

	x = 194;
	y = 1;
	mvwprintw(win, y, x, "PLAYER 1 :");
	mvwprintw(win, y, x + 11, "#name player 1#");
	mvwprintw(win, y + 1, x + 2, "Last live: ");
	mvwprintw(win, y + 1, x + 13, "#last live#");
	mvwprintw(win, y + 2, x + 2, "Lives in current period: ");
	mvwprintw(win, y + 2, x + 27, "#input period#");

	mvwprintw(win, y + 4, x, "PLAYER 2 :");
	mvwprintw(win, y + 4, x + 11, "name player 2");
	mvwprintw(win, y + 5, x + 2, "Last live: ");
	mvwprintw(win, y + 5, x + 13, "#last live#");
	mvwprintw(win, y + 6, x + 2, "Lives in current period: ");
	mvwprintw(win, y + 6, x + 27, "#input period#");

	set_menu2(win, lst, 194, 1);
}

int main(int argc, char **argv)
{
	initscr();

	WINDOW *win;
	t_ssl *lst;
	int i = -1, y = 1, x = 1;

	while (++i < 4096)
		lst = structura(lst);

	start_color();

	win = create_win();
	while (lst)
	{
		make_color(win, lst);
		mvwprintw(win, y, x, "ff");
		wattroff(win, COLOR_PAIR(lst->player));
		wrefresh(win);
		set_position(&x, &y);
		lst = lst->next;
		set_menu(win, lst);
	}
	set_menu(win, lst);
	getch();
	endwin();
	return (1);
}
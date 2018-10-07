#include <ncurses.h>

int main(int argc, char **argv)
{

	int max_y; 
	int max_x;
	initscr();
	noecho();
	// halfdelay(3); //делает задержку работы или ждет что-то я ебу
	timeout(500); // -1 ждет след команды для нажатия 500 такое же как halfdelay(5);


	int c;
	while ((c = getch()) != 'x')
		printw("%d\n", c);


	endwin();	
	return (1);
}



//https://code-live.ru/post/terminal-mode-management-ncurses/  полезная

//позиция вывода и движение курсора


// int main(int argc, char **argv)
// {
// 	initscr(); 
// 	raw();
// 	int derp = 4;
// 	move(0, 3); // сперва передвигаем курсор потом пишем
// 	printw("This is bog %d", derp);
// 	addch('a');
	

// 	mvprintw(15, 20, "Movement");
// 	mvaddch(0, 50, '@'); // выводим символ на позицию

// 	getch(); // пишем чтоб вывело то что мы имеем сверху

// 	endwin();

// 	return (1);
// }




//Подчеркивание, выдиление вклю и выкл

// int main(int argc, char **argv)
// {
// 	initscr(); 
// 	raw();
// 	attron(A_STANDOUT | A_UNDERLINE);
// 	printw("Let's fuck all");
// 	attroff(A_STANDOUT | A_UNDERLINE);
// 	printw("Let's fuck all");

// 	getch();
// 	endwin();

// 	return (1);
// }


//Цвета

// int main(int argc, char **argv)
// {
// 	initscr(); 
// 	raw();

// 	start_color();
// 	init_pair(1, COLOR_RED, COLOR_BLACK);
// 	attron(COLOR_PAIR(1) | A_UNDERLINE);
// 	printw("PIZDEC MY LITTLE FRIEND");
// 	attroff(COLOR_PAIR(1));

// 	getch();
// 	endwin();

// 	return (1);
// }



//очистка и ввод символа  клавиатуры

// int main(int argc, char **argv)
// {
// 	initscr();			/* Start curses mode 		  */
// 	printw("Hello World !!!");	/* Print Hello World		  */
// 	refresh();

// 	int c = getch();
// 	clear();
// 	printw("%d", c);			/* Print it on to the real screen */
// 	getch();			/* Wait for user input */
// 	clear();
// 	endwin();			/* End curses mode		  */

// 	return (1);
// }


//окна

// int main(int argc, char **argv)
// {
// 	initscr();			/* Start curses mode 		  */

// 	int height, width, start_y, start_x;
// 	height = 65; // высота бокса
// 	width = 190; // ширина бокса
// 	start_y = 0;
// 	start_x = 0;
// 	WINDOW * win = newwin(height, width, start_y, start_x);
// 	refresh();
// 	box(win, 0, 0);
// 	mvwprintw(win, 1, 1, "0e 90 02 ff fa 32 66 7a 0e 90 02 ff fa 32 66 7a 0e 90 02 ff fa 32 66 7a");
// 	wrefresh(win); // приставка w используется при работе с окнам


// 	getch();			/* Wait for user input */
// 	endwin();			/* End curses mode		  */

// 	return (1);
// }


//убираем ребро бокса и узнаем что такое raw cbreak

// int main(int argc, char **argv)
// {
// 	initscr();			/* Start curses mode 		  */

// 	//noecho(); // не выводит getch если мы нажимаем
// 	//raw(); // попадают все символы с клавиатуры даже ctrl+c которое зарезервировано при прирывании
// 	//cbreak(); // отменяет действие raw
// 	int height, width, start_y, start_x;
// 	height = 65; // высота бокса
// 	width = 190; // ширина бокса
// 	start_y = 0;
// 	start_x = 0;
// 	WINDOW * win = newwin(height, width, start_y, start_x);
// 	refresh();
// 	box(win, 0, 0); // в этом режиме вместо нулей будет аски символ из которого будет линия
// 	wborder(win, left, right, top, bottom, tlc, trc, blc, brc); - первые 4 это стороны вторые 4 это углы
// 	mvwprintw(win, 1, 1, "0e 90 02 ff fa 32 66 7a 0e 90 02 ff fa 32 66 7a 0e 90 02 ff fa 32 66 7a");
// 	wrefresh(win); // приставка w используется при работе с окнам

// 	getch();
// 	getch();			/* Wait for user input */
// 	endwin();			/* End curses mode		  */

// 	return (1);
// }


//еще раз работа со шрифтами и цветами

// int main(int argc, char **argv)
// {
// 	initscr();		

// 	if (!has_colors()) // делаем сперва проверку на цвета
// 	{
// 		printw("Terminal does not support color");
// 		getch();
// 		return (-1);
// 	}
// 	start_color();
// 	init_pair(1, COLOR_CYAN, COLOR_WHITE); // создаем номер пары с параметрами цветов
// 	init_color(COLOR_WHITE, 0, 0, 255); // сами создаем цвет для константы какой захотим
// 	attron(COLOR_PAIR(1));

// 	printw("This is some text");
// 	attroff(COLOR_PAIR(1));
// 	// A_NORMAL
// 	// A_STANDOUT
// 	// A_BLINK
// 	// A_DIM
// 	// A_BOLD
// 	// A_PROTECT
// 	// A_INVIS
// 	// A_ALTCHARSET

// 	// COLOR_PAIR(n)
// 	// COLOR_BLACK
// 	// COLOR_RED
// 	// COLOR_GREEN
// 	// COLOR_YELLOW
// 	// COLOR_BLUE
// 	// COLOR_MAGENTA
// 	// COLOR_CYAN
// 	// COLOR_WHITE

// 	getch();			
// 	endwin();			

// 	return (1);
// }

//ввод с клавиатуры и вывод в таблицу как символов так и нажатия на кнопку

// int main(int argc, char **argv)
// {

// 	int max_y;
// 	int max_x;
// 	initscr();


// 	getmaxyx(stdscr, max_y, max_x);

// 	WINDOW *win = newwin(max_y - 3, max_x - 2, 1, 1);
// 	box(win, 0, 0);
// 	refresh();
// 	wrefresh(win);



// 	keypad(win, true); //сперва эта хуйня
// 	int c = wgetch(win);

// 	if (c == 'j')
// 	{
// 		mvwprintw(win, 1, 1, "you pressed j!");
// 		wrefresh(win);
// 	}
// 	if (c == KEY_UP)
// 	{
// 		mvwprintw(win, 1, 1, "you pressed UP!");
// 		wrefresh(win);
// 	}

// 	getch();

// 	endwin();	
// 	return (1);
// }

//Менюшка внутри (пока что не надо урок 7 если что)

// int main(int argc, char **argv)
// {

// 	int max_y; 
// 	int max_x;
// 	initscr();


// 	getmaxyx(stdscr, max_y, max_x);

// 	WINDOW *win = newwin(max_y - 3, max_x - 2, 1, 1);
// 	box(win, 0, 0);
// 	refresh();
// 	wrefresh(win);
// 	keypad(win, true); //сперва эта хуйня

// 	string choices[3] = {"Walk", "Jog", "Run"};
// 	int choice;
// 	int highlight = 0;

// 	while (1)
// 	{
// 		for (int i = 0; i < 3; i++)
// 		{
// 			if (i == highlight)
// 				wattron(menuwin, A_REVERSE);
// 			mvprintw(menuwin, i+1, 1, choice[i].c_str())
// 			wattron(menuwin, A_REVERSE);
// 		}
// 	}
// 	choice = wgetch(menuwin);

// 	getch();

// 	endwin();	
// 	return (1);
// }


//
// while ((c = getch()) != 'x')
// 	printw("%d\n", c);

// по дефолту -1 а так то что ввелем пока не х





















//http://alexber220.narod.ru/ncurses/


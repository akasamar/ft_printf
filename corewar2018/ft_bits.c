#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *ft_from16to2(int num)
{
	char *str;
	int div;
	int i;

	div = 128;
	i = -1;
	str = (char *)malloc(sizeof(char) * 9);
	while ((++i || 1) && div != 0)
	{
		if (div <= num && ((str[i] = '1') || 1))
			num = num % div;
		else
			str[i] = '0';
		div = div / 2;
	}
	str[i] = '\n';
	return (str);
}

void	ft_live(){}  
void	ft_ld(){}
void	ft_st(){}  
void	ft_add(){}   
void	ft_sub(){}    
void	ft_and(){}   
void	ft_or(){}     
void	ft_xor(){} 
void	ft_zjmp(){}    
void	ft_ldi(){}  
void	ft_sti(){}   
void	ft_fork(){}  
void	ft_lld(){}   
void	ft_lldi(){} 
void	ft_lfork(){}   
void	ft_aff(){} 

void	ft_operations2(int num)
{
	switch(num)   
	{  
	    case 9:  
	        ft_zjmp();   
	    case 10:  
	        ft_ldi();  
	    case 11:  
	        ft_sti();   
	    case 12:  
	        ft_fork();  
	    case 13:  
	        ft_lld();   
	    case 14:  
	        ft_lldi(); 
	    case 15:  
	        ft_lfork();  
	    case 16:  
	        ft_aff(); 
	    default :  
	        printf("Not found correct operation. Make next step,");
	}  
}

void	ft_operations(int num)
{
	switch(num)   
	{  
	    case 1:  
	        ft_live(); 
	    case 2:  
	        ft_ld();
	    case 3:  
	        ft_st();  
	    case 4:  
	        ft_add();   
	    case 5:  
	        ft_sub();   
	    case 6:  
	        ft_and(); 
	    case 7:  
	        ft_or();   
	    case 8:  
	        ft_xor(); 
	    default :  
	        ft_operations2(num);
	}  
}

int main(void)
{
	printf("%s", ft_from16to2(66));
	return (1);
}


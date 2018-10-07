#include <iostream>
#include <string>
#include "phonebook.hpp"

void    fillAbonent(Abonent *p)
{
    std::cout << "Input first name:";
    std::getline(std::cin, p->first_name);
    std::cout << "Input last name:";
    std::getline(std::cin, p->last_name);
    std::cout << "Input nickname:";
    std::getline(std::cin, p->nickname);
    std::cout << "Input login:";
    std::getline(std::cin, p->login);
    std::cout << "Input post adress:";
    std::getline(std::cin, p->post_adress);
    std::cout << "Input email adress:";
    std::getline(std::cin, p->email_adress);
    std::cout << "Input phone number:";
    std::getline(std::cin, p->phone_number);
    std::cout << "Input birth date:";
    std::getline(std::cin, p->birth_date);
    std::cout << "Input favorite meal:";
    std::getline(std::cin, p->favorite_meal);
    std::cout << "Input underwear color:";
    std::getline(std::cin, p->underwear_color);
    std::cout << "Input darkest secret:";
    std::getline(std::cin, p->darkest_secret);
}

void    inputText2(int id, int i, Abonent *ab)
{
    int diff;
    int z;

    diff = 10;
    z = -1;
    if (i == 2)
    {
        if (ab[id].last_name.length() <= 10)
        {
            diff -= ab[id].last_name.length();
            while (diff--)
                std::cout << " ";
            std::cout << ab[id].last_name;
        }
        else
        {
            while (++z <= 8)
                std::cout << ab[id].last_name[z];
            std::cout << ".";
        }
    }
    else if (i == 3)
    {
        if (ab[id].nickname.length() <= 10)
        {
            diff -= ab[id].nickname.length();
            while (diff--)
                std::cout << " ";
            std::cout << ab[id].nickname;
        }
        else
        {
            while (++z <= 8)
                std::cout << ab[id].nickname[z];
            std::cout << ".";
        }
    }
}

void    inputText(int id ,int i, Abonent *ab)
{
    int diff;
    int z;

    diff = 10;
    z = -1;
    if (i == 0)
    {
        std::cout << "         " << id;
    }
    else if (i == 1)
    {
        if (ab[id].first_name.length() <= 10)
        {
            diff -= ab[id].first_name.length();
            while (diff--)
                std::cout << " ";
            std::cout << ab[id].first_name;
        }
        else
        {
            while (++z <= 8)
                std::cout << ab[id].first_name[z];
            std::cout << ".";
        }
    }
    else
        inputText2(id, i, ab);
}

void    findByIndex(int len, Abonent *ab)
{
    std::string str;
    int index;
    std::cout << "Input index of person from 0 to " << len << ":";
    std::cin >> str;
    index = str[0] - 48;
    if (str.length() == 1 && index >= 0 && index <= len)
    {
        std::cout << "The information about person by index #" << index << ":\n" << std::endl;
        std::cout << "First name: " << ab[index].first_name << std::endl;
        std::cout << "Last name: " << ab[index].last_name << std::endl;
        std::cout << "Nickname: " << ab[index].nickname << std::endl;
        std::cout << "Login: " << ab[index].login << std::endl;
        std::cout << "Postal adress: " << ab[index].post_adress << std::endl;
        std::cout << "Email adress: " << ab[index].email_adress << std::endl;
        std::cout << "Phone number: " << ab[index].phone_number << std::endl;
        std::cout << "Birthday date: " << ab[index].birth_date << std::endl;
        std::cout << "Favorite meal: " << ab[index].favorite_meal << std::endl;
        std::cout << "Underwear color: " << ab[index].underwear_color << std::endl;
        std::cout << "Darkest Secret: " << ab[index].darkest_secret << std::endl;
    }
    else
        std::cout << "Invalid index of person." << std::endl;

}

void    searchAbonent(int len, Abonent *ab) {
    int i;
    int k;

    i = -1;
    k = -1;
    if (len < 0) {
        std::cout << "The book is empty." << std::endl;
        return ;
    }
    else
    {
        std::cout << "|     index|first name| last name|  nickname|" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        while (++k <= len)
        {
            i = -1;
            std::cout << "|";
            while (++i < 4)
            {
                inputText(k, i, ab);
                std::cout << "|";
             }
             std::cout << std::endl;
        }
    }
    findByIndex(len, ab);
}
int main(void)
{
    Abonent ab[8];
    std::string str;
    int i;

    i = -1;
    std::cout << "Phonebook was loaded! Use allow command as ADD, SEARCH or EXIT:";
    while (1)
    {
        std::getline(std::cin, str);
        if ("ADD" == str) {
            if (i < 7)
                fillAbonent(&ab[++i]);
            else
                std::cout << "The phonebook is full." << std::endl;
            std::cout << "Use allow command as ADD, SEARCH or EXIT:";
        }
        else if ("SEARCH" == str) {
            searchAbonent(i, ab);
            std::cout << "Use allow command as ADD, SEARCH or EXIT:";
        }
        else if ("EXIT" == str || std::cin.eof() != 0)
            break ;
        else if (str.length() > 0)
            std::cout << "Use allow command as ADD, SEARCH or EXIT:";
    }
    return (0);
}
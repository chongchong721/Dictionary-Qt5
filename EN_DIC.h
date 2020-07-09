#ifndef EN_DIC_H
#define EN_DIC_H
#pragma once
#include "CHN_DIC.h"
#include "MEANING.h"


class EN_Dic_node
{
public:
	EN_to_CHN_Meaning *node_content;
	EN_Dic_node *child[30];

	EN_Dic_node()
	{
		this->node_content =nullptr;
		for (int i = 0; i < 30; i++)
		{
			child[i] = nullptr;
		}
	}

	EN_Dic_node(string str)
	{
		node_content = new EN_to_CHN_Meaning(str);
		for (int i = 0; i < 30; i++)
		{
			child[i] = nullptr;
		}
	}

	void add_meaning_no_existing_meaning(string str)
	{
		if (node_content == nullptr)
		{
			node_content = new EN_to_CHN_Meaning(str);
		}
	}

	
	
};

class EN_Dic
{
public:

	friend class CHN_Dic;

	EN_Dic_node *root;

	EN_Dic()
	{
		root = new EN_Dic_node;
	}

    string * split_str(string str)
    {
        string  *sub_string;
        sub_string = new string[2];
        int length = str.length();
        int En_length = 0;
        bool flag = false;
        for (int i = 0; !flag; i++, En_length++)
        {
            char tmp = str[i];
            if (tmp == ' '&&str[i+1]==' ')
                flag = true;
        }

        En_length = En_length - 1;

        sub_string[0] = str.substr(0, En_length);
        sub_string[1] = str.substr(En_length + 3, length-En_length-3);
        return sub_string;
    }

	EN_Dic_node * search(string En_word)
	{
		EN_Dic_node *tmp = root;
		if (tmp == nullptr)
		{
			cout << "no result found" << endl;
			return nullptr;
		}
		int length = En_word.length();
		bool flag = true;
		for (int i = 0; i < length; i++)
		{
			switch (En_word[i])
			{
			case 'a':
			case 'A':
				tmp = tmp->child['a' - 97];
				break;
			case 'b':
			case 'B':
				tmp = tmp->child['b' - 97];
				break;
			case 'c':
			case 'C':
				tmp = tmp->child['c' - 97];
				break;
			case 'd':
			case 'D':
				tmp = tmp->child['d' - 97];
				break;
			case 'e':
			case 'E':
				tmp = tmp->child['e' - 97];
				break;
			case 'f':
			case 'F':
				tmp = tmp->child['f' - 97];
				break;
			case 'g':
			case 'G':
				tmp = tmp->child['g' - 97];
				break;
			case 'h':
			case 'H':
				tmp = tmp->child['h' - 97];
				break;
			case 'i':
			case 'I':
				tmp = tmp->child['i' - 97];
				break;
			case 'j':
			case 'J':
				tmp = tmp->child['j' - 97];
				break;
			case 'k':
			case 'K':
				tmp = tmp->child['k' - 97];
				break;
			case 'l':
			case 'L':
				tmp = tmp->child['l' - 97];
				break;
			case 'm':
			case 'M':
				tmp = tmp->child['m' - 97];
				break;
			case 'n':
			case 'N':
				tmp = tmp->child['n' - 97];
				break;
			case 'o':
			case 'O':
				tmp = tmp->child['o' - 97];
				break;
			case 'p':
			case 'P':
				tmp = tmp->child['p' - 97];
				break;
			case 'q':
			case 'Q':
				tmp = tmp->child['q' - 97];
				break;
			case 'r':
			case 'R':
				tmp = tmp->child['r' - 97];
				break;
			case 's':
			case 'S':
				tmp = tmp->child['s' - 97];
				break;
			case 't':
			case 'T':
				tmp = tmp->child['t' - 97];
				break;
			case 'u':
			case 'U':
				tmp = tmp->child['u' - 97];
				break;
			case 'v':
			case 'V':
				tmp = tmp->child['v' - 97];
				break;
			case 'w':
			case 'W':
				tmp = tmp->child['w' - 97];
				break;
			case 'x':
			case 'X':
				tmp = tmp->child['x' - 97];
				break;
			case 'y':
			case 'Y':
				tmp = tmp->child['y' - 97];
				break;
			case 'z':
			case 'Z':
				tmp = tmp->child['z' - 97];
				break;
			case '-':
				tmp = tmp->child[26];
				break;
			case '.':
				tmp = tmp->child[27];
				break;
			case 39:
				tmp = tmp->child[28];
				break;
			case ' ':
				tmp = tmp->child[29];
				break;
			}
			if (tmp == nullptr)
			{
				flag = false;
				break;
			}
			else if (i==length-1 && tmp->node_content == nullptr)
			{
				flag = false;
				break;
			}
			else
			{
				continue;
			}
		}
		if (flag)
		{
			return tmp;
		}
		else
		{
			cout << "no result found" << endl;
			return nullptr;
		}
	}

	EN_Dic_node * search_no_output(string En_word)
	{
		EN_Dic_node *tmp = root;
		if (tmp == nullptr)
		{
			return nullptr;
		}
		int length = En_word.length();
		bool flag = true;
		for (int i = 0; i < length; i++)
		{
			switch (En_word[i])
			{
			case 'a':
			case 'A':
				tmp = tmp->child['a' - 97];
				break;
			case 'b':
			case 'B':
				tmp = tmp->child['b' - 97];
				break;
			case 'c':
			case 'C':
				tmp = tmp->child['c' - 97];
				break;
			case 'd':
			case 'D':
				tmp = tmp->child['d' - 97];
				break;
			case 'e':
			case 'E':
				tmp = tmp->child['e' - 97];
				break;
			case 'f':
			case 'F':
				tmp = tmp->child['f' - 97];
				break;
			case 'g':
			case 'G':
				tmp = tmp->child['g' - 97];
				break;
			case 'h':
			case 'H':
				tmp = tmp->child['h' - 97];
				break;
			case 'i':
			case 'I':
				tmp = tmp->child['i' - 97];
				break;
			case 'j':
			case 'J':
				tmp = tmp->child['j' - 97];
				break;
			case 'k':
			case 'K':
				tmp = tmp->child['k' - 97];
				break;
			case 'l':
			case 'L':
				tmp = tmp->child['l' - 97];
				break;
			case 'm':
			case 'M':
				tmp = tmp->child['m' - 97];
				break;
			case 'n':
			case 'N':
				tmp = tmp->child['n' - 97];
				break;
			case 'o':
			case 'O':
				tmp = tmp->child['o' - 97];
				break;
			case 'p':
			case 'P':
				tmp = tmp->child['p' - 97];
				break;
			case 'q':
			case 'Q':
				tmp = tmp->child['q' - 97];
				break;
			case 'r':
			case 'R':
				tmp = tmp->child['r' - 97];
				break;
			case 's':
			case 'S':
				tmp = tmp->child['s' - 97];
				break;
			case 't':
			case 'T':
				tmp = tmp->child['t' - 97];
				break;
			case 'u':
			case 'U':
				tmp = tmp->child['u' - 97];
				break;
			case 'v':
			case 'V':
				tmp = tmp->child['v' - 97];
				break;
			case 'w':
			case 'W':
				tmp = tmp->child['w' - 97];
				break;
			case 'x':
			case 'X':
				tmp = tmp->child['x' - 97];
				break;
			case 'y':
			case 'Y':
				tmp = tmp->child['y' - 97];
				break;
			case 'z':
			case 'Z':
				tmp = tmp->child['z' - 97];
				break;
			case '-':
				tmp = tmp->child[26];
				break;
			case '.':
				tmp = tmp->child[27];
				break;
			case 39:
				tmp = tmp->child[28];
				break;
			case ' ':
				tmp = tmp->child[29];
				break;
			}
			if (tmp== nullptr)
			{
				flag = false;
				break;
			}
			else if (i==length-1 && tmp->node_content == nullptr)
			{
				flag = false;
				break;
			}
			else
			{
				continue;
			}
				
		}
		if (flag)
		{
			return tmp;
		}
		else
		{
			return nullptr;
		}
	}

	EN_Dic_node * insert(string str)
	{
		string *sub_string = split_str(str);
		string En_word = sub_string[0];
		EN_Dic_node *Found =search_no_output(En_word);
		EN_Dic_node *tmp = root;
		if (Found != nullptr)
		{
			cout << "already exist" << endl;
			return nullptr;
		}
		else
		{
			
			int length = En_word.length();
			for (int i = 0; i < length; i++)
			{
				switch (En_word[i])
				{
				case 'a':
				case 'A':
					if (tmp->child['a' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['a' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['a' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['a' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['a' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['a' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['a' - 97];
					break;
				case 'b':
				case 'B':
					if (tmp->child['b' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['b' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['b' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['b' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['b' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['b' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['b' - 97];
					break;
				case 'c':
				case 'C':
					if (tmp->child['c' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['c' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['c' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['c' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['c' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['c' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['c' - 97];
					break;
				case 'd':
				case 'D':
					if (tmp->child['d' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['d' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['d' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['d' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['d' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['d' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['d' - 97];
					break;
				case 'e':
				case 'E':
					if (tmp->child['e' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['e' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['e' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['e' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['e' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['e' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['e' - 97];
					break;
				case 'f':
				case 'F':
					if (tmp->child['f' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['f' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['f' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['f' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['f' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['f' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['f' - 97];
					break;
				case 'g':
				case 'G':
					if (tmp->child['g' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['g' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['g' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['g' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['g' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['g' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['g' - 97];
					break;
				case 'h':
				case 'H':
					if (tmp->child['h' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['h' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['h' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['h' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['h' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['h' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['h' - 97];
					break;
				case 'i':
				case 'I':
					if (tmp->child['i' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['i' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['i' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['i' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['i' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['i' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['i' - 97];
					break;
				case 'j':
				case 'J':
					if (tmp->child['j' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['j' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['j' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['j' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['j' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['j' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['j' - 97];
					break;
				case 'k':
				case 'K':
					if (tmp->child['k' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['k' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['k' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['k' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['k' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['k' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['k' - 97];
					break;
				case 'l':
				case 'L':
					if (tmp->child['l' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['l' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['l' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['l' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['l' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['l' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['l' - 97];
					break;
				case 'm':
				case 'M':
					if (tmp->child['m' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['m' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['m' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['m' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['m' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['m' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['m' - 97];
					break;
				case 'n':
				case 'N':
					if (tmp->child['n' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['n' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['n' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['n' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['n' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['n' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['n' - 97];
					break;
				case 'o':
				case 'O':
					if (tmp->child['o' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['o' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['o' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['o' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['o' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['o' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['o' - 97];
					break;
				case 'p':
				case 'P':
					if (tmp->child['p' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['p' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['p' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['p' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['p' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['p' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['p' - 97];
					break;
				case 'q':
				case 'Q':
					if (tmp->child['q' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['q' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['q' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['q' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['q' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['q' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['q' - 97];
					break;
				case 'r':
				case 'R':
					if (tmp->child['r' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['r' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['r' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['r' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['r' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['r' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['r' - 97];
					break;
				case 's':
				case 'S':
					if (tmp->child['s' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['s' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['s' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['s' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['s' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['s' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['s' - 97];
					break;
				case 't':
				case 'T':
					if (tmp->child['t' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['t' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['t' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['t' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['t' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['t' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['t' - 97];
					break;
				case 'u':
				case 'U':
					if (tmp->child['u' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['u' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['u' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['u' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['u' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['u' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['u' - 97];
					break;
				case 'v':
				case 'V':
					if (tmp->child['v' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['v' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['v' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['v' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['v' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['v' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['v' - 97];
					break;
				case 'w':
				case 'W':
					if (tmp->child['w' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['w' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['w' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['w' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['w' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['w' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['w' - 97];
					break;
				case 'x':
				case 'X':
					if (tmp->child['x' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['x' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['x' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['x' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['x' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['x' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['x' - 97];
					break;
				case 'y':
				case 'Y':
					if (tmp->child['y' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['y' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['y' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['y' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['y' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['y' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['y' - 97];
					break;
				case 'z':
				case 'Z':
					if (tmp->child['z' - 97] == nullptr&&i != length - 1)
					{
						tmp->child['z' - 97] = new EN_Dic_node;
					}
					else if (tmp->child['z' - 97] == nullptr&&i == length - 1)
					{
						tmp->child['z' - 97] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child['z' - 97] != nullptr&&i == length - 1)
					{
						tmp->child['z' - 97]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child['z' - 97];
					break;
				case '-':
					if (tmp->child[26] == nullptr&&i != length - 1)
					{
						tmp->child[26] = new EN_Dic_node;
					}
					else if (tmp->child[26] == nullptr&&i == length - 1)
					{
						tmp->child[26] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child[26] != nullptr&&i == length - 1)
					{
						tmp->child[26]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child[26];
					break;
				case '.':
					if (tmp->child[27] == nullptr&&i != length - 1)
					{
						tmp->child[27] = new EN_Dic_node;
					}
					else if (tmp->child[27] == nullptr&&i == length - 1)
					{
						tmp->child[27] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child[27] != nullptr&&i == length - 1)
					{
						tmp->child[27]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child[27];
					break;
				case 39:
					if (tmp->child[28] == nullptr&&i != length - 1)
					{
						tmp->child[28] = new EN_Dic_node;
					}
					else if (tmp->child[28] == nullptr&&i == length - 1)
					{
						tmp->child[28] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child[28] != nullptr&&i == length - 1)
					{
						tmp->child[28]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child[28];
					break;
				case ' ':
					if (tmp->child[29] == nullptr&&i != length - 1)
					{
						tmp->child[29] = new EN_Dic_node;
					}
					else if (tmp->child[29] == nullptr&&i == length - 1)
					{
						tmp->child[29] = new EN_Dic_node(sub_string[1]);
					}
					else if (tmp->child[29] != nullptr&&i == length - 1)
					{
						tmp->child[29]->add_meaning_no_existing_meaning(sub_string[1]);
					}
					tmp = tmp->child[29];
					break;
				}
			}
		}
		
		return tmp;
	}

	void go_next_node(EN_Dic_node *&tmp, char chr)
	{
        /**********异常处理*************/
        if(tmp==nullptr)
        {
            throw -1;
        }
        /**********异常处理*************/

            if (chr >= 'a'&&chr <= 'z')
            {
                tmp = tmp->child[chr - 'a'];
            }
            else if (chr = '-')
            {
                tmp = tmp->child[26];
            }
            else if (chr = '.')
            {
                tmp = tmp->child[27];
            }
            else if (chr = 39)
            {
                tmp = tmp->child[28];
            }
            else if (chr = ' ')
            {
                tmp = tmp->child[29];
            }


	}

	void print_word_meaning(EN_Dic_node *tmp)
	{
            vector<Meaning *>::iterator it;
            for (it=tmp->node_content->meanings->begin();it!=tmp->node_content->meanings->end();it++)
            {
                cout << (*it)->meaning << endl;
            }
	}

	void print_word_single_meaning(EN_Dic_node *tmp)
	{
		vector<Meaning *>::iterator it;
		it = tmp->node_content->meanings->begin();
		cout << (*it)->meaning;
	}

    void get_result_string(EN_Dic_node *tmp,string * & result)
    {
        vector<Meaning *>::iterator it=tmp->node_content->meanings->begin();
        result->append((*it)->meaning);
    }

    void get_result_string(string str,string * & result)
    {
        result->append(str);
    }

    string* print_meaning(string str,vector<EN_Dic_node *> *& Find_CHN_Alternative)
	{
        string * result=new string;
		EN_Dic_node *tmp = root;
		for (int i = 0; i < str.length(); i++)
		{
			if (i < str.length() - 1)
			{
				if (str[i] != '.')
				{
					if (str[i] != ' ')
					{
						go_next_node(tmp, str[i]);
					}
					else
					{
						if (tmp->child[29] == nullptr)
						{
                            /**********异常处理*************/
                            if(tmp->node_content==nullptr)
                            {
                                throw -1;
                            }
                            /**********异常处理*************/
							print_word_single_meaning(tmp);
                            get_result_string(tmp,result);
                            Find_CHN_Alternative->push_back(tmp);
							if (str[i - 1] == '.')
							{
								string dot = "。";
                                get_result_string(dot,result);
								cout << dot;

							}
							else if (str[i - 1] == ',')
							{
								string dot = "，";
                                get_result_string(dot,result);
								cout << dot;
							}
							tmp = root;
							continue;
						}
						else
						{
							tmp = tmp->child[29];
							continue;
						}
					}
				}
				else
				{
					if (str[i + 1] == ' ')
					{
						if (str[i - 2] == '.')
						{

							go_next_node(tmp, str[i]);
						}
						else
						{
							continue;
						}
					}
					else
					{
						go_next_node(tmp, str[i]);
					}
				}
				
			}
			else 
			{
				if (str[i] == '.')
				{
                    /**********异常处理*************/
                    if(tmp->node_content==nullptr)
                    {
                        throw -1;
                    }
                    /**********异常处理*************/
					print_word_single_meaning(tmp);
                    get_result_string(tmp,result);
                    Find_CHN_Alternative->push_back(tmp);
					string dot = "。";
                    get_result_string(dot,result);
					cout << dot;
				}
				else
                {
                    go_next_node(tmp, str[i]);
                    /**********异常处理*************/
                    if(tmp->node_content==nullptr)
                    {
                        throw -1;
                    }
                    /**********异常处理*************/

					print_word_single_meaning(tmp);
                    get_result_string(tmp,result);
                    Find_CHN_Alternative->push_back(tmp);
				}
				
				//tmp = root;
			}
		}
        return result;
	}
};


#endif

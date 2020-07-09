#ifndef CHN_DIC_H
#define CHN_DIC_H
#pragma once
#include "MEANING.h"
#include "EN_DIC.h"
class CHN_Dic_node
{
public:

	CHN_to_EN_meaning *node_content;
	CHN_Dic_node *child[131];

	CHN_Dic_node()
	{
		node_content = nullptr;
		for (int i = 0; i < 131; i++)
		{
			child[i] = nullptr;
		}
	}

	CHN_Dic_node(Meaning *show_word_kind,string En_meaning)
	{
		node_content = new CHN_to_EN_meaning(show_word_kind,En_meaning);
		for (int i = 0; i < 131; i++)
		{
			child[i] = nullptr;
		}
	}

	void add_meaning(Meaning *show_word_kind, string En_meaning)
	{
		if (node_content == nullptr)
		{
			node_content = new CHN_to_EN_meaning(show_word_kind, En_meaning);
		}
		else
		{
			Meaning *tmp = new Meaning(show_word_kind->word_kind, En_meaning);
			this->node_content->meanings->push_back(tmp);
		}
		
	}
};



class CHN_Dic
{
public:
	CHN_Dic_node *root;

	CHN_Dic()
	{
		root = new CHN_Dic_node;
	}

	CHN_Dic_node * search_no_output(string Chn_word)
	{
		CHN_Dic_node *tmp = root;
		if (tmp == nullptr)
		{
			return nullptr;
		}
		int length = Chn_word.length();
		bool flag = true;
		for (int i = 0; i < length; i++)
		{
			if (Chn_word[i] < 0)
			{
				tmp = tmp->child[Chn_word[i] + 128];
			}
			else if (Chn_word[i] == '(')
			{
				tmp = tmp->child[128];
			}
			else if (Chn_word[i] == ')')
			{
				tmp = tmp->child[129];
			}
			else if (Chn_word[i] == '.')
			{
				tmp = tmp->child[130];
			}

			if (tmp == nullptr)
			{
				flag = false;
				break;
			}
			else if (i == length - 1 && tmp->node_content == nullptr)
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

	void insert(string En_word, Meaning * meaning)  //这里的meaning是英翻中的一个meaning，用来构造中翻英
	{
		CHN_Dic_node *tmp = root;
		string Chn_word = meaning->meaning;
		int length = Chn_word.length();
		for (int i = 0; i < length; i++)
		{
			if (Chn_word[i] < 0)
			{
				if (tmp->child[Chn_word[i] + 128] == nullptr && i != length - 1)
				{
					tmp->child[Chn_word[i] + 128] = new CHN_Dic_node;
				}
				else if (tmp->child[Chn_word[i] + 128] == nullptr && i == length - 1)
				{
					tmp->child[Chn_word[i] + 128] = new CHN_Dic_node(meaning, En_word);
				}
				else if (tmp->child[Chn_word[i] + 128] != nullptr && i == length - 1)
				{
					tmp->child[Chn_word[i] + 128]->add_meaning(meaning, En_word);
				}
				tmp = tmp->child[Chn_word[i] + 128];
			}
			else if (Chn_word[i] == '(')
			{
				if (tmp->child[128] == nullptr && i != length - 1)
				{
					tmp->child[128] = new CHN_Dic_node;
				}
				else if (tmp->child[128] == nullptr && i == length - 1)
				{
					tmp->child[128] = new CHN_Dic_node(meaning, En_word);
				}
				else if (tmp->child[128] != nullptr && i == length - 1)
				{
					tmp->child[128]->add_meaning(meaning, En_word);
				}
				tmp = tmp->child[128];
			}
			else if (Chn_word[i] == ')')
			{
				if (tmp->child[129] == nullptr && i != length - 1)
				{
					tmp->child[129] = new CHN_Dic_node;
				}
				else if (tmp->child[129] == nullptr && i == length - 1)
				{
					tmp->child[129] = new CHN_Dic_node(meaning, En_word);
				}
				else if (tmp->child[129] != nullptr && i == length - 1)
				{
					tmp->child[129]->add_meaning(meaning, En_word);
				}
				tmp = tmp->child[129];
			}
			else if (Chn_word[i] == '.')
			{
				if (tmp->child[130] == nullptr && i != length - 1)
				{
					tmp->child[130] = new CHN_Dic_node;
				}
				else if (tmp->child[130] == nullptr && i == length - 1)
				{
					tmp->child[130] = new CHN_Dic_node(meaning, En_word);
				}
				else if (tmp->child[130] != nullptr && i == length - 1)
				{
					tmp->child[130]->add_meaning(meaning, En_word);
				}
				tmp = tmp->child[130];
			}
		}
	}


	bool go_next_node(char tmp,CHN_Dic_node *& node)
	{
		if (tmp < 0)
		{
			node = node->child[tmp + 128];
		}
		else if (tmp == '(')
		{
			node = node->child[128];
		}
		else if (tmp == ')')
		{
			node = node->child[129];
		}
		else if (tmp == '.')
		{
			node = node->child[130];
		}


		if (node == nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void print_single_word(CHN_Dic_node * tmp)
	{
		vector<Meaning *>::iterator it;
		it = tmp->node_content->meanings->begin();
		cout << (*it)->meaning << " ";
	}

	void print_single_word_with_dot(CHN_Dic_node * tmp)
	{
		vector<Meaning *>::iterator it;
		it = tmp->node_content->meanings->begin();
		cout << (*it)->meaning << ". ";
	}

    void get_result_string(CHN_Dic_node *tmp,string * & result)
    {
        vector<Meaning *>::iterator it=tmp->node_content->meanings->begin();
        result->append((*it)->meaning);
        result->append(" ");
    }

    void get_result_string_with_dot(CHN_Dic_node *tmp,string * & result)
    {
        vector<Meaning *>::iterator it=tmp->node_content->meanings->begin();
        result->append((*it)->meaning);
        result->append((". "));
    }

    string * print_meaning(string str,vector<CHN_Dic_node *> *& Find_EN_Alternative)
	{
        string *result=new string;
		CHN_Dic_node *tmp = root;
		vector<CHN_Dic_node *> trans_list;
		for (int i = 0; i < str.length(); i++)
		{
			if (i != str.length()-1)
			{
				if (go_next_node(str[i], tmp))
				{
					trans_list.push_back(tmp);
				}
				else
				{
					vector<CHN_Dic_node *>::iterator it;
					int j = 0;
					for (it = trans_list.end() - 1; it != trans_list.begin(); it--, j++)
					{
                        //if ((*it)->node_content->meanings != nullptr)
                        if((*it)->node_content!=nullptr)
						{
								break;
						}
					}
					i = i - j - 1;
					if ((str[i + 1] == -29 && str[i + 2] == -128 && str[i + 3] == -126) || (str[i + 1] == -17 && str[i + 2] == -68 && str[i + 3] == -116))
					{
						i = i + 3;
                        /**********异常处理*************/
                        if((*it)->node_content==nullptr)
                        {
                            throw -1;
                        }
                        /**********异常处理*************/
						print_single_word_with_dot(*it);
                        get_result_string_with_dot(*it,result);
                        Find_EN_Alternative->push_back(*it);
                        trans_list.clear();   //清空vector 还未调试
						tmp = root;
						continue;
					}
                    /**********异常处理*************/
                    if((*it)->node_content==nullptr)
                    {
                        throw -1;
                    }
                    /**********异常处理*************/
					print_single_word(*it);
                    get_result_string(*it,result);
                    Find_EN_Alternative->push_back(*it);
                    trans_list.clear();   //清空vector 还未调试
					tmp = root;
					continue;
				}
			}
			else
			{
				go_next_node(str[i], tmp);
                /**********异常处理*************/
                if(tmp->node_content==nullptr)
                {
                    throw -1;
                }
                /**********异常处理*************/
				print_single_word(tmp);
                get_result_string(tmp,result);
                Find_EN_Alternative->push_back(tmp);
			}
			
		}
		
        return result;
	}

};

#endif

#ifndef MEANING_H
#define MEANING_H
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


enum word_class
{
	noun,
	verb,
	prep,
	intj,
	adj,
	adv,
	conj,
	pron,
	abbr,
	art,
	num
};


class Meaning
{
public:
	word_class word_kind;
	string meaning;

	Meaning(string word_kind, string meaning)
	{
		get_word_kind(word_kind);
		get_meaning(meaning);
	}

	Meaning(word_class tmp, string meaning)
	{
		this->word_kind = tmp;
		get_meaning(meaning);
	}
	void get_word_kind(string str)
	{
		if (str == "v.")
		{
			word_kind = verb;
		}
		else if (str == "n.")
		{
			word_kind = noun;
		}
		else if (str == "adj.")
		{
			word_kind = adj;
		}
		else if (str == "adv.")
		{
			word_kind = adv;
		}
		else if (str == "prep.")
		{
			word_kind = prep;
		}
		else if (str == "conj.")
		{
			word_kind = conj;
		}
		else if (str == "int.")
		{
			word_kind = intj;
		}
		else if (str == "abbr.")
		{
			word_kind = abbr;
		}
		else if (str == "art.")
		{
			word_kind = art;
		}
		else if (str == "num.")
		{
			word_kind = num;
		}
        else if(str=="pron.")
        {
            word_kind= pron;
        }
	}

	void get_meaning(string str)
	{
		meaning.assign(str);
	}
};

class EN_to_CHN_Meaning
{
	int num;

public:

	vector<Meaning *> * meanings;



	EN_to_CHN_Meaning()
	{
		meanings = nullptr;
	}

	EN_to_CHN_Meaning(string str)
	{
		meanings = new vector<Meaning*>;
		int length = str.length();
		int k = 1;
		int interval[3];
		interval[0] = -1;
		int *word_start;
		int *word_end;
		int *meaning_start;
		int *meaning_end;
		for (int i = 0; i < length; i++)
		{
			char tmp = str[i];
			if (tmp == ' ')
			{
				interval[k] = i;
				k++;
			}
		}
		this->num = k;
//		this->chn_meaning = new Meaning[num];
		word_start = new int[num];
		word_end = new int[num];
		meaning_start = new int[num];
		meaning_end = new int[num];
		word_start[0] = 0;
		for (int i = 0; i < num; i++)
		{
			int tmp = interval[i] + 1;
			word_start[i] = tmp;
			int j = tmp;
			while (str[j] != '.')
			{
				j++;
			}
			word_end[i] = j;
			meaning_start[i] = j + 1;
			if (i < num-1)
			{
				meaning_end[i] = interval[i + 1] - 1;
			}
			else
			{
				meaning_end[i] = length;
			}

		}
		for (int i = 0; i < k; i++)
		{
			string tmp_meaning = str.substr(meaning_start[i], meaning_end[i]-meaning_start[i]+1);
			string tmp_word = str.substr(word_start[i], word_end[i]-word_start[i]+1);

			queue<string> *single_meaning = new queue<string>;
			single_meaning = get_single_meaning(tmp_meaning);

			while(!single_meaning->empty())
			{
				string single_meaning_str = single_meaning->front();
				Meaning *tmp = new Meaning(tmp_word, single_meaning_str);
				meanings->push_back(tmp);
				single_meaning->pop();
			}
			
		}
	}

	queue<string> * get_single_meaning(string str)
	{
		queue<string> *tmp = new queue<string>;
		int length = str.length();
		int k = 1;
		int pos[10];
		memset(pos, -1, sizeof(pos));
		int *single_meaning_begin;
		int *single_meaning_end;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ',')
			{
				pos[k] = i;
				k++;
			}
		}
		single_meaning_begin = new int[k];
		single_meaning_end = new int[k];
		
		for (int i = 0; i < k; i++)
		{
			single_meaning_begin[i] = pos[i] + 1;
			single_meaning_end[i] = pos[i + 1] - 1;
		}
		single_meaning_begin[0] = 0;
		single_meaning_end[k - 1] = length - 1;
		for (int i = 0; i < k; i++)
		{
			string single_meaning = str.substr(single_meaning_begin[i], single_meaning_end[i] - single_meaning_begin[i] + 1);
			tmp->push(single_meaning);
		}
		return tmp;
	}
};


class CHN_to_EN_meaning
{

public:

	vector<Meaning *> *meanings;
	


	CHN_to_EN_meaning()
	{
		meanings = nullptr;
	}

	CHN_to_EN_meaning(Meaning * show_word_kind, string En_meaning)
	{
		meanings = new vector<Meaning *>;
		Meaning * tmp = new Meaning(show_word_kind->word_kind, En_meaning);
		meanings->push_back(tmp);
	}

	
	//构造函数
};

#endif

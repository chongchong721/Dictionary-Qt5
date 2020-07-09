#ifndef DIC_H
#define DIC_H
#pragma once

#include "CHN_DIC.h"
#include <algorithm>
class DIC
{
public:
	EN_Dic *en_dic;
	CHN_Dic *chn_dic;


	DIC(string path)
	{
		en_dic = new EN_Dic;
		chn_dic = new CHN_Dic;
		initialize(path);
	}

    DIC()
    {
        en_dic = new EN_Dic;
        chn_dic = new CHN_Dic;
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

	void initialize(string path)
	{
		string str;
		freopen(path.c_str(), "r", stdin);
		while (getline(cin, str))
		{
			insert(str);
		}
		/*for (int i = 0; i < 1878; i++)
		{
			getline(cin, str);
			insert(str);
		}
		getline(cin, str);
		insert(str);*/

		cin.clear();
		freopen("CON", "r", stdin);
	}


	void insert(string str)
	{
		string *sub_string = split_str(str);
		string en_word = sub_string[0];
		EN_Dic_node * tmp = en_dic->insert(str);
		vector<Meaning *> * tmp_meanings = tmp->node_content->meanings;
		for (int i = 0; i < tmp_meanings->size(); i++)
		{
			chn_dic->insert(en_word, (*tmp_meanings)[i]);
		}
	}

    string * print_EN_to_CHN(string str,vector<EN_Dic_node *> *& Find_CHN_Alternative)
	{
		string deststr;
		deststr.resize(str.size());
		transform(str.begin(), str.end(), deststr.begin(), ::tolower);
        string * result=en_dic->print_meaning(deststr,Find_CHN_Alternative);
        return result;
	}

    string * print_CHN_to_EN(string str,vector<CHN_Dic_node *> *& Find_EN_Alternative)
	{
		
        string *result=chn_dic->print_meaning(str,Find_EN_Alternative);
        return result;
	}
};

#endif

#include "define.h"
void read_from_file(const char *filename, int array[][NUM])
{
    string str;
    ifstream fin;
    fin.open(filename);
    char ch;
    int i = 0;
    while(fin.get(ch))
    {
        if(ch != '\n')
            str.push_back(ch);
        if(fin.peek() == '\n')
        {
            write_to_array(array,str,i);
            str.clear();
            i++;
        }
    }
    fin.close();
}


void write_to_array(int array[][NUM], string str, int n)
{
    vector<string> sub_vec;
    string temp;
    temp.clear();
    int id = str.find(":");
    for(unsigned int i=id+2;i<str.size();i++)
    {
        if(str[i] != ' ')
        {
            temp.push_back(str[i]);
        }
        if(str[i] == ' '){
                sub_vec.push_back(temp.substr(1,temp.size()-1));
                temp.clear();
        }
    }
    sub_vec.push_back(temp.substr(1,temp.size()-1));
    for(int j=0;j<200;j++)
    {
        array[n][j] = atoi(sub_vec[j].c_str());
    }
}

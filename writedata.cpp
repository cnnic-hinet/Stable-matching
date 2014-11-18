#include "define.h"
void writedata(const char *filename,int *result)
{
    ofstream fout;
    fout.open(filename);
    fout<<"Matching result is :"<<endl;
    for(int i=0;i<NUM;i++)
    {
        fout <<"B"<<i<<"<-->G"<<result[i]<<endl;
    }
    fout.close();
}


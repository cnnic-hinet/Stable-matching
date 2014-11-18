#include "define.h"
int main()
{
    const char* File_boy = "boys_rankings.txt";
    const char* File_girl = "girls_rankings.txt";
    const char* File_write = "result.txt";
    //初始化
    int boyarray[NUM][NUM] = {0};
    int girlarray[NUM][NUM] = {0};
    int boyperfer[NUM] = {0}; //记录每位男生选中的女生编号
    int boystartid[NUM] = {0}; //记录每位男生选择的心目中的第几个女生，以便下次开始
    int girlnow[NUM] = {0};
    for (int i=0;i<NUM;i++)
        girlnow[i] = NIL;
    stack<int> boystack;//单身男生
    //读入数据
    read_from_file(File_boy,boyarray);
    read_from_file(File_girl,girlarray);
    for(int id = 0; id <NUM; id++) //所有男生向心目中最喜欢的女孩表白,第一轮
    {
        findgirl(boystack,id,boyarray,girlarray,boyperfer,boystartid,girlnow);
    }
    while(boystack.size()!=0) //单身的再次向排序中的下一个女孩表白
    {
        int id = boystack.top();
        boystack.pop();
        findgirl(boystack,id,boyarray,girlarray,boyperfer,boystartid,girlnow);
    }
    for(int i=0;i<NUM;i++)
    {
        cout<<"B"<<i<<"<----->G"<<boyperfer[i]<<endl;
    }

    writedata(File_write,boyperfer);
    return 0;
}



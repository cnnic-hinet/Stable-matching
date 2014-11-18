#include "define.h"


void findgirl(stack<int> &boystack, int id, int boyarray[][NUM], int girlarray[][NUM], int boyperfer[], int boystartid[], int girlnow[])
{
    int perfergirl = boyarray[id][boystartid[id]];
    if(girlnow[perfergirl] == NIL)
    {
        girlnow[perfergirl] = id;
        boyperfer[id] = perfergirl;
    }
    else
    {
        int oldboy = findboy(girlarray,perfergirl,girlnow[perfergirl]);
        int newboy = findboy(girlarray,perfergirl,id);
        if(oldboy < newboy)
        {
            boystartid[id]++;
            boystack.push(id);
        }
        else
        {
            boystartid[girlnow[perfergirl]]++;
            boystack.push(girlnow[perfergirl]);
            girlnow[perfergirl] = id;
            boyperfer[id] = perfergirl;
        }
    }
}

int findboy(int girlarray[][NUM], int girl, int boy)
{
    for(int i=0;i<NUM;i++)
    {
        if(girlarray[girl][i] == boy)
            return i;
    }
    return NIL;
}


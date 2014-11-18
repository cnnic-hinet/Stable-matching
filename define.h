#ifndef DEFINE_H
#define DEFINE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#define NUM 200
#define NIL -1
using namespace std;

void read_from_file(const char *filename,int array[][NUM]);
void write_to_array(int array[][NUM],string str, int n);
void findgirl(stack<int> &boystack,int id,int boyarray[][NUM],int girlarray[][NUM],int boyperfer[],int boystartid[],int girlnow[]);
int findboy(int girlarray[][NUM],int girl,int boy);
void writedata(const char *filename,int *result);
#endif // DEFINE_H

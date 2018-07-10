#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
class student
{
public:
    string numbers;
    string name;
    string sex;
    string birthofdate;
    string cla;
    string phoneNO;
    double average;
};
double ave(string num[]){
    int sum;
    int max=0;
    int min=101;
    int i;
    for(i=0;i<5;++i){
        sum+=atof(num[i]);
        if(max<atof(num[i])
            max=atof(num[i]);
        if(min>atof(num[i])
            min=atof(num[i]);
    }
    return (sum-max-min)/3;
}


int main()
{
    int i=0;
    int l;
    string judge[5];
    student s[100];
    ifstream fin("/Users/lichenxi/Desktop/dm/LCX/studentdata.csv");
    string line;
    vector<string>::iterator fie;
    while(getline(fin,line)){
        istringstream sin(line);
        vector<string> fields;
        string field;
        while (getline(sin,field,',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        }
            //一组数据传参
            s[i].numbers=fields[0];
            s[i].name=fields[1];
            s[i].sex=fields[2];
            s[i].birthofdate=fields[3];
            s[i].cla=fields[4];
            s[i].phoneNO=fields[5];
            for(l=0;l<5;++l)
                judge[l]=fields[6+l];
            s[i].average=ave(judge);
            ++i;
    }
    ofstream  out("/Users/lichenxi/Desktop/dm/LCX/studentdataout.csv");
    if(out.is_open()){
        out<<"numbers,name,sex,dateofbirth,class,phoneNO,average\n";
        for(l=1;l<i;++l){
        out<<s[l].numbers<<","<<s[l].name<<","<<s[l].sex<<","<<s[l].birthofdate<<","<<s[l].cla<<","<<s[l].phoneNO<<","<<s[l].average<<endl;
        }
        out.close();
    }
    return 0;
}

#include<iostream>  
#include<string>  
#include<sstream>  
using namespace std;  
  

int main()  
{  
    string str,num;  
    int exp;  
    cin >> str;  
    char sign = str[0];//符号位  
    int LocE = str.find('E');//找到E的位置  
    num = str[1];   
    num += str.substr(3,LocE - 3);//得到数字部分内容  
    exp = stoi(str.substr(LocE+1));  
  
    /////设置输出  
    if(sign == '-')  
        cout<<"-";  
    //三种可能的情况  
    if(exp<0)//前面加0  
    {  
        cout<<"0.";  
        for(int i = 0;i<-exp-1;i++)  
            cout<<'0';  
        cout<<num;  
    }  
    else if(exp>=num.length()-1)//后面加0,没小数点  
    {  
        cout<<num;  
        for(int i = 0;i<exp-num.length()+1;i++)  
            cout<<'0';  
    }  
    else //小数点在中间  
    {  
        cout<<num.substr(0,exp+1);  
        cout<<".";  
        cout<<num.substr(exp+1);  
    }  
    
    return 0;  
}  
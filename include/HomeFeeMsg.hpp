/*注意：乱码是因为vscode默认的文件编码格式是UTF-8，而Windows的终端默认编码格式是gbk，两种格式冲突导致乱码；
解决办法就是修改vscode默认设置，与Windows终端同步即可*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//成员类
class Homemember
{
    public:
        Homemember():ID("none"),amount(0.0),type("none"),method("none"),
        site("none"),detail("none"),next(nullptr){}

        void entermsgs(Homemember *temp)                        //录入数据
        {
            std::cout<<"----------------------------------"<<std::endl;
            std::cout<<"请输入消费日期（例：20240409）："<<std::endl;
            std::cin>>temp->Date;

            std::cout<<"请输入成员信息："<<std::endl;
            std::cin>>temp->ID;

            std::cout<<"请输入消费金额："<<std::endl;
            std::cin>>temp->amount;

            std::cout<<"请输入消费品类："<<std::endl;
            std::cin>>temp->type;

            std::cout<<"请输入支出方式："<<std::endl;
            std::cin>>temp->method;

            std::cout<<"请输入消费场所："<<std::endl;
            std::cin>>temp->site;

            std::cout<<"请输入商品详情："<<std::endl;
            std::cin>>temp->detail;

        }
    
        std::string Date;
        std::string ID;
        double amount;
        std::string type;
        std::string method;
        std::string site;
        std::string detail;
        Homemember *next;
};
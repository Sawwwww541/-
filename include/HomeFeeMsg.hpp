#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Homemember
{
    public:
        Homemember():ID("none"),amount(0.0),type("none"),method("none"),
        site("none"),detail("none"),next(nullptr){}

        void entermsgs(Homemember *temp)
        {
            std::cout<<"----------------------------------"<<std::endl;
            std::cout<<"请输入日期（格式：20240409）："<<std::endl;
            std::cin>>temp->Date;

            std::cout<<"请输入成员身份："<<std::endl;
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
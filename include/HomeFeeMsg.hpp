/*ע�⣺��������ΪvscodeĬ�ϵ��ļ������ʽ��UTF-8����Windows���ն�Ĭ�ϱ����ʽ��gbk�����ָ�ʽ��ͻ�������룻
����취�����޸�vscodeĬ�����ã���Windows�ն�ͬ������*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//��Ա��
class Homemember
{
    public:
        Homemember():ID("none"),amount(0.0),type("none"),method("none"),
        site("none"),detail("none"),next(nullptr){}

        void entermsgs(Homemember *temp)                        //¼������
        {
            std::cout<<"----------------------------------"<<std::endl;
            std::cout<<"�������������ڣ�����20240409����"<<std::endl;
            std::cin>>temp->Date;

            std::cout<<"�������Ա��Ϣ��"<<std::endl;
            std::cin>>temp->ID;

            std::cout<<"���������ѽ�"<<std::endl;
            std::cin>>temp->amount;

            std::cout<<"����������Ʒ�ࣺ"<<std::endl;
            std::cin>>temp->type;

            std::cout<<"������֧����ʽ��"<<std::endl;
            std::cin>>temp->method;

            std::cout<<"���������ѳ�����"<<std::endl;
            std::cin>>temp->site;

            std::cout<<"��������Ʒ���飺"<<std::endl;
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
#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"

//��Ϣ��ӡ����
void printmsgs(Homemember *target)
{
    std::cout<<"-------------------------------------"<<std::endl;
    std::cout<<"�������ڣ�"<<target->Date<<std::endl;
    std::cout<<"��Ա��ݣ�"<<target->ID<<std::endl;
    std::cout<<"���ѽ�"<<target->amount<<std::endl;
    std::cout<<"����Ʒ�ࣺ"<<target->type<<std::endl;
    std::cout<<"֧����ʽ��"<<target->method<<std::endl;
    std::cout<<"���ѳ�����"<<target->site<<std::endl;
    std::cout<<"��Ʒ���飺"<<target->detail<<std::endl;
    std::cout<<"-------------------------------------"<<std::endl;
}


//���������Ĵ�ӡ��������װ�����ÿ�һ��
void printall(Homemember *head,char& isprint)
{
    std::cout<<"�Ѱ��������������Ƿ��ӡ��Ϣ��[y/n]"<<std::endl;
    std::cin>>isprint;
    if(isprint=='y')
    {
        Homemember *move=head->next;
        while(move!=nullptr)
        {
            printmsgs(move);
            move=move->next;
        }
    }
    return;
}
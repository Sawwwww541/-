#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"

//��ӡ�����ڵ�
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

//��ӡ������Ϣ
void printall(Homemember *head)
{
    Homemember *move=head->next;
    while(move!=nullptr)
    {
        printmsgs(move);
        move=move->next;
    }
    
    return;
}
#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"

//打印单个节点
void printmsgs(Homemember *target)
{
    std::cout<<"-------------------------------------"<<std::endl;
    std::cout<<"消费日期："<<target->Date<<std::endl;
    std::cout<<"成员身份："<<target->ID<<std::endl;
    std::cout<<"消费金额："<<target->amount<<std::endl;
    std::cout<<"消费品类："<<target->type<<std::endl;
    std::cout<<"支出方式："<<target->method<<std::endl;
    std::cout<<"消费场所："<<target->site<<std::endl;
    std::cout<<"商品详情："<<target->detail<<std::endl;
    std::cout<<"-------------------------------------"<<std::endl;
}

//打印所有信息
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
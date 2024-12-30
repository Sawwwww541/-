#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"

//信息打印函数
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


//用于排序后的打印函数，封装起来好看一点
void printall(Homemember *head,char& isprint)
{
    std::cout<<"已按消费日期升序，是否打印信息？[y/n]"<<std::endl;
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
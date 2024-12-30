#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\searchfunc.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"
//查询函数群(1.起止日期2.金额3.某人+起止日期4.某物+起止日期)
void findtotal(Homemember *head) 
{

    int choice=0;

    while(1){

        findmenu();
        std::cin>>choice;

        switch (choice)
        {
        case 11 :
            find1(head);
            break;
        case 12 :
            find2(head);
            break;
        case 13 :
            find3(head);
            break;
        case 14 :
            find4(head);
            break;
        case 15 :
            system("cls");
            return;
            break;
        default:
            std::cout<<"请输入有效指令"<<std::endl;
            break;
        }
    }

}

//日期
void find1(Homemember *head)
{
    auto *move=head->next;
    int temp=0;
    std::string Date;

    std::cout<<"请输入消费日期（例：20240409）："<<std::endl;
    std::cin>>Date;

    while(move!=nullptr)
    {
        if(Date==move->Date)
        {
            //打印消费记录
            printmsgs(move);
            temp++;
        }

        move=move->next;
    }
    if(temp==0)
    {
        //输出错误
        std::cout<<"未找到相关消费记录，即将返回查找导航菜单"<<std::endl;
        system("pause");
        system("cls");
    }
}

//金额
void find2(Homemember *head)
{
    auto *move=head->next;
    double amount;
    int temp=0;

    std::cout<<"请输入消费金额："<<std::endl;
    std::cin>>amount;

    while(move!=nullptr)
    {
        if(amount==move->amount)
        {
            //打印
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //输出错误
        std::cout<<"未找到相关消费记录，即将返回查找导航菜单"<<std::endl;
        system("pause");
        system("cls");
    }

}

//人+日期
void find3(Homemember *head)
{
    auto *move=head->next;
    std::string ID;
    int temp=0;
    std::string Date;

    std::cout<<"请输入消费日期（例：20240409）："<<std::endl;
    std::cin>>Date;
    std::cout<<"请输入成员信息："<<std::endl;
    std::cin>>ID;

    while(move!=nullptr)
    {
        if(Date==move->Date)
        {
            //打印消费记录
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //输出错误
        std::cout<<"未找到相关消费记录，即将返回查找导航菜单"<<std::endl;
        system("pause");
        system("cls");
    }
}

//物+日期
void find4(Homemember *head)
{
    auto *move=head->next;
    std::string type;
    int temp=0;
    std::string Date;

    std::cout<<"请输入消费日期（例：20240409）："<<std::endl;
    std::cin>>Date;
    std::cout<<"请输入消费品类："<<std::endl;
    std::cin>>type;

    while(move!=nullptr)
    {
        if(Date==move->Date)
        {
            //打印消费记录
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //输出错误
        std::cout<<"未找到相关消费记录，即将返回查找导航菜单"<<std::endl;
        system("pause");
        system("cls");
    }

}
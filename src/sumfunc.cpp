#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\sumfunc.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"

//统计函数群(求某一条件下的总金额)
void sumtotal(Homemember *head) 
{
    int choice=0;
    
    while(1)
    {
        summenu();
        double sumamount=0.0;
        std::cin>>choice;
        switch (choice)
        {
        case 31 :
            sumamount=sum3(head);
            break;
        case 32 :
            sumamount=sum1(head);
            break;
        case 33 :
            sumamount=sum2(head);
            break;
        case 34 :
            system("cls");
            return;
            break;
        default:
            std::cout<<"请输入有效指令"<<std::endl;
        }

        std::cout<<"统计完毕，符合条件的消费金额总数为："<<sumamount<<"元"<<std::endl;
    }
}

//谁+时间段
double sum1(Homemember *head)
{
    auto *move=head->next;
    std::string begin,end;
    std::string ID;
    double sumamount=0.0;

    do{
        std::cout<<"请输入起始时间：(例如：20240409)"<<std::endl;
        std::cin>>begin;
        std::cout<<"请输入终止时间：(例如：20240409)"<<std::endl;
        std::cin>>end;   

        if(begin.size()!=8||end.size()!=8) std::cout<<"日期格式错误，请输入正确格式的日期"<<std::endl;
    }while(begin.size()!=8||end.size()!=8);

    std::cout<<"请输入家庭成员："<<std::endl;
    std::cin>>ID;

    while(move!=nullptr)
    {
        if(move->ID==ID&&move->Date>=begin&&move->Date<=end)
            sumamount+=move->amount;    

        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"未找到对应消费记录"<<std::endl;
    
    return sumamount;
}

//品类+时间段
double sum2(Homemember *head)
{
    auto *move=head->next;
    std::string begin,end;
    std::string type;
    double sumamount=0.0;

    do{
        std::cout<<"请输入起始时间：(例如：20240409)"<<std::endl;
        std::cin>>begin;
        std::cout<<"请输入终止时间：(例如：20240409)"<<std::endl;
        std::cin>>end;   

        if(begin.size()!=8||end.size()!=8) std::cout<<"日期格式错误，请输入正确格式的日期"<<std::endl;
    }while(begin.size()!=8||end.size()!=8);

    std::cout<<"请输入消费品类："<<std::endl;
    std::cin>>type;

    while(move!=nullptr)
    {
        if(move->type==type&&move->Date>=begin&&move->Date<=end)
            sumamount+=move->amount;

        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"未找到对应消费记录"<<std::endl;

    return sumamount;
}

//时间段
double sum3(Homemember *head)
{
    auto *move=head->next;
    std::string begin,end;
    double sumamount=0.0;

    do{
        std::cout<<"请输入起始时间：(例如：20240409)"<<std::endl;
        std::cin>>begin;
        std::cout<<"请输入终止时间：(例如：20240409)"<<std::endl;
        std::cin>>end;   

        if(begin.size()!=8||end.size()!=8) std::cout<<"日期格式错误，请输入正确格式的日期"<<std::endl;
    }while(begin.size()!=8||end.size()!=8);

    while(move!=nullptr)
    {
        if(move->Date>=begin&&move->Date<=end)
            sumamount+=move->amount;
            
        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"未找到对应消费记录"<<std::endl;

    return sumamount;
}

#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\sumfunc.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"

//ͳ�ƺ���Ⱥ(��ĳһ�����µ��ܽ��)
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
            std::cout<<"��������Чָ��"<<std::endl;
        }

        std::cout<<"ͳ����ϣ��������������ѽ������Ϊ��"<<sumamount<<"Ԫ"<<std::endl;
    }
}

//˭+ʱ���
double sum1(Homemember *head)
{
    auto *move=head->next;
    std::string begin,end;
    std::string ID;
    double sumamount=0.0;

    do{
        std::cout<<"��������ʼʱ�䣺(���磺20240409)"<<std::endl;
        std::cin>>begin;
        std::cout<<"��������ֹʱ�䣺(���磺20240409)"<<std::endl;
        std::cin>>end;   

        if(begin.size()!=8||end.size()!=8) std::cout<<"���ڸ�ʽ������������ȷ��ʽ������"<<std::endl;
    }while(begin.size()!=8||end.size()!=8);

    std::cout<<"�������ͥ��Ա��"<<std::endl;
    std::cin>>ID;

    while(move!=nullptr)
    {
        if(move->ID==ID&&move->Date>=begin&&move->Date<=end)
            sumamount+=move->amount;    

        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"δ�ҵ���Ӧ���Ѽ�¼"<<std::endl;
    
    return sumamount;
}

//Ʒ��+ʱ���
double sum2(Homemember *head)
{
    auto *move=head->next;
    std::string begin,end;
    std::string type;
    double sumamount=0.0;

    do{
        std::cout<<"��������ʼʱ�䣺(���磺20240409)"<<std::endl;
        std::cin>>begin;
        std::cout<<"��������ֹʱ�䣺(���磺20240409)"<<std::endl;
        std::cin>>end;   

        if(begin.size()!=8||end.size()!=8) std::cout<<"���ڸ�ʽ������������ȷ��ʽ������"<<std::endl;
    }while(begin.size()!=8||end.size()!=8);

    std::cout<<"����������Ʒ�ࣺ"<<std::endl;
    std::cin>>type;

    while(move!=nullptr)
    {
        if(move->type==type&&move->Date>=begin&&move->Date<=end)
            sumamount+=move->amount;

        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"δ�ҵ���Ӧ���Ѽ�¼"<<std::endl;

    return sumamount;
}

//ʱ���
double sum3(Homemember *head)
{
    auto *move=head->next;
    std::string begin,end;
    double sumamount=0.0;

    do{
        std::cout<<"��������ʼʱ�䣺(���磺20240409)"<<std::endl;
        std::cin>>begin;
        std::cout<<"��������ֹʱ�䣺(���磺20240409)"<<std::endl;
        std::cin>>end;   

        if(begin.size()!=8||end.size()!=8) std::cout<<"���ڸ�ʽ������������ȷ��ʽ������"<<std::endl;
    }while(begin.size()!=8||end.size()!=8);

    while(move!=nullptr)
    {
        if(move->Date>=begin&&move->Date<=end)
            sumamount+=move->amount;
            
        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"δ�ҵ���Ӧ���Ѽ�¼"<<std::endl;

    return sumamount;
}

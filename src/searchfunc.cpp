#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\searchfunc.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"
//��ѯ����Ⱥ(1.��ֹ����2.���3.ĳ��+��ֹ����4.ĳ��+��ֹ����)
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
            std::cout<<"��������Чָ��"<<std::endl;
            break;
        }
    }

}

//����
void find1(Homemember *head)
{
    auto *move=head->next;
    int temp=0;
    std::string Date;

    std::cout<<"�������������ڣ�����20240409����"<<std::endl;
    std::cin>>Date;

    while(move!=nullptr)
    {
        if(Date==move->Date)
        {
            //��ӡ���Ѽ�¼
            printmsgs(move);
            temp++;
        }

        move=move->next;
    }
    if(temp==0)
    {
        //�������
        std::cout<<"δ�ҵ�������Ѽ�¼���������ز��ҵ����˵�"<<std::endl;
        system("pause");
        system("cls");
    }
}

//���
void find2(Homemember *head)
{
    auto *move=head->next;
    double amount;
    int temp=0;

    std::cout<<"���������ѽ�"<<std::endl;
    std::cin>>amount;

    while(move!=nullptr)
    {
        if(amount==move->amount)
        {
            //��ӡ
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //�������
        std::cout<<"δ�ҵ�������Ѽ�¼���������ز��ҵ����˵�"<<std::endl;
        system("pause");
        system("cls");
    }

}

//��+����
void find3(Homemember *head)
{
    auto *move=head->next;
    std::string ID;
    int temp=0;
    std::string Date;

    std::cout<<"�������������ڣ�����20240409����"<<std::endl;
    std::cin>>Date;
    std::cout<<"�������Ա��Ϣ��"<<std::endl;
    std::cin>>ID;

    while(move!=nullptr)
    {
        if(Date==move->Date)
        {
            //��ӡ���Ѽ�¼
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //�������
        std::cout<<"δ�ҵ�������Ѽ�¼���������ز��ҵ����˵�"<<std::endl;
        system("pause");
        system("cls");
    }
}

//��+����
void find4(Homemember *head)
{
    auto *move=head->next;
    std::string type;
    int temp=0;
    std::string Date;

    std::cout<<"�������������ڣ�����20240409����"<<std::endl;
    std::cin>>Date;
    std::cout<<"����������Ʒ�ࣺ"<<std::endl;
    std::cin>>type;

    while(move!=nullptr)
    {
        if(Date==move->Date)
        {
            //��ӡ���Ѽ�¼
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //�������
        std::cout<<"δ�ҵ�������Ѽ�¼���������ز��ҵ����˵�"<<std::endl;
        system("pause");
        system("cls");
    }

}
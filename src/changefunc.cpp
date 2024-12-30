#include "D:\\Finalworks\\include\\changefunc.hpp"
#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"

//¼�뺯��Ⱥ(¼�벢���浽�ļ�)
void add(Homemember *head)
{
    //�ƶ�ָ�룬����β�巨��������ڵ�
    auto *temp=new Homemember;
    auto *move=head;

    while(move->next!=nullptr) 
    {
        move=move->next;
    }

    temp->entermsgs(temp);
    move->next=temp;
                
}
//������Ⱥ(��������������)
//���ù鲢����
Homemember* rank(Homemember *head) 
{
    if(head==nullptr||head->next==nullptr) return head;

    Homemember *head1=head;
    Homemember *head2=midsearch(head);

    head1=rank(head1);
    head2=rank(head2);

    return merge(head1,head2);

}
//���������е�
Homemember* midsearch(Homemember *head)
{
    Homemember *slow=head,*fast=head->next;

    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    Homemember *mid=slow->next;
    slow->next=nullptr;         //�ж��е�����һ�������

    return mid;
}
//�ϲ���˳���������
Homemember* merge(Homemember *head1,Homemember *head2)
{
    Homemember *temp=new Homemember(),*p=temp;

    while(head1!=nullptr&&head2!=nullptr)
    {
        if(head1->Date<=head2->Date)
        {
            p->next=head1;
            head1=head1->next;
        }
        else
        {
            p->next=head2;
            head2=head2->next;
        }

        p=p->next;
    }

    if(head1!=nullptr) p->next=head1;
    else p->next=head2;

    Homemember *ret=temp->next;
    delete temp;
    temp=nullptr;
    return ret;

}

//���º���Ⱥ(�޸Ĳ����浽�ļ�,����ɾ��ĳһ���)
void change(Homemember *head,int& judgement) 
{
    std::string ID,type;
    double amount;
    std::string Date;
    auto *target=head->next,*slow=head;
    char yesorno='n';

    //����ϸ������ģ�飬��ֹ�޸ĵ�һ�����ϵ���Ŀ

    std::cout<<"�����������Ϣ���Ա㶨λ��Ҫ�޸ĵ���Ŀ"<<std::endl;
    std::cout<<"�������������ڣ�����20240409����"<<std::endl;
    std::cin>>Date;    
    std::cout<<"��Ա��ݣ�"<<std::endl;
    std::cin>>ID;
    std::cout<<"���ѽ�"<<std::endl;
    std::cin>>amount;
    std::cout<<"����Ʒ�ࣺ"<<std::endl;
    std::cin>>type;

    while(target!=nullptr)
    {
        if(Date==target->Date&&ID==target->ID
        &&amount==target->amount&&type==target->type)
        {
            //��ӡ���Ѽ�¼
            printmsgs(target);
            break;
        }
        slow=target;
        target=target->next;
    }
    if(target==nullptr)
    {
        //�������
        std::cout<<"δ�ҵ�������Ѽ�¼����������"<<std::endl;
        system("pause");
        system("cls");
        return;
    }

    if(judgement==0)
    {
        std::cout<<"��������ĺ������"<<std::endl;
        target->entermsgs(target);
        std::cout<<"�޸ĳɹ�"<<std::endl;
    }
    else
    {
        std::cout<<"ȷ��ɾ����[y/n]"<<std::endl;
        std::cin>>yesorno;
        if(yesorno=='y')
        {
            slow->next=target->next;
            delete target;
            target=nullptr;
        }else
        {
            std::cout<<"ȡ��ɾ������������"<<std::endl;
            system("pause");
            system("cls");
            return;
        }
    }

}
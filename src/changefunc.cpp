#include "D:\\Finalworks\\include\\changefunc.hpp"
#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"

void add(Homemember *head)
{
    int cnt=0;
    double amount;
    std::string Date,ID,type,method,site,detail;
    //输入信息
    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"请输入日期（格式：20240409）："<<std::endl;
    std::cin>>Date;

    std::cout<<"请输入成员身份："<<std::endl;
    std::cin>>ID;

    std::cout<<"请输入消费金额："<<std::endl;
    std::cin>>amount;

    std::cout<<"请输入消费品类："<<std::endl;
    std::cin>>type;

    std::cout<<"请输入支出方式："<<std::endl;
    std::cin>>method;

    std::cout<<"请输入消费场所："<<std::endl;
    std::cin>>site;

    std::cout<<"请输入商品详情："<<std::endl;
    std::cin>>detail;    
    //查重
    auto *move=head;
    auto *slow=head;
    while(move!=nullptr) 
    {
        if(Date==move->Date&&ID==move->ID
        &&amount==move->amount&&type==move->type
        &&method==move->method&&site==move->site&&detail==move->detail)
            cnt++;
        slow=move;
        move=move->next;
    }
    if(cnt==0){
        auto *temp=new Homemember;
        temp->Date=Date;
        temp->ID=ID;
        temp->amount=amount;
        temp->type=type;
        temp->method=method;
        temp->site=site;
        temp->detail=detail;
        slow->next=temp;
        std::cout<<"添加成功"<<std::endl;        
    }else std::cout<<"您已添加过该条目，添加失败"<<std::endl;
    std::cout<<"----------------------------------"<<std::endl;        
}

Homemember* rank(Homemember *head) 
{
    if(head==nullptr||head->next==nullptr) return head;

    Homemember *head1=head;
    Homemember *head2=midsearch(head);

    head1=rank(head1);
    head2=rank(head2);

    return merge(head1,head2);

}

Homemember* midsearch(Homemember *head)
{
    Homemember *slow=head,*fast=head->next;

    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    Homemember *mid=slow->next;
    slow->next=nullptr;         

    return mid;
}

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

void change(Homemember *head,int& judgement) 
{
    std::string ID,type,Date,method,site,detail;
    double amount;
    auto *target=head->next,*slow=head;
    char yesorno='n';

    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"请输入日期（格式：20240409）："<<std::endl;
    std::cin>>Date;

    std::cout<<"请输入成员身份："<<std::endl;
    std::cin>>ID;

    std::cout<<"请输入消费金额："<<std::endl;
    std::cin>>amount;

    std::cout<<"请输入消费品类："<<std::endl;
    std::cin>>type;

    std::cout<<"请输入支出方式："<<std::endl;
    std::cin>>method;

    std::cout<<"请输入消费场所："<<std::endl;
    std::cin>>site;

    std::cout<<"请输入商品详情："<<std::endl;
    std::cin>>detail;

    while(target!=nullptr)
    {
        if(Date==target->Date&&ID==target->ID
        &&amount==target->amount&&type==target->type
        &&method==target->method&&site==target->site&&detail==target->detail)
        {
            printmsgs(target);
            break;
        }
        slow=target;
        target=target->next;
    }
    if(target==nullptr)
    {
        std::cout<<"未查找到相关信息"<<std::endl;
        system("pause");
        system("cls");
        return;
    }

    if(judgement==0)
    {
        std::cout<<"请输入更改后的信息"<<std::endl;
        target->entermsgs(target);
        std::cout<<"更改成功"<<std::endl;
    }
    else
    {
        std::cout<<"确认删除[y/n]"<<std::endl;
        std::cin>>yesorno;
        if(yesorno=='y')
        {
            slow->next=target->next;
            delete target;
            target=nullptr;
        }else
        {
            std::cout<<"取消删除"<<std::endl;
            system("pause");
            system("cls");
            return;
        }
    }

}
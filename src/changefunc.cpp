#include "D:\\Finalworks\\include\\changefunc.hpp"
#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"

//录入函数群(录入并保存到文件)
void add(Homemember *head)
{
    //移动指针，利用尾插法增添链表节点
    auto *temp=new Homemember;
    auto *move=head;

    while(move->next!=nullptr) 
    {
        move=move->next;
    }

    temp->entermsgs(temp);
    move->next=temp;
                
}
//排序函数群(按交易日期升序)
//采用归并排序
Homemember* rank(Homemember *head) 
{
    if(head==nullptr||head->next==nullptr) return head;

    Homemember *head1=head;
    Homemember *head2=midsearch(head);

    head1=rank(head1);
    head2=rank(head2);

    return merge(head1,head2);

}
//查找链表中点
Homemember* midsearch(Homemember *head)
{
    Homemember *slow=head,*fast=head->next;

    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    Homemember *mid=slow->next;
    slow->next=nullptr;         //切断中点与另一半的链接

    return mid;
}
//合并，顺便完成排序
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

//更新函数群(修改并保存到文件,或者删除某一结点)
void change(Homemember *head,int& judgement) 
{
    std::string ID,type;
    double amount;
    std::string Date;
    auto *target=head->next,*slow=head;
    char yesorno='n';

    //更详细的搜索模块，防止修改到一个以上的条目

    std::cout<<"请输入相关信息，以便定位您要修改的条目"<<std::endl;
    std::cout<<"请输入消费日期（例：20240409）："<<std::endl;
    std::cin>>Date;    
    std::cout<<"成员身份："<<std::endl;
    std::cin>>ID;
    std::cout<<"消费金额："<<std::endl;
    std::cin>>amount;
    std::cout<<"消费品类："<<std::endl;
    std::cin>>type;

    while(target!=nullptr)
    {
        if(Date==target->Date&&ID==target->ID
        &&amount==target->amount&&type==target->type)
        {
            //打印消费记录
            printmsgs(target);
            break;
        }
        slow=target;
        target=target->next;
    }
    if(target==nullptr)
    {
        //输出错误
        std::cout<<"未找到相关消费记录，即将返回"<<std::endl;
        system("pause");
        system("cls");
        return;
    }

    if(judgement==0)
    {
        std::cout<<"请输入更改后的数据"<<std::endl;
        target->entermsgs(target);
        std::cout<<"修改成功"<<std::endl;
    }
    else
    {
        std::cout<<"确认删除？[y/n]"<<std::endl;
        std::cin>>yesorno;
        if(yesorno=='y')
        {
            slow->next=target->next;
            delete target;
            target=nullptr;
        }else
        {
            std::cout<<"取消删除，即将返回"<<std::endl;
            system("pause");
            system("cls");
            return;
        }
    }

}
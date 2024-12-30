#include "D:\\Finalworks\\include\\io.hpp"
#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"

//文件IO
void ifile(Homemember *head)                //内存到文件
{
    std::ofstream file("fee.dat",std::ios::out);
    auto *move=head->next;

    if(file.is_open())
    {
        while(move!=nullptr)
        {
            file<<move->Date<<" "<<move->ID<<" "<<move->amount<<" "<<move->type<<" "
            <<move->method<<" "<<move->site<<" "<<move->detail<<"\n"
            <<"###"<<std::endl;              //＃号作为大分隔符，将模块区分开
            move=move->next;
        }
    }

    file.close();
}

void ofile(Homemember *head)                //文件到内存
{
    auto *tail=head;
    std::ifstream file("fee.dat");
    std::string _check;
    
    if(file.is_open())
    {
        while(std::getline(file,_check))
        {
            
            if(_check=="###")
            {
                 while(tail->next!=nullptr)              //将指针移到链表尾
                {
                    tail=tail->next;
                }
                
            }
            else
            {
                Homemember *newnode=new Homemember;
                std::istringstream iss(_check);
                if(iss>>newnode->Date>>newnode->ID>>newnode->amount>>newnode->type>>newnode->method>>newnode->site>>newnode->detail)
                {
                    tail->next=newnode;
                    tail=newnode;
                }
            }
        }
    }

}

//内存管理
void Deletelist(Homemember *head)
{
    auto *move=head;
    while(move!=nullptr)
    {
        auto *temp=move;
        move=move->next;
        delete temp;
    }
}
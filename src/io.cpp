#include "D:\\Finalworks\\include\\io.hpp"
#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"

//�ļ�IO
void ifile(Homemember *head)                //�ڴ浽�ļ�
{
    std::ofstream file("fee.dat",std::ios::out);
    auto *move=head->next;

    if(file.is_open())
    {
        while(move!=nullptr)
        {
            file<<move->Date<<" "<<move->ID<<" "<<move->amount<<" "<<move->type<<" "
            <<move->method<<" "<<move->site<<" "<<move->detail<<"\n"
            <<"###"<<std::endl;              //������Ϊ��ָ�������ģ�����ֿ�
            move=move->next;
        }
    }

    file.close();
}

void ofile(Homemember *head)                //�ļ����ڴ�
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
                 while(tail->next!=nullptr)              //��ָ���Ƶ�����β
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

//�ڴ����
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
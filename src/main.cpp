#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\changefunc.hpp"
#include "D:\\Finalworks\\include\\io.hpp"
#include "D:\\Finalworks\\include\\menufunc.hpp"
#include "D:\\Finalworks\\include\\searchfunc.hpp"
#include "D:\\Finalworks\\include\\sumfunc.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"

int main()
{
    Homemember *head=new Homemember;        
    ofile(head);                            

    while(1){                               
        int n=-1,num=0,judgement=0;
        char isprint='n';
        usrmenu();
        std::cin>>n;

        switch (n)
        {
        case 0:
            printall(head);
            break;
        case 1:
            findtotal(head);                
            break;
        case 2:                             
            head=rank(head);

            std::cout<<"�Ƿ��ӡȫ����Ϣ��[y/n]"<<std::endl;
            std::cin>>isprint;

            if(isprint=='y') printall(head);
            system("pause");
            system("cls");
            break;
        case 3:                             
            sumtotal(head);
            break;
        case 4:                             
            std::cout<<"������Ҫ��ӵ���Ŀ��Ŀ��"<<std::endl;
            std::cin>>num;
            for(int i=0;i<num;i++)
            {
                add(head);
            }
            break;
        case 5:                             
            std::cout<<"���ģ�����0������ɾ��������1��"<<std::endl;
            std::cin>>judgement;
            change(head,judgement);
            break;
        case 6:                             
            ifile(head);
            Deletelist(head);
            return 0;
            break;
        default:
            std::cout<<"��������Чָ��"<<std::endl;
        }
    }

    return 0;
}
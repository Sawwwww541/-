/*如若vscode终端出现乱码，或者改编码后在程序执行过程中乱码，但编译正常的情况下，使用系统终端*/
#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\changefunc.hpp"
#include "D:\\Finalworks\\include\\io.hpp"
#include "D:\\Finalworks\\include\\menufunc.hpp"
#include "D:\\Finalworks\\include\\searchfunc.hpp"
#include "D:\\Finalworks\\include\\sumfunc.hpp"
#include "D:\\Finalworks\\include\\printmsg.hpp"

int main()
{
    Homemember *head=new Homemember;        //头节点不存放有效数据
    ofile(head);                            //启动程序，载入数据

    while(1){                               //为了维持初始主界面的死循环
        int n=0,num=0,judgement=0;
        char isprint='n';
        usrmenu();
        std::cin>>n;

        switch (n)
        {
        case 1:
            findtotal(head);                //查找
                                            /*为了实现二级菜单的滞留与可返回性，使用函数封装一个菜单死循环,
                                             *这样在需要返回初始菜单时return当前函数即可*/
            break;
        case 2:                             //排序
            head=rank(head);
            printall(head,isprint);
            system("pause");
            system("cls");
            break;
        case 3:                             /*统计;
                                            *这里选择与查找函数群类似的结构*/
            sumtotal(head);
            break;
        case 4:                             //增加
            std::cout<<"请输入要增加的条目数："<<std::endl;
            std::cin>>num;
            for(int i=0;i<num;i++)
            {
                add(head);
            }
            break;
        case 5:                             //更新
            std::cout<<"更改(输入0)还是删除(输入1)？"<<std::endl;
            std::cin>>judgement;
            change(head,judgement);
            break;
        case 6:                             //结束程序，保存数据，释放内存
            ifile(head);
            Deletelist(head);
            return 0;
            break;
        default:
            std::cout<<"请输入有效指令"<<std::endl;
        }
    }

    return 0;
}
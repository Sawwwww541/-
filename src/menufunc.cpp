#include "D:\\Finalworks\\include\\HomeFeeMsg.hpp"
#include "D:\\Finalworks\\include\\menufunc.hpp"

//初始用户界面--一级菜单
void usrmenu()
{
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"欢迎使用家庭消费管理系统，请根索引选择对应服务"<<std::endl;
    std::cout<<"0----打印全部 1----查询 2----排序 3----统计 4----录入 5----更新 6----退出"<<std::endl;
    std::cout<<"**************************************************************************"<<std::endl;
}


//查询菜单--二级菜单
void findmenu()
{
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"11----按日期区间段查询              12----按交易金额查询"<<std::endl;
    std::cout<<"13----按家庭成员加日期区间查询      14----按消费品类加日期区间查询"<<std::endl;
    std::cout<<"15----返回上级菜单"<<std::endl;
    std::cout<<"**************************************************************************"<<std::endl;
}


//统计菜单--二级菜单
void summenu() 
{
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"31----给定时间段家庭消费总额统计        32----特定成员在给定时间段消费总额统计"<<std::endl;
    std::cout<<"33----特定品类在给定时间段消费总额统计     34----返回上级菜单"<<std::endl;
    std::cout<<"**************************************************************************"<<std::endl;
}
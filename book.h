//
// Created by Thrall on 2023/6/26.
//

#include "string"
#include "iostream"
#include "fstream"

using namespace std;


#ifndef TEXT_MANAGEMENT_SYS_BOOK_H
#define TEXT_MANAGEMENT_SYS_BOOK_H

#endif //TEXT_MANAGEMENT_SYS_BOOK_H

class book{
public:
    string name;
    int store;
    int num;
    double price;
    book(const string& name,int store,int num,int price):name(name),store(store),num(num),price(price){}
};

class trade{
public:
    string name;
    string date;
    int store;
    int num;
    double costing;
    trade(const string& name,const string date,int store,int num,double costing):name(name),date(date),store(store),num(num),costing(costing){}
};

class textbook{
public:
    void buy_book();      //购买录入
    void buy_serch();       //购买记录查询
    void sell_book();       //出售录入
    void sell_serch();      //出售记录查询
    void day_stats();       //每日统计
    void store_stats();     //库存统计
    void sell_stats();      //出售统计
    void store_info();      //总库存查询
    void store_check();     //库存预警
    void save();
    textbook();

private:
    book* textbook_all[100];
    trade* sell[100];
    trade* buy[100];
    int datalocation;
    int buylocation;
    int selllocation;
    int isdataempty;
    int isbuyempty;
    int issellempty;
    int isdatachange;
    string datapath;
    string sellpath;
    string buypath;

};

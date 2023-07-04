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
    void buy_book();      //����¼��
    void buy_serch();       //�����¼��ѯ
    void sell_book();       //����¼��
    void sell_serch();      //���ۼ�¼��ѯ
    void day_stats();       //ÿ��ͳ��
    void store_stats();     //���ͳ��
    void sell_stats();      //����ͳ��
    void store_info();      //�ܿ���ѯ
    void store_check();     //���Ԥ��
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

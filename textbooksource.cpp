//
// Created by Thrall on 2023/6/26.
//

#include "book.h"

void textbook::buy_book(){
    {
        string name;
        string date;
        int store;
        int num;
        double price;
        double costing;
        cout<<"请输入书名"<<endl;
        cin.ignore(1024,'\n');
        getline(cin,name);
        cout<<"请输入存储仓库"<<endl;
        cin>>store;
        for (int i = 0; i < datalocation; i++) {                                       //检测是否有同一库存内的同名书籍
            if (textbook_all[i]->name==name && textbook_all[i]->store==store){
                cout<<"请输入数量"<<endl;
                cin>>num;
                cout<<"请输入日期  格式  xxxx/xx/xx "<<endl;
                cin>>date;
                cout<<"请输入订购总消费"<<endl;
                cin>>costing;
                trade *newbuy = new trade(name,date,store,num,costing);
                textbook_all[i]->num+=num;
                buy[buylocation]=newbuy;
                buylocation++;
                isdatachange=1;
                return;
            }
        }
        cout<<"请输入数量"<<endl;
        cin>>num;
        cout<<"请输入售价"<<endl;
        cin>>price;
        cout<<"请输入日期  格式  xxxx/xx/xx "<<endl;
        cin>>date;
        cout<<"请输入订购总消费"<<endl;
        cin>>costing;
        book *newbook = new book(name,store,num,price);
        trade *newbuy = new trade(name,date,store,num,costing);
        textbook_all[datalocation]=newbook;
        buy[buylocation]=newbuy;
        datalocation++;
        buylocation++;
        isdatachange=1;
    }
}



void textbook::buy_serch() {
    if (buylocation==0){
        cout<<"无购买记录"<<endl;
    }else {
        cout << endl;
        cout<<" 购买日期  "<<"  书籍名称  "<<" 订购数量 "<<" 库位号 "<<" 订购消费 "<<endl<<endl;
        for (int i = 0; i < buylocation; i++) {
            cout << buy[i]->date << " ";
            cout << buy[i]->name << "   ";
            cout << buy[i]->num << "       ";
            cout << buy[i]->store << "      ";
            cout << buy[i]->costing << endl;
        }
        cout << endl;
    }

}



void textbook::sell_book() {
    string tname;
    string date;
    int num;
    int isbookfound=0;
    cout<<"请输入出售书名"<<endl;
    cin.ignore(1024,'\n');
    getline(cin,tname);
    for (int i = 0; i < datalocation; i++) {
        if (textbook_all[i]->name==tname){                 //判断库中是否有此书
            isdatachange=1;
            isbookfound=1;
            cout<<"请输入出售数量"<<endl;
            cin>>num;
            if (textbook_all[i]->num>=num) {                        //判断库中书的数量是否足够
                cout << "请输入日期  格式  xxxx/xx/xx " << endl;
                cin >> date;
                textbook_all[i]->num -= num;
                trade *newsell = new trade(tname, date, textbook_all[i]->store, num, textbook_all[i]->price);      //存储出售信息
                sell[selllocation] = newsell;
                selllocation++;
                if (textbook_all[i]->num == 0) {            //检测库存是否清零，如果清零，清除库中此书籍的信息
                    textbook_all[i] = NULL;
                }
                cout << "出售完成" << endl;
                break;
            }else{
                cout<<"出售数量大于库存数量"<<endl;
            }
        }
    }
    if (isbookfound==0) {
        cout << "库中无此书" << endl;
    }
}


void textbook::sell_serch() {
    if (selllocation==0){
        cout<<"无销售记录"<<endl;
    }else {
        cout << endl;
        cout<<" 销售日期  "<<"   书籍名称    "<<" 出售数量  "<<" 库位号 "<<endl<<endl;
        for (int i = 0; i < selllocation; i++) {
            cout << sell[i]->date << " ";
            cout << sell[i]->name << "     ";
            cout << sell[i]->num << "       ";
            cout << sell[i]->store << endl;
        }
        cout << endl;
    }
}


void textbook::day_stats() {
    int totalbuy = 0;
    int totalsell = 0;
    double totalget = 0;
    string date;
    cout<<"请输入查询日期"<<endl;
    cin>>date;
    cout<<endl;

    for (int i = 0; i < buylocation; i++) {
        if (buy[i]->date==date) {
            totalbuy += buy[i]->num;
        }
    }

    for (int i = 0; i < selllocation; i++) {
        if (sell[i]->date==date) {
            totalsell += sell[i]->num;
            totalget += sell[i]->costing * sell[i]->num;
        }
    }
    if (totalbuy!=0 && totalsell!=0){
        cout << "当日统计：" << endl;
        cout << "总购买教材数量: " << totalbuy << endl;
        cout << "总售出教材数量: " << totalsell << endl;
        cout << "销售额: " << totalget << endl;
    }else{
        cout<<"当日无交易数据"<<endl;
    }


}



void textbook::store_stats() {
    int booksinstore[100] = {0};
    int maxstore=0;
    int isdatanull=0;
    for (int i = 0; i < datalocation; i++) {
        if (textbook_all[i]!=NULL){
            int storenumber = textbook_all[i]->store;
            if (storenumber>maxstore) {
                maxstore = storenumber;
            }
            booksinstore[storenumber] += textbook_all[i]->num;
        }
    }

    cout <<endl<< "仓库位号统计：" << endl;
    for (int i = 1; i < maxstore+1; i++) {
        if (booksinstore[i] > 0) {
            cout << "仓库 " << i << ": " << booksinstore[i] << " 本教材" << endl;
            isdatanull=1;
        }
    }
    if (isdatanull==0){
        cout<<"库中无书"<<endl;
    }
}


void textbook::sell_stats() {
    int totalsell = 0;
    double totalget = 0;

    for (int i = 0; i < buylocation; i++) {
        totalget -= buy[i]->costing;
    }

    for (int i = 0; i < selllocation; i++) {
        totalsell += sell[i]->num;
        totalget += sell[i]->costing*sell[i]->num;

    }
    cout<<endl;
    cout << "销售统计：" << endl;
    cout << "总售出教材数量: " << totalsell << endl;
    cout << "总利润: " << totalget << endl;
}


void textbook::store_info() {
    cout << endl;
    int isdatanull=0;
    cout<<"  书籍名称  "<<" 数量 "<<" 库位号 "<<endl<<endl;
    for (int i = 0; i < datalocation; i++){
        if (textbook_all[i]!=NULL){
            isdatanull=1;
            cout << textbook_all[i]->name << "   ";
            cout << textbook_all[i]->num << "       ";
            cout << textbook_all[i]->store << endl;
        }

    }
    if (isdatanull==0) {
        cout << "无书籍数据" << endl;
    }


}


void textbook::store_check() {
    cout<<endl;
    int isbookwarn=0;
    int isdatanull=0;
    for (int i = 0; i < datalocation; i++){
        if (textbook_all[i]!=NULL){
            isdatanull=1;
            if (textbook_all[i]->num<10){
                cout<<"仓库："<<textbook_all[i]->store<<"的 "<<textbook_all[i]->name<<" 库存不足十本。";
                isbookwarn=1;
            }
        }
    }
    if (isbookwarn==0 && isdatanull==1){
        cout<<"图书库存充足"<<endl;
    }
    if (isdatanull==0){
        cout<<"库中无书"<<endl;
    }
    cout << endl;


}



void textbook::save() {
    if(isdatachange==0){
        cout<<"数据未被修改"<<endl;
        return;
    }
    ofstream bookf;
    ofstream buyf;
    ofstream sellf;

    bookf.open(datapath,ios::out);
    for(int i=0;i<datalocation;i++){
        if (textbook_all[i]!=NULL){
            bookf<<textbook_all[i]->name<<"$ ";
            bookf<<textbook_all[i]->num<<" ";
            bookf<<textbook_all[i]->store<<" ";
            bookf<<textbook_all[i]->price<<endl;
        }

    }

    buyf.open(buypath,ios::out);
    for(int i=0;i<buylocation;i++){
        buyf<<buy[i]->date<<" ";
        buyf<<buy[i]->name<<"$ ";
        buyf<<buy[i]->num<<" ";
        buyf<<buy[i]->store<<" ";
        buyf<<buy[i]->costing<<endl;
    }

    sellf.open(sellpath,ios::out);
    for(int i=0;i<selllocation;i++){
        sellf<<sell[i]->date<<" ";
        sellf<<sell[i]->name<<"$ ";
        sellf<<sell[i]->num<<" ";
        sellf<<sell[i]->store<<" ";
        sellf<<sell[i]->costing<<endl;
    }
    cout<<"保存成功"<<endl;

}



textbook::textbook() {
    datapath="bookinfo.txt";
    buypath="buyrecord.txt";
    sellpath="sellrecord.txt";
    isdatachange=0;
    isdataempty = 0;
    isbuyempty =0;
    issellempty =0;
    ifstream bookf;
    ifstream buyf;
    ifstream sellf;
    
//书籍数据文件读取    
    
    cout<<"正在读取书籍数据文件"<<endl;
    bookf.open(datapath, ios::in);
    if (bookf.is_open()==0) {
        cout << "未找到书籍数据文件" << endl;
        isdataempty = 1;
        bookf.close();
    } else {
        char c;
        bookf.get(c);
        if (bookf.eof()) {
            isdataempty = 1;
            cout << "书籍数据文件为空" << endl;
        }
        bookf.close();
    }
    if (isdataempty==0) {
        bookf.open(datapath, ios::in);
        datalocation = 0;
        char name[50];
        int store;
        int num;
        double price;
        while (bookf.getline(name,50,'$') && bookf >> num && bookf >> store && bookf >> price && bookf.get()) {
            book *newbook = new book(name,store,num,price);
            textbook_all[datalocation] = newbook;
            datalocation++;
        }
        cout<<"书籍数据文件读取完成"<<endl;
    }else {
        datalocation=0;
    }

//购买记录文件读取
    
    cout<<"正在读取购买记录文件"<<endl;
    buyf.open(buypath, ios::in);
    if (buyf.is_open()==0) {
        cout << "未找到购买记录文件" << endl;
        isbuyempty = 1;
        buyf.close();
    } else {
        char c;
        buyf.get(c);
        if (buyf.eof()) {
            isbuyempty = 1;
            cout << "购买记录文件为空" << endl;
        }
        buyf.close();
    }
    if (isbuyempty==0) {
        buyf.open(buypath, ios::in);
        buylocation = 0;
        char name[50];
        string date;
        int store;
        int num;
        double costing;
        while (buyf >> date && buyf.get() && buyf.getline(name,50,'$') && buyf >> num && buyf >> store && buyf >> costing) {
            trade *newbuy = new trade(name,date,store,num,costing);
            buy[buylocation] = newbuy;
            buylocation++;
        }
        cout<<"购买记录文件读取完成"<<endl;
    }else {
        buylocation=0;
    }

//读取出售记录文件

    cout<<"正在读取出售记录文件"<<endl;
    sellf.open(sellpath, ios::in);
    if (sellf.is_open()==0) {
        cout << "未找到出售记录文件" << endl;
        issellempty = 1;
        sellf.close();
    } else {
        char c;
        sellf.get(c);
        if (sellf.eof()) {
            issellempty = 1;
            cout << "出售记录文件为空" << endl;
        }
        sellf.close();
    }
    if (issellempty==0) {
        sellf.open(sellpath, ios::in);
        selllocation = 0;
        char name[50];
        string date;
        int store;
        int num;
        double costing=0;
        while (sellf >> date && sellf.get() && sellf.getline(name,50,'$') && sellf >> num && sellf >> store && sellf >> costing) {
            trade *newsell = new trade(name,date,store,num,costing);
            sell[selllocation] = newsell;
            selllocation++;
        }
        cout<<"出售记录文件读取完成"<<endl;
    }else {
        selllocation=0;
    }
}

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
        cout<<"����������"<<endl;
        cin.ignore(1024,'\n');
        getline(cin,name);
        cout<<"������洢�ֿ�"<<endl;
        cin>>store;
        for (int i = 0; i < datalocation; i++) {                                       //����Ƿ���ͬһ����ڵ�ͬ���鼮
            if (textbook_all[i]->name==name && textbook_all[i]->store==store){
                cout<<"����������"<<endl;
                cin>>num;
                cout<<"����������  ��ʽ  xxxx/xx/xx "<<endl;
                cin>>date;
                cout<<"�����붩��������"<<endl;
                cin>>costing;
                trade *newbuy = new trade(name,date,store,num,costing);
                textbook_all[i]->num+=num;
                buy[buylocation]=newbuy;
                buylocation++;
                isdatachange=1;
                return;
            }
        }
        cout<<"����������"<<endl;
        cin>>num;
        cout<<"�������ۼ�"<<endl;
        cin>>price;
        cout<<"����������  ��ʽ  xxxx/xx/xx "<<endl;
        cin>>date;
        cout<<"�����붩��������"<<endl;
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
        cout<<"�޹����¼"<<endl;
    }else {
        cout << endl;
        cout<<" ��������  "<<"  �鼮����  "<<" �������� "<<" ��λ�� "<<" �������� "<<endl<<endl;
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
    cout<<"�������������"<<endl;
    cin.ignore(1024,'\n');
    getline(cin,tname);
    for (int i = 0; i < datalocation; i++) {
        if (textbook_all[i]->name==tname){                 //�жϿ����Ƿ��д���
            isdatachange=1;
            isbookfound=1;
            cout<<"�������������"<<endl;
            cin>>num;
            if (textbook_all[i]->num>=num) {                        //�жϿ�����������Ƿ��㹻
                cout << "����������  ��ʽ  xxxx/xx/xx " << endl;
                cin >> date;
                textbook_all[i]->num -= num;
                trade *newsell = new trade(tname, date, textbook_all[i]->store, num, textbook_all[i]->price);      //�洢������Ϣ
                sell[selllocation] = newsell;
                selllocation++;
                if (textbook_all[i]->num == 0) {            //������Ƿ����㣬������㣬������д��鼮����Ϣ
                    textbook_all[i] = NULL;
                }
                cout << "�������" << endl;
                break;
            }else{
                cout<<"�����������ڿ������"<<endl;
            }
        }
    }
    if (isbookfound==0) {
        cout << "�����޴���" << endl;
    }
}


void textbook::sell_serch() {
    if (selllocation==0){
        cout<<"�����ۼ�¼"<<endl;
    }else {
        cout << endl;
        cout<<" ��������  "<<"   �鼮����    "<<" ��������  "<<" ��λ�� "<<endl<<endl;
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
    cout<<"�������ѯ����"<<endl;
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
        cout << "����ͳ�ƣ�" << endl;
        cout << "�ܹ���̲�����: " << totalbuy << endl;
        cout << "���۳��̲�����: " << totalsell << endl;
        cout << "���۶�: " << totalget << endl;
    }else{
        cout<<"�����޽�������"<<endl;
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

    cout <<endl<< "�ֿ�λ��ͳ�ƣ�" << endl;
    for (int i = 1; i < maxstore+1; i++) {
        if (booksinstore[i] > 0) {
            cout << "�ֿ� " << i << ": " << booksinstore[i] << " ���̲�" << endl;
            isdatanull=1;
        }
    }
    if (isdatanull==0){
        cout<<"��������"<<endl;
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
    cout << "����ͳ�ƣ�" << endl;
    cout << "���۳��̲�����: " << totalsell << endl;
    cout << "������: " << totalget << endl;
}


void textbook::store_info() {
    cout << endl;
    int isdatanull=0;
    cout<<"  �鼮����  "<<" ���� "<<" ��λ�� "<<endl<<endl;
    for (int i = 0; i < datalocation; i++){
        if (textbook_all[i]!=NULL){
            isdatanull=1;
            cout << textbook_all[i]->name << "   ";
            cout << textbook_all[i]->num << "       ";
            cout << textbook_all[i]->store << endl;
        }

    }
    if (isdatanull==0) {
        cout << "���鼮����" << endl;
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
                cout<<"�ֿ⣺"<<textbook_all[i]->store<<"�� "<<textbook_all[i]->name<<" ��治��ʮ����";
                isbookwarn=1;
            }
        }
    }
    if (isbookwarn==0 && isdatanull==1){
        cout<<"ͼ�������"<<endl;
    }
    if (isdatanull==0){
        cout<<"��������"<<endl;
    }
    cout << endl;


}



void textbook::save() {
    if(isdatachange==0){
        cout<<"����δ���޸�"<<endl;
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
    cout<<"����ɹ�"<<endl;

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
    
//�鼮�����ļ���ȡ    
    
    cout<<"���ڶ�ȡ�鼮�����ļ�"<<endl;
    bookf.open(datapath, ios::in);
    if (bookf.is_open()==0) {
        cout << "δ�ҵ��鼮�����ļ�" << endl;
        isdataempty = 1;
        bookf.close();
    } else {
        char c;
        bookf.get(c);
        if (bookf.eof()) {
            isdataempty = 1;
            cout << "�鼮�����ļ�Ϊ��" << endl;
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
        cout<<"�鼮�����ļ���ȡ���"<<endl;
    }else {
        datalocation=0;
    }

//�����¼�ļ���ȡ
    
    cout<<"���ڶ�ȡ�����¼�ļ�"<<endl;
    buyf.open(buypath, ios::in);
    if (buyf.is_open()==0) {
        cout << "δ�ҵ������¼�ļ�" << endl;
        isbuyempty = 1;
        buyf.close();
    } else {
        char c;
        buyf.get(c);
        if (buyf.eof()) {
            isbuyempty = 1;
            cout << "�����¼�ļ�Ϊ��" << endl;
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
        cout<<"�����¼�ļ���ȡ���"<<endl;
    }else {
        buylocation=0;
    }

//��ȡ���ۼ�¼�ļ�

    cout<<"���ڶ�ȡ���ۼ�¼�ļ�"<<endl;
    sellf.open(sellpath, ios::in);
    if (sellf.is_open()==0) {
        cout << "δ�ҵ����ۼ�¼�ļ�" << endl;
        issellempty = 1;
        sellf.close();
    } else {
        char c;
        sellf.get(c);
        if (sellf.eof()) {
            issellempty = 1;
            cout << "���ۼ�¼�ļ�Ϊ��" << endl;
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
        cout<<"���ۼ�¼�ļ���ȡ���"<<endl;
    }else {
        selllocation=0;
    }
}

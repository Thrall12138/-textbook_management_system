#include "book.h"

int main() {
    int func = 0;
    textbook book;
    while (1) {
        cout << "1.����ϵͳ��2.����ϵͳ��3.ͳ��ϵͳ��4.������ϵͳ��5.���棬6.�˳�" << endl;
        if (cin >> func && func>0 && func<7) {

            switch (func) {
                case 1:
                    cout << "1.������Ϣ�Ǽ�,2.������Ϣ��ѯ" << endl;
                    cin >> func;
                    if (func == 1) { book.buy_book(); }else
                    if (func == 2) { book.buy_serch(); }else
                    { cout << "�����������������" << endl; }
                    break;
                case 2:
                    cout << "1.����¼��,2.������Ϣ��ѯ" << endl;
                    cin >> func;
                    if (func == 1) { book.sell_book(); }else
                    if (func == 2) { book.sell_serch(); }else
                    { cout << "�����������������" << endl; }
                    break;
                case 3:
                    cout << "1.ÿ��ͳ�� 2.����λ��ͳ�� 3.����ͳ��" << endl;
                    cin >> func;
                    if (func == 1) { book.day_stats(); }else
                    if (func == 2) { book.store_stats(); }else
                    if (func == 3) { book.sell_stats(); }else
                    { cout << "�����������������" << endl; }
                    cout<<endl;
                    break;
                case 4:
                    cout << "1.�����Ϣ 2.���Ԥ��" << endl;
                    cin >> func;
                    if (func == 1) { book.store_info(); }else
                    if (func == 2) { book.store_check(); }else
                    { cout << "�����������������" << endl; }
                    cout<<endl;
                    break;
                case 5:
                    book.save();
                    cout<<endl;
                    break;
                case 6:
                    return 0;
                    break;

            }

        }else{
            cin.clear();
            cin.ignore(1024,'\n');
            cout << "�����������������" << endl;
        }
    }

}



//ĸ��Ĳ����� 100 15 2023/06/26 1 100
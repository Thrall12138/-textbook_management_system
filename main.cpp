#include "book.h"

int main() {
    int func = 0;
    textbook book;
    while (1) {
        cout << "1.订购系统，2.出售系统，3.统计系统，4.库存管理系统，5.保存，6.退出" << endl;
        if (cin >> func && func>0 && func<7) {

            switch (func) {
                case 1:
                    cout << "1.订购信息登记,2.订购信息查询" << endl;
                    cin >> func;
                    if (func == 1) { book.buy_book(); }else
                    if (func == 2) { book.buy_serch(); }else
                    { cout << "输入错误，请重新输入" << endl; }
                    break;
                case 2:
                    cout << "1.出售录入,2.销售信息查询" << endl;
                    cin >> func;
                    if (func == 1) { book.sell_book(); }else
                    if (func == 2) { book.sell_serch(); }else
                    { cout << "输入错误，请重新输入" << endl; }
                    break;
                case 3:
                    cout << "1.每日统计 2.按库位号统计 3.销售统计" << endl;
                    cin >> func;
                    if (func == 1) { book.day_stats(); }else
                    if (func == 2) { book.store_stats(); }else
                    if (func == 3) { book.sell_stats(); }else
                    { cout << "输入错误，请重新输入" << endl; }
                    cout<<endl;
                    break;
                case 4:
                    cout << "1.库存信息 2.库存预警" << endl;
                    cin >> func;
                    if (func == 1) { book.store_info(); }else
                    if (func == 2) { book.store_check(); }else
                    { cout << "输入错误，请重新输入" << endl; }
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
            cout << "输入错误，请重新输入" << endl;
        }
    }

}



//母猪的产后护理 100 15 2023/06/26 1 100
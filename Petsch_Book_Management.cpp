#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <limits>

using namespace std;

void control();

class Petsch_Book_Management
{
public:
    int book_id, price, count = 0, numbook;
    char book_name[50], fname[20], sname[20];

    void homepage();
    void display_book();
    void add_book();
    void search_book();
    void update_book();
    void delete_book();
};

class customer
{
public:
    char phone[20], fname[20], sname[20], city[20], dob[20], email[20], unique_id;
    void chome();
    void search_customer();
    void add_customer();
    void update_customer();
    void delete_customer();
};

class order
{
public:
    int quantity;
    char bookn[20], fname[20], sname[20],order_id[20];
    void order_home();
    void enter_order();
    void history_order();
    void modify_order();
    void search_order();
    void delete_order();
};

void order ::order_home()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\tPetsch Book Collection\n\n\n";

    cout << "   1.ENTER ORDER" << endl;
    cout << "   2.VIEW ORDER HISTORY" << endl;
     cout << "   3.MODIFY ORDER" << endl;
    cout << "   4.SEARCH ORDER" << endl;
     cout << "   5.MAIN MENU" << endl;
     cout << "   6.EXIT" << endl;
}
//o1
void order ::enter_order()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\tPetsch Book Collection\n";

    fstream order;

    cout << "  ENTER QUANTITY : ";
    cin >> quantity;
    cout << "\n\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "  ENTER AUTHOR FIRST NAME : ";
    cin >> fname;
    cout << "\n\n";

    cout << "  ENTER AUTHOR LAST NAME : ";
    cin >> sname;
    cout << "\n\n";

    cout << "  ENTER BOOK NAME : ";
    cin >> bookn;
    cout << "\n\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "  ENTER ORDER ID : ";
    cin >> order_id;
    cout << "\n\n";

    order.open("D:// order.txt", ios::out | ios::app);
    order << " " << quantity
          << " " << fname << " " << sname << " " << bookn << " "<< order_id <<"\n";

    order.close();
}
//o2
void order::history_order()
{
    system("cls");
    int sr = 0;
    fstream order;
    cout << "\t\t\t\t\t\tPetsch Book Collection\n\n\n";

    order.open("D:// order.txt", ios::in);

    if (!order)
    {
        cout << "\n\nFile Opening Error!";
    }

    else
    {
        cout << "  BOOK NAME\t   "
             << "  AUTHOR  NAME\t\t\t"
             << "  QUANTITY\t\t\t"
             << "  ORDER ID\t\n\n";

        order >>quantity;
        order >> fname >> sname;
        order >> bookn >> order_id;

        while (!order.eof())
        {

            cout << "  " << bookn << "\t   "
                 << "  " << fname << " " << sname <<"\t\t\t\t"
                 << "  " << quantity << "    \t\t\t"
                 << "  " << order_id << "    \t\t\n\n";

            order >> quantity;
            order >> fname >> sname;
            order >> bookn >>  order_id;
        }
        cout << "\n\n\n\n\n";
        system("pause");

        order.close();
    }
}
//o3
void order::modify_order()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\tPetsch Book Collection\n";

    fstream order, order1;

    int tquantity,count =0;
    char tbookn[20], tfname[20], tsname[20], key[20];

    order1.open("D:// order1.txt", ios::app | ios::out);

    order.open("D:// order.txt", ios::in);

    if (!order)
    {
        cout << "\n\nFile Opening Error!";
    }

    else
    {
        cout << "\n\n ORDER ID : ";
        cin >> order_id;

        order >> quantity >> fname >> sname >> bookn >> key;

        while (!order.eof())
        {
            if (order_id == key)
            {
                cout << "  ENTER QUANTITY : ";
                cin >> tquantity;
                cout << "\n\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "  ENTER AUTHOR FIRST NAME : ";
                cin >> tfname;
                cout << "\n\n";

                cout << "  ENTER AUTHOR LAST NAME : ";
                cin >> tsname;
                cout << "\n\n";

                cout << "  ENTER BOOK NAME : ";
                cin >> tbookn;
                cout << "\n\n";

                order1 << " " << tquantity << " " << tfname << " " << tsname << " " << tbookn <<  " " << key <<  "\n";
                count++;
            }
            else
            {
                order1 << " " << quantity
                      << " " << fname << " " << sname << " " << bookn << " " << key << "\n";
            }

            order >> quantity >> fname >> sname >> bookn >> key;
        }
        if (count == 0)
        {
            cout << "\n\n ORDER NOT FOUND\n";
        }
    }
    cout << endl;
    system("pause");

    order.close();
    order1.close();
    remove("D:// order.txt");
    rename("D:// order1.txt", "D:// order.txt");
}

//o4
void order::search_order()
{
    system("cls");
    fstream order;
    int  ptr = 0;
    char id[20], key[20];

    cout << "\t\t\t\t\t\tPetsch Book Collection\n\n\n\n\n\n";

    order.open("D:// bookdata.txt", ios::in);
    if (!order)
    {
        cout << "\n\nFile not found";
    }

    else
    {
        cout << "\n\nEnter order ID : ";
        cin >> id;
        cout << "\n\n\n\n";

        order >> quantity >> fname >> sname >> bookn >> order_id;

        while (!order.eof())
        {
            if (id == order_id)
            {
                system("cls");
                cout << "\t\t\t\t\t\tPetsch Book Collection\n";
                cout << "order found\n\n";
                cout << "  ORDER ID : " << id << endl;
                cout << "  BOOK NAME : " << bookn << endl;
                cout << "  AUTHOR NAME : " << fname << " " << sname << endl;
                cout << "  QUANTITY : " << quantity << endl;
                ptr++;
                break;
            }

            else
            {
                cout << "Book ID " << id << " not found in Inventory";
            }
            order >> quantity >> fname >> sname >> bookn >> order_id;
        }
        cout << "\n\n\n\n";
        system("pause");
        order.close();
        if (ptr == 0)
        {
            cout << "\n\nBook ID Not Found...\n\n";
        }
    }
}

//o
void order_main()
{

    system("cls");
    order o ;
    cout << "\n\n\t\t\t\t\t\tPetsch Book Collection\n\n\n";
    int k;
    char asd;

    while (1)
    {
        o.order_home();
        cout << "\n\n\n";
        cout << "ENTER OPTION : ";
        cin >> k;

        switch (k)
        {
        case 1:
            do
            {
                o.place_order();
                cout << "PLACE ANOTHER ORDER (y/n) : " ;
                cin >> asd;

            } while (asd == 'y');
            break;

        case 2:
            o.history_order();
            break;

        case 3:
            o.modify_order();
            break;

        case 4:
            o.search_order();
            break;

        case 5:
            control();
            break;

        case 6:
            cout << "\n\nEXIT PROGRAM? (y/n) : ";
            cin >> asd;
            if (asd == 'y')
            {
                cout << "\nPROGRAM TERMINATED\n\n\n\n\n\n\n\n\n\n\n";
                exit(0);
            }
            break;

        default:
            cout << "\n\nINVALID OPTION\n";
            break;
        }
    }
}
//c1
void customer ::chome()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\tPetsch Book Collection\n\n\n";

    cout << "  1.SEARCH CUSTOMER" << endl;
    cout << "  2.ADD CUSTOMER" << endl;
    cout << "  3.DELETE CUSTOMER" << endl;
    cout << "  4.UPADATE CUSTOMER DETAILS" << endl;
    cout << "  5.MAIN MENU" << endl;
    cout << "  6.EXIT" << endl;
}
//c2
void customer ::search_customer()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\tPetsch Book Collection\n";

    fstream cusdt;
    int count = 0;
    char st, search_id;

    cusdt.open("D:// cusdt.txt", ios::in);
    if (!cusdt)
    {
        cout << "\n\nFile Opening Error!";
    }

    else
    {
        cout << "\n\n UNIQUE ID : ";
        cin >> search_id;
        cout << "\n\n\n\n";
        cusdt >> unique_id >> fname >> sname >> phone >> dob >> city >> email;

        while (!cusdt.eof())
        {
            if (search_id == unique_id)
            {
                cout << "  FIRST NAME : " << fname;
                cout << "\n\n";
                cout << "  LAST NAME : " << sname;
                cout << "\n\n";
                cout << "  MOBILE NUMBER : " << phone;
                cout << "\n\n";
                cout << "  DATE OF BIRTH (DD/MM/YYY) : " << dob;
                cout << "\n\n";
                cout << "  CITY OF REGISTRATION : " << city;
                cout << "\n\n";
                cout << "  E-MAIL : " << email;
                cout << "\n\n";
                count++;
                break;
            }

            cusdt >> unique_id >> fname >> sname >> phone >> dob >> city >> email;
        }
        cout << "\n\n\n";
        cusdt.close();
        if (count == 0)
        {
            cout << "\n\nCUSTOMER NOT REGESTERED\n\n";
        }
    }
    system("pause");
}
//c3
void customer ::add_customer()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\tPetsch Book Collection\n";

    fstream cusdt;

    cout << "  ASSIGN UNIQUE ID : ";
    cin >> unique_id;
    cout << "\n\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "  ENTER FIRST NAME : ";
    cin >> fname;
    cout << "\n\n";

    cout << "  ENTER LAST NAME : ";
    cin >> sname;
    cout << "\n\n";

    cout << "  ENTER MOBILE NUMBER : ";
    cin >> phone;
    cout << "\n\n";

    cout << "  ENTER DATE OF BIRTH (DD/MM/YYY) : ";
    cin >> dob;
    cout << "\n\n";

    cout << "  PLACE OF REGISTRATION : ";
    cin >> city;
    cout << "\n\n";

    cout << "  ENTER E-MAIL : ";
    cin >> email;
    cout << "\n\n";

    cusdt.open("D:// cusdt.txt", ios::out | ios::app);
    cusdt << " " << unique_id
          << " " << fname << " " << sname << " " << phone << " " << dob << " " << city << " " << email << "\n";

    cusdt.close();
}
//c4
void customer ::update_customer()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\tPetsch Book Collection\n";

    fstream cusdt, cusdt1;
    int count = 0;
    char st, search_id, nfname[20], nsname[20], nphone[20], nemail[20];
    cusdt1.open("D:// cusdt1.txt",
                ios::app | ios::out);
    cusdt.open("D:// cusdt.txt", ios::in);

    if (!cusdt)
    {
        cout << "\n\nFile Opening Error!";
    }

    else
    {
        cout << "\n\n UNIQUE ID : ";
        cin >> unique_id;

        cusdt >> search_id >> fname >> sname >> phone >> dob >> city >> email;

        while (!cusdt.eof())
        {
            if (unique_id == search_id)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "  ENTER NEW FIRST NAME : ";
                cin >> nfname;
                cout << "\n\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "  ENTER NEW LAST NAME : ";
                cin >> nsname;
                cout << "\n\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "  ENTER NEW MOBILE NUMBER : ";
                cin >> nphone;
                cout << "\n\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "  ENTER NEW E-MAIL : ";
                cin >> nemail;
                cout << "\n\n";

                cusdt1 << " " << unique_id
                       << " " << nfname << " " << nsname << " " << nphone << " "
                       << " " << dob << " " << city << " " << nemail << "\n";
                count++;
            }

            else
            {
                cusdt1 << " " << search_id
                       << " " << fname << " " << sname << " " << phone << " " << dob << " " << city << " " << email << "\n";
            }

            cusdt >> search_id >> fname >> sname >> phone >> dob >> city >> email;
        }

        if (count == 0)
        {
            cout << "\n\nCUSTOMER NOT FOUND\n";
        }
    }
    cout << endl;
    system("pause");

    cusdt.close();
    cusdt1.close();
    remove("D:// cusdt.txt");
    rename("D:// cusdt1.txt", "D:// cusdt.txt");
}

//5
void customer ::delete_customer()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\tPetsch Book Collection\n";

    fstream cusdt, cusdt1;
    int count = 0, search_id;

    cusdt1.open("D:// cusdt1.txt",
                ios::app | ios::out);
    cusdt.open("D:// cusdt.txt", ios::in);

    cout << "\n\n UNIQUE ID : ";
    cin >> search_id;

    if (!cusdt.eof())
    {
        cout << "\n\nFile Opening Error!";
    }
    while (!cusdt.eof())
    {
        if (search_id == unique_id)
        {
            system("cls");
            cout << "LMAO CUSTOMER DELETED";
            count++;
        }

        else
        {
            cusdt1 << " " << unique_id
                   << " " << fname << " " << sname << " " << phone << " " << dob << " " << city << " " << email << "\n";
        }
        cusdt >> unique_id >> fname >> sname >> phone >> dob >> city >> email;
    }
    char st;
    if (count == 0)
    {
        cout << "\n\nCUSTOMER NOT FOUND\n";
        cout << "\n\nCUSTOMER NOT REGESTERED\n\n";
        cout << "REGISTER THE CUSTOMER? (y/n) : ";
        cin >> st;
        cout << "\n\n\n";
        if (st == 'y')
        {
            add_customer();
        }
    }

    cout << "\n\n";
    system("pause");

    cusdt.close();
    cusdt1.close();
    remove("D:// cusdt.txt");
    rename("D:// cusdt1.txt",
           "D:// cusdt.txt");
}

//main
void customer_main()
{
    system("cls");
    cout << "\t\t\t\t\t\tPetsch Book Collection\n\n\n";

    int opt;
    char ans;
    cout << "\n\n\n";

    customer c;
    while (1)
    {

        c.chome();
        cout << "\n\n\nChoose option : ";
        cin >> opt;
        cout << "\n\n\n";
        switch (opt)
        {
        case 1:
            do
            {
                c.search_customer();
                cout << "SEARCH FOR ANOTHER CUSTOMER? (y/n) : ";
                cin >> ans;

            } while (ans == 'y');
            break;

        case 2:
            do
            {
                c.add_customer();
                cout << "ADD ANOTHER CUSTOMER? (y/n) : ";
                cin >> ans;
            } while (ans == 'y');
            break;

        case 3:
            do
            {
                c.delete_customer();
                cout << "DELETE ANOTHER CUSTOMER? (y/n) : ";
                cin >> ans;
            } while (ans == 'y');
            break;

        case 4:
            do
            {
                c.update_customer();
                cout << "UPDATE ANOTHER CUSTOMER? (y/n) : ";
                cin >> ans;
            } while (ans == 'y');
            break;

        case 5:
            control();
            break;

        case 6:
            cout << "\n\nEXIT PROGRAM? (y/n) : ";
            cin >> ans;
            if (ans == 'y')
            {
                cout << "\nPROGRAM TERMINATED\n\n\n\n\n\n\n\n\n\n\n";
                exit(0);
            }
            break;

        default:
            cout << "\n\nINVALID OPTION\n";
            break;
        }
    }
    cout << "\n\n\n";
    system("pause");
}

void Petsch_Book_Management ::homepage()
{
    system("cls");
    cout << "\t\t\t\t\t\tPetsch Book Collection\n";
    cout << "\t\t\t\t\t\t  Admin login\n\n\n";

    cout << "  1.SHOW ALL BOOKS" << endl;
    cout << "  2.ADD BOOK" << endl;
    cout << "  3.SEARCH BOOK" << endl;
    cout << "  4.UPADATE BOOK DETAILS" << endl;
    cout << "  5.DELETE BOOK" << endl;
    cout << "  6.CUSTOMER DETAILS" << endl;
    cout << "  7.ORDERS" << endl;
    cout << "  8.EXIT" << endl;
}
//1

void Petsch_Book_Management ::display_book()
{
    system("cls");

    Petsch_Book_Management b;

    int sr = 0;
    fstream bookdata;
    cout << "\t\t\t\t\t\tPetsch Book Collection\n";

    bookdata.open("D:// bookdata.txt", ios::in);

    if (!bookdata)
    {
        cout << "\n\nFile Opening Error!";
    }

    else
    {
        cout << "  Book ID\t   "
             << "  Title\t\t\t\t"
             << "  Author\t\t"
             << "  Price\t\t"
             << "  Availability\n\n";

        bookdata >> book_id;
        bookdata >> book_name >> fname >> sname;
        bookdata >> price >> numbook;

        while (!bookdata.eof())
        {

            cout << "  " << book_id << "\t\t   "
                 << "  " << book_name << "\t\t\t\t"
                 << "  " << fname << " " << sname << "\t\t"
                 << "  " << price << "    \t\t"
                 << "  " << numbook << "\t\t\n\n";

            bookdata >> book_id;
            bookdata >> book_name >> fname >> sname;
            bookdata >> price >> numbook;
            sr++;
        }
        cout << "\n\n\n\n\n";
        system("pause");

        bookdata.close();
    }
}

//2
void Petsch_Book_Management ::add_book()
{
    system("cls");
    fstream bookdata;

    cout << "\t\t\t\t\t\tPetsch Book Collection\n";

    cout << "  Enter Book ID : ";
    cin >> book_id;
    cout << "\n\n";

    cout << "  Enter Book Name : ";
    cin >> book_name;
    cout << "\n\n";

    cout << "  Enter Author First Name : ";
    cin >> fname;
    cout << "\n\n";

    cout << "  Enter Author Last Name : ";
    cin >> sname;
    cout << "\n\n";

    cout << "  Enter Price : ";
    cin >> price;
    cout << "\n\n";

    cout << "  Available Piece : ";
    cin >> numbook;
    cout << "\n\n";

    bookdata.open("D:// bookdata.txt", ios::out | ios::app);
    bookdata << " " << book_id << " " << book_name << " " << fname << " " << sname << " " << price << " " << numbook << "\n";

    bookdata.close();
}

//3
void Petsch_Book_Management ::search_book()
{
    system("cls");
    fstream bookdata;
    int nbook, id, price, ptr = 0;

    cout << "\t\t\t\t\t\tPetsch Book Collection\n\n\n\n\n\n";

    bookdata.open("D:// bookdata.txt", ios::in);
    if (!bookdata)
    {
        cout << "\n\nFile not found";
    }

    else
    {
        cout << "\n\nEnter Book ID : ";
        cin >> id;
        cout << "\n\n\n\n";

        bookdata >> book_id;
        bookdata >> book_name >> fname >> sname;
        bookdata >> price >> numbook;

        while (!bookdata.eof())
        {
            if (id == book_id)
            {
                system("cls");
                cout << "\t\t\t\t\t\tPetsch Book Collection\n";
                cout << "Book found\n\n";
                cout << "  BOOK ID : " << book_id << endl;
                cout << "  BOOK NAME : " << book_name << endl;
                cout << "  AUTHOR NAME : " << fname << " " << sname << endl;
                cout << "  PRICE : " << price << endl;
                cout << "  AVALABILITY : " << numbook << endl;
                ptr++;
                break;
            }

            else
            {
                cout << "Book ID " << id << " not found in Inventory";
            }
            bookdata >> book_id;
            bookdata >> book_name >> fname >> sname;
            bookdata >> price >> numbook;
        }
        cout << "\n\n\n\n";
        system("pause");
        bookdata.close();
        if (ptr == 0)
        {
            cout << "\n\nBook ID Not Found...\n\n";
        }
    }
}
//4

void Petsch_Book_Management ::update_book()
{
    system("cls");
    fstream bookdata, bookdata1;

    int up_price, up_numbook, id, count = 0;
    char up_book_name[50], up_fname[20], up_sname[20];

    cout << "\n\n\t\t\t\tUpdate Book Record";
    bookdata1.open("D:// bookdata1.txt",
                   ios::app | ios::out);
    bookdata.open("D:// bookdata.txt", ios::in);

    if (!bookdata)
    {
        cout << "\n\nFile Opening Error!";
    }

    else
    {
        cout << "\n\nBook ID : ";
        cin >> book_id;

        bookdata >> id;
        bookdata >> book_name >> fname >> sname;
        bookdata >> price >> numbook;

        while (!bookdata.eof())
        {
            if (id == book_id)
            {
                // char up_book_name[50], up_fname[20], up_sname[20];
                system("cls");
                cout << "\t\t\t\t\t\tPetsch Book Collection\n";
                cout << "\t\t\t\t"
                     << "Update Book Record\n\n\n";
                cout << "  Enter Updated Book Name : ";
                cin >> up_book_name;
                cout << "\n\n";

                cout << "  Enter Updated Author First Name : ";
                cin >> up_fname;
                cout << "\n\n";

                cout << "  Enter Updated Author Last Name : ";
                cin >> up_sname;
                cout << "\n\n";

                cout << "  Enter Updated Price : ";
                cin >> up_price;
                cout << "\n\n";

                cout << "  Available Updated Piece : ";
                cin >> up_numbook;
                cout << "\n\n";

                bookdata1 << " " << book_id << " " << up_book_name << " " << up_fname << " " << up_sname << " " << up_price << " " << up_numbook << "\n";

                count++;
            }

            else
            {
                bookdata1 << " " << id << " " << book_name << " " << fname << " " << sname << " " << price << " " << numbook << "\n";
            }

            bookdata >> id >> book_name >> fname >> sname >> price >> numbook;
        }
        if (count == 0)
            cout << "\n\nBook ID " << book_id << " Not Found...";
    }
    cout << endl;
    system("pause");

    bookdata.close();
    bookdata1.close();
    remove("D:// bookdata.txt");
    rename("D:// bookdata1.txt",
           "D:// bookdata.txt");
}

//5
void Petsch_Book_Management ::delete_book()
{
    system("cls");
    fstream bookdata, bookdata1;
    int count = 0, id;

    cout << "\t\t\t\t\t\tPetsch Book Collection\n";

    bookdata1.open("D:// bookdata1.txt", ios::app | ios::out);
    bookdata.open("D:// bookdata.txt", ios::in);

    if (!bookdata)
    {
        cout << "\n\nFile Opening Error...";
    }

    else
    {
        cout << "\n\nBook ID : ";
        cin >> book_id;
        bookdata >> id;
        bookdata >> book_name >> fname >> sname;
        bookdata >> price >> numbook;

        while (!bookdata.eof())
        {
            if (book_id == id)
            {
                system("cls");
                cout << "\t\t\t\t\t\tPetsch Book Collection\n";

                cout << "\n\nBook with ID number " << book_id << " Deleted Successfully...\n\n";
                count++;
            }

            else
            {
                bookdata1 << " " << id << " " << book_name << " " << fname << " " << sname << " " << price << " " << numbook << "\n";
            }
            bookdata >> id >> book_name >> fname >> sname >> price >> numbook;
        }
        if (count == 0)
            cout << "\n\nBook with ID " << book_id << " Not Found...";
    }
    cout << "\n\n\n\n";
    system("pause");
    bookdata.close();
    bookdata1.close();
    remove("D:// bookdata.txt");
    rename("D:// bookdata1.txt",
           "D:// bookdata.txt");
}

//driver function
void control()
{
    int option;
    char x;
    Petsch_Book_Management b;

    while (1)
    {

        b.homepage();
        cout << "  Enter the option value : ";
        cin >> option;
        cout << "\n\n";
        switch (option)
        {
        case 1:
            b.display_book();
            break;

        case 2:
            do
            {
                b.add_book();
                cout << "\n\nWant to add another book? (y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;

        case 3:
            b.search_book();
            break;

        case 4:
            b.update_book();
            break;

        case 5:
            b.delete_book();
            break;

        case 6:
            customer_main();
            break;

        case 7:
            order_main();
            break;

        case 8:
            cout << "\n\nEXIT PROGRAM? (y/n) : ";
            cin >> x;
            if (x == 'y')
            {
                cout << "\nPROGRAM TERMINATED\n\n\n\n\n\n\n\n\n\n\n";
                exit(0);
            }
            break;

        default:
            cout << "  Invalid Option\n";
            system("pause");
            break;
        }
    }
}

//driver
int main()
{

    system("cls");
    control();
    return 0;
}
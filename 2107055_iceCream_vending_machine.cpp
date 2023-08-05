#include <bits/stdc++.h>
#include<conio.h>
#include <chrono>
#include <thread>
using namespace std;


int password();


const int totalType = 4;
const int totalFlavour = 4;


string arrType[totalType] = {"CONE", "KULFI", "CUP","ROLLED ICE CREAM"};
string arrFlavour[totalFlavour] = {"CHOCOLATE", "VANILA", "MANGO","STRAWBERY"};
int array_price[totalType] = {40, 35, 50,60};


class System;
class Manager;
class Order;
void control(Manager);

class Icecream
{
    string flavour;
    string type;
    int quantity;
    int price;

public:
    Icecream()
    {
        quantity = 0;
    }
    Icecream(string type, string flavour, int quantity, int price)
    {
        this->flavour = flavour;
        this->type = type;
        this->quantity = quantity;
        this->price = price;
    }
    int get_price()
    {
        return price;
    }
    int getTotal_price()
    {
        return price * quantity;
    }
    void display()
    {

        if(type=="ROLLED ICE CREAM"&&flavour=="STRAWBERY")
        {
            cout <<"\t\t\t"<< type <<"\t\t"<< flavour <<"\t"<< quantity<<" x " << get_price() <<"\t\t\t= "<< get_price()*quantity << endl;
        }
        else if(type=="ROLLED ICE CREAM"&&flavour=="VANILA")
        {

            cout <<"\t\t\t"<< type <<"\t\t"<< flavour <<"\t\t"<< quantity<<" x " << get_price() <<"\t\t\t= "<< get_price()*quantity << endl;
        }
        else if(type=="ROLLED ICE CREAM"&&flavour=="CHOCOLATE")
        {

            cout <<"\t\t\t"<< type <<"\t\t"<< flavour <<"\t"<< quantity<<" x " << get_price() <<"\t\t\t= "<< get_price()*quantity << endl;
        }
        else if(type=="ROLLED ICE CREAM"&&flavour=="MANGO")
        {

            cout <<"\t\t\t"<< type <<"\t\t"<< flavour <<"\t\t"<< quantity<<" x " << get_price() <<"\t\t\t= "<< get_price()*quantity << endl;
        }
        else if(type=="CUP"&&flavour=="CHOCOLATE"||type=="CONE"&&flavour=="CHOCOLATE"||type=="KULFI"&&flavour=="CHOCOLATE")
        {

            cout <<"\t\t\t"<< type <<"\t\t\t\t"<< flavour <<"\t"<< quantity<<" x " << get_price() <<"\t\t\t= "<< get_price()*quantity << endl;
        }
        else if(type=="CUP"&&flavour=="STRAWBERY"||type=="CONE"&&flavour=="STRAWBERY"||type=="KULFI"&&flavour=="STRAWBERY")
        {

            cout <<"\t\t\t"<< type <<"\t\t\t\t"<< flavour <<"\t"<< quantity<<" x " << get_price() <<"\t\t\t= "<< get_price()*quantity << endl;
        }
        else
        {
            cout <<"\t\t\t"<< type <<"\t\t\t\t"<< flavour <<"\t\t"<< quantity<<" x " << get_price() <<"\t\t\t= "<< get_price()*quantity << endl;
        }


    }
    friend class Order;
    friend class Manager;
};

class Order
{
    vector<Icecream> icecream_List;
    string customerName;
    float total;
    string customerNumber;

public:
    Order() {}

    void add_Icecream(string type, string flavour, int quantity, int price)
    {
        icecream_List.push_back(Icecream(type, flavour, quantity, price));
        cout << "\t\tSUCCESSFULLY ADDED" << endl;
    }
    void setName(string name)
    {
        this->customerName = name;
    }
    void setNumber(string customerNumber)
    {
        this->customerNumber=customerNumber;
    }
    void recipt()
    {
        total = 0;
        cout<<endl<<endl<<"\t\t\t\t\t       KUET ICE-CREAM VENDING MACHINE"<<endl<<endl;
        cout<<"\t\t\t--------------------------------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<endl<<"\t\t\t\t\t\t       ORDER RECIPT "<<endl;
        cout<<"\t\t\t--------------------------------------------------------------------------------"<<endl<<endl;;
        cout<<"\t\t\tNAME           : "<<customerName<<endl<<endl;
        cout<<"\t\t\tMOBILE NUMBER  : "<<customerNumber<<endl<<endl;
        cout<<"\t\t\tORDERS --"<<endl<<endl;
        cout<<"\t\t\tTYPE\t\t\t\tFLAVOUR\t\tQUANTITY\t\tcost"<<endl<<endl<<endl;
        for (Icecream i : icecream_List)
        {
            i.display();
            total += i.getTotal_price();
        }
        cout <<endl<<endl<<"\t\t\tVAT"<<"\t\t\t\t"<<"\t\t"<<"   "<<"\t\t\t= 15%"<< endl;
        cout<<endl<<endl;
        cout<<"\t\t\t--------------------------------------------------------------------------------"<<endl;
        cout<<"\t        \t\tTOTAL   \t\t\t\t\t\t\t= "<<total+total*0.15<<endl;

    }
    friend class Manager;
};

class Manager
{
    vector<Order> survey;
    int arrQuantity[totalType][totalType] = {};

public:
    Manager() { }
    void total_income()
    {
        int total_income = 0;
        for (int type = 0; type < totalType; type++)
        {
            for (int flavour = 0; flavour < totalFlavour; flavour++)
            {
                total_income += arrQuantity[type][flavour] * array_price[type];
            }
        }
        cout << "\t     TOTAL REVENUE GENERATED : " << total_income << endl;
    }
    void saveOrder(Order ord)
    {
        for (Icecream ice : ord.icecream_List)
        {
            int type, flavour;
            for (type = 0; type < totalType; type++)
            {
                if (ice.type == arrType[type])
                    break;
            }
            for (flavour = 0; flavour < totalFlavour; flavour++)
            {
                if (ice.flavour == arrFlavour[flavour])
                    break;
            }
            arrQuantity[type][flavour] += ice.quantity;
        }
    }
    void show_product_sells()
    {
        cout <<endl<<"\t\t\t----------PRODUCT DETAILS WITH REVENUE ----------"<<endl<<endl;
        int type, flavour;
        for (type = 0; type < totalType; type++)
        {
            cout << endl<<"\t\tTYPE : " << arrType[type] << endl;
            for (flavour = 0; flavour < totalFlavour; flavour++)
            {
                cout <<endl<< "\t\t - FLAVOUR : " << arrFlavour[flavour] << "\tQUANTITY : " << arrQuantity[type][flavour] ;
                cout << "\tREVENUE : " << arrQuantity[type][flavour] * array_price[type] << "\n";
            }
        }
    }
};
class System
{
    Order ord;
    string name;
    string mobile_no;
public:
    System()
    {
    }
    void menu(Manager &mn)
    {
        cout <<endl<< "\t\tENTER NAME :  ";
        getline(cin,name);
        ord.setName(name);
        cout <<endl<< "\t\tENTER MOBILE NUMBER :  ";
        getline(cin,mobile_no);
        ord.setNumber(mobile_no);

        char s, d;
        cout <<endl<< "\t\t   ---- OUR PRODUCTS ----\n"<<endl;
        for(int i = 0; i<totalType; i++)
        {
            if(arrType[i]=="ROLLED ICE CREAM")
                cout <<"\t\t"<< i+1 << ". " << arrType[i] <<"\tPRICE: " << array_price[i] << "\n";
            else if(arrType[i]=="KULFI")
                cout <<"\t\t"<< i+1 << ". " << arrType[i] <<"\t\tPRICE: " << array_price[i] << "\n";
            else
                cout <<"\t\t"<< i+1 << ". " << arrType[i] <<"\t\t\tPRICE: " << array_price[i] << "\n";

        }
        cout <<endl<< "\t\t   ---- AVAILABLE FLAVOURS ----"<<endl<<endl;
        for(int i = 0; i<totalFlavour; i++)
        {
            cout <<"\t\t"<< i+1 << ". " << arrFlavour[i] << "\n";

        }
        do
        {
            takeOrder();
            cout <<endl<< "\t\tWOULD YOU LIKE TO ORDER AGAIN .";
            cout<<endl<<"\t\tIF YES PRESS (y/Y) OR PRESS (N/n) :";
            cin >> s;
            cout<<endl;
        }
        while (s == 'y' || s == 'Y');
        cout << "\t\t\tPROCESSING YOUR REQUEST...\n";

        //a processing delay
        this_thread::sleep_for(std::chrono::seconds(3));

        cout << "\t\t\tPRINTING RECIPT...\n";

        // another delay for receipt printing
        this_thread::sleep_for(chrono::seconds(2));

        cout << "\t\t\tRECIPT PRINTED SUCCESSFULLY!\n";
        ord.recipt();
        mn.saveOrder(ord);
        cout << endl<<endl<<"\t\t ENTER ANY KEY TO EXIT : ";
        cin >> d;
    }
    void takeOrder()
    {
        cout<<endl;
        int command_type, command_flavour, command_quantity;
        for(int i = 0; i<totalFlavour; i++)
        {
            cout <<"\t\t\tPRESS "<<i+1 << " FOR " << arrFlavour[i] <<" FAVORES "<<endl;

        }
        cout <<endl<< "\t\tENTER YOU FAVOURITE FLAVOUR : ";
        cin >> command_flavour;
        cout<<endl;
        for(int i = 0; i<totalFlavour; i++)
        {
            cout <<"\t\t\tPRESS "<<i+1 << " FOR " << arrType[i] <<" TYPES "<<endl;
        }
        cout <<endl<<  "\t\tENTER YOU FAVOURITE TYPE : ";
        cin >> command_type;
        cout<<endl;
        cout <<endl<<  "\t\tENTER QUANTITY : ";
        cin >> command_quantity;
        ord.add_Icecream(arrType[command_type - 1], arrFlavour[command_flavour - 1], command_quantity, array_price[command_type - 1]);
    }
    friend class Manager;
    friend void control();
};

int main()
{

    Manager b;
    char k;
    while (true)
    {
        char s;
        cout<<endl<<"\t\t\t\t\tWELCOME TO KUET ICE-CREAM VENDING MACHINE"<<endl<<endl<<endl;
        this_thread::sleep_for(std::chrono::seconds(2));
        cout << "\t\tARE YOU A STUDENT ???" << endl<<endl;
        cout << "\t\tIF YES PTRESS (Y/y) else PRESS (n/N) : ";
        cin >> s;
        cin.ignore();
        if (s == 'y'||s == 'Y')
        {
            System x;
            x.menu(b);
        }
        else if (s == 'n'||s == 'N')
        {
            cout<<"\t\t ENTER PASSWORD : ";
            if(password()==1)
            {
                cout <<endl<<endl<<"\t\t\tWELCOME TO KUET VENDING MACHINE CONTROL PANNEL " << endl<<endl;
                cout<<endl<<"\t    PRESS 1 TO SEE TOTAL REVENUE"<<endl;
                cout<<"\t    PRESS 2 TO SEE SOLD PRODUCTS WITH QUANTITY"<<endl;
                cout<<"\t    ENTER : ";
                cin>>s;
                if(s=='1')
                {
                    b.total_income();
                }
                else if(s=='2')
                {
                    b.show_product_sells();
                }
                do
                {
                    this_thread::sleep_for(std::chrono::seconds(2));
                    cout<<endl<<endl<<"\t\t\t\t WOULD YOU LIKE TO CHECK AGAIN ? "<<endl;
                    cout<<endl<<endl<<"\t\t\t\t IF YES PRESS(y/Y) OR PRESS(N/n)  :  ";
                    cin>>s;
                    if(s=='y')
                        control(b);
                }
                while(s=='y'&&s!='n');
            }
            else
                cout<<"\t  WRONG PASSWORD ! \n TRY FROM BEGINNING"<<endl;
        }
        if (s == 'y'||s == 'Y')
        {
            system("cls");
            cout<<endl<<endl<<"\t\t\t-----------THANKS FOR USING KUET VENDING MACHINE-----------"<<endl<<endl;
            cout<<"\t\t\t\t         HAVE A NICE DAY  !!!! "<<endl;
        }
        cout <<endl<< "\t\t\t ENTER ANY KEY TO EXIT : ";
        cin >> k;
        system("cls");
    }
    return 0;
}
void control(Manager b)
{
    char s;
    cout<<" \t    PRESS 1 TO SEE TOTAL REVENUE"<<endl;
    cout<<" \t    PRESS 2 TO SEE SOLD PRODUCTS WITH QUANTITY"<<endl<<endl;
    cout<<" \t    ENTER : ";
    cin>>s;

    if(s=='1')
    {
        b.total_income();
    }
    else if(s=='2')
    {
        b.show_product_sells();
    }
}
int password()
{
    const string correctPassword = "one";
    string enteredPassword;
    char ch;
    while ((ch = _getch()) != 13)
    {
        if (ch == 8)
        {
            if (!enteredPassword.empty())
            {
                enteredPassword.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            enteredPassword.push_back(ch);
            cout << '*';
        }
    }

    cout << endl;

    if (enteredPassword == correctPassword)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;
void login();
void signup();
void forgot();

int main()
{
    int option;
    cout<<" ***---*** Welcome to Login Page ***---***\n";
    cout<<"1. Login\n";
    cout<<"2. Sign Up\n";
    cout<<"3. Forgot Password/Username\n";
    cout<<"4. Exit\n";
    cout<<"Choose your Option: ";
    cin>>option;
    switch(option){
        case 1:
            login();
            break;
        case 2:
            signup();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"Thanks for using this Logon Page\n";
            break;
        default:
            cout<<"Wrong Option selected";
            main();
    }
}

void signup(){
    string reguser, regpass;
    system("cls");
    cout<<"Enter the new Username: ";
    cin>>reguser;
    cout<<"Enter the new Password: ";
    cin>>regpass;

    ofstream reg("database.txt", ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"Sign Up is Successful\n";
    main();
}

void login(){
    int exist;
    string user, pass, u, p;
    system("cls");
    cout<<"Enter the Username: ";
    cin>>user;
    cout<<"Enter the Password: ";
    cin>>pass;

    ifstream input("database.txt");

    while (input>>u>>p)
    {
        if(u==user && p==pass){
            exist=1;
            system("cls");
        }
    }
    input.close();
    if(exist==1){
        cout<<"Hello "<<user<<"\nWe're pleased to welcome you Onboard\nYou have successfully Logged In\n";
        cin.get();
        cin.get();
        main();
    }
    else{
        cout<<"Error!! Username or Password is incorrect. ";
        cin.get();
        cin.get();
        main();
    }
    
}

void forgot(){
    int op;
    system("cls");
    cout<<"Forgotten your Username or Password! We're here to help\n";
    cout<<"1. Access your account by Username\n";
    cout<<"2. Access your account by Password\n";
    cout<<"3. Main Menu\n";
    cout<<"Choose your option: ";
    cin>>op;

    switch(op){
        case 1:
        {
            int ex=0;
            string searchuser, su1, sp1;
            cout<<"Enter the Username you remember:";
            cin>>searchuser;

            ifstream searchu("database.txt");
            while (searchu>>su1>>sp1)
            {
                if(su1==searchuser){
                    ex=1;
                    break;
                }
            }
            searchu.close();
            if(ex==1){
                cout<<"Congo! Your account found!\n";
                cout<<"Your Password is "<<sp1;
                cin.get();
                cin.get();
                main();
            }
            else{
                cout<<"Sorry, The account was not registered with us.\n";
                cin.get();
                cin.get();
                main();
            }
            break;
        }
        case 2:
        {
            int exi=0;
            string searchpass, su2, sp2;
            cout<<"Enter the password you remember: ";
            cin>>searchpass;

            ifstream searchp("database.txt");
            while(searchp>>su2>>sp2)
            {
                if(sp2==searchpass){
                exi=1;
                break;
                }
            }
            searchp.close();
            if(exi==1){
            cout<<"Congo! Your account found!\n";
            cout<<"Your Username is: "<<su2;
            cout<<"\nYour Password is: "<<sp2;
            cin.get();
            cin.get();
            main();
            }
            break;
        }
    case 3:
    {
        main();
        break;
    }
    default:
        {
            cout<<"Wrong option selected. Please try again by pressing any key.";
            cin.get();
            cin.get();
            forgot();
        }
    }
}

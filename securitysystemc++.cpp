#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    int a,i=0;
    string text,old, password1, password2, pass, name,password0, age, user, word,word1;
    string creds[2],cp[2];

cout<<"    security system "<<endl;

cout<<"__________"<<endl<<endl;
cout<<"|       1.Register         |"<<endl;
cout<<"|       2.Login            |"<<endl;
cout<<"|       3.Change Password  |"<<endl;
cout<<"|_4.End Program____|"<<endl<<endl;

do{
    cout<<endl<<endl;
    cout<<"enter your choice:-";
    cin>>a;
    switch(a)
    {

        case 1:{
            cout<<"______________"<<endl<<endl;
            cout<<"|-----------------Register----------------|"<<endl;
            cout<<"|_______________|"<<endl<<endl;
            cout<<"please enter username:- ";
            cin>>name;
            cout<<"please enter password:- ";
            cin>>password0;
            cout<<"please enter your age:- ";
            cin>>age;

            ofstream of1;
            of1.open("file.txt");
            if(of1.is_open()){
                of1<<name<<"\n";
                of1<<password0;
                cout<<"Registeration successful"<<endl;
                }
        break;
        
        }
        
        case2:{

            i=0;

            cout<<"______________"<<endl<<endl;
            cout<<"|-----------------Login-------------------|"<<endl;
            cout<<"|_______________|"<<endl<<endl;

            ifstream of2;
            of2.open("file.txt");
            cout<<"please enter the username:- ";
            cin>>user;
            cout<<"please enter the password:-";
            cin>>pass;

            if(of2.is_open())
            {
                while(!of2.eof())
                {
                    while(getline(of2, text)) { 
                    istringstream iss(text);
                    iss>>word;
                    creds[i]=word;
                    i++;
                    }

                    if(user==creds[0] && pass==creds[1])
                    {
                        cout<<"---Log in successful---";
                        cout<<endl<<endl;

                        cout<<"Details: "<<endl;

                        cout<<"Username: "+name<<endl;
                        cout<<"password: "+pass<<endl;
                        cout<<"Age: "+ age<<endl;
                    }
                    else {
                        cout<<endl<<endl;
                        cout<<"Incorrect credentials"<<endl;
                        cout<<"|    1.Press 2 to Login                  |"<<endl;
                        cout<<"|    2.Press 3 to change the password    |"<<endl;
                        break;
                    }
              }
              
            }
            
                 break; 
                    }
                    case 3:{
                i=0;

                cout<<"----------------------Change password--------------------"<<endl;

                ifstream of0;
                of0.open("file.txt");
                cout<<"enter the old password:- ";
                cin>>old;

                if(of0.is_open())
                {
                    while(of0.eof())
                    {
                        while(getline(of0,text));
                        istringstream iss(text);
                        iss>>word1;
                        cp[i]=word1;
                        i++;
                    }

                    if(old==cp[1])
                    {
                        of0.close();

                        ofstream of1;
                        if(of1.is_open())
                        {
                        	cout<<"enter your new password:-";
                            cin>>password1;
                            cout<<" enter your password again:-";
                            cin>>password2;

                           if(password1==password2) 
                           {
                            of1<<cp[0]<<"\n";
                            of1<<password1;
                            cout<<"password change successfully"<<endl;
                           }

                           else{
                            of1<<cp[0]<<"\n";
                            of1<<old;
                            cout<<"password do not match"<<endl;
                           }
                        }
                    }
                    else{
                        cout<<"please enter a valid password "<<endl;
                        break;
                    }
                    }
                }

                break;
                }
                case4 :
                {
                    cout<<"___Thank you!___";
                    break; ;
                }
                
                cout<<"enter a valid choice";
    
    }
while(a!=4);
return 0;
}
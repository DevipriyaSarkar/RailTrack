#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <process.h>
class train
{   long PNR_no;
    int amount, tno, clas, distance, nos, age[6], i;
    int con, child, senior;
    char tname[50], bpt[50], dpt[50], pname[6][50], date[20];
public:
    train()
    {   con=child=senior=PNR_no=0;
    }

    float calc_fare()
    {   float f1, f2, fare;
        if (distance<1000)
            f1=200;
        else if (distance<5000)
            f1=500;
        else
            f1=1000;

        f2=(f1*nos)-(f1*0.2*con)-(f1*0.5*senior)-(f1*child);

        if (clas==3)
            fare=f2;
        else if (clas==2)
            fare=1.5*f2;
        else
            fare=2*f2;

        if (fare<0)
            fare=0;

        return(fare);
    }

    void getdetail()
    {
        cout<<"\nENTER THE DETAILS: "<<endl;
        cout<<"Train number: ";
        cin>>tno;
        cout<<"Train name: ";
        gets(tname);
        cout<<"Boarding point: ";
        gets(bpt);
        cout<<"Destination point: ";
        gets(dpt);
        cout<<"Distance (km): ";
        cin>>distance;
        cout<<"Class (Enter only 1/2/3): ";
        cin>>clas;
        cout<<"No. of seats required (not more than 6): ";
        cin>>nos;
        cout<<"Date of travel (dd-mm-yy): ";
        gets(date);
        cout<<"Enter the details of passengers: ";
        for(i=0; i<nos; i++)
        {   cout<<"\nPassenger "<<i+1<<endl;
            cout<<"Enter name: ";
            gets(pname[i]);
            cout<<"Enter age (years): ";
            cin>>age[i];
            if (age[i]<=6)
                child++;
            else if (age[i]>60)
                senior++;
        }
        cout<<"NOTE- Senior citizens are not eligible to get military concession..!!\n";
        cout<<"No. of passengers eligible for military concession (enter 0 for NIL): ";
        cin>>con;
        amount= calc_fare();
        cout<<".....END OF GETTING DETAILS!!!...."<<endl;
    }

    void dispdetail()
    {   cout<<"\n\n\n...DISPLAYING THE DETAILS..."<<endl;
        cout<<"PNR NO.: "<<PNR_no<<endl;
        cout<<"TRAIN NO.: "<<tno<<" || TRAIN NAME: "<<tname<<" || CLASS: "<<clas<<endl;
        cout<<"BOARDING POINT: "<<bpt<<" || DESTINATION POINT: "<<dpt<<" || DISTANCE: "<<distance<<endl;
        cout<<"DATE OF TRAVEL: "<<date<<endl;
        cout<<"TOTAL NO. OF PASSENGERS: "<<nos<<endl;
        cout<<"DETAILS OF PASSENGERS: "<<endl;
        for(i=0; i<nos; i++)
        {   cout<<"PASSENGER "<<i+1<<" || NAME: "<<pname[i]<<" || AGE: "<<age[i]<<endl;
        }
        cout<<"CONCESSION DETAILS: "<<endl;
        cout<<"MILITARY: "<<con<<" || CHILDREN: "<<child<<" || SENIOR: "<<senior<<endl;
        cout<<"...YOU HAVE TO PAY RS."<<amount<<"/-...\n"<<endl;
    }

    void assign_PNR()
    {   cout<<"Enter the PNR no.: ";
        cin>>PNR_no;
    }

    void modify()
    {   cout<<"OLD DETAILS:"<<endl;
        dispdetail();
        long nPNR_no;
        int ntno, nclas, ndistance, nnos, nage[6];
        char ntname[50], nbpt[50], ndpt[50], npname[6][50], ndate[20];
        i=con=child=senior=0;
        cout<<"\n...ENTER THE NEW DETAILS..."<<endl;
        cout<<"New PNR no.: (Enter -1 to retain the old one) ";
        cin>>nPNR_no;
        cout<<"New train number: (Enter -1 to retain the old one) ";
        cin>>ntno;
        cout<<"New train name: (Enter '.' to retain the old one) ";
        gets(ntname);
        cout<<"New boarding point: (Enter '.' to retain the old one) ";
        gets(nbpt);
        cout<<"New destination point: (Enter '.' to retain the old one) ";
        gets(ndpt);
        cout<<"New distance (km): (Enter -1 to retain the old one) ";
        cin>>ndistance;
        cout<<"New class (Enter only 1/2/3): (Enter -1 to retain the old one) ";
        cin>>nclas;
        cout<<"New no. of seats required(not more than 6): (Enter -1 to retain the old one) ";
        cin>>nnos;
        cout<<"New date of travel (dd-mm-yy): (Enter '.' to retain the old one) ";
        gets(date);
        cout<<"Enter the new details of passengers: ";
        if(nnos!=-1)
            nos=nnos;
        for(i=0; i<nos; i++)
        {   cout<<"Passenger "<<i+1<<endl;
            cout<<"Enter new name: (Enter '.' to retain the old one) ";
            gets(npname[i]);
            cout<<"Enter new age (years): (Enter -1 to retain the old one) ";
            cin>>nage[i];
        }
        cout<<"\nNOTE- Senior citizens are not eligible to get military concession..!!\n";
        cout<<"\nNo. of passengers eligible for military concession (enter 0 for NIL): ";
        cin>>con;
        if(nPNR_no!=-1)
            PNR_no=nPNR_no;
        if(ntno!=-1)
            tno=ntno;
        if(ndistance!=-1)
            distance=ndistance;
        if(nclas!=-1)
            clas=nclas;
        if(strcmp(ntname,".")!=0)
            strcpy(tname,ntname);
        if(strcmp(nbpt,".")!=0)
            strcpy(bpt,nbpt);
        if(strcmp(ndpt,".")!=0)
            strcpy(dpt,ndpt);
        if(strcmp(ndate,".")!=0)
            strcpy(date,ndate);
        for(i=0; i<nos; i++)
        {   if(strcmp(npname[i],".")!=0)
                strcpy(pname[i],npname[i]);
            if(nage[i]!=-1)
                age[i]=nage[i];
        }
        for(i=0; i<nos; i++)
        {   if (age[i]<=6)
                child++;
            else if (age[i]>60)
                senior++;
        }
        amount= calc_fare();
        cout<<".....END OF GETTING DETAILS!!!...."<<endl;
    }

    int ret_tno()
    {   return tno;
    }

    long ret_PNR()
    {   return PNR_no;
    }

    char* ret_tname()
    {   return tname;
    }
};

class account
{   char sname[50];
    char spass[50];

public:
    char* getusername()
    {   return sname;
    }

    char* getpassword()
    {   return spass;
    }

    void setusername(char N[])
    {   strcpy(sname, N);
    }

    void setpassword(char P[])
    {   strcpy(spass, P);
    }
};

class login
{   char id[50], password[50];
    account obj;
public:
    login(int check)
    {   fstream f;
        if(check == 1)
        {   f.close();
            strcpy(id, "ADMIN");
            strcpy(password, "PASSWORD");
            f.open("LOGIN.DAT", ios::out| ios::binary);
            f.seekp(0);
            obj.setusername(id);
            obj.setpassword(password);
            f.write((char*)&obj, sizeof(obj));
            f.close();
        }
        else
        {   f.close();
            f.open("LOGIN.DAT", ios::in| ios::binary);
            f.seekg(0);
            //read username from file
            f.read((char*)&obj, sizeof(obj));
            strcpy(id, obj.getusername());
            //read password from file
            strcpy(password, obj.getpassword());
            f.close();
        }
    }

    void changelogin()
    {   char N[50], newN[50], newP[50], P[50];
        fstream f;
        f.open("LOGIN.DAT", ios::in| ios::binary);
        f.seekg(0);
        //read username and password from file
        f.read((char*)&obj, sizeof(obj));
        strcpy(id, obj.getusername());
        strcpy(password, obj.getpassword());
        f.close();
        //ask previous username
        cout<<"\nEnter previous username: ";
        cin>>N;
        //ask previous password
        cout<<"\nEnter previous password: ";
        cin>>P;
        //if matches change username and password
        if(strcmp(N, id)==0 && strcmp(P, password)==0)
        {   cout<<"\nEnter new username: ";
            cin>>newN;
            cout<<"\nEnter new password: ";
            cin>>newP;
            //store into file
            remove("LOGIN.DAT");
            f.open("LOGIN.DAT", ios::out| ios::binary);
            f.seekp(0);
            obj.setusername(newN);
            obj.setpassword(newP);
            f.write((char*)&obj, sizeof(obj));
            f.close();
            strcpy(id, newN);
            strcpy(password, newP);
        }
        else
        {   cout<<"\nUsername and/or Password doesn't match!\n";
        }
    }

    int match( char N[], char P[] )
    {   if ( (strcmp(N,id)==0) && (strcmp(P,password)==0) )
            return 1;
        else
            return -1;
    }
};

class train_list
{   char destination[50], boardingpt[50], train_name[50];
    int train_num;
public:
    void disp_train()
    {   cout<<"TRAIN NUMBER: "<<train_num<<"\t TRAIN NAME: "<<train_name<<endl;
        cout<<"BOARDING POINT: "<<boardingpt<<"\t DESTINATION POINT: "<<destination<<endl;
    }

    void enter_train()
    {   cout<<"Enter train number: ";
        cin>>train_num;
        cout<<"Enter train name: ";
        gets(train_name);
        cout<<"Enter boarding point: ";
        gets(boardingpt);
        cout<<"Enter destination point: ";
        gets(destination);
        cout<<".....END OF GETTING DETAILS!!!...."<<endl;
    }

    char* getboard()
    {   return boardingpt;
    }

    char* getdest()
    {   return destination;
    }
};

void add_train()
{   train_list t;
    fstream f;
    f.open("TRAIN_LIST.DAT", ios::app|ios::binary);
    t.enter_train();
    f.write((char*)&t, sizeof(t));
    f.close();
}

void find_train()
{   fstream f;
    train_list t;
    int flag=0;
    char destpt[50], boardpt[50];
    cout<<"Enter the boarding point: ";
    gets(boardpt);
    cout<<"Enter the destination point: ";
    gets(destpt);
    f.open("TRAIN_LIST.DAT", ios::in|ios::binary);
    while( f.read((char*)&t, sizeof(t)) )
    {   if( (strcmpi(t.getboard(),boardpt)==0)&&(strcmpi(t.getdest(),destpt)==0) )
        {   t.disp_train();
            flag=1;
        }
    }
    if (flag==0)
        cout<<"DIRECT TRAIN NOT IN RECORD!!!"<<endl;
    f.close();
}

void add_data()
{   train t;
    fstream f;
    f.open("RESERVATION.DAT", ios::app|ios::binary);
    cout<<"Enter the record to be added: \n";
    t.assign_PNR();
    t.getdetail();
    f.write( (char*)&t, sizeof(t) );
    f.close();
}

void delete_data()
{   train t;
    fstream f1, f2;
    f1.open("RESERVATION.DAT", ios::in|ios::binary);
    f2.open("TEMP.DAT", ios::out|ios::binary); //temporary file
    int flag=0;
    long pno;
    cout<<"Enter PNR no. to be deleted: ";
    cin>>pno;
    while( f1.read((char*)&t, sizeof(t)))
    {   if (t.ret_PNR()==pno)
            flag=1;
        else
            f2.write((char*)&t, sizeof(t));
    }
    remove("RESERVATION.DAT");
    rename("TEMP.DAT","RESERVATION.DAT");
    if (flag==0)
        cout<<"\nThe record does not exist!!!\n";
    else
        cout<<"THE REQUIRED RECORD DELETED!!!"<<endl;
    f1.close();
    f2.close();
}

void edit_train()
{   fstream f;
    train t;
    long pos, spno;
    char found='f';
    f.open("RESERVATION.DAT", ios::in|ios::ate|ios::binary);
    cout<<"Enter the PNR no. of the ticket whose details are to be modified: ";
    cin>>spno;
    f.seekg(0);
    while(f)
    {   pos=f.tellg();
        f.read((char*)&t, sizeof(t));
        if (t.ret_PNR()==spno)
        {   t.modify();
            f.seekg(pos);
            f.write((char*)&t, sizeof(t));
            found='t';
            break;
        }
    }
    if(found=='f')
        cout<<"PNR NO. DOES NOT EXIST!!!\n";
    else
        cout<<"\n...RECORD SUCCESSFULLY MODIFIED!!!..."<<endl;
    f.close();
}

void show_fare()
{   train t;
    t.getdetail();
    t.dispdetail();
    cout<<"NOTE: This is only fare calculation. Your ticket has not been booked. Ticket can be booked only by administrator!!! \n"<<endl;
}

void search_PNR()
{   train t;
    fstream f;
    long p_num;
    int flag=0;
    cout<<"Enter the PNR no. to be searched: ";
    cin>>p_num;
    f.open("RESERVATION.DAT", ios::in|ios::binary);
    while(f.read((char*)&t, sizeof(t)))
    {   if (t.ret_PNR()==p_num)
        {   t.dispdetail();
            flag=1;
        }
    }
    if (flag==0)
        cout<<"\nPNR no. entered does not exist!!!"<<endl;
    f.close();
}

void searcht()
{   train t;
    fstream f;
    char t_name[50], c;
    int t_num, flag=0;
    cout<<"Do you know the train no.??? (Y/N): ";
    cin>>c;
    if (c=='Y'||c=='y')
    {   cout<<"Enter train no. to be searched: ";
        cin>>t_num;
    }
    else
    {   cout<<"Enter train name to be searched: ";
        gets(t_name);
    }
    f.open("RESERVATION.DAT", ios::in|ios::binary);
    while(f.read((char*)&t, sizeof(t)))
    {   if ( (t.ret_tno()==t_num) || (strcmpi(t.ret_tname(),t_name)==0) )
        {   t.dispdetail();
            flag=1;
        }
    }
    if(flag==0)
        cout<<"\nRECORD DOES NOT EXIT!!!"<<endl;
    f.close();
}

void database()
{   char N[20], P[20], ch;
    int result, opt, check;
    cout<<"ARE YOU USING FOR THE FIRST TIME..? (Y/N) ";
    cin>>ch;
    if(ch == 'Y' || ch == 'y')
        check=1;
    else
        check=0;
    if(check==1)
        cout<<"\nNOTE: Enter username as \"ADMIN\" and password as \"PASSWORD\" if logging in for the first time! \n";
    cout<<"Enter username: ";
    cin>>N;
    cout<<"Enter password: ";
    cin>>P;
    login L(check);
    result=L.match(N,P);
    if (result==1)
    {   cout<<"ACCESS ALLOWED!!! \n";
        do
        {   cout<<"\n\n\t\tADMIN MENU \n ";
            cout<<"\t1. ADD RECORD \n";
            cout<<"\t2. DELETE RECORD \n";
            cout<<"\t3. ADD TRAINS TO THE TRAIN LIST \n";
            cout<<"\t4. MODIFY A RECORD \n";
            cout<<"\t5. CHANGE USERNAME AND PASSWORD \n";
            cout<<"\t6. RETURN TO MAIN MENU \n";
            cout<<"\t7. EXIT \n";
            cout<<"\n Enter your choice: ";
            cin>>opt;
            cout<<endl;
            switch(opt)
            {
            case 1:
                add_data();
                break;
            case 2:
                delete_data();
                break;
            case 3:
                add_train();
                break;
            case 4:
                edit_train();
                break;
            case 5:
                L.changelogin();
                break;
            case 6:
                return;
            case 7:
                exit(0);
            }
        } while(opt<=7);
    }
    else if (result==-1)
    {   cout<<"ACCESS DENIED!!! \n";
        return;
    }
}

void user()
{   int choice;
    cout<<"\n\n\t\tUSER MENU\n";
    do
    {   cout<<"\t1. RESERVATION FARE CALCULATION \n";
        cout<<"\t2. DISPLAY DETAILS OF THE PASSENGER BY PNR NO. \n";
        cout<<"\t3. DISPLAY DETAILS OF THE PASSENGERS BY TRAIN NO. OR TRAIN NAME \n";
        cout<<"\t4. DISPLAY TRAINS IN BETWEEN THE GIVEN TWO STATIONS \n";
        cout<<"\t5. RETURN TO MAIN MENU \n";
        cout<<"\t6. EXIT \n";
        cout<<"\n Enter your choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
        case 1:
            show_fare();
            break;
        case 2:
            search_PNR();
            break;
        case 3:
            searcht();
            break;
        case 4:
            find_train();
            break;
        case 5:
            return;
        case 6:
            exit(0);
        }
    } while(choice<=6);
}
void main()
{   clrscr();
    int ch;
    cout<<"\t\t\tWELCOME TO RAILWAY DATABASE MANAGEMENT SYSTEM \n";
    do
    {   cout<<"\t\t MAIN MENU"<<endl;
        cout<<"\t1. ADMIN MODE \n";
        cout<<"\t2. USER MODE \n";
        cout<<"\t3. EXIT\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
            database();
            break;
        case 2:
            user();
            break;
        case 3:
            exit(0);
        }
    } while(ch<=3);
    getch();
}
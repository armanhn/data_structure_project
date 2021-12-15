#include<iostream>
#include<fstream>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

struct spambot
{
    string messageID;
    string status;
    string emailAddress;
    string subject;
    string tag;
    string date;
    string time;
    string bounceReason;


    spambot *link;
};



void InsertAtEnd(spambot *&head, spambot*& tail, string words[])
{

    spambot *newNode = new spambot;

    newNode-> messageID = words[0];
    newNode-> status = words[1];
    newNode-> emailAddress = words[2];
    newNode-> subject = words[3];
    newNode-> tag = words[4];
    newNode-> date = words[5];
    newNode-> time = words[6];
    newNode-> bounceReason= words[7];


    newNode->link = NULL;


    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {

        tail->link = newNode;
        tail = newNode;
    }
}

spambot*searchData(spambot*n,string x)
{

    while(n!=NULL)
    {
        if(n->status == x)
        {
            return n;
        }
        n=n->link;
    }
    return NULL;

}


spambot*SendingBefore(spambot* n, spambot* link)
{

    while(n!=NULL)
    {
        if(n->link == link)
            return n;

        n = n->link;
    }
    return NULL;

}

void deliveredEmailDelete(spambot*&head,spambot*n,string x)
{
    while(n!=NULL)
    {


        spambot* tobeDeleted = searchData(head, x);

        spambot* before = SendingBefore(head, tobeDeleted);

        before->link = tobeDeleted->link;

        delete tobeDeleted;
        n=n->link;
    }
}







void dEmailEntry(spambot *&head1, spambot*& tail1, string words[])
{
    string checkDelivered = "Delivered";
    if(words[1]==checkDelivered)
    {
        spambot *newNode = new spambot;



        newNode-> messageID = words[0];
        newNode-> status = words[1];
        newNode-> emailAddress = words[2];
        newNode-> subject = words[3];
        newNode-> tag = words[4];
        newNode-> date = words[5];
        newNode-> time = words[6];
        newNode-> bounceReason= words[7];


        newNode->link = NULL;


        if(head1== NULL)
        {
            head1 = newNode;
            tail1 = newNode;
        }

        else
        {

            tail1->link = newNode;
            tail1 = newNode;
        }

    }
    else
    {
        return;
    }
}




void ShowList(spambot *n)
{

    while(n != NULL)
    {
        cout << "Message ID = " << n-> messageID<<endl;
        cout <<"Status = " << n-> status<<endl;
        cout << "Email Address = " << n-> emailAddress<<endl;
        cout << "Subject = " << n-> subject<<endl;
        cout << "Tag = " << n-> tag<<endl;
        cout << "Date = " << n-> date<<endl;
        cout << "Time = " << n-> time<<endl;
        cout << "Bounce Reason = " <<  n-> bounceReason<<endl;


        cout << endl;
        n = n->link;
    }
    cout << endl;
}

void ShowDEmail(spambot *n)
{

    while(n != NULL)
    {
        cout << "Message ID = " << n-> messageID<<endl;
        cout <<"Status = " << n-> status<<endl;
        cout << "Email Address = " << n-> emailAddress<<endl;
        cout << "Subject = " << n-> subject<<endl;
        cout << "Tag = " << n-> tag<<endl;
        cout << "Date = " << n-> date<<endl;
        cout << "Time = " << n-> time<<endl;
        cout << "Bounce Reason = " <<  n-> bounceReason<<endl;

        cout << endl;
        n = n->link;
    }
    cout << endl;
}

void searchStatus(spambot*n,string statusName[])
{
    int countSmtp=0;
    int countSpamC=0;
    int countDeli=0;
    int countHard=0;
    int countIsp=0;
    int countPro=0;
    int countQue=0;
    int countSoft=0;
    int countSpamN=0;
    int countUnDeli=0;


    while(n != NULL)
    {

        if(n->status == statusName[0])
        {
            countSmtp++;
        }
        else if(n->status == statusName[1])
        {
            countSpamC++;
        }
        else if(n->status == statusName[2])
        {
            countDeli++;
        }
        else if(n->status == statusName[3])
        {
            countHard++;
        }
        else if(n->status == statusName[4])
        {
            countIsp++;
        }
        else if(n->status == statusName[5])
        {
            countPro++;
        }
        else if(n->status == statusName[6])
        {
            countQue++;
        }
        else if(n->status == statusName[7])
        {
            countSoft++;
        }
        else if(n->status == statusName[8])
        {
            countSpamN++;
        }
        else if(n->status == statusName[9])
        {
            countUnDeli++;
        }

        n = n->link;
    }

    ///Creating A dynamic Array of Size 10*2.

    string **A = new string *[10];
    for(int i=0; i<10 ; i++)
    {
        A[i]= new string [2];
    }

    ///Inserting Data In dynamic Array.

    int j=0;
    while(j<10)
    {
        ostringstream str1;/// string stream output string
        string data;   /// string to store converted data

        if(j==0)
        {

            str1 << countSmtp; /// Sending integer into string stream.
            data = str1.str(); /// stream string converting integer into string.

            A[j][0] = statusName[j];
            A[j][1] = data;
        }
        else if(j==1 )
        {
            str1 << countSpamC;
            data = str1.str();

            A[j][0] = statusName[j];
            A[j][1] = data;
        }
        else if(j == 2)
        {
            str1 << countDeli;
            data = str1.str();

            A[j][0] = statusName[j];
            A[j][1] = data;
        }
        else if(j == 3 )
        {
            str1 << countHard;
            data = str1.str();

            A[j][0] = statusName[j];
            A[j][1] = data;
        }
        else if(j == 4 )
        {
            str1 << countIsp;
            data = str1.str();

            A[j][0] = statusName[j];
            A[j][1] = data;
        }
        else if(j == 5 )
        {
            str1 << countPro;
            data = str1.str();

            A[j][0] = statusName[j];
            A[j][1] = data;
        }
        else if(j == 6 )
        {
            str1 << countQue;
            data = str1.str();

            A[j][0] = statusName[j];
            A[j][1] = data;
        }
        else if(j==7 )
        {
            str1 << countSoft;
            data = str1.str();

            A[j][0] = statusName[j];
            A[j][1] = data;
        }
        else if(j == 8 )
        {

            str1 << countSpamN;
            data = str1.str();

            A[j][0] = statusName[j];
            A[j][1] = data;
        }
        else if( j == 9 )
        {
            str1 << countUnDeli;
            data = str1.str();

            A[j][0] = statusName[j];
            A[j][1] = data;
        }

        j++;

    }

    /// Printing the Status list in 2D.


    int k=0;
    while(k<10)
    {
        char y = 205;
        char x = 186;

        char m = 187;
        char n = 188;

        if(k==0)
        {


            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<m;
            cout<<endl;
            cout<<A[k][0]<< "\t\t "<<x<<"\t\t" <<A[k][1]<<x<<endl;
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<n;
            cout<<endl;


        }
        else if(k==1 )
        {
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<m;
            cout<<endl;
            cout<<A[k][0]<< "\t\t "<<x<<"\t\t" <<A[k][1]<<x<<endl;
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<n;
            cout<<endl;
        }
        else if(k == 2)
        {
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<m;
            cout<<endl;
            cout<<A[k][0]<< "\t\t "<<x<<"\t       " <<A[k][1]<<x<<endl;
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<n;
            cout<<endl;
        }
        else if(k == 3 )
        {
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<m;
            cout<<endl;
            cout<<A[k][0]<< "\t\t "<<x<<"\t\t" <<A[k][1]<<x<<endl;
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<n;
            cout<<endl;
        }
        else if(k == 4 )
        {
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<m;
            cout<<endl;
            cout<<A[k][0]<< "\t\t "<<x<<"\t\t" <<A[k][1]<<x<<endl;
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<n;
            cout<<endl;
        }
        else if(k == 5 )
        {
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<m;
            cout<<endl;
            cout<<A[k][0]<< "\t\t "<<x<<"\t\t" <<A[k][1]<<x<<endl;
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<n;
            cout<<endl;
        }
        else if(k == 6 )
        {
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<m;
            cout<<endl;
            cout<<A[k][0]<< "\t\t\t "<<x<<"\t\t " <<A[k][1]<<x<<endl;
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<n;
            cout<<endl;
        }
        else if(k==7 )
        {
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<m;
            cout<<endl;
            cout<<A[k][0]<< "\t\t "<<x<<"\t\t " <<A[k][1]<<x<<endl;
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<n;
            cout<<endl;
        }
        else if(k == 8 )
        {
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<m;
            cout<<endl;
            cout<<A[k][0]<< "\t "<<x<<"\t\t" <<A[k][1]<<x<<endl;
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<n;
            cout<<endl;
        }
        else if( k == 9 )
        {
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<m;
            cout<<endl;
            cout<<A[k][0]<< "\t\t "<<x<<"\t\t" <<A[k][1]<<x<<endl;
            for(int i=0; i<42; i++)
            {
                cout<<y;
            }
            cout<<n;
            cout<<endl;
        }

        k++;

    }


    for(int i=0; i<10 ; i++)
    {
        delete []A[i];
    }


}

int time_conv(string time_b[]) ///  this function is Hour min sec converter, returns total sec.
{
    string s = time_b[0];

    int hour;
    istringstream(s) >> hour;

    string s1 = time_b[1];

    int minute;
    istringstream(s1) >> minute;

    string s2 = time_b[2];

    int sec;
    istringstream(s) >> sec;

    int tHour = hour*3600;
    int tMinute = minute*60;
    int tSec = tHour+tMinute+sec;


    return tSec;
}

int secondReturn(string data) /// this function initially breaks the string "6:28:41" and returns total sec.
{
    int y;
    string time_b[3];
    string x = data;
    stringstream s(x);
    int i = 0;
    while(getline(s, time_b[i], ':'))
    {
        i++;
    }

    y = time_conv(time_b);

    return y;
}


void SearchD_and_time(spambot *n,string word,string words[])
{
    string time_collector[478];
    string time_breaker[2];
    string time_dataS[478];
    int time_dataI[478];
    int difference[478];
    int sum=0;

    int c=0;
    int i=0;
    while(n != NULL)
    {


        if(n->date == word)
        {
            c++;
            time_collector[i] = n->time;
            i++;

        }
        n = n->link;
    }

    if(c>0)
    {
        cout << "On 2-Sep-2020, "<<c<<" emails were sent." ;
    }



    for(int i=0; i<478; i++)
    {

        stringstream s(time_collector[i]);
        int j = 0;
        while(getline(s, time_breaker[j], ' '))
        {
            j++;
        }

        time_dataS[i]=time_breaker[0];

    }

    for(int i = 0 ; i<478 ; i++)
    {
        string rawdata = time_dataS[i] ;   /// Converting string into integers and making 06:48:42 into seconds.
        int x;
        x=secondReturn(rawdata);
        time_dataI[i]=x;
    }

    int j = 477;
    for(int i = 478; i > 0; i--)  /// storing the  moving differences.
    {

        difference[i] = time_dataI[j] - time_dataI[i];
        j--;
    }

    for(int i =0; i < 477; i++) /// size of difference is one less than data because it has one less entry.
    {

        sum=difference[i]+sum;

    }

    int avg = sum/477;

    int time = avg;
    int hour = 0;
    int minute = 0;
    int sec = 0;

    hour = time/3600;
    time = time%3600;
    minute = time/60;
    time = time%60;
    sec = time;

    cout<<endl;
    cout<<"The average time difference between the starting operation till the end is: "<<hour<<" Hour "<<minute<<" minutes "<<sec<<" seconds."<<endl;


}


void SearchBounce(spambot *n,string words[])
{
    int c=0;
    while(n != NULL)
    {

        if(n->bounceReason == "")
        {
            c++;
        }
        n = n->link;
    }

    if(c>0)
    {
        cout <<c<<" Emails were sent without bounce." ;
    }
    cout << endl;
}



void emaildata(spambot *n,string words[])
{

    string *ArrEmail = new string [520];
    string *ArrEmailD = new string [520];
    queue <string> emailPrint;



    int k=0;
    while(n != NULL)
    {
        string email_b[2];
        string after_b[4];

        string x = n->emailAddress;
        stringstream s(x);
        int i = 0;
        while(getline(s, email_b[i], '@'))  /// Breaking words After @ .
        {
            i++;
        }

        string y = email_b[1];
        stringstream s1(y);

        int j = 0;
        while(getline(s1, after_b[j], '.'))  /// Breaking words After . .
        {
            j++;
        }



        ArrEmail[k] = after_b[0]; /// Inserting All the domain with repetition.
        k++;
        n = n->link;
    }

    for(int i=0; i<520; i++)
    {
        int c=0;
        int j=0;
        if(i==0)
        {
            ArrEmailD[i]=ArrEmail[i];/// if empty then push the data without checking.
        }
        else
        {
            while(j<520)/// checks does data exists.
            {
                if(ArrEmailD[j]==ArrEmail[i])
                {
                    c++;
                }
                j++;
            }

            if(c==0)/// if does not exist then push the data in the array.
            {
                ArrEmailD[i]=ArrEmail[i];
            }
            else
            {
                ArrEmailD[i]=" ";/// pushing space rather keeping the array empty.
            }

        }

    }
    /// putting the array data inside queue to print the data.
    for(int i=0; i<520; i++)
    {
        string data=ArrEmailD[i];
        if(data!=" ")
        {
            emailPrint.push(data);
        }
    }

    while(!emailPrint.empty())
    {
        cout<<emailPrint.front()<<endl;
        emailPrint.pop();
    }


    delete[] ArrEmail;
    delete[] ArrEmailD ;
}

void printList(spambot*&head,spambot*n,string x)
{

    deliveredEmailDelete(head,head,x);
    ShowList(head);
}



int main()
{
    string line;
    string words[8];
    string date_arr[3];
    string dateAndTime;
    string time;
    string date;
    fstream fin;
    string word = "2020-09-02";
    string statusName[10];
    string x = "Delivered";



    spambot *head = NULL;
    spambot *tail = NULL;
    spambot *head1 = NULL;
    spambot *tail1= NULL;

    fin.open("file.csv", ios::in);

    while(getline(fin, line))
    {
        stringstream s(line);

        int i = 0;
        while(getline(s, words[i], ','))
        {
            i++;
        }

        string bounce = words[6];
        words[7] = bounce ;

        dateAndTime = words[5];

        stringstream separator(dateAndTime);/// separating date and time in the pieces

        int j = 0;
        while(separator >> date_arr[j] )
        {
            j++;
        }
        string space1 = " ";
        string data = date_arr[2];

        date_arr[2] = space1.append(data);/// adding space before +6.00.
        data = date_arr[1].append (date_arr[2]); /// adding time and time zone.



        words[5] = date_arr[0];
        words[6] = data;

        char c = '"';
        string line_error;
        stringstream converterC;

        converterC <<c ;
        converterC >> line_error;

        if(words[0] != line_error)
        {
            InsertAtEnd(head, tail, words);
            dEmailEntry(head1, tail1,words);

        }


    }

    statusName[0] = "SMTP API Error";
    statusName[1] = "Spam Complaint";
    statusName[2] = "Delivered";
    statusName[3] = "Hard Bounce";
    statusName[4] = "ISP Block";
    statusName[5] = "Processed";
    statusName[6] = "Queued";
    statusName[7] = "Soft Bounce";
    statusName[8] = "Spam Notification";
    statusName[9] = "Undeliverable";



    string a;
    while( a!= "8")
    {




        char y = 177;
        cout<<"\t\t\t\t\t";
        for(int i=0; i<41; i++)
        {
            cout<<y;
        }
        cout<<endl;
        cout<<"\t\t\t\t\t"<<y<<"\t\t Menu\t\t\t"<<y<<endl;
        cout<<"\t\t\t\t\t";
        for(int i=0; i<41; i++)
        {
            cout<<y;
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;

        cout<<"1. Print Full list. "<<endl;
        cout<<"2. Print List without Delivered emails. "<<endl;
        cout<<"3. Print delivered mails in a new linked list . "<<endl;
        cout<<"4. Print Status in 2D dynamic array. "<<endl;
        cout<<"5. Print total number of emails were sent on 2nd September,and the average time difference of the operation . "<<endl;
        cout<<"6. Print Distinct Domain names. "<<endl;
        cout<<"7. Print total number of mails were sent without bounce."<<endl;
        cout<<"8. Exit."<<endl;
        cout<<endl;

        cout<<"Enter any one of the options: ";
        cin>>a;
        cout<<endl;

        if (a =="1")
        {
            char y = 177;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<41; i++)
            {
                cout<<y;
            }
            cout<<endl;
            cout<<"\t\t\t\t\t"<<y<<"\t Print Full list\t \t"<<y<<endl;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<41; i++)
            {
                cout<<y;
            }

            cout<<endl;
            cout<<endl;
            ShowList(head);
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;

        }

        else if (a=="2")
        {
            char y = 177;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<41; i++)
            {
                cout<<y;
            }
            cout<<endl;
            cout<<"\t\t\t\t\t"<<y<<"\t List without Delivered emails\t"<<y<<endl;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<41; i++)
            {
                cout<<y;
            }

            cout<<endl;
            cout<<endl;
            printList(head,head,x);
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;

        }
        else if (a=="3")
        {


            char y = 177;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<49; i++)
            {
                cout<<y;
            }
            cout<<endl;
            cout<<"\t\t\t\t\t"<<y<<"\t\tDelivered mails\t\t\t"<<y<<endl;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<49; i++)
            {
                cout<<y;
            }
            cout<<endl;
            cout<<endl;
            ShowDEmail(head1);
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;





        }
        else if (a=="4")
        {

            char y = 177;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<41; i++)
            {
                cout<<y;
            }
            cout<<endl;
            cout<<"\t\t\t\t\t"<<y<<"\t Status in 2D dynamic array\t"<<y<<endl;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<41; i++)
            {
                cout<<y;
            }

            cout<<endl;
            cout<<endl;
            searchStatus(head,statusName);
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;


        }
        else if (a=="5")
        {
            char y = 177;
            cout<<"\t\t\t\t";
            for(int i=0; i<63; i++)
            {
                cout<<y;
            }
            cout<<endl;
            cout<<"\t\t\t\t"<<y<<"   Total Mail and Average time difference of 2nd september   "<<y<<endl;
            cout<<"\t\t\t\t";
            for(int i=0; i<63; i++)
            {
                cout<<y;
            }

            cout<<endl;
            cout<<endl;
            SearchD_and_time(head,word,words);
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;

        }
        else if (a=="6")
        {
            char y = 177;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<41; i++)
            {
                cout<<y;
            }
            cout<<endl;
            cout<<"\t\t\t\t\t"<<y<<"\t Distinct Domain names \t\t"<<y<<endl;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<41; i++)
            {
                cout<<y;
            }

            cout<<endl;
            cout<<endl;
            emaildata(head,words);
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;


        }
        else if (a=="7")
        {

            char y = 177;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<49; i++)
            {
                cout<<y;
            }
            cout<<endl;
            cout<<"\t\t\t\t\t"<<y<<"\t Total emails sent without Bounce   \t"<<y<<endl;
            cout<<"\t\t\t\t\t";
            for(int i=0; i<49; i++)
            {
                cout<<y;
            }

            cout<<endl;
            cout<<endl;
            SearchBounce(head,words);
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;



        }

        else if (a=="8")
        {

            break;
        }

        else
        {
            cout<<"Invalid Input."<<endl;
        }

    }



}



















































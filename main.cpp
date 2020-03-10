#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct players{
    int number;
    string name;
    string type;
    string country;
    string cap;
    int SR;
    string franchise;
    int bat;
    int ball;
    int wicket;
    int catches;
    int price;
    int points;
    int economy;
};
struct score{
    string name;
    int bat;
    int ball;
    int wicket;
    int catches;
    int economy;
};
int n;
struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;

class player
{
    public:
        void create_plist(int value);
        void add_player(int value);
        void delete_player(int value);
        void display_plist();
        void count();
        int * getRandom();
        int getn();
        player()
        {
            start = NULL;
        }
};

void player::create_plist(int value)
{
    struct node *s, *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}

void player::add_player(int value)
{
    if (start == NULL)
    {
        cout<<"First create the list with the power player."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
}

void player::delete_player(int value)
{
    struct node *tmp, *q;
    if (start->info == value)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        cout<<"Player Deleted"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {

        if (q->next->info == value)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
    if (q->next->info == value)
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Player Deleted"<<endl;
        return;
    }
    cout<<"Player "<<value<<" not found"<<endl;
}

void player::display_plist()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"Player List empty,no players to display"<<endl;
        return;
    }
    q = start;
    cout<<"Player List :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<endl;
        q = q->next;
    }
}

void player::count()
{
    cout<<"Number of Players selected are: "<<n<<endl<<endl;
}

int * player ::  getRandom()
{
    struct node *q;
    static int  r[10];
    q = start;
    n=0;
    while (q != NULL)
    {
        r[n]=q->info;
        q = q->next;
        n++;
        for(int i=0; i < n; i++)
        {
            for(int j=i+1; j < n; )
            {
                if(r[j] == r[i])
                {
                    for(int k=j; k < n;k++)
                    {
                        r[k] = r[k+1];
                    }
                    n--;
                }
                else {
                    j++;
                }
            }
        }
    }
    return r;
}

int player :: getn()
{
   return n;
}

int main()
{
    int choice, element;
    player dl;
    ifstream myfile;
    ifstream scoref;
    int *p;
    int n,q,k,i;
    myfile.open("Playersf.txt");
    if (!myfile)
        exit(1);
    int num;
	myfile>>num;
	players S[num];
	for (int i = 0; i < num; i++){
        myfile>>S[i].number>>S[i].name>>S[i].type>>S[i].country>>S[i].cap>>S[i].franchise>>S[i].price;
    }
    scoref.open("scoreboard.txt");
    if(!scoref)
        exit(1);
    int num1;
    scoref>>num1;
    score sb[num1];
    for(int y=0;y<num1;y++){
        scoref>>sb[y].name>>sb[y].bat>>sb[y].ball>>sb[y].catches>>sb[y].wicket>>sb[y].economy;
    }
    cout<<"Rules for choosing players :\n1.Batsmans-min-4,max-5(including wicketkeepers)\n2.Bowlers-min-2,max-5(including all rounders)\n3.Wicket keepers-min-1,max-3\n4.All rounders-min-1,max-4\n5.Eleven players in a team\n6.Indian players - 7 (Uncapped Players - min-1)\n  Overseas Players - 4\n7.Max 6 from a franchise\n8.Total price - 10000000\n\n"<<endl;
    int batsman;
    int bowler;
    int al;
    int dlf;
    int wk;
    int rps;
    int rcb;
    int pepsi=1;
    int tprice;
    int india;
    int ucap;
    int over;
    int npq=1;
    while(pepsi==1)
    {
        if(npq==1)
        {
            for (i = 0; i < num; i++){
                    cout<<S[i].number<<" "<<S[i].name<<" "<<S[i].type<<" "<<S[i].country<<" "<<S[i].cap<<" "<<S[i].franchise<<" "<<S[i].price<<endl;
            }
            cout<<endl;
            cout<<"1.Start selecting"<<endl;
            cout<<"2.Quit"<<endl;
            cout<<"Enter your choice : ";
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<"Enter the player number: ";
                cin>>element;
                dl.create_plist(element);
                cout<<endl;
                system("CLS");
                p=dl.getRandom();
                n=dl.getn();
                for(k=0;k<n;k++)
                {
                    for(q=0;q<num;q++)
                    {
                        if(*(p+k)==S[q].number)
                        {
                            cout<<S[q].number<<" "<<S[q].name<<endl;
                        }
                    }
                }
                cout<<endl;
                npq++;
                break;
            case 2:
                exit(1);
            default:
                cout<<"Wrong choice"<<endl;
            }
        }
        else
        {
            for (i = 0; i < num; i++){
                    cout<<S[i].number<<" "<<S[i].name<<" "<<S[i].type<<" "<<S[i].country<<" "<<S[i].cap<<" "<<S[i].franchise<<" "<<S[i].price<<endl;
            }
            cout<<"1.Add Player"<<endl;
            cout<<"2.Remove Player"<<endl;
            cout<<"3.Display Player List"<<endl;
            cout<<"4.Total players"<<endl;
            cout<<"5.Finish selecting team"<<endl;
            cout<<"6.Quit"<<endl;
            cout<<"Enter your choice : ";
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<"Enter the player number: ";
                cin>>element;
                dl.add_player(element);
                cout<<endl;
                system("CLS");
                p=dl.getRandom();
                n=dl.getn();
                for(k=0;k<n;k++)
                {
                    for(q=0;q<num;q++)
                    {
                        if(*(p+k)==S[q].number)
                        {
                            cout<<S[q].number<<" "<<S[q].name<<endl;
                        }
                    }
                }
                cout<<endl;
                break;
            case 2:
                if (start == NULL)
                {
                    system("CLS");
                    cout<<"List empty,No players to remove"<<endl;
                    break;
                }
                cout<<"Enter the player's number who you want to remove: ";
                cin>>element;
                dl.delete_player(element);
                cout<<endl;
                system("CLS");
                p=dl.getRandom();
                n=dl.getn();
                for(k=0;k<n;k++)
                {
                    for(q=0;q<num;q++)
                    {
                        if(*(p+k)==S[q].number)
                        {
                            cout<<S[q].number<<" "<<S[q].name<<endl;
                        }
                    }
                }
                cout<<endl;
                break;
            case 3:
                system("CLS");
                p=dl.getRandom();
                n=dl.getn();
                for(k=0;k<n;k++)
                {
                    for(q=0;q<num;q++)
                    {
                        if(*(p+k)==S[q].number)
                        {
                            cout<<S[q].number<<" "<<S[q].name<<endl;
                        }
                    }
                }
                cout<<endl;
                break;
            case 4:
                system("CLS");
                dl.count();
                break;
            case 5:
                system("CLS");
                if(dlf==0)
                {
                    pepsi=2;
                    system("CLS");
                }
                else
                {
                    cout<<"You have to make changes"<<endl<<endl;
                }
                break;
            case 6:
                exit(1);
            default:
                cout<<"Wrong choice"<<endl;
            }
        }
        tprice=0;
        batsman=0;
        bowler=0;
        al=0;
        wk=0;
        rps=0;
        rcb=0;
        india=0;
        ucap=0;
        over=0;
        p=dl.getRandom();
        n=dl.getn();
        for(k=0;k<n;k++)
        {
            for(q=0;q<num;q++)
            {
                if(*(p+k)==S[q].number)
                {
                    tprice+=S[q].price;
                    if(S[q].type=="Batsman")
                    {
                        batsman++;
                    }
                    else if(S[q].type=="Bowler")
                    {
                        bowler++;
                    }
                    else if(S[q].type=="AL")
                    {
                        al++;
                        bowler++;
                    }
                    else if(S[q].type=="WK")
                    {
                        wk++;
                    }
                    if(S[q].country=="India")
                    {
                        india++;
                    }
                    else if(S[q].country=="Over")
                    {
                        over++;
                    }
                    if(S[q].cap=="uncapped")
                    {
                        ucap++;
                    }
                    if(S[q].franchise=="RCB")
                    {
                        rcb++;
                    }
                    if(S[q].franchise=="RPS")
                    {
                        rps++;
                    }
                }
            }
        }
        dlf=0;
        cout<<"Remaining amount : "<<10000000-tprice<<endl;
        if(batsman>5)
        {
            cout<<"Maximum 5 batsmans only.You have selected "<<batsman<<endl;
            dlf++;
        }
        if(bowler>5)
        {
            cout<<"Maximum 5 bowlers only.You have selected "<<bowler<<endl;
            dlf++;
        }
        if(al>4)
        {
            cout<<"Maximum 4 all rounders only.You have selected "<<al<<endl;
            dlf++;
        }
        if(wk>3)
        {
            cout<<"Maximum 3 wicket keepers only.You have selected "<<wk<<endl;
            dlf++;
        }
        if(over>4)
        {
            cout<<"Maximum 4 overseas players only.You have selected "<<over<<endl;
            dlf++;
        }
        if(rcb>6)
        {
            cout<<"Maximum 6 from a franchise.You have selected "<<rcb<<" from RCB"<<endl;
            dlf++;
        }
        if(rps>6)
        {
            cout<<"Maximum 6 from a franchise.You have selected "<<rps<<" from RPS"<<endl;
            dlf++;
        }
        if(ucap<1)
        {
            cout<<"You must choose atleast one uncapped player"<<endl;
            dlf++;
        }
        if(india>7)
        {
            cout<<"Maximum 7 Indian players only.You have selected "<<india<<endl;
            dlf++;
        }
        if(batsman<4)
        {
            cout<<"Minimum 4 batsmans.You have selected "<<batsman<<endl;
            dlf++;
        }
        if(bowler<2)
        {
            cout<<"Minimum 2 bowlers.You have selected "<<bowler<<endl;
            dlf++;
        }
        if(al<1)
        {
            cout<<"Minimum 1 all rounders.You have selected "<<al<<endl;
            dlf++;
        }
        if(wk<1)
        {
            cout<<"Minimum 1 wicket keeper.You have selected "<<wk<<endl;
            dlf++;
        }
        if(over<4)
        {
            cout<<"Minimum 4 overseas players.You have selected "<<over<<endl;
            dlf++;
        }
        if(india<7)
        {
            cout<<"Minimum 7 Indian players.You have selected "<<india<<endl;
            dlf++;
        }
        if(10000000-tprice<0)
        {
            cout<<"No enough money"<<endl;
            dlf++;
        }
        cout<<endl;
    }
    int point=0;
    p=dl.getRandom();
    n=dl.getn();
    for(k=0;k<n;k++)
    {
        for(q=0;q<num;q++)
        {
            if(*(p+k)==S[q].number)
            {
                S[q].bat=0;
                S[q].ball=0;
                S[q].catches=0;
                S[q].wicket=0;
                S[q].economy=0;
                for(int ft=0;ft<num1;ft++)
                {
                    if(S[q].name==sb[ft].name)
                    {
                    S[q].bat=sb[ft].bat;
                    S[q].ball=sb[ft].ball;
                    S[q].catches=sb[ft].catches;
                    S[q].wicket=sb[ft].wicket;
                    S[q].economy=sb[ft].economy;
                    }
                }
                if(S[q].ball!=0)
                {
                    S[q].SR=S[q].bat/S[q].ball*100;
                }
                if(S[q].ball==0)
                {
                    S[q].SR=0;
                }
                S[q].points=0;
                if(S[q].bat>50 && S[q].bat<100 && S[q].SR>200.0)
                {
                    S[q].points+=50;
                }
                if(S[q].bat>50 && S[q].bat<100 && S[q].SR<200.0 && S[q].SR>100.0)
                {
                    S[q].points+=30;
                }
                if(S[q].bat>100 && S[q].SR>200.0)
                {
                    S[q].points+=100;
                }
                if(S[q].bat>100 && S[q].SR<200.0 && S[q].SR>100.0)
                {
                    S[q].points+=75;
                }
                if(S[q].bat>29 && S[q].bat<50 && S[q].SR>200.0)
                {
                    S[q].points+=5;
                }
                if(S[q].bat>29 && S[q].bat<50 && S[q].SR<200.0 && S[q].SR>100.0)
                {
                    S[q].points+=2;
                }
                if(S[q].SR<200.0 && S[q].SR>99.0)
                {
                    S[q].points+=2;
                }
                if(S[q].SR<100.0 && S[q].SR>50.0)
                {
                    S[q].points-=5;
                }
                if(S[q].SR==0 && S[q].ball>0)
                {
                    S[q].points-=10;
                }
                if(S[q].economy<=6&& S[q].economy>0)
                {
                    S[q].points+=15;
                }
                if(S[q].economy>6 && S[q].economy<10)
                {
                    S[q].points+=2;
                }
                if(S[q].economy>10&& S[q].economy<15)
                {
                    S[q].points-=5;
                }
                if(S[q].economy>15)
                {
                    S[q].points-=15;
                }
                point+=S[q].points+5*S[q].catches+10*S[q].wicket;
            }
        }
    }
    system("CLS");
    cout<<"The number of points won by team you selected is : "<<point<<endl;
    cout<<"Congrats"<<endl;
        return 0;
}

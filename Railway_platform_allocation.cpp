#include <bits/stdc++.h>

#ifdef _WIN32
#include <Windows.h>                       // Using Library For Sleep Fuction....
#else
#include <unistd.h>
#endif

using namespace std;


//Using Global Variable....
   vector<pair<string,string>> SOTD[4];             //SOTD[1] --> Stored One Directions Trains Data In Platform Number 1.
   int COFT;                                       // COFT --> Check One Direction's First Train Or Not....
   vector<pair<string,string>> SBTD[4];           //SBTD[1]  --> Stored BiDirections Trains Data In Section Number 1.
   int CBFT;                                     // CBFT --> Check Bidirection's First Train Or Not....
   int total_size;
   int sum[3];

class interfaces1                               //Declared Interfec1....
{

    public:
        virtual ~interfaces1() {}              //Create Destructor Of Interfaces1 Class....
        virtual  int check_platform(int i,vector<pair<string,string>> store[],string new_arrivial,string new_departure)=0; //Declared An Abstract Method....


};

class interfaces2
{
    public:
        virtual ~interfaces2() {}
        virtual  int CTT(int a,int b,int x,int y,int new_arrivial_minute,int new_departure_minute,int old_arrivial_minute,int old_departure_minute,int new_arrivial_hour,int new_departure_hour)=0;

};


class check_valid : public interfaces2      //Using Simple Inheritances....
{
    public:
        check_valid()                       //Declared Constructor....
        {
            this->arrivial_hour=0;
            this->departure_hour=0;
        }

    private:
        int arrivial_hour;
        int departure_hour;
    public:

            int CTT(int a,int b,int x,int y,int new_arrivial_minute,int new_departure_minute,int old_arrivial_minute,int old_departure_minute,int new_arrivial_hour,int new_departure_hour);
            // CTT --> Comapre Two Train Time....
};


int check_valid :: CTT(int a,int b,int x,int y,int new_arrivial_minute,int new_departure_minute,int old_arrivial_minute,int old_departure_minute,int new_arrivial_hour,int new_departure_hour)    //Declared Different Type Of Method....
            {
                arrivial_hour=a,departure_hour=b;
                if(a==b)
                {

                    if(new_arrivial_minute>new_departure_minute)
                    {
                        if(!(old_arrivial_minute>new_departure_minute && old_departure_minute<new_arrivial_minute))
                        return 0;
                    }
                    if(old_arrivial_minute>old_departure_minute)
                    {
                        if(!(new_arrivial_minute>old_departure_minute && new_departure_minute<old_arrivial_minute))
                        return 0;
                    }
                }

                while(a!=(b+1))
                {
                    a%=24;
                    if(a==x || a==y)
                    {

                        if(a==arrivial_hour || a==departure_hour)
                        {
                            if(a==x && a==y && a==arrivial_hour)
                            {
                                if(new_arrivial_minute>=old_arrivial_minute && new_arrivial_minute<=old_departure_minute)
                                    return 0;

                            }
                            if(a==x && a==y && a==departure_hour)
                            {
                                if(new_departure_minute>=old_arrivial_minute && new_departure_minute<=old_departure_minute)
                                    return 0;
                            }
                            if(a==arrivial_hour && a==x)
                            {

                                    return 0;
                            }
                            if(a==departure_hour && a==x)
                            {
                                if(departure_hour==new_departure_hour)
                                {

                                    if(new_departure_minute>=old_arrivial_minute)
                                    return 0;
                                }
                                else
                                {
                                    if(new_arrivial_minute<=old_departure_minute)
                                        return 0;
                                }
                            }
                            if(a==arrivial_hour && a==y)
                            {
                                if(arrivial_hour==new_arrivial_hour)
                                {
                                    if(new_arrivial_minute<=old_departure_minute)
                                    return 0;
                                }
                                else
                                {
                                    if(new_departure_minute>=old_arrivial_minute)
                                        return 0;
                                }
                            }
                            if(a==departure_hour && a==y)
                            {

                                return 0;
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    a++;

                }
                return 1;
              }










class check_valid_platform : public check_valid,public interfaces1   //Using Multiple Inheritance....
{
    public:                             //Declared Public Access Modifier.....
    check_valid_platform()
    {
        this->new_arrivial_hour=0;
        this->new_arrivial_minute=0;
        this->new_departure_hour=0;
        this->new_departure_minute;
        this->count=0;
        this->a=0;this->b=0;this->c=0;this->d=0;this->e=0;
        this->x=0;this->y=0;
    }
    private:                           //Declared Private Access Modifier.....
        int new_arrivial_hour;
        int new_arrivial_minute;
        int new_departure_hour;
        int new_departure_minute;
        int count;
        int a,b,c,d,e;
        int x,y;
    public:


        int check_platform(int i,vector<pair<string,string>> store[],string new_arrivial,string new_departure);

};


int check_valid_platform :: check_platform(int i,vector<pair<string,string>> store[],string new_arrivial,string new_departure)
            {
                     count=0;

                     new_arrivial_hour=((new_arrivial[0]-'0')*10)+(new_arrivial[1]-'0');
                     new_arrivial_minute=((new_arrivial[3]-'0')*10)+(new_arrivial[4]-'0');
                     new_departure_hour=((new_departure[0]-'0')*10)+(new_departure[1]-'0');
                     new_departure_minute=((new_departure[3]-'0')*10)+(new_departure[4]-'0');




                    for(int j=0;j<store[i].size();j++)
                    {


                        string old_arrivial=store[i][j].first;
                        string old_departure=store[i][j].second;
                        int old_arrivial_hour=((old_arrivial[0]-'0')*10)+(old_arrivial[1]-'0');
                        int old_arrivial_minute=((old_arrivial[3]-'0')*10)+(old_arrivial[4]-'0');
                        int old_departure_hour=((old_departure[0]-'0')*10)+(old_departure[1]-'0');
                        int old_departure_minute=((old_departure[3]-'0')*10)+(old_departure[4]-'0');
                         a=new_arrivial_hour;
                         b=new_departure_hour;
                         c=new_arrivial_hour;
                         d=new_departure_hour;

                        if(new_arrivial_hour>new_departure_hour)
                            d+=24;
                        else if(new_arrivial_hour == new_departure_hour  && new_arrivial_minute>new_departure_minute)
                            d+=24;

                        x=old_arrivial_hour;
                        y=old_departure_hour;
                        if(old_arrivial_hour>old_departure_hour)
                            y+=24;
                        else if(old_arrivial_hour==old_departure_hour && old_arrivial_minute>old_departure_minute)
                            y+=24;

                           if(d-c<y-x)
                            a=old_arrivial_hour,b=old_departure_hour;
                         check_valid mast;
                        if(a==new_arrivial_hour)
                            e=mast.CTT(a,b,old_arrivial_hour,old_departure_hour,new_arrivial_minute,new_departure_minute,old_arrivial_minute,old_departure_minute,new_arrivial_hour,new_departure_hour);
                        else
                            e=mast.CTT(a,b,new_arrivial_hour,new_departure_hour,new_arrivial_minute,new_departure_minute,old_arrivial_minute,old_departure_minute,new_arrivial_hour,new_departure_hour);

                         if(!e)
                          break;
                       count++;



                   }
                   return count;




                }







class bidirection : public virtual check_valid_platform       //Using Multilevel Inheritance....
{

    public:
            int add_train(string new_arrivial,string new_departure,int size);

};


int bidirection :: add_train(string new_arrivial,string new_departure,int size)
            {
               total_size+=size;
               if(!CBFT && total_size<=40)
               {
                  SBTD[0].push_back({new_arrivial,new_departure});
                  cout<<"This Train Allocate In Bidirection Section Number: "<<1<<endl;
                  CBFT=1;
                  sum[0]=total_size;
                  return 1;
               }
               if(total_size>40)
                  {
                     total_size-=size;
                     return 0;
                  }
               for(int i=0;i<3;i++)
               {
                    int count=0;
                    check_valid_platform fun;
                     if(fun.check_platform(i,SBTD,new_arrivial,new_departure)==SBTD[i].size())
                     {
                        sum[i]+=size;
                        total_size-=(sum[i]-size);
                        cout<<"Allocate This Train In Bidirection Section Number: "<<i+1<<endl;
                        SBTD[i].push_back({new_arrivial,new_departure});
                        return 1;
                     }

               }
               return 0;
            }



class one_direction : public virtual check_valid_platform,public bidirection     //Using Hierarhical Inheritance....
{
    public:
        one_direction()
        {
            this->STP=0;
        }
    private:
        int STP;     //Start Checking In Which Platform We add_trained Train....
    public:
            int add_train(string new_arrivial,string new_departure,int size);          //Using Method Overriding....


};

int one_direction :: add_train(string new_arrivial,string new_departure,int size)
            {
                   if(size>30)
                      {
                        bidirection obj2;
                               if(!obj2.add_train(new_arrivial,new_departure,size))
                               cout<<"Sorry We Can Not Insert This Train In Any Platform: "<<endl;
                            return 0;
                      }
                   if(!COFT)
                   {
                      if(size<=15)
                         SOTD[0].push_back({new_arrivial,new_departure}),COFT=1;
                      else if(size<=20)
                         SOTD[1].push_back({new_arrivial,new_departure}),COFT=1;
                      else if(size<=25)
                         SOTD[2].push_back({new_arrivial,new_departure}),COFT=1;
                      else if(size<=30)
                         SOTD[3].push_back({new_arrivial,new_departure}),COFT=1;

                      cout<<"This Train Is Allocate In Platform Number: "<<1<<endl;
                      return 0;

                   }
                   check_valid_platform fun;
                    STP=size-11;
                   if(STP<0)
                      STP=0;
                   STP=STP/5;
                   for(int i=STP;i<4;i++)
                   {
                               int count=0;


                            if(fun.check_platform(i,SOTD,new_arrivial,new_departure)==SOTD[i].size())
                            {
                               cout<<"Allocate This Train In Platform Number: "<<i+1<<endl;
                               SOTD[i].push_back({new_arrivial,new_departure});
                               return 1;
                            }
                   }
                   bidirection obj2;
                   if(!obj2.add_train(new_arrivial,new_departure,size))
                      cout<<"Sorry We Can Not Insert This Train In Any Platform: "<<endl;
                  return 0;

           }


class admin_system : public one_direction    //Using Multileval Inheritance....
{
    public:
    admin_system()
    {
        for(int i=0;i<4;i++)
            SOTD[i].clear(),SBTD[i].clear();
        for(int i=0;i<3;i++)
            sum[i]=0;
        COFT=0;
        CBFT=0;
        total_size=0;
    }
    ~admin_system()                         //Using Default Destructor....
    {
        cout<<"Thank Yous...."<<endl;
    }
    private:
        int number_of_train;
        string start_time;
        string end_time;
        string cabs;
        int n;
    public:
        void start_time_process();
        bool check_valid_string(string str);
        bool check_valid_number(string cabs);
};


void admin_system :: start_time_process()
        {

            cout<<"Enter How Many Total Train You Want To Entered: ";

               cin>>number_of_train;
             one_direction obj1;
               for(int i=0;i<number_of_train;i++)
               {
                 cout.flush();
                 sleep(1);                    //Using Sleep Method For Stop Executing For 1 Second....

                 try
                 {
                 cout<<endl<<endl<<"Enter Train"<<i+1<<"'s Arrivial Time <HH:MM>: ";

                     cin>>start_time;

                     cout<<endl<<"Enter Train"<<i+1<<"'s Departure Time <HH:MM>: ";

                     cin>>end_time;



                     cout<<endl<<"Enter Number Of Cabs(Integer) In Train"<<i+1<<" : ";

                         cin>>cabs;

                         if(!check_valid_string(start_time))
                         {
                            throw start_time;
                         }
                         if(!check_valid_string(end_time))
                         {
                            throw end_time;
                         }
                         if(!check_valid_number(cabs))
                            {
                                throw cabs;
                            }
                        n=stoi(cabs);

                     obj1.add_train(start_time,end_time,n);
                 }
                 catch(string str)
                 {
                    cout<<str<<" It's Not A Valid...."<<endl;
                    cout<<"Again Insert Valid Form...."<<endl;
                    i--;

                 }

               }
        }

bool admin_system :: check_valid_string(string str)
{
    if(str.size()!=5)
        return 0;
    if(str[2]!=':')
        return 0;
    for(int i=0;i<5;i++)
    {
        if(i!=2)
        {
            if(!(str[i]>='0' && str[i]<='9'))
                return 0;
        }
    }
    return 1;
}

bool admin_system :: check_valid_number(string cabs)
{
    for(int i=0;i<cabs.size();i++)
    {
        if(!(cabs[i]>='0' && cabs[i]<='9'))
            return 0;
    }
    return 1;
}

int main()
{

   admin_system begin;
   begin.start_time_process();

}

#include<iostream>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<sstream>
#include<map>
#include<vector>
#include<fstream>
#include<ctime>
#include<algorithm>
#include<cctype>
using namespace std; 
string no[]={"sum","product","divide","multiply","add","subtract","#","#","#"};                                        //Keywords for parsing a string
string sal[]={"morning","evening","night","afternoon","bye","thank","ok","okay","then"};
string wh[]={"which","who","what","where","who","tell","suggest","list","how"};
string gr[]={"awezome","cool","super","fantastic","wonderful","good","love","lovely","great"};
string c;
string s;
vector<float>a;
int counter=0;
float add(vector<float> a)                                                                                         //Function for addition on parsed string
{ 
    float m=0;
    vector<float>::iterator p;
    for(p=a.begin();p!=a.end();p++)
    {
    m=m+*p;
    }
    return m;
 }
 float subtract(vector<float> a)
{
  float m=a.front();
  vector<float>::iterator p;
  for(p=a.begin()+1;p!=a.end();p++)                                                                                //Function for subraction on parsed string
  {
      m=m-(*p);
  }
  return m;
}
float multiply(vector<float> a)
{
    float m=1;
    vector<float>::iterator p;                                                                                    //Function for multiplication on parsed string
    for(p=a.begin();p!=a.end();p++)
    {
      m=m*(*p);
    }
    return m;
}   
float divide(vector<float> a)
{
      float m=a.front();
      vector<float>::iterator p;
      for(p=a.begin()+1;p!=a.end();p++)                                                                            //Function for addition on parsed string
      {
              m=m/(*p);  
      }
      return m;
}     
typedef float (*FnPtr)(vector<float>);
void arithmetic(size_t pos)
 {
 	counter=1;
    char t[20]={0},r[50]={0};                                                                                    //arithmetic() is a function to parse string and do corresponding arithmetic operation
    string::iterator it;
    float n;
 	int k,i=0,j=0;
    for(it=s.begin()+pos;*it!=' ';it++)                                                                         //Loop to extract the keyword
	{
		t[i++]=*it;
	}
    for(it=s.begin();it<s.end();it++)                                                                          //loop to extract the numbers
    {
            
        if(isdigit(*it)||*it=='.')
        {
             r[j++]=*it;
        }
         else
		 { 
		 r[j++]=' ';
		 }
	 }
    stringstream ss(r);
    for(k=0;k<ss.str().size();k++)                                                                             //Using stringstream to convert the numbers from char to int
    {
        n=0;
		ss>>n;
        if(n!=0)
        {
          a.push_back(n);
        }
    }
    map<string,FnPtr> myMap;                                                                                //Using map function based on the key to call the corresponding function to perform operation 
    myMap["add"]=add; 
    myMap["sum"]=add;
    myMap["product"]=multiply;  
    myMap["subtract"]=subtract;
    myMap["multiply"]=multiply;
    myMap["divide"]=divide;
    float res = myMap[t](a);
    cout<<"Scorpion: " << "Your answer is "<<res<<" "<<c;
    a.clear();
}
void salutation(size_t pos)                                                                               //Function to respond to the wishes
{
	counter=1;
	string::size_type i = s.find("scorpion");
    if (i != std::string::npos)
    {
    s.erase(i,' ');
    } 
	string::iterator it;
    it=s.begin()+pos;
    if(*it=='b')
    {
    	cout<<"Scorpion: "<<s<<" "<<c;
    	exit(0);
	}
	
    else if(*it=='o'||s=="then"||s=="then?")
    {
    	cout<<"Scorpion: "<<"Then?";
	}
	else if(*it=='t')
	{
		
        cout<<"Scorpion: "<<"You are welcome "<<c;
    }
    else
    {  
       cout<<"Scorpion: "<<s<<" "<<c;
	}
}
void question()                                                                                      //Function to respond to the questions asked by the user
{
	counter=1;
	ifstream f;
	string line;
	size_t pos;
    f.open("Database.txt",ios::in);                                                                 //Database is a file that has pre-recorded questions and answers
    while(f)
    {
	   getline(f,line,'.');                                                                        //Extracting the question from database
	   if(s==line)                                                                                 //Checking if that matches with user input
	   {
	   	 f.seekg(0,ios::cur);                                                                      //If so, printing the answer from database
	   	 getline(f,line,'#');
	   	 cout<<"Scorpion: "<<line;
	   	 return;
	   }
	   else
	   {
	   f.ignore(10000,'\n');                                                                    //Else skipping the next question in file
	   }
	   line.clear();
    }
    if((pos=s.find("date"))!=string::npos||(pos=s.find("time"))!=string::npos)
    {
    	time_t now = time(0);
        char* dt = ctime(&now);                                                              
        cout<<"Scorpion: " << "The local date and time is: " << dt;                         
        return;
	}
	else
	{
		cout<<"Scorpion: "<<"Check if you have missed the question mark or check if the sentence formation is correct";
	}
	f.close();
}
void greetings(size_t pos)                                                                      //Function to respond to greetings such as "good" or "cool"
{
	counter=1;
	string::iterator it;
    it=s.begin()+pos;
	if(*it=='l')
	{
		cout<<"Scorpion: "<<"Awwww...It's good to hear that "<<c;
	}
	else if(*it=='a'||*it=='f'||*it=='w')
		{
			cout<<"Scorpion: "<<"I'm doing my maximum.Thank you for your appreciation";
		}
	else
	    {
			cout<<"Scorpion: "<<"Thank you "<<c;
		}
}
 
int main()
{
 	cout<<"----------------------------------------------PERSONAL ASSISSTANT Scorpion----------------------------------------------"<<endl;
 	cout<<"Scorpion: "<<"Hello!! I'm Scorpion "<<endl;
 	cout<<"Scorpion: "<<"How may I call you?"<<endl<<"You: ";
 	getline(cin,c);
 	c=c.substr(c.find_last_of(' ') + 1);                                                                                 //Stores your name
 	cout<<endl;
 	cout<<"Scorpion: "<<"That's a sweet name "<<c<<endl;
 	cout<<"Scorpion: "<<"Welcome "<<c<<endl<<endl;
 	cout<<"Scorpion: "<<"How may i help you?\n";
 
    while(1)
    {
     int k=0,i=0,j=0,l=0;
     float n;
     s.clear();
     a.clear();
     size_t pos;
     cout<<c<<": ";
	 getline(cin,s);
	 cout<<endl;
	 transform(s.begin(), s.end(), s.begin(), ::tolower);
     for(l=0;l<9;l++)                                                                                          //Loop to find the keywords
     {
     	if ((pos= s.find(wh[l]))!= std::string::npos) 
		{
			question();
			break;
		}
        else if ((pos= s.find(no[l]))!= std::string::npos)
        {
            arithmetic(pos);
            break;
		}
		else if ((pos= s.find(sal[l]))!= std::string::npos)
		{
			salutation(pos);
			break;
		}
		else if((pos= s.find(gr[l]))!= std::string::npos)
		{
			greetings(pos);
			break;
		}
	}
	if(s=="scorpion")
	{
		cout<<"Scorpion: "<<"I'm listening "<<c;
	}
	else if(counter==0)                                                                                    //User friendly measure if keyword is not present
	{
		cout<<"Scorpion: "<<"Oops....I can't get you."<<"For support type 'help' at anytime";
		if(s=="help")
		{
		cout<<"Scorpion: "<<"Here is what i can do"<<endl;
		ifstream help;
		string line;
		help.open("Help.txt",ios::in);
		while(help)
		{
			getline(help,line,'\n');
			cout<<line<<endl;
		}
		cout<<"Scorpion: "<<"Waiting for your reply "<<c;
	    }
		
	}
    	s.clear();
    	counter=0;
    	cout<<endl;
	}
}
    


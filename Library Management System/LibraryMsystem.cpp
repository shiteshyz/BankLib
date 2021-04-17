#include<iostream>
#include<time.h>
#include<conio.h>
#include<fstream>
#include<string.h>

using namespace std;
int c,i,x;                 // c:counter i:loop   x:number of books

void both();               //clear screen + time  
void waqt();               //display time
void nowhat();             //now what?
void login();              //login
void main_menu();          //main menu
void addnBook();           //add new books to the records
void display();            //display all records of books
void issue();              //issue books for student
void srecords();           //records of student
void search();             //search for book by ISBN
void sforstudent();        //search for student by regisration id
void returnBook();         //in time of return

class book
       {
       	char name[25];     //name of the book
       	char publisher[20];
       	char author[20];
       	public:
       		 int isbn;     //International Standard Book Number
       		 void enter_data()
       		     {  
					fflush(stdin);
       		     	cout<<"\n\tName: ";
       		     	gets(name);
       		     	cout<<"\n\tPublisher :";
       		     	gets(publisher);
       		     	cout<<"\n\tAuthor :";
       		     	gets(author);
       		     	cout<<"\n\tInternational Standard Book Number(ISBN) :";
       		     	cin>>isbn;
       		     	fflush(stdin);
					}
			    void show()
			       {
       		     	cout<<"\n\tName      : "<<name;
       		     	cout<<"\n\tPublisher : "<<publisher;
       		     	cout<<"\n\tAuthor    : "<<author;
       		     	cout<<"\n\tInternational Standard Book Number(ISBN) : "<<isbn;
       		     	cout<<"\n\n";
				   }
				
       		 
	   };

class student               // class student 
     {
     	char date[10];      //date of issue
     	int sisbn;          //isbn of book that issue to student
     	public:
     		int rid;        //registration id of student
     		 void enter_data()
       		     {  
					fflush(stdin);
       		     	cout<<"\n\n\n\tRegistration Id :";
       		     	cin>>rid;
       		     	cout<<"\n\tISBN of Book :";
       		     	cin>>sisbn;
       		     	cout<<"\n\tDate issue :";
       		     	cin>>date;
       		     	fflush(stdin);
       		      }
       		       	void show()
			       {
       		     	cout<<"\n\tRegistration Id      : "<<rid;
       		     	cout<<"\n\tISBN of Book         : "<<sisbn;
       		     	cout<<"\n\tDate of Issue        : "<<date;
       		     	cout<<"\n\n";
				   }
					
			};	   
	   
void both()                //clear screen + time
     {
     	system("cls");
		waqt();
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t      Read.Know.Grow";
		cout<<"\n\n\t\t\t\tthe LIBRARY";
	 }
 
void waqt()                //for time
      {
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
  		timeinfo = localtime ( &rawtime );
  		cout<<"\n\t\t\t\t\t\t\t\tCurrent local time and date:"<<asctime(timeinfo);
	  }

void nowhat()              //way to main menu or logout
    {
        int c=0;
         	cout<<"\n\n\n\t1.Main Menu\n\n\t2.Logout";
         	cout<<"\n\n\n\t\tChoice : ";
     	  	cin>>c;
     	  	if(c==1)
     	  	  main_menu();
     	  	else if(c==2)
			    { 
				 both();
			   	 cout<<"\n\n\n\t\tSuccessfully Logout\n\n\n";
			   	 getch();
				 exit(1);
				  }	
			else
			  {
			 	both();
			    cout<<"\n\n\n\t\tError\tLogging Out\n\n\n";
			    getch();
			    exit(1);
			  }
	}
	
		  
void login()               //login page
     { 
     both();
     c=0;
     char u[]="",p[]="",username[10],password[10];
     ps:
     cout<<"\n\n\n\n\n\t\t\tUsername : ";
     gets(username);
     cout<<"\n\t\t\tPassword : ";
     gets(password);
     if(!(strcmp(username,u)||strcmp(password,p)))
        {  
        	both();
	    	cout<<"\n\n\n\t\tLogin Successful\n\n\n\t\t";
			system("pause");
		}
	 else 
	    {   
			if(c==0)
        	   { 
        	    both();
        	    cout<<"\n\n\n\t\t\tWrong Username or Password \n\n\t\t\tEnter Again\n";
        	   	c++;
        	   	goto ps;
			   }
			else
			  { 
			   both();
			   cout<<"\n\n\n\t\tFailed to Login \n\n\t\tCalling 911\n\n\n";
			   exit(1);
			  }
	    }
   }


void main_menu()           //main menu .. for different choice
     {      
            both();
	    	cout<<"\n\n\n\n\t1.Add New Book\n\n\t2.Display All Records\n\n\t";
			cout<<"3.Issue Book\n\n\t4.Student Records\n\n\t5.Search by ISBN\n\n\t6.Search for Student for Registration id\n\n\t7.Logout";
	    	cout<<"\n\n\n\tEnter your choice : ";
	        int choice;
	        c=0;
	        char rchoice;
	    	r:
	    	cin>>choice;
	    	switch(choice)
	    	  {
	    	  	case 1:
				       addnBook();
	    	  	           break;
	    	  	case 2:display();
	    	  	           break;
	    	  	case 3:issue();
	    	  		       break;
	    	  	case 4:srecords();
	    	  		       break;
	    	  	case 5:search();
	    	  		       break;
	    	    case 6:sforstudent();
	    	              break;		   
	    	  	case 7:both();
				       cout<<"\n\n\n\t\tSuccessfully Logout\n\n\n";
	    	  	       getch();
	    	  	       exit(1);
	    	  	default:if(c==0)
	    	  	        { 
						  c++;
	      	              cout<<"\n\n\nInvalid selection\n\nWhat to Enter Again? \"YES\"(y) or \"NO\"(n) : ";
	      	              rchoice=getche();
	      	              if(rchoice=='y'||rchoice=='Y')
	      	              {
	      	              	printf("\n\n\tChoice : ");
	      	              	goto r;
							}
						  else if(rchoice=='n'||rchoice=='N')
						   { 
						    both();
						   	cout<<"\n\n\n\t\tSuccessfully Logout\n\n\n";
						   	getch();
						   	exit(1);
							   }	
						  else
						   {
						   	both();
						    cout<<"\n\n\n\t\tError\tLogging Out\n\n\n";
						    getch();
						    exit(1);
						   }
					   }
					else
					  { both();
					  	cout<<"\n\n\tLimit Exceeded\n\n\tLogging Out\n\n\n";
					  	getch();
					  	exit(1);
					  }  	   
	  	       }	
	  }  



void addnBook()               //add new book into the system
        {
   	        both();
   	        book b;
   			cout<<"\n\n\n\tNumber of Book :";
   			cin>>x;
   			cout<<"\n\n\tEnter Details";
   			cout<<"\n\n\t1.";
   			i=0;
   			for(i=1;i<=x;i++)
   	  			{
	   				ofstream fout("record.txt",ios::app);
   	    			b.enter_data();
   	    			fout.write((char*)&b,sizeof(book));
   	    			fout.close();
   	    			both();
   	    			cout<<"\n\n\t"<<i+1<<".";
	     		 }
			both();
			cout<<"\n\n\n\t\tData Saved";
			nowhat();
   	 }
   	

void display()               //display records of all books
      {
      	both();
      	ifstream fin("record.txt");
      	book b;
      	if(!fin)
      	  {
      	  	cout<<"\n\n\tNothing Display";
			}
		else
		  {
		  	while(fin.read((char*)&b,sizeof(book)))
	            {
	            cout<<"\n\n";
		        b.show();
	            }
	           fin.close();
		  }
	    getch();
	    both();
	    nowhat();
      	
        }
        

void issue()                //for Book issue
     {
     	both();
     	student s;
     	ofstream fout("student.txt",ios::app);
   	    s.enter_data();
   	    fout.write((char*)&s,sizeof(student));
   	    fout.close();
   	   	both();
		cout<<"\n\n\n\t\tData Saved\n\n";
		s.show();
		getch();
		both();
		nowhat();
       }
    

void srecords()             //display records of student
     {
	    both();
      	ifstream fin("student.txt");
      	student s;
      	if(!fin)
      	  {
      	  	cout<<"\n\n\tNothing to Display";
			}
	    else 
	      {
	        while(fin.read((char*)&s,sizeof(student)))
	      		{
	        		cout<<"\n\n";
		    		s.show();
	       			}
	    		fin.close();
		     }
	    getch();
	    both();
	    nowhat();                     

	 }
	

void search()               //search book by isbn
    {
    	both();
    	int isbn;
      	ifstream fin("record.txt");
      	book b;
      	if(!fin)
      	   {
      	   	cout<<"\n\n\tNothing to display";
			 }
		else
		   {
		    cout<<"\n\n\tEnter ISBN :";
      	    cin>>isbn;
      	    while(fin.read((char*)&b,sizeof(book)))
	            {
	            cout<<"\n\n";
		        if(b.isbn==isbn)
		          {
		          	i++;
		          	b.show();
				  }
	            }
	        if(i==0)
	         {
	         	cout<<"\n\n\tNo such book with isbn "<<isbn;
			 }
	    fin.close();
		   }
	    getch();
	    both();
	    nowhat();
	}


void sforstudent()          //display record of desire student by registration id
        {
        both();
    	int rid;
    	i=0;
      	ifstream fin("student.txt");
      	student s;
      	if(!fin)
      	   {
      	   	cout<<"\n\n\tNothing to display";
			 }
		else
		   {
		    cout<<"\n\n\tEnter Registration id :";
      	    cin>>rid;
      	    while(fin.read((char*)&s,sizeof(student)))
	            {
	            cout<<"\n\n";
		        if(s.rid==rid)
		          {
		          	i++;
		          	s.show();
				  }
	            }
	        if(i==0)
	         {
	         	cout<<"\n\n\tNo record for student with registration id "<<rid;
			 }
	    fin.close();
		   }
	    getch();
	    both();
	    nowhat();
		}
   	
main()                      //main function
      {    
	     system("COLOR F0");
    	 login();
		 main_menu();
		 getch();	   	 
	    }

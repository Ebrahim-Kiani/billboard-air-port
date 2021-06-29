#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct node
{
	int info;
	struct node *next;
};

typedef struct node *NODEPTR;
NODEPTR makeNode(int);
//declaring all of my public prototypes in my List
//class
class List
{
    friend class airport;
    
public:
      //**** important_flith_number 

	List();
	~List();
	void deletEndNode();
	int emptylist();
	void insertend(int);
	void printlist();
	void addFront(int);
	void deleteFront();
	void addspecific(int);
	void deletespecific(int);
	int deleteAllspecific(int);
	void deletee();
	void translator(int );
	int flith_number_maker();
	int find_type(int);
	int Band_capacity(int  , int [1000] , int );


	     int flith_number[1000];         // **test**

private:
	NODEPTR listptr;
};
 
     void List::deletee(){
         cout<< "Enter the flith_number for take_off:";
         int f_number;
         cin >> f_number;
         	deletespecific(f_number);
         	cout<< "your airplain taking_off"<<endl;
     }

    int List::flith_number_maker(){
           printlist();

    
    // functions
  
   // int find_type(int);
  //  int Band_capacity(int,int [],int);
    
    
        // Variables
    int answer=0;
    int clock_flith_hour;
    string clock_flith_minute;
    string type;
    int model;
    int band;
    int passengers;
   
   
    
  
    
    // clock
    cout<<"***Enter the clock flith ('00:00')*** "<<endl;
    cout << "Enter the hour of flith :";
    cin >> clock_flith_hour;
    
    answer=clock_flith_hour*10000000;
   
   correctly: cout<<"Enter the minute of flith('00' or '30'):";
    cin >> clock_flith_minute;
    
    if(clock_flith_minute=="00" || clock_flith_minute=="30"){
        if(clock_flith_minute=="30")
        answer = answer + (5*1000000);
        
    }else{ cout << "Please enter correctly"<<endl;
            goto correctly;
        }
        
    //type    
        
      
        answer = answer + 100000;
    //model
    cout<<"Enter model of airplain:";
    cin >> model;
    answer = answer + (10000 * model);
    
    // band
    int yellow_lamp=0;
    
       for(int i=(model/2)+1 ; i <= 5 ; i++){
           if (Band_capacity(i , flith_number ,answer/1000000 ) >0 ){
               cout<<"your band is:"<<i<<endl;
               yellow_lamp++;
               answer=answer+(1000 * i);
                  cout<<"Band ("<<(i)<<") capacity is "<<Band_capacity(i , flith_number ,answer/1000000 )-1<<" now"<<endl;
               break;
           }
           
       }if(yellow_lamp==0)cout<<"All suitable bands are full you must try again at 30 minutes later"<<endl;
        
    // passengers
    cout<<"Enter the number of passengers:";
    cin >> passengers;
    answer +=passengers;
        // finished
        insertend(answer);
        return answer;
        
       
}
int  List::find_type(int number){
    
       if((number/100000%10)==0)
       return 0;
       else
       return 1;
}
int List::Band_capacity(int band , int flith_number_[1000] , int time_){
    int i=0;
   int answer=0;
    
    while(flith_number_[i] !=0){
        int timy=0;
        int bandy=0;
        timy=flith_number_[i]/1000000;
      bandy= (flith_number_[i]/1000)%10;
        if(bandy == band && timy==time_)
        answer++;
        i++;
    }

    return 2-answer;
}




//constructor
List::List()
{
	listptr=0;
}
//Destructor. If the list is not
// empty, this will destroy the nodes that exist
List::~List()
{
	NODEPTR CurrPtr;
	if(emptylist())
		return;
	while(listptr!=NULL)
	{
		CurrPtr=listptr;
		listptr =listptr->next;
		delete CurrPtr;
	}
	cout<<"\nAll nodes destroyed\n";
}
//this function adds a node to the front of the list
//If the list is empty, the user will get a message
//saying "the list is empty"
void List::addFront(int value)
{
	NODEPTR currPtr, newNode;
	newNode = makeNode(value);
	currPtr= listptr;
	newNode->info=value;
	if(emptylist())
	{
		newNode->next = listptr;
		listptr= newNode;
	}
	else
	{
		for(currPtr=listptr;currPtr->next!=NULL;currPtr=currPtr->next);
                  newNode->next= listptr;
		  listptr = newNode;

        }

}
NODEPTR makeNode(int number)
{
	NODEPTR newNode;
	if(!(newNode = new node))
	{
		cout<<"MEMORY Allocation error";
		exit(0);
	}
	newNode->info= number;
	newNode->next=NULL;
	return newNode;
}
//This function will print all the nodes that you
//have in the list
void List::printlist()
{
   for (int i=0 ; i < 1000 ; i++)
   flith_number[i]=0; 

int i=0;
	NODEPTR currPtr;
	if(emptylist())
		cout<<"\nthe list is empty\n";
	else
	{
		cout<<endl;
		for(currPtr=listptr;currPtr!=NULL;currPtr=currPtr->next){
		    
		flith_number[i]=currPtr->info;
	
		i++;
		//	cout<<currPtr->info<<endl;
		}
		
	}
}
//checking if the list is NULL
int List::emptylist()
{
	return (listptr==0);
}
//This function will add a node to the end of the
//list
void List::insertend(int value)
{
	NODEPTR currPtr, newNode;
	newNode = makeNode(value);
	newNode->info=value;
	//check if the list is empty
	if(emptylist())
	{
		newNode->next=listptr;
		listptr=newNode;
	}
	else
	{
		//adds a node to the end of the list;
		for(currPtr=listptr;currPtr->next!=NULL;currPtr=currPtr->next);
		 newNode->next= currPtr->next;
		 currPtr->next=newNode;

	}
}
//this function will add a node after a node that you told it
//to that exists in the list.  If that node doesn't exist, then
//the user will receive a message saying that the node doesn't exists
void List::addspecific(int value)
{
	int spec;
	NODEPTR currPtr, newNode;
	cout<<"Enter the number you want to add: ";
	cin>>value;
	cout<<"After what node: ";
	cin>>spec;
	newNode = makeNode(value);
	currPtr= listptr;
	if(currPtr==NULL)
	{
		cout<<"\nthe list is empty\n";
	}	
	
	else
	{
	
		currPtr = listptr;
		while(currPtr->info !=NULL)
		{
			if(currPtr->info==spec)
			{
				newNode->next = currPtr->next;
		   		currPtr->next = newNode;
				return;
			}
			else
			{
				while(currPtr->next ==NULL)
				{
					if(currPtr->info!=spec)
					{
						cout<<endl<<"the node "<<spec
							<<" was not found"<<endl;
						return;
					}
			currPtr= currPtr->next;

				}
			}

		
			currPtr= currPtr->next;

		}
	}
}
//this function deletes at the end of the node.
//If the node doesn't exist, the user will get a message
//saying that the value is not found, or the list is empty that's
//if the list is empty
void List::deletEndNode(void)
{
	NODEPTR currPtr, prevPtr;
	if(emptylist())
	{
		cout<<"\nthe list is empty"<<endl;
		return;
	}
	if(listptr->next==NULL)
	{
		currPtr=listptr;
		listptr= listptr->next;
		delete currPtr;
	}
	else
	{
		currPtr= listptr;
		while(currPtr->next !=NULL)
		{
			prevPtr=currPtr;
			currPtr=currPtr->next;
		}
		prevPtr->next = currPtr->next;
		delete currPtr;

	}
}
//same thing with the delete end except it deletes
//the front
void List::deleteFront()
{
	NODEPTR currPtr, prevPtr;
	if(emptylist())
	{
		cout<<"\nthe list is empty"<<endl;
		return;
	}
	if(listptr->next==NULL)
	{
		currPtr=listptr;
		listptr= listptr->next;
		delete currPtr;
	}
	else
	{
		currPtr= listptr;
		while(currPtr->next !=NULL)
		{

			currPtr=currPtr->next;
		}
		currPtr = listptr;
		listptr = listptr->next;

		delete currPtr;

	}
}
//the function deletes everything that contain the same
//node.  if you have 111,222,1111,22,111 and you ask to delete
//one, then yoy should end up with 222,22
int List::deleteAllspecific(int value)
{
	NODEPTR currPtr, prevPtr;
	int counter=0;

	currPtr= listptr;
	if(emptylist())
	{
		cout<<"\nthe list is empty";
		return counter;
	}
	currPtr = prevPtr = listptr;
	while(currPtr !=NULL)
	{
		 if(currPtr->info == value)
		 {
			  if (currPtr == listptr)
			  {
				deleteFront();
				 currPtr = prevPtr = listptr;
				 counter++;
			  }

			else
			{
				prevPtr->next = currPtr->next;
				delete currPtr;
				currPtr = prevPtr->next;
				counter++;
			}
		}
		else
		{
			prevPtr = currPtr;
			currPtr = currPtr->next;
		}
	}
	return counter;
}
//this function will delete the value that you asked it
//to.  If the list is empty you will receive a message
//saying that the list is empty or value not found that's
//if there are nodes in the list
void List::deletespecific(int value)
{
	NODEPTR currPtr, prevPtr, tempPtr;

	currPtr= listptr;
	if(currPtr == NULL)
	{
		cout<<"\nthe list is empty";
		return;
	}
	if(value == listptr->info)
	{
		tempPtr = listptr;
		listptr = listptr->next;
		return;
	}
	else if(value != listptr->info)
	{
		prevPtr = listptr;
		currPtr = listptr->next;
		while(currPtr !=NULL && currPtr->info !=value)
		{
			prevPtr= currPtr;
			currPtr= currPtr->next;
		}
		if(currPtr !=NULL)
		{
			tempPtr = currPtr;
			prevPtr->next= currPtr->next;
			delete tempPtr;
			return;
		}

	}
	cout<<"\nValue "<<value<<" was not found"<<endl;
	return;
}
void List::translator(int band){
   printlist();
   
    
    for(int i=0 ; i < 1000; i++)
        for(int j=0 ; j < 1000 ; j++){
            if(flith_number[j]<flith_number[i]){
                flith_number[j]=flith_number[i]+flith_number[j];
                flith_number[i]=flith_number[j]-flith_number[i];
                flith_number[j]=flith_number[j]-flith_number[i];
            }
        }
        int i=0;
    if(band==0){
    while(flith_number[i]!=0){
    cout << "hour:"<<flith_number[i]/10000000;
    if(flith_number[i]/1000000 %10==5 )
    cout<<"  minute:"<<30;
    else
    cout<<"  minute:"<<00;
    if(flith_number[i]/100000%10==1)
    cout<<"  type: landing";
    else
    cout<<" type: taking_off";
    cout<<"  model:"<<flith_number[i]/10000 %10;
    cout<<"  band:"<<flith_number[i]/1000 %10;
    cout<<"  passengers:"<<flith_number[i]%1000<<endl;
    i++;
    }
    }
    else{
        while(flith_number[i]!=0){
        if(flith_number[i]/1000 %10==band){
         cout << "hour:"<<flith_number[i]/10000000;
    if(flith_number[i]/1000000 %10==5 )
    cout<<"  minute:"<<30;
    else
    cout<<"  minute:"<<00;
    
    cout<<"  type:"<<flith_number[i]/100000 %10;
    cout<<"  model:"<<flith_number[i]/10000 %10;
    
    cout<<"  band:"<<flith_number[i]/1000 %10;
    cout<<"  passengers:"<<flith_number[i]%1000<<endl;
    i++;
    }
    }
    }
}

//main driver.  The main driver will call the functions
//and the user will add or delete the node he or she chooses




int main(){
    cout<<"There are 10 models of airplain"<<endl;
    cout<<"number 1,2 -->band(1)"<<endl;
    cout<<"number 3,4 -->band(2)"<<endl;
    cout<<"number 5,6 -->band(3)"<<endl;
    cout<<"number 7,8 -->band(4)"<<endl;
    cout<<"number 9,10-->band(5)"<<endl;
     List ebi;
  help:      int choice=0;
 
  while(choice!=5){
        cout<<endl<<"main Menu:"<<endl;
        cout<<"1.landing"<<endl;
        cout<<"2.taking_off(or delete from List)"<<endl;
        cout<<"3.Print special band List(you can Enter '0' to print all list) "<<endl;
        cout<<"4.main Menu"<<endl;
        cout<<"5.End program"<<endl;        
        
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
    case 1:cout<<ebi.flith_number_maker()<<" is your special flith_number"<<endl;       break;

    
    case 2:cout<<"Enter the flight number:"; int airplain; cin>>airplain;ebi.deletespecific(airplain);       break;

    
    case 3:int band ;cout<<"Enter the band number:" ;cin >> band;ebi.translator(band);       break;

    
    case 4:goto help ;   
       break;
         
        }
  }
    return 0;
}

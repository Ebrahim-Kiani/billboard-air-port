#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int flith_number_maker();
int find_type(int);
int Band_capacity(int,int [],int);
int main(){

    cout<<flith_number_maker()<<" is your special flith_number"<<endl;
    
    
    return 0;
}
int flith_number_maker(){
    int answer=0;
    int clock_flith_hour;
    string clock_flith_minute;
    string type;
    int model;
    int band;
    int passengers;
    int flith_number[1000];         // test
    for(int i=0 ; i < 1000 ; i++)
    flith_number[i]=0;
    
   
    
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
        cout << "Enter type of flith( 'landing' or 'take-off'): ";
        cin >> type;
        if(type=="landing"){
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
               answer=answer+(1000 * model);
                  cout<<"Band capacity:"<<Band_capacity(i , flith_number ,answer )<<endl;
               break;
           }
           
       }if(yellow_lamp==0)cout<<"All suitable bands are full you must try again at 30 minutes later"<<endl;
        
    // passengers
    cout<<"Enter the number of passengers:";
    cin >> passengers;
    answer +=passengers;
        // finished
        
        return answer;
        
        }else{ // **************************************important************************
            
            }
}
int find_type(int number){
    char find[10];
        sprintf(find, "%d", number);
       if(find[3]=='0')
       return 0;
       else
       return 1;
};
int Band_capacity(int band , int flith_number_[1000] , int time_){
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
























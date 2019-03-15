/*
* Project Title:
* - You Are Trapped!
* Description: 
* This is a Zork like game, where you are trapped in a house and must get out by finding the key.
*
* Developers:
* - Kartikey Pandey - pandeykh@mail.uc.edu
* - Krishnan Srinivasan- srinivkn@mail.uc.edu
*
* Help Received:
* - Adedapo Alabi
*
* Developer comments: 
* Kartikey Pandey:
* Programmed different functions for the game and did the required testing to ensure that game *was working properly.
* Krishnan Srinivasan:
* Created certain functions that pertained to different rooms such as living room and room 1, and 
*helped come up with the storyline, also involved in testing and debugging. Learnt more about functions and function calls from working on this project.
*/



#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

bool flashlight=0;
bool hammer=0;
bool batteries=0;
bool key_card=0;
bool final_key=0;

bool lobby=1;
bool upstairs=0;
bool lr=0;
bool kitchen=0;
bool storage=0;
bool room1=0;
bool room2=0;

bool cab1_kitchen=0;
bool cab2_kitchen=0;
bool TV_cabinet=0;

bool playing=1;

void Lobby();
void Livingroom();
void Room1();
void Room2();
void Kitchen();
void Upstairs();
void Cab_kitchen();
void TVcab();
void room1_cabinet();
void room2_cabinet();

/* Function Name: instructions
 *
 * Function Description:
 * This function prints out basic description of the game and the rules to play the game.
 *
 * Parameters:None
 * return value: void
 */

void instructions(){
 cout<<"Welcome to \"YOU ARE TRAPPED!\""<<endl<<endl;
 system("Pause"); cout<<endl;
 cout<<"It is a dark night and you're driving back home after a vacation to the countryside.\nSuddenly your car stutters and breaks down in the middle of the road.\nYou sigh and get out of the car to see what's wrong,";
 cout<<"You can see smoke coming out from the front of the car. Having no tools, you take your phone out to call for help but its battery is dead."<<endl;
 cout<<"You are in the middle of a deserted road around midnight and you see no other cars.(You really should've brought those tools...)"<<endl;
 cout<<"You look around to see if you can find help and notice a house in the distance with lights turned on."<<endl<<endl;
 system("Pause"); cout<<endl;
 cout<<"You walk towards the house. You knock on the door but the door is unlocked and it creaks open.\nYou shout,\"Hello, is anyone there?\"\n No one answers."<<endl;
 cout<<"You take two steps forward and the door closes shut behind you. The lights start flickering."<<endl;
 cout<<"You try to open the door but somehow it locked itself... YOU ARE TRAPPED!"<<endl;
 cout<<"Objective: GET OUT OF HERE!!!.\nTo achieve that you will have to find the key to the house."<<endl;
 cout<<"Good Luck!"<<endl<<endl;
 system("Pause");cout<<endl;
}

/* Function Name: Upstairs
 *
 * Function Description:
 * This function provides the player with possible options when they are in the upstairs portion  * of the house.
 * Parameters:
 * none
 * return value:
 * void function
 */

void Upstairs(){
  cout<<endl<<endl;
  int ch=0;
  cout<<"You are in the upstairs lobby.\nYou can see three doors on this floor.\nWhat will you do next?"<<endl;
  do{
  cout<<"1) Open the only door on the left\nThere are two doors on your right.\n2) Open the first door on your right.\n3)Open the second door on your right.\n4)Or do you want to go downstairs again?\n Enter 0 to exit the game."<<endl;
  cin>>ch;
  switch(ch){
      case 0: playing=0;
              cout<<"Thank you for playing the game!"<<endl;
               break;
      case 1: lr=1;
              upstairs=0;
              Livingroom();
              break;
      case 2: room2=1;
              upstairs=0;
              Room2();
              break;
      case 3: room1=1;
              upstairs=0;
              Room1();
              break;
      case 4: lobby=1;
              upstairs=0;
              Lobby();
      default: cout<<"Invalid choice."<<endl;
               ch=-1;
               break;
  }
  }while(ch==-1);
}

/* Function Name: Cab_kitchen
 *
 * Function Description:
 * This function provides options once the kitchen cabinet has been opened.
 *
 * Parameters:
 * none
 * return value:
 * void
 */

void Cab_kitchen(){
  cout<<endl<<endl;
  int cab1_ch=0;
  int cab2_ch=0;
  if(cab1_kitchen==1){
      cout<<"You open the first cabinet.\nYou see a lot of objects inside."<<endl;
      do{
          cout<<"You can see the following objects:\n1)Fruity Loops\n2)Crackers\n3)Cookie Boxes\n4)Flashlight"<<endl;
          cout<<"What do you choose?"<<endl;
          cin>>cab1_ch;
          if(cab1_ch==4){
           if(batteries!=1){
               cout<<"You pick up the flashlight and try to turn it on, but you quickly realise that it needs batteries."<<endl;
               cout<<"There must be some batteries somewhere in this godforsaken house..."<<endl;
              }
           else{
               cout<<"You pick up the flashlight for later use!"<<endl;
           }
          flashlight=1;
          }
          else{
              cout<<"Mmm, tasty! You satisfy your hunger but this isn't going to help you get out of here! Pick something else."<<endl;
          }
      }while(!flashlight);
      cab1_kitchen=0;
  }
  else{
      cout<<"You open the second cabinet and see a bunch of potentially useful things."<<endl;
      do{
          cout<<"You can see the following objects:\n1)Screw Driver\n2)Hammer\n3)Knife"<<endl;
          cout<<"What do you choose?"<<endl;
          cin>>cab2_ch;
          if(cab2_ch==2){
              cout<<"You pick up the hammer for later use."<<endl;
              hammer=1;
          }
          else{
              cout<<"It is not an useful object, choose again."<<endl;
          }
      }while(!hammer);
      cab2_kitchen=0;
  }
  Kitchen();
}

/* Function Name: Kitchen()
 *
 * Function Description:
 * This function provides the player with several options once they enter the kitchen.
 * Parameters:
 * none
 *
 * return value:
 * void
 */

void Kitchen(){
  cout<<endl<<endl;
  int ch=0;
  cout<<"You are in the kitchen."<<endl;
  cout<<"You can see two unlocked cabinets in the kitchen."<<endl;
  cout<<"What will you do next?"<<endl;
  do{
  cout<<"1) Open the first cabinet\n2) Open the second cabinet\n3)Go back to the lobby.\n Enter 0 to exit the game."<<endl;
  cin>>ch;
  switch(ch){
      case 1: cab1_kitchen=1;
              Cab_kitchen();
              break;
      case 2: cab2_kitchen=1;
              Cab_kitchen();
              break;
      case 3: lobby=1;
              kitchen=0;
              Lobby();
              break;
      case 0: playing=0;
              cout<<"Thank you for playing the game!"<<endl;
              break;
      default: cout<<"Invalid choice."<<endl;
               break;
  }
  }while(ch==-1);
}

/* Function Name: TVcab()
 *
 * Function Description:
 * This function lists the stuff in the tv cabinet in the living room. *
 * Parameters:
 *  none 
 * return value:
 * void
 */

void TVcab(){
  cout<<endl<<endl;
  int uchoice;
  do{
      cout<<"You open the cabinet drawer and see some items in it."<<endl;
      cout<<"Pick something up!\n1)Batteries\n2)A Book\n3)TV Remote"<<endl;
      cin>>uchoice;
      switch(uchoice){
          case 1: cout<<"You pick up the batteries for later use."<<endl;
                  batteries =1;
                  break;
          case 2: cout<<"You could read the book, but there's still the fact that you're stuck in a creepy house!"<<endl;
                  cout<<"Try picking up something else."<<endl;
                  break;
          case 3: cout<<"The TV remote looks brand new, but pressing the power button does nothing."<<endl;
                  cout<<"See what else is in the cabinet."<<endl;
                  break;
          case 0: cout<<"Thanks for playing the game!"<<endl;
                  break;
          default:cout<<"Invalid choice!"<<endl;
                  break;
                
      }
  }while(uchoice==-1);
  Upstairs();
}

/* Function Name: room1_cabinet
 *
 * Function Description:
 * This function is called when the user opens the room1 cabinet. It prints out all the prompts for the user when he opens the cabinet.
 *
 * Parameters:none
 * return value:void
 */

void room1_cabinet(){
  string choice;
  cout<<"You turn on the flashlight and look around the room. Something shiny catches your eye."<<endl;
  cout<<"Upon further investigation, you realise there’s a cabinet and decide to look inside it."<<endl;
  cout<<"It opens effortlessly and you see a key."<<endl;
  cout<<"Do you want to pick up the key?\n Enter Yes or No.\n";
  cin>>choice;
  if(choice=="Yes"|| choice=="yes"){
      final_key=1;
      cout<<"You pick up the key and examine it. The craftsmanship is extraordinary."<<endl;
      cout<<"Suddenly, a cold chill travels down your spine and you shiver in excitement.\n Could this be it? Could this be the way out, to freedom?"<<endl;
      cout<<"Your heart races as you run out the room and down the stairs two steps at a time, and reach the front door."<<endl;
      cout<<"Hands trembling in anticipation, you fumble with the key and drop it. Cursing under your breath, you pick it up and try again."<<endl;
      cout<<"The key slides in. You turn it, and hear a satisfying click. A gentle nudge opens the door. You step outside, and feel the cool breeze blowing."<<endl;
      cout<<"As you walk down the road to where your car was, you make a mental note: \"Don't walk into weird houses again...\""<<endl;
      cout<<"You look up to where you left your car. Only to find out it's not there anymore. RIGHT WHEN YOU THOUGHT THIS DAY COULDN'T GET WORSE."<<endl;
      cout<<"Congratulations! You won the game!"<<endl;
  }
  else if(choice=="No"||choice=="no"){
      cout<<"You decide not to pick up the key. Guess who's not getting out of this house?"<<endl;
  }
}

/* Function Name: room2_cabinet
 *
 * Function Description:
 * This function is called when the user opens the room2 cabinet. It prints out all the prompts for the user when he opens the cabinet.
 *
 * Parameters:none
 * return value:void
 */

void room2_cabinet(){
  string choice;
  cout<<"You turn on the flashlight and look around the room."<<endl;
  cout<<"You see a closed closet."<<endl;
  cout<<"You open the closet to go through it. You find a drawer."<<endl;
  cout<<"After opening the drawer, you find a keycard.\nDo you want to pick up the key?\n Enter Yes or No.\n";
  cin>>choice;
  if(choice=="Yes"|| choice=="yes"){
     key_card=1;
  }
  else if(choice=="No"||choice=="no"){
      cout<<"You decide not to pick up the key. Guess who's not getting out of this house?"<<endl;
  }
}

/* Function Name: livingroom
 *
 * Function Description:
 * This function is called when the user enters the living room. It prints out all the prompts for the user when he is in the living room.
 *
 * Parameters:none
 * return value:void
 */

void Livingroom(){
  cout<<endl<<endl;
  int ch=0;
  do{
       cout<<"You are inside the living room now."<<endl;
       cout<<"You see a TV cabinet."<<endl;
       cout<<"What will your next step be?\n 1)Open the TV Cabinet\n2)Go back to the upstairs lobby";
       cin>>ch;
       switch(ch){
           case 1:  TV_cabinet=1;
               upstairs=0;
               TVcab();
               break;
           case 2:  upstairs=1;
               Upstairs();
           default: cout<<"Invalid choice."<<endl;
               ch=-1;
               break;
       }
  }while(ch==-1);
}

/* Function Name: Room1
 *
 * Function Description:
 * This function is called when the user enters room1. It prints out all the prompts for the user when he is in the room.
 *
 * Parameters:none
 * return value:void
 */

void Room1(){
  cout<<endl<<endl;
  if(key_card==1&&flashlight==1&&batteries==1){
      cout<<"You open the second door on the right using the Key Card. This room is dark as well, so you pull out your flashlight."<<endl;
  }
  else if(key_card==1 || (key_card==1&&flashlight==1)){
      cout<<"You open the door but it's dark inside and you can't see anything."<<endl;
      cout<<"You are back in the upstairs lobby"<<endl;
      Upstairs();
  }
  else{
      cout<<"The door is locked. You don't have the key to open this door yet."<<endl;
      cout<<"You are back in the upstairs lobby"<<endl;
      Upstairs();
  }
  room1_cabinet();
 
}

/* Function Name: Room2
 *
 * Function Description:
 * This function is called when the user enters room2. It prints out all the prompts for the user when he is in the room.
 *
 * Parameters:none
 * return value:void
 */

void Room2(){
  cout<<endl<<endl;
  if(hammer==1&&flashlight==1&&batteries==1){
      cout<<"You break the lock on the door. You are inside the secondary bedroom."<<endl;
  }
  else if(hammer==1|| (hammer==1&&flashlight==1)){
      cout<<"You break the lock and enter but it's dark inside and you can't see anything."<<endl;
      cout<<"You are back in the upstairs lobby"<<endl;
      Upstairs();
  }
  else{
      cout<<"The door is locked. You don't have the key to open this door yet."<<endl;
      cout<<"You are back in the upstairs lobby"<<endl;
      Upstairs();
  }
   room2_cabinet();
   Upstairs();
}

/* Function Name: Lobby
 *
 * Function Description:
 * This is the first function called. It prints out all the prompts for the user when he is in the lobby.
 *
 * Parameters:none
 * return value:void
 */

void Lobby(){
  cout<<endl<<endl;
  int ch=0;
  do{
      cout<<"You are inside the house:\nWhat do you want to do next?\n1)Open the door on the left\n2)Go Upstairs\nEnter 0 to exit the game."<<endl;
      cin>>ch;
      switch(ch){
          case 2: upstairs=1;
                  lobby=0;
                  Upstairs();
                  break;
          case 1: kitchen=1;
                  lobby=0;
                  Kitchen();
                  break;
          case 0: playing=0;
                  cout<<"Thank you for playing the game!"<<endl;
                  break;
          default:cout<<"Invalid choice."<<endl;
                  ch=-1;
                  break;
      }
  }while(ch==-1);
}

int main(){

  instructions();
  Lobby();

  return 0;
}
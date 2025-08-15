#include <iostream>
using namespace std;
#include "redBlackTree.h"
int main() {
redBlackTree tree;
cout<<"Welcome to a basic red black tree project"<<endl;
string ans="2";
while(ans!="1"){
cout<<"Enter 1 to begin:"<<endl;
cin>>ans;
if (ans != "1") {
        cout<<"1 hasn't been entered"<<endl;
    }
}
string answer="9";
while(answer!="5"){
cout<<"______________________Menu______________________"<<endl;
cout<<"Chose option from menu"<<endl;
cout<<"[1] Insert"<<endl;
cout<<"[2] Delete"<<endl;
cout<<"[3] Print"<<endl;
cout<<"[4] Check value count"<<endl;
cout<<"[5] Terminate"<<endl;
cin>>answer;
if(answer=="1"){
int ins;
cout<<"input number to insert"<<endl;
cin>>ins;
tree.insert(ins);
}
else if(answer=="2"){
int ins;
cout<<"input number to delete"<<endl;
cin>>ins;
tree.remove(ins);
}
else if(answer=="3"){
tree.print();
}
else if(answer=="4"){
int ins;
cout<<"input number to count"<<endl;
cin>>ins;
tree.getValCount(ins);
}
else if(answer=="5"){
cout<<"Process Terminated"<<endl;
return 0;
}
else{
cout<<"An option has not been picked"<<endl;
}
}
}
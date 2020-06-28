#include<iostream>
#include<cstring>
#include "hashtable.h"

using namespace std;
int main(){
 hashtable<int>price_menu;
 price_menu.insert("Burger",100);
 price_menu.insert("Pizza",120);
 price_menu.insert("Potato",160);
 price_menu.insert("IceCream",130);
 price_menu.insert("Coldrink",190);
 price_menu.insert("Samosa",10)
 price_menu.print();

 int *price= price_menu.search("IceCream");
 if(price==NULL){
 	cout<<"Not Found"<<endl;
 }
 else{
 	cout<<"Price is "<<*price<<endl;
 }
 price_menu["Dosa"]=60;
 price_menu["Dosa"]+=10;
 cout<<price_menu["Dosa"]<<endl;
 return 0;
}
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <iterator>
#include <map>

using namespace std;

//Item_Paper_Notebook_Pencil_Pen
class Item{

protected:
string name; //onoma proiontos
    double price; //timh proiontos se euro
    string description; // perigrafh proiontos
    int stock=stock; //diathesimh posothta proiontos
    int id; //kwdikos proiontos

	public:
void getDetails();
string getName();
double getPrice();
string getDescription();
int getId();
int getStock();
void setStock(int newStock);
void getBasicInfo();
friend class ItemOrdered;
};
string Item::getDescription(){return description;}
double Item::getPrice(){return price;}
string Item::getName(){return name;}
int Item::getId(){return id;}
int Item::getStock(){return stock;}
void Item::setStock(int newStock){
stock=newStock;
}
void Item::getBasicInfo(){
cout<<"\n-------------------\n";
cout<<"\tBasic Info\nName: "<<getName()<<"\nPrice: "<<getPrice() <<"\nDescription: "<<getDescription() <<"\nStock: "<<getStock() <<"\nID: "<< getId();
}

class Notebook: public Item
{
protected:
int sections; //arithmos thematvn
public:
Notebook(string nname, double nprice, string ndescription, int nstock,  int nid, int nsections)
    {
name = nname;
price = nprice;
description = ndescription;
stock = nstock;
id = nid;
sections = nsections;
    }
    virtual void getDetails(void);
int getSections(void);
};
int Notebook::getSections(void)
{
return sections;
}
void Notebook::getDetails(void)
{
cout<<"\n-------------------\n";
cout<<"\tDetails\nsections: "<<getSections();
}

class Paper: public Item{
public:
int weight;
int pages;
Paper(string pname, double pprice, string pdescription, int pstock,  int pid, int pweight, int ppages)
    {
name = pname;
price = pprice;
description = pdescription;
stock = pstock;
id = pid;
weight = pweight;
    pages = ppages;
    }
int getweight(void);
int getpages(void);
virtual void getDetails(void);
};
int Paper::getpages(void){
return pages;
}
int Paper::getweight(void){
return weight;
}
void Paper::getDetails(void){
cout<<"\n-------------------\n";
cout<<"\tDetails\nweight: "<<getweight()<<"\npages: "<<getpages();
}

class Pen: public Item {
public:
string color;
double tipSize; //megethos se mm
  Pen(string penname, double penprice, string pendescription, int penstock,  int penid, string pencolor, double pentipSize)
    {
name = penname;
price = penprice;
description = pendescription;
stock = penstock;
id = penid;
color = pencolor;
tipSize = pentipSize;
    }
  string getColor(void);
    virtual void getDetails(void);
     double gettipSize(void);
};
string Pen::getColor(void){
return color;
}
double Pen::gettipSize(void){
return tipSize;
}

void Pen::getDetails(void){
cout<<"\n-------------------\n";
cout<<"\tDetails\ncolor: "<<getColor()<<"\ntipSize(megethos se mm): "<<gettipSize();

}

class Pencil: public Item{

public:
double tipSize;
string type;
Pencil(string pencname, double pencprice, string pencdescription, int pencstock,  int pencid, string penctype, double penctipSize)
    {
name = pencname;
price = pencprice;
description = pencdescription;
stock = pencstock;
id = pencid;
type = penctype;
tipSize = penctipSize;
    }
virtual void getDetails(void);
string getType(void);
double gettipSize(void);
};
string Pencil::getType(void){

return type;
}
void Pencil::getDetails(void){
cout<<"\n-------------------\n";
cout<<"\tDetails\ntype: "<<getType()<<"\ntipSize(megethos se mm): "<<gettipSize();
}
double Pencil::gettipSize(void){
return tipSize;
}

//User_Owner_Buyer
class User
{
protected:
string name;
string email;

public:
string getName( void );
string getEmail( void );
void setName( string newName );
void setEmail( string newEmail );
};

void User::setEmail(string newEmail){
email = newEmail;
}
void User::setName(string newName){
name = newName;
}
string User::getName( void ){
return name;
}
string User::getEmail( void ){
return email;
}

class Owner: public User
{
public:
    bool isAdmin = true;

Owner(string oname, string oemail)
    {
name = oname;
        email = oemail;
    }
    bool getAdmin( void );
};
bool Owner::getAdmin( void ){
return isAdmin;
}
class Buyer: public User
{
protected:
int bonus=1;
string buyerCategory ="BRONZE";
public:

Buyer(string bname, string bemail)
    {
        name = bname;
        email = bemail;
    }
    float awardBonus( void );
    string setbuyerCategory( void );
    void placeOrder( void );
friend class ShoppingCart;

};
   float Buyer::awardBonus( void ){
return bonus+bonus*0.2;
}
string Buyer::setbuyerCategory( void ){
if (awardBonus()<100){
cout<<buyerCategory<<endl;
}
else if (awardBonus()>=100 && awardBonus()<200){

buyerCategory="SILVER";
cout<<buyerCategory<<endl;
}
else if(awardBonus()>200) {
buyerCategory="GOLD";
cout<<buyerCategory<<endl;
}
return buyerCategory;
}
void Buyer::placeOrder( void ){

}

class ItemOrdered: public Item
{
public:
Item item;
int quantity;
ItemOrdered(Item it, int quantit)
    {
int newSt;

if(quantit <= it.getStock()){
quantity=quantit;
newSt = it.getStock()-quantity;
}
else{
cout<<"\n-------------------\n";
cout<<"\nCannot buy so many: "<<it.getName()<<"s"<<endl;
quantit=0;
}
it.setStock(newSt);
    }
int getQuantity(void);
void setQuantity(Item it, int newQuan);
void getItem(Item it);
};
void ItemOrdered ::getItem(Item it){
return it.getBasicInfo();
}
int ItemOrdered::getQuantity(void){
return quantity;
}
void ItemOrdered::setQuantity(Item it, int newQuan){
quantity = newQuan;
int newSt;
newSt = it.getStock()- newQuan;
it.setStock(newSt);
}


//EShop


class EShop: public User, public Item{
public:
string name;
    User owner;

    list <Item*> itemsList;
list <Buyer*> buyersList;
EShop(User own, string name){
        name = name;
    }
	void addItem(Item itemtoadd);
    void addBuyer(Buyer buyertoadd);
	void getItemById(void);
    void removeItem(Item itemtoremove);
    void removeBuyer(Buyer buyertoremove);
    int updateItemStock();
    void showCategories();
    void showProductsInCategory();
    void showProduct(Item it);
    void checkStatus();
};
void EShop::addItem(Item itemtoadd)
{
    itemsList.push_back(&itemtoadd);
    cout<<"\n-------------------\n";
cout<<"Item added";
}
void EShop::getItemById(void)
{
int itemid;
cout<<"Give ID of product: ";
cin>>itemid;
list<Item*>::iterator it;
for (list<Item*>::iterator it = itemsList.begin(); it != itemsList.end(); it++)
{
if(id==itemid){
cout<<*it;
}
}
}
void EShop::removeItem(Item itemtoremove)
{
    itemsList.remove(&itemtoremove);
    cout<<"\n-------------------\n";
cout<<"\nItem removed"<<endl;
}
void EShop::addBuyer(Buyer buyertoadd){
	 buyersList.push_back(&buyertoadd);
cout<<"\n-------------------\n";
cout<<"\nBuyer added"<<endl;   
}
void EShop::removeBuyer(Buyer buyertoremove)
    {
    buyersList.remove(&buyertoremove);
cout<<"\n-------------------\n";
cout<<"\nBuyer removed"<<endl;    
}  
int EShop::updateItemStock()
    {
    return 0;
    }  
void EShop::showCategories()
    {
    cout<<"\n-------------------\n";
cout<<"Pen \nPencil \nNotebook \nPaper"<<endl;
}
void EShop::showProduct(Item it)
{
    cout<<"\n-------------------\n";
it.getBasicInfo();
}
void EShop::showProductsInCategory()
    {
cout<<"\n-------------------\n";
list<Item*>::iterator it;
for (auto it = itemsList.begin(); it != itemsList.end(); it++){
cout <<*it<<"  "<<&name<<"\n-------------------\n";
   
}
cout<<"List Size: "<<itemsList.size()<<endl;
}

void EShop::checkStatus(){
cout<<"\n-------------------\n";
list<Buyer*>::iterator it;
for (list<Buyer*>::iterator it = buyersList.begin(); it != buyersList.end(); it++){
cout <<*it<<"  "<<&name<<"\n-------------------\n";
   
}
cout<<"Total number of Buyers: "<<buyersList.size()<<endl;
}

//ShoppingCart


class ShoppingCart//: public Buyer, public Item
{
	public:
	list <ItemOrdered*> itemsorderedList;
	void addItemOrdered(ItemOrdered itemadd);
	void removeItemOrdered(ItemOrdered itremove);
	void changeItemOrderedQuantity(ItemOrdered itnewquan, int newquan);
	void showCart();
	void clearCart();
	void checkout();
	float calculateNet();
	float calcluateCourierCost();	
};
void ShoppingCart::addItemOrdered(ItemOrdered itemadd){
	itemsorderedList.push_back(&itemadd);
    cout<<"\n-------------------\n";
cout<<"Item added to Shopping Cart";
}
void ShoppingCart::removeItemOrdered(ItemOrdered itremove)
{
	itemsorderedList.remove(&itremove);
    cout<<"\n-------------------\n";
cout<<"Item removed from Shopping Cart";
}
void ShoppingCart::changeItemOrderedQuantity(ItemOrdered itnewquan, int newquan){
	itnewquan.setQuantity(itnewquan, newquan);
}
void ShoppingCart::showCart(){
	cout<<"\n-------------------\n";
list<ItemOrdered*>::iterator it;
for (list<ItemOrdered*>::iterator it = itemsorderedList.begin(); it != itemsorderedList.end(); it++){
cout <<*it<<"  "<<"\n-------------------\n";  
}
cout<<"List Size: "<<itemsorderedList.size()<<endl;
}
void ShoppingCart::clearCart(){
	itemsorderedList.clear();
}
void ShoppingCart::checkout(){
	Buyer b(" "," ");
	string answer;
	showCart();
	cout<<"Continue to Payment? (yes / no)"<<endl;
	getline(cin,answer);//Eisodos apo ton xrhsth gia plhrvmh h eksodo apo to Shopping Cart
	if(answer=="yes"){
	b.awardBonus();
	
}
	else 
	{
cout<<"Exit from Shopping Cart"<<endl;  
}
}
float ShoppingCart::calculateNet(){
float totalprice;
list<ItemOrdered*>::iterator it;
Item i;
for (list<ItemOrdered*>::iterator it = itemsorderedList.begin(); it != itemsorderedList.end(); it++){
	totalprice=totalprice+i.getPrice();
	}
	return totalprice;		
}
float ShoppingCart::calcluateCourierCost(){
	float courier;
	courier=calculateNet()*0.2;
	Buyer b(" "," ");
	if (b.awardBonus()>200){
	courier=0;
}
	else if (b.awardBonus()>=100 && b.awardBonus()<200){
	
		courier=courier-courier*0.5;		
}
return courier;
}


class Menu{
public:
string mname; //onoma proiontos
    double mprice; //timh proiontos se euro
    string mdescription; // perigrafh proiontos
    int mstock; //diathesimh posothta proiontos
    int mid; //kwdikos proiontos
int msections;
int mweight;
int mpages;
string mcolor;
double mtipSize; //megethos se mm
string mtype;
int mquantity;
int menu();
string ename;
string eemail;
};


int Menu::menu(){
	int ans;
	
	int buyerorowner;
do{
cout<<"Are you an: \n0.Owner\n1.Buyer\n(Choose the right Number 0 or 1)"<<endl;
cin>>buyerorowner;

}while(buyerorowner!=1&&buyerorowner!=0);
	
	if (buyerorowner==0){
	cout<<"\tOwner\nGive Email: ";
	cin>>eemail;
	cout<<"\nGive Name(With . after the end of the name): ";
	getline(cin, ename, '.');
	Owner own(ename, eemail);
	EShop e(own, "ESHOP");
		do{
		cout<<"\n1.addItem\t2.updateItemStock\t3.showCategories\n(Choose by number 0 to exit)"<<endl;
		cin>>ans;
		if(ans==1){
			cout<<"\nChoose a Category(By Number): \n1.Pen\n2.Pencil\n3.Notebook\n4.Paper"<<endl;
			int cat;
			cin>>cat;
			if(cat==1){
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";
				getline(cin,mdescription,'.');
				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give color(With . after the end): ";
				getline(cin,mcolor,'.');
				cout<<"Give tipSize: ";
				cin>>mtipSize;
				Pen p(mname,mprice,mdescription,mstock,mid,mcolor,mtipSize);
				e.addItem(p);
			}
			else if(cat==2)
			{
				cout<<"Give name(with . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";
				getline(cin,mdescription,'.');
				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give type(With . after the end): ";
				getline(cin,mtype,'.');
				cout<<"Give tipSize: ";
				cin>>mtipSize;
				Pencil p(mname,mprice,mdescription,mstock,mid,mtype,mtipSize);
				e.addItem(p);
			}
			else if(cat==3)
			{
				cout<<"Give name(With . after the end of the name): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";
				getline(cin,mdescription,'.');
				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give sections: ";
				cin>>msections;
				Notebook n(mname,mprice,mdescription,mstock,mid,msections);
				e.addItem(n);
			}
			else if(cat==4)
			{
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";
				getline(cin,mdescription,'.');

				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give weight: ";
				cin>>mweight;
				cout<<"Give pages: ";
				cin>>mpages;
				Paper p(mname,mprice,mdescription,mstock,mid,mweight,mpages);
				e.addItem(p);
			}
		}
		else if(ans==2){
			int newstoc;
			cout<<"Give new Stock\n";
			cin>>newstoc;
		}
		else if(ans==3){
			e.showCategories();	
		}
		}while(ans!=0&&ans<4);
	
	
	}
	else if (buyerorowner==1){
		Owner own(" "," ");
	EShop e(own, " ");
	cout<<"\tBuyer\nGive Email: ";
	cin>>eemail;
	cout<<"\nGive Name(With . after the end): ";
	getline(cin,ename,'.');
	Buyer buy(ename, eemail);
	e.addBuyer(buy); 
		cout<<"1.addItemOrdered\t2.removeItemOrdered\t3.changeItemOrderedQuantity\n4.showCart\t5.clearCart\t6.checkout\n7.calculateNet\n8.calcluateCourierCost\n(Choose by Number 0 to exit)"<<endl;
		ShoppingCart sc;
	do{
		cin>>ans;
		if(ans==1){
			cout<<"Choose a Category(By Number): \n1.Pen\n2.Pencil\n3.Notebook\n4.Paper"<<endl;
			int cat;
			cin>>cat;
			if(cat==1){
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give Description(With . after the end): ";

				getline(cin,mdescription,'.');

				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give color: ";
				getline(cin,mcolor);
				cout<<"Give tipSize: ";
				cin>>mtipSize;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Pen p(mname,mprice,mdescription,mstock,mid,mcolor,mtipSize);
				ItemOrdered io(p,mquantity);
				sc.addItemOrdered(io);
			}
			else if(cat==2)
			{
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";

				getline(cin,mdescription,'.');

				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give type(With . after the end): ";
				getline(cin,mtype,'.');
				cout<<"Give tipSize: ";
				cin>>mtipSize;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Pencil p(mname,mprice,mdescription,mstock,mid,mtype,mtipSize);
				ItemOrdered io(p,mquantity);
				sc.addItemOrdered(io);
			}
			else if(cat==3)
			{
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";
				getline(cin,mdescription,'.');
				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give sections: ";
				cin>>msections;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Notebook n(mname,mprice,mdescription,mstock,mid,msections);
				ItemOrdered io(n,mquantity);
				sc.addItemOrdered(io);
			}
			else if(cat==4)
			{
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";
				getline(cin,mdescription,'.');
				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give weight: ";
				cin>>mweight;
				cout<<"Give pages: ";
				cin>>mpages;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Paper p(mname,mprice,mdescription,mstock,mid,mweight,mpages);
				ItemOrdered io(p,mquantity);
				sc.addItemOrdered(io);
			}
		}
		else if(ans==2){
		int cat;
		cout<<"Choose a Category(By Number): \n1.Pen\n2.Pencil\n3.Notebook\n4.Paper"<<endl;
		cin>>cat;
			if(cat==1){
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";

				getline(cin,mdescription,'.');

				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give color(With . after the end): ";
				getline(cin,mcolor,'.');
				cout<<"Give tipSize: ";
				cin>>mtipSize;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Pen p(mname,mprice,mdescription,mstock,mid,mcolor,mtipSize);
				ItemOrdered io(p,mquantity);
				sc.removeItemOrdered(io);
			}
			else if(cat==2)
			{
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";

				getline(cin,mdescription,'.');

				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give type(With . after the end): ";
				getline(cin,mtype,'.');
				cout<<"Give tipSize: ";
				cin>>mtipSize;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Pencil p(mname,mprice,mdescription,mstock,mid,mtype,mtipSize);
				ItemOrdered io(p,mquantity);
				sc.removeItemOrdered(io);
			}
			else if(cat==3)
			{
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";

				getline(cin,mdescription,'.');

				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give sections: ";
				cin>>msections;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Notebook n(mname,mprice,mdescription,mstock,mid,msections);
				ItemOrdered io(n,mquantity);
				sc.removeItemOrdered(io);
			}
			else if(cat==4)
			{
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";

				getline(cin,mdescription,'.');

				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give weight: ";
				cin>>mweight;
				cout<<"Give pages: ";
				cin>>mpages;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Paper p(mname,mprice,mdescription,mstock,mid,mweight,mpages);
				ItemOrdered io(p,mquantity);
				sc.removeItemOrdered(io);
			}
		}
		else if(ans==3){
			int cat;
		cout<<"Choose a Category(By Number): \n1.Pen\n2.Pencil\n3.Notebook\n4.Paper"<<endl;
		cin>>cat;
			if(cat==1){
				cout<<"Give name: ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";

				getline(cin,mdescription,'.');

				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give color(With . after the end): ";
				getline(cin,mcolor,'.');
				cout<<"Give tipSize: ";
				cin>>mtipSize;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Pen p(mname,mprice,mdescription,mstock,mid,mcolor,mtipSize);
				ItemOrdered io(p,mquantity);
				sc.changeItemOrderedQuantity(io,mquantity);
			}
			else if(cat==2)
			{
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";

				getline(cin,mdescription,'.');

				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give type(With . after the end): ";
				getline(cin,mtype,'.');
				cout<<"Give tipSize: ";
				cin>>mtipSize;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Pencil p(mname,mprice,mdescription,mstock,mid,mtype,mtipSize);
				ItemOrdered io(p,mquantity);
				sc.changeItemOrderedQuantity(io, mquantity);
			}
			else if(cat==3)
			{
				cout<<"Give name(With . after the end): ";
				cin>>mname;
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";
				getline(cin,mdescription,'.');
				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give sections: ";
				cin>>msections;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Notebook n(mname,mprice,mdescription,mstock,mid,msections);
				ItemOrdered io(n,mquantity);
				sc.changeItemOrderedQuantity(io, mquantity);
			}
			else if(cat==4)
			{
				cout<<"Give name(With . after the end): ";
				getline(cin,mname,'.');
				cout<<"Give price: ";
				cin>>mprice;
				cout<<"Give description(With . after the end): ";

				getline(cin,mdescription,'.');

				cout<<"Give stock: ";
				cin>>mstock;
				cout<<"Give id: ";
				cin>>mid;
				cout<<"Give weight: ";
				cin>>mweight;
				cout<<"Give pages: ";
				cin>>mpages;
				cout<<"Give Quantity: ";
				cin>>mquantity;
				Paper p(mname,mprice,mdescription,mstock,mid,mweight,mpages);
				ItemOrdered io(p,mquantity);
				sc.changeItemOrderedQuantity(io, mquantity);
			}	
		}
		else if(ans==4){
			sc.showCart();
		}
		else if(ans==5){
			sc.clearCart();	
		}
		else if(ans==6){
			sc.checkout();	
		}
		else if(ans==7){
			sc.calculateNet();	
		}
		else if(ans==8){
			sc.calcluateCourierCost();	
		}
		}while(ans!=0&&ans<8);
	
	}
	cout<<"\nThank you for Choosing us for your Shopping Good Bye :)\n"<<endl;
}



//Main
int main(){
Paper p("Paper",5.90,"Piece of Paper", 4, 1051,150,10);
Pen pen("Pen",0.90,"A Pen", 4, 1051,"Blue",10);
Pencil pencil("Pencil",0.90,"A Pencil", 4, 1051,"H",10);
Notebook n("Notebook", 1.90,"A Notebook", 10, 1051, 3);
cout<<"\tCatalogue"<<endl;
cout<<"\n--------------------\n";
cout<<"\n\tPencil";
pencil.getBasicInfo();
pencil.getDetails();
cout<<"\n--------------------\n";
cout<<"\n\tPaper";
p.getBasicInfo();
p.getDetails();
cout<<"\n--------------------\n";
cout<<"\n\tPen";
pen.getBasicInfo();
pen.getDetails();
cout<<"\n--------------------\n";
cout<<"\n\tNotebook";
n.getBasicInfo();
n.getDetails();
cout<<"\n\n--------------------\n\n";
Menu m;
m.menu();
system("PAUSE");
return 0;

}

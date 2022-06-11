#include <iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>

using namespace std;
struct Node{
	string name,id,dept;
	int sal;
	struct Node *next;
}*head=NULL;





 void update(){
 	struct Node *p=head;
 	
 	if(p==NULL)return;
 	int f=0;
 	string id1;
 		cout<<"Enter id of employee you want to update: ";
		cin>>id1;
 	while(p!=NULL){
 		
		if(p->id==id1){
			f=1;
			cout<<"Enter the new details of the employee: "<<endl;
			string namen,idn,deptn;
			int saln;
cout<<"enter new name: ";
cin>>namen;
cout<<"enter new id: ";
cin>>idn;
cout<<"enter new dept: ";
cin>>deptn;

cout<<"enter new salary: ";
cin>>saln;

	p->name=namen;
			p->id=idn;
			p->dept=deptn;
			p->sal=saln;
			
			break;
		}
	else{
	
		p=p->next;
	}
	 }
	 if(!f)cout<<"Id not found!"<<endl;
 }

void Delete(){
	
	
		struct Node *p=head,*r=NULL;
		
		string id1;
		cout<<"Enter id of employee you want to delete: ";
		cin>>id1;
			
	if(p!=NULL && p->id==id1){
		head=p->next;
		
		delete p;
	
		return;
	
	}
	
	else{
		while(p!=NULL&& p->id!=id1 ){
			r=p;
			p=p->next;
			
			
		}
		if(p==NULL)return;
		
		r->next=p->next;
	
		delete p;
		
	}
				
				
			
		
	
}


void search(){
	struct Node *p=head;
	
	if(p==NULL)return;
	int f=0;
	string id1;
		cout<<"Enter id of employee to search: ";
		cin>>id1;
	while(p!=NULL){
		
		if(p->id==id1){
			f=1;
			cout<<"Name: "<<p->name<<endl;
		cout<<"id: "<<p->id<<endl;
		cout<<"dept: "<<p->dept<<endl;
		cout<<"Sal: "<<p->sal<<endl;
		
		cout<<"\n\n";
		break;
		
		}
		
		else{
		
		p=p->next;
		
	}
}
	if(!f)cout<<"Invalid id!"<<endl;
	
}
void writetofile(){
	Node* p=head;
	ofstream outfile;
	outfile.open("emp.txt",ios::app);
	if(head==NULL)cout<<"No nodes";
	else{
	outfile<<"Name\t\t\id\t\tSalary\t\tDept"<<endl;
		while(p!=NULL){
			
			outfile<<p->name<<"\t\t"<<p->id<<"\t\t"<<p->sal<<"\t\t"<<p->dept<<endl;
			p=p->next;
		}
	}
	outfile.close();
}
void display(){
	struct Node *p=head;

	if(p==NULL)cout<<"List is empty: "<<endl;
	cout<<"Name\t\t\id\t\tSalary\t\tDept"<<endl;
	while(p!=NULL)
	{
	    cout<<p->name<<"\t\t"<<p->id<<"\t\t"<<p->sal<<"\t\t"<<p->dept<<endl;
		p=p->next;
		
	
	}
	writetofile();

	}

void insertstr(){
	
	struct Node *temp,*p;
	p=head;
string name,id,dept;
int sal;
cout<<"enter name: ";
cin>>name;
cout<<"enter id: ";
cin>>id;
cout<<"enter dept: ";
cin>>dept;
cout<<"enter salary: ";
cin>>sal;
		
			temp=new Node();
			temp->name=name;
			temp->id=id;
			temp->dept=dept;
			temp->sal=sal;
			temp->next=NULL;
	if(head==NULL)
	{
	
		
		
		head=temp;
		p=head;
	
	
    }
else{
	while(p->next!=NULL)
	{
		p=p->next;
	}
	
		p->next=temp;
		p=temp;
	
}
	
}

int main() {
	

	
	cout<<"\n\n\t\tONGC Employee Management System"<<endl;
	cout<<"\n\t\tSign Up Here"<<endl;
	string a,b;
	cout<<"\n\t\tEnter Username: ";
	getline(cin,a);
	cout<<"\n\t\tEnter your password: ";
	cin>>b;
	cout<<"\n\n\t\tPlease wait while your id is being created";
	for(int i=0;i<=3;i++){
		cout<<".";
		Sleep(1000);
	}
	
	cout<<"\n\n\t\t Your id has been created successfully"<<endl;
	
	system("CLS");
	start:
	cout<<"\n\n\t\tONGC Employee Management System"<<endl;
	cout<<"\n\t\tLogin"<<endl;
	string a1,b1;
	
	cout<<"\n\t\tEnter Username: ";
    cin>>a1;
	cout<<"\n\t\tEnter your password: ";
	cin>>b1;
	if(a1==a && b1==b){
		system("CLS");
		int ch;
		while(1){
			cout<<"Press 1 to enter data"<<endl;
			cout<<"Press 2 to display data"<<endl;
			cout<<"Press 3 to delete data"<<endl;
			cout<<"Press 4 to update data"<<endl;
			cout<<"Press 5 to search data"<<endl;
			cout<<"Press 6 to logout data"<<endl;
		    cout<<"Press 7 to exit"<<endl;
			cout<<"Enter your choice: ";
			cin>>ch;
			switch(ch){
				case 1: 
			         	
						
				        
				        insertstr();
		
				        break;
				        
				case 2: display();
				
				break;
				
				
				case 3: Delete();
				break;
				case 4: update();
				break;
				case 5: search();
				break;
				
				case 6: 
				system("CLS");
				goto start;
				break;
				
				case 7: exit(0);
				break;
			default: cout<<"invalid";   
			}
		}
	}
	else if(a1!=a ){
		cout<<"\n\n\t\tUsername is incorrect"<<endl;
		Sleep(3000);
		goto start;
	}
	else if(b1!=b ){
		cout<<"\n\n\t\tInvalid Password"<<endl;
		Sleep(3000);
		goto start;
	}
	

	
	return 0;
}

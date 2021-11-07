#include <bits/stdc++.h>
using namespace std;
// accerss modifiers public private, protected.
// class method fuctions only && ffunction also called method
class AbstractEmployee{
    virtual void askforpromotion() = 0; //virtual fuctions is obligatory fuction in a class, 
};
class Employee : AbstractEmployee{ //Employee signed a class AbstractEmployee
protected:
    string name;
    string company;
    int age;
    
public:
    void setname(string Name){
        name = Name;}
    string getName(){return name;}
    void setCompany(string Company){company = Company;}
    string getCompany(){return company;}
    void setAge(int Age){age = Age;}
    int getAge(){return age;}
    void introduce(){
        cout<<"my name is "<<name<<" I work at "<< company<<" and my age is "<<age<<"\n";
    }
    Employee(string Name, string Company, int Age){
        name = Name;
        company = Company;
        age = Age;
    }
    void askforpromotion(){
        if(age > 18)cout<<"promtion ios granted\n";
        else cout<<"No promtion\n";
    }
    virtual void work(){ //most derived function will be executed due to the virtual function;
        cout<<name<<" is workng\n";
    }
};
class developers:public Employee{ //if we do not define it is private Inheritance
public:
    string lang;
    developers(string name, string company, int age, string Lang):Employee(name, company, age){
        lang = Lang;
    }
    void fixbug(){
        cout<<getName()<<" fixed bug in "<<lang<<"\n"; //cannot be acceses without getters
        //to make it accesible we put name in protected to let it be accesed in derived class
    }
    void work(){ //Polymorphism various form for work function
        cout<<name<<" is coding\n";
    }
};
class Teacher: public Employee{
public:
    string subject;
    void prepareLesson(){
        cout<<name<<" is preparting "<<subject<<" lessons "<<endl;
    }
    Teacher(string name, string company, int age, string Subject):Employee(name, company, age){
        subject = Subject;
    }
};
int main(){
    Employee emp = Employee("paritosh", "youtuve", 22); //Constructors
    // emp.name = "Paritosh";
    // emp.company = "skoldfhjn";
    // emp.age = 25;
    emp.introduce();
    //Encapsulation accesing entities in the private section outside the class via a setters and getters
    cout<<emp.getAge()<<"\n";//Encapsulation of age;
    
    //Abstactions hidden complex logic 
    emp.askforpromotion();
    //Inheritance
    developers d = developers("saldina","media.nert",33, "C++");
    d.fixbug();
    Teacher t = Teacher("Jack", "sdfsf",34,"history");
    t.prepareLesson();
    t.askforpromotion();
    d.work();
    
    Employee* e1 = &d;
    Employee* e2 = &t;
    e1->work();
    e2->work();
    return 0;
}

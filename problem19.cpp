#include<iostream>
#include<string>
using namespace std;


class People{
public:
    char gender;
    int age;
    long long int money;
    double height;
    double weight;
    People * in_relation_with;
    bool flirt(People &);
};

bool People::flirt(People &target){
if(target.gender == 'F' && target.age > 18 && target.age < 30 && target.money > 120000 && target.in_relation_with == NULL){
    target.in_relation_with = this;
    this->in_relation_with = &target;
    return true;
}
else{
    return false;
}
}

int main(){
    
    People you;
    you.gender='M';
    you.age=25;
    you.money=150000;
    you.height=1.75;
    you.weight=60;
    you.in_relation_with=NULL;
    People my;
    my.gender='F';
    my.age=20;
    my.money=200000;
    my.height=1.65;
    my.weight=50;
    my.in_relation_with=NULL;
    if(you.flirt(my)){
        cout << "You are in a relationship with me now!" << endl;
    }
    else{
        cout << "You are not in a relationship with me now!" << endl;
    }






}
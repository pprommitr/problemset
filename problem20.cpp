#include <iostream>
#include <string>
#include <vector>
using namespace std;



class People{
string name;
vector<People *> parents;
vector<People *> children;
public:
People(string);
~People();
void setParent(People *);
void setChild(People *);
void removeChild(People *);
string getName();
void showParents();
void showChildren();
};
People::People(string s){
name = s;
}
People::~People(){
cout << name << " was deleted.\n";
}
void People::setParent(People *p){
for(int i=0;i < parents.size(); i++){
if(parents[i] == p) return;
}
parents.push_back(p);
p->setChild(this);
}
void People::setChild(People *p){
for(int i=0;i < children.size(); i++){
if(children[i] == p) return;
}
children.push_back(p);
p->setParent(this);
}
void People::removeChild(People *p){
for(int i=0;i < children.size(); i++){
if(children[i] == p) children.erase(children.begin()+i);
}
}
string People::getName(){
return name;
}
void People::showParents(){
cout << name << "'s parents: ";
for(int i=0;i < parents.size(); i++){
cout << parents[i]->getName() << " ";
}
cout << "\n";
}
void People::showChildren(){
cout << name << "'s children: ";
for(int i=0;i < children.size(); i++){
cout << children[i]->getName() << " ";
}
cout << "\n";
}

int main(){
    People *a = new People("Alice");
People *b = new People("Bob");
People *c = new People("Charlie");
People *d = new People("David");
People *e = new People("Eve");
People *f = new People("Frank");
People *g = new People("Grace");
People *h = new People("Heidi");
c->setParent(a);
c->setParent(b);
c->setChild(e);
d->setChild(e);
f->setChild(g);
f->setChild(h);
a->showChildren();
c->showParents();
c->showChildren();
f->showChildren();
return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Visitor;

class Element
{
  public:
    Element(const string &name) : _name(name){};
    virtual void accept(Visitor *v){};
    string _name;
};

class ElementA : public Element
{
  public:
    ElementA(const string &name) : Element(name) {}
    virtual void accept(Visitor *v);
};

class ElementB : public Element
{
  public:
    ElementB(const string &name) : Element(name) {}
    virtual void accept(Visitor *v);
};

class Visitor
{
  public:
    virtual void visit(ElementA *e) { cout << "A" << endl; }
    virtual void visit(ElementB *e) { cout << "B" << endl; }
};

class VisitorA : public Visitor
{
  public:
    virtual void visit(ElementA *e) { cout << "AA" << endl; }
    virtual void visit(ElementB *e) { cout << "AB" << endl; }
};

class VisitorB : public Visitor
{
  public:
    virtual void visit(ElementA *e) { cout << "BA" << endl; }
    virtual void visit(ElementB *e) { cout << "BB" << endl; }
};

void ElementA::accept(Visitor *v) { v->visit(this); }

void ElementB::accept(Visitor *v) { v->visit(this); }

int main()
{
    ElementA a("e");
    ElementB b("e");
    VisitorA va;
    VisitorB vb;
    a.accept(&va); //AA
    a.accept(&vb); //BA
    b.accept(&va); //AB
    b.accept(&vb); //BB

    return 0;
}
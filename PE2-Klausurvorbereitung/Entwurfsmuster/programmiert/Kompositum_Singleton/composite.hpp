#ifndef _COMPOSITE_HPP
#define _COMPOSITE_HPP

#include <string>
#include <vector>

class Component{
public:
    virtual std::string getType() = 0;
};

class A: public Component{
private:
    static Component *_exemplar;
    A() {}
    A(const Component &c) = delete;
    Component& operator=(Component *c) = delete;
public:
    std::string getType() override;
    static Component* exemplar();
};

class B: public Component{
private:
    static Component *_exemplar;
    B() {}
    B(const Component &c) = delete;
    Component& operator=(Component *c) = delete;
public:
    std::string getType() override;
    static Component* exemplar();
};

class C: public Component{
private:
    static Component *_exemplar;
    C() {}
    C(const Component &c) = delete;
    Component& operator=(Component *c) = delete;
public:
    std::string getType() override;
    static Component* exemplar();
};

class Composite: public Component{
private:
    std::vector<Component*> _childs;
public:
    std::string getType() override;
    void add(Component *c);
    void remove(Component *c);
    Component* child(int id);
};

#endif
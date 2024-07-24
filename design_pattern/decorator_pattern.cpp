//装饰器模式
#include <iostream>

class AbstractComponent
{
  public:
    virtual void action() = 0;
};

class Component : public AbstractComponent
{
  public:
    virtual void action() { std::cout << "Component." << std::endl; }
};

class AbstractDecorator : public AbstractComponent
{
  public:
    AbstractDecorator(AbstractComponent *component) : _component(component) {}

    virtual ~AbstractDecorator()
    {
        if (nullptr != _component)
            delete _component;
    }

    virtual void action()
    {
        if (nullptr != _component)
        {
            _component->action();
        }
    }

  protected:
    AbstractComponent *_component;
};

class DecoratorA : public AbstractDecorator
{
  public:
    DecoratorA(AbstractComponent *component) : AbstractDecorator(component) {}

    virtual void action()
    {
        _action();
        AbstractDecorator::action();
    }

  private:
    void _action()
    {
        std::cout << "DecoratorA." << std::endl;
    }
};

class DecoratorB : public AbstractDecorator
{
  public:
    DecoratorB(AbstractComponent *component) : AbstractDecorator(component) {}

    virtual void action()
    {
        _action();
        AbstractDecorator::action();
    }

  private:
    void _action()
    {
        std::cout << "DecoratorB." << std::endl;
    }
};

int main()
{
    AbstractComponent *component = new DecoratorB(new DecoratorA(new Component()));
    component->action();

    return 0;
}
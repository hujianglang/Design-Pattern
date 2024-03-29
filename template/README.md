#### ”组件协作“模式：

- 现代软件专业分工之后的第一个结果是“框架与应用程序的划分“，”组件协作“模式通过晚期绑定，来实现框架与应用程序之间的松耦合，是二者之间协作时常用的模式。

  ##### 典型模式：

  - Template Method
  - Strategy
  - Observer/Event

  ##### 动机(Motivation)

  - 在软件构建过程中，对于某一项任务，它常常有**稳定**的整体操作结构，但各个子步骤却又很多**改变**的需求，或者由于固有的原因（比如框架与应用之间的关系）而无法和任务的整体结构同时实现。
  - 如何在确定**稳定**操作结构的前提下，来灵活应对各个子步骤的**变化**或者**晚期**实现需求？

  ##### 模式定义

  - 定义一个操作中的算法的骨架（**稳定**），而将一些步骤延迟（**变化**）到子类中。Template Method使得子类可以不改变（复用）一个算法的结构即可重定义（override重写）该算法的某些特定步骤。《设计模式》

  ##### 要点总结

  - Template Method模式是一种非常基础性的设计模式，在面向对象系统中有着大量的应用。它用最简洁的机制（虚函数的多态性为很多应用程序框架提供灵活的扩展点，是代码复用方面的基本实现结构。）
  - 除了可以灵活应对子步骤的变化外，“不要调用我，让我来调用你。“的反向控制结构是Template Method的典型应用。
  - 在具体实现方面，被Template Method调用的虚方法可以实现，也可以没有任何实现（抽象方法、纯虚方法），但一般推荐设为proteced方法。

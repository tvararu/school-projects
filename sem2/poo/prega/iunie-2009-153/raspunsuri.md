#Iunie 2009 153

##1 - incorect
Nu este supraincarcat `operator<<`, astfel incat compilarea va esua la linia `cout << a + b;`.

##2 - *Teorie:* mecanismul de control al tipului in timpul executiei
???

##3 - incorect
Metoda `f` primeste parametru de tip `const A& c`, dar `A a(25)` este declarat fara const. Apelarea metodei va esua.

##4
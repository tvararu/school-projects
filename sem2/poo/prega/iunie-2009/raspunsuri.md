#Iunie 2009

##1 - corect
Afiseaza `12`.

##2 - *Teorie:* Constructorul de copiere in procesul de mostenire
Daca clasa derivata **nu are** definit un constructor de copiere atunci compilatorul genereaza unul automat care va realiza copierea datelor membre mostenite apeland la constructorii de copiere ai claselor de baza (definiti de utilizator sau generati de compilator), iar datele specifice clasei derivate se vor copia bit cu bit.

Daca clasa derivata **are** definit un constructor de copiere atunci acesta va realiza copierea tuturor datelor membre (mostenite sau proprii), apeland eventual la constructorii claselor de baza.

##3 - incorect
Nu poti sa initializezi un obiect de tip clasa derivata cu un obiect de tip clasa parinte.

##4 - incorect
Nu poti apela printr-o lista de initializare o variabila de tip static.

##5 - *Teorie:* typeid
`typeid(p)` returneaza un obiect cu informatii in legatura cu tipul structurii de date `p`. cu metoda `typeid(p).name()` se poate determina numele clasei aferente. (vezi `05_exemplu.cpp`)

##6 - incorect
Constructorul de copiere este de forma `A::A(A&)` in timp ce linia `c = a + b;` necesita o functie de tip `A::A(A)`.

##7 - incorect
`A` are nevoie de un constructor care primeste parametru int inainte de declararea operatorului de conversie `B::operator A()`. Daca declararea completa a clasei `A` s-ar afla inainte de declararea operatorului de conversie, programul ar fi valid si ar afisa `107`.

##8 - *Teorie:* obiectul implicit al unei metode
Obiectul implicit al unei metode este obiectul care apeleaza metoda. Apelari de metode sau modificari la membrii acestuia (private sau de orice alt tip) se pot face direct prin intermediul pointerului this.

##9 - incorect
Supraincarcarea operatorului `operator=` trebuie sa fie declarata ca membru al unei clase.

##10 - incorect
`*p1 = p1->minus()` o sa schimbe tipul de obiect retinut in pointerul `p1` la un obiect de tip `A`, pentru ca functia `minus()` intoarce `A`. Prin urmare, metoda `afisare()` va fi cautata in cadrul obiectului `A`, care nu are aceasta metoda.

##11 - *Teorie:* Functii virtuale
Functiile virtuale sunt descrieri generice pentru interfata comuna claselor de baza si a celor derivate.

Un exemplu ar fi un vector de pointeri la o clasa de baza, pe care il populam cu obiecte derivate. Pentru fiecare element din vector, putem apela o metoda care daca este de tip virtual, va fi aleasa la runtime in functie de tipul obiectului ce o apeleaza. (vezi `11_exemplu.cpp`)

##12 - incorect
La apelarea metodei `f(a)` se va incerca copierea obiectului de tip `const A` intr-un obiect local metodei `f`, pentru ca functia `f` primeste parametru prin valoare. deoarece nu avem constructor de copiere care sa primeasca ca parametru o referinta spre un obiect de tip constant (i.e.: `A(const A& a)`), aceasta operatie va esua.

##13 - incorect
Daca intr-o clasa derivata nu declaram niciun constructor, aceasta va mosteni constructorii clasei de baza. Dar, daca in clasa mostenitoare, declaram un constructor care accepta parametru, această clasa nu mai mosteneste constructorii impliciti. Prin urmare, declaratia `B b1` va esua cu `no matching constructor`.

##14 - *Teorie:* functii constante
Functiile constante sunt metode care nu au dreptul sa modifice niciun membru al obiectului implicit. De exemplu, daca declaram un obiect `const` atunci acesta nu va putea apela decat functii constante. (vezi `14_exemplu.cpp`)

##15 - corect
Afiseaza `-61`.
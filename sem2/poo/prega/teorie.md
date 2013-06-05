iunie-2009-1 - corect, afiseaza 12

iunie-2009-2 - Constructorul de copiere in procesul de mostenire

Daca clasa derivata **nu are** definit un constructor de copiere atunci compilatorul genereaza unul automat care va realiza copierea datelor membre mostenite apeland la constructorii de copiere ai claselor de baza (definiti de utilizator sau generati de compilator), iar datele specifice clasei derivate se vor copia bit cu bit.

Daca clasa derivata **are** definit un constructor de copiere atunci acesta va realiza copierea tuturor datelor membre (mostenite sau proprii), apeland eventual la constructorii claselor de baza.

iunie-2009-3 - incorect; nu poti sa initializezi un obiect de tip clasa derivata cu un obiect de tip clasa parinte

iunie-2009-4 - incorect, deoarece nu poti apela printr-o lista de initializare o variabila de tip static

iunie-2009-5 - typeid(p) returneaza un obiect cu informatii in legatura cu tipul structurii de date p. cu metoda typeid(p).name() se poate determina numele clasei aferente.

iunie-2009-6 - incorect; constructorul de copiere este de forma A::A(A&) in timp ce linia c = a + b; necesita o functie de tip A::A(A).

iunie-2009-7 - incorect; A are nevoie de un constructor care primeste parametru int inainte de declararea operatorului de conversie B::operator A(). daca declararea completa a clasei A s-ar afla inainte de declararea operatorului de conversie, programul ar fi valid si ar afisa 107.

iunie-2009-8 - obiectul implicit al unei metode
Obiectul implicit al unei metode este obiectul care apeleaza metoda. Apelari de metode sau modificari la membrii acestuia (private sau de orice alt tip) se pot face direct prin intermediul pointerului this.

iunie-2009-9 - incorect; supraincarcarea operatorului "operator=" trebuie sa fie declarata ca membru al unei clase

iunie-2009-10 - incorect; *p1 = p1->minus() o sa schimbe tipul de obiect retinut in pointerul p1 la un obiect de tip A, pentru ca functia minus() intoarce A. prin urmare, metoda de afisare() va fi cautata in cadrul obiectului A, care nu are aceasta metoda.

iunie-2009-11 - Teorie: Functii virtuale
Functiile virtuale sunt descrieri generice pentru interfata comuna claselor de baza si derivate. Un exemplu ar fi un vector de pointeri la o clasa de baza, pe care il populam cu obiecte derivate. Pentru fiecare element din vector, putem apela o metoda care daca este de tip virtual, va fi aleasa la runtime in functie de tipul obiectului ce o apeleaza.

iunie-2009-12 - incorect; la apelarea functiei f(a) se va incerca copierea obiectului de tip const A intr-un obiect local metodei f, pentru ca functia f primeste parametru prin valoare. deoarece nu avem constructor de copiere care sa primeasca ca parametru o referinta spre un obiect de tip constant (i.e.: A(const A& a) ), aceasta operatie va esua.

iunie-2009-13 - incorect; daca intr-o clasa derivata nu declaram niciun constructor, aceasta va mosteni constructorii clasei de baza. dar, daca in clasa mostenitoare, declaram un constructor care accepta parametru, această clasa nu mai mosteneste constructorii impliciti. prin urmare, declaratia B b1; va esua cu "no matching constructor"

iunie-2009-14 - Teorie: functii constante
Functiile constante sunt metode care nu au dreptul sa modifice niciun membru al obiectului implicit. De exemplu, daca declaram un obiect const atunci acesta nu va putea apela decat functii constante.

iunie-2009-15 - corect; afiseaza -61
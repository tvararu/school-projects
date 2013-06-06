#Iunie 2008

##1 - incorect
In cadrul executiei lui `operator<<` se va incerca folosirea lui `operator[]` in cadrul instructiunii `o << a[i]`. Deoarece acesta nu este definit de tip `const`, incercarea de a-l apela pentru un obiect de tip `const D` va esua.

##2 - *Teorie:* trei metode de proiectare prin care elementele unei clase se pot gasi in dublu exemplar in definitia altei clase
* mostenire virtuala multipla
* compunere; initializarea sub forma de membri a unor alte clase
* ???

##3 - incorect
`int x` e de tip private si nu merge apelat in cadrul lui `class D`.

##4 - corect
Afiseaza `41`.

##5 - *Teorie:* obiectul implicit al unei metode
Obiectul implicit al unei metode este obiectul care apeleaza metoda.

Proprietati:
* se apeleaza prin intermediul cuvantului cheie `this`
* modificari produse in functie se reflecta asupra obiectului
* nu se mai apeleaza constructor/destructor pentru acesta

##6 - corect
Afiseaza `0 0 0 0 -15 0 0 0 0 0`.

##7 - incorect
`f()` intoarce un element de tip `const int&`, pe care nu putem apela metoda `++`.

##8 - *Teorie:* mostenire virtuala
Cand avem o clasa derivata care mosteneste din mai multe clase care la randul lor mostenesc non-virtual dintr-o clasa comuna, incercarea de a apela o metoda din clasa comuna prin intermediul unei variabilele de tipul clasei derivate va fi ambigua. Solutia consta in declararea mostenirilor dintre clasa comuna si clasele derivate sa fie de tip virtual.
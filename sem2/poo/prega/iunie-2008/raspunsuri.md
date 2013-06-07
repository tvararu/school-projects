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

##9 - incorect
Nu putem apela membrul `static int x` in clasa `D` deoarece acesta a fost declarat de tip private, nu protected.

##10 - corect
Afiseaza 11.

##11 - *Teorie:* 3 metode de implementare a polimorfismului de compilare
* polimorfism ad-hoc prin **supraincarcarea metodelor**
* polimorfism de incluziune prin **functii virtuale**
* polimorfism parametric prin **șabloane**

##12 - incorect
Din 3 motive, toate in metoda `static int g() { return f() / 2; }`:
* nu se poate apela o metoda nonstatica `f()` dintr-o metoda statica
* metoda `f()` necesita parametru la apelare
* metoda `f()` returneaza `cls`, care nu are definita operatia de impartire cu o variabila de tip `int`

##13 - s-ar putea sa compileze, dar va fi incorect/imprevizibil
Clasei `cls` ii lipseste un constructor de copiere, care este necesar apelului `y = x`. De asemenea, pentru apelul `z = x + y` este necesara si suprascrierea operatorului de atribuire. Este posibil ca programul sa compileze oricum, dar acesta va intampina probleme de alocare a memoriei la runtime (datorita destructorului `~cls()`), iar afisarea va outputa garbage.

##14 - *Teorie:* mecanismul de tratare a exceptiilor
In C++, mecanismul de tratare a exceptiilor este compus din 3 componente: `try`, `throw` si `catch`. Se executa cod in interiorul blocului de `try`, iar la prima apelare a metodei `throw` se va iesi din executarea blocului `try`. Obiectul transmis ca parametru metodei `throw` este pasat in continuare unui bloc de cod compatibil `catch`.

##15 - corect
Ce afiseaza variaza in functie de implementarea compilatorului a functiei `typeid`. Daca outputul pentru un obiect de tip `D*` este intradevar `D*`, atunci programul va afisa `2`. Altfel, daca outputul este de exemplu `P1B`, programul nu va mai afisa nimic.

##16 - incorect
Prima problema este in cadrul alocarii `new cls[10]`, care nu este permisa fara declararea unui constructor **fara** parametrii deoarece a fost declarat un constructor **cu** parametru. A doua problema este in cadrul apelului `p[i].get_x(i)`, cu metoda `get_x()` care nu accepta parametru.

##17 - *Teorie:* diferenta intre pointeri si referinte
Diferenta dintre un pointer si o referinta este ca un pointer contine adresa spre o zona de memorie in timp ce o referinta este un alias pentru o variabila existenta. In consecinta, o referinta nu poate fi modificata pentru a se referi la alte zone de memorie.

##18 - corect
Afiseaza `-3`.
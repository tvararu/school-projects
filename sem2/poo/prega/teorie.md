iunie-2009-1 - corect

iunie-2009-2 - Constructorul de copiere in procesul de mostenire

Daca clasa derivata **nu are** definit un constructor de copiere atunci compilatorul genereaza unul automat care va realiza copierea datelor membre mostenite apeland la constructorii de copiere ai claselor de baza (definiti de utilizator sau generati de compilator), iar datele specifice clasei derivate se vor copia bit cu bit.

Daca clasa derivata **are** definit un constructor de copiere atunci acesta se va realiza copierea tuturor datelor membre (mostenite sau proprii) - apeland eventual la constructorii claselor de baza.

iunie-2009-3 - incorect; nu poti sa initializezi un obiect de tip clasa derivata cu un obiect de tip clasa parinte

iunie-2009-4 - incorect, deoarece nu poti apela printr-o lista de initializare o variabila de tip static

iunie-2009-5 - typeid(p) returneaza informatii in legatura cu tipul structurii de date p.
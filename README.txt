Nume : George Caloian
Grupa : 322 seria CC
Tema 1 Proiectarea Algoritmilor

Parere personala:
Consider ca gradul de dificultate al temei a fost potrivit, adica nu e imposibil de rezolvat
daca aloci suficient timp.
Chiar daca nu am apelat in mod direct la el consider ca suportul de pe forum a fost absolut
ok din punct de vedere calitativ si cantitativ si apreciez flexibilitatea cu privire la 
manipularea deadlineului in favoarea studentilor atunci cand s-a produs o schimbare in teste,
pentru ca poate alte persoane ar fi considerat ca aceasta defapt nu implica nicio modificare
din moment ce oricum studentul trebuia sa gaseasca o implementare valida si nu una care doar
sa treaca testele.



Problema 1 - Abordare Greedy

Pentru prima problema am ales urmatoarea abordare greedy:
Parcurg cuvantul din ambele sensuri (plec cu un indice de pe prima pozitie
si cu al 2-lea de pe ultima pozitie) de fiecare data cand literele de pe
cele 2 pozitii coincid cresc primul indice si il scad pe al 2-lea deoarece
inseamna ca aceste pozitii sunt corecte din punct de vedere al structurii
unui palindrom.
In caz contrar (ele difera) este evident faptul ca este nevoie de un anumit
numar de "switch-uri" (interschimbari intre elemente de pe poztii consecutive).
Asadar fac 2 parcurgeri: pentru fiecare plec de la elementul curent pana cand
gasesc in cuvant corespondentul celuilalt (adica pana cand gasesc litera care
pusa in locul celei curente ar respecta structura de palindrom si as putea
astfel trece la urmatoarele elemente).
Cu ajutorul a 2 contori imi pot da seama care din aceste pargurgeri ajunge 
mai repede la pozitia dorita pentru ca avem nevoie de numarul minim de 
interschimbari.
In acest moment fac toate aceste interschimbari (inca odata pentru varianta
mai scurta) si adun la numarul total de interschimbari numarul pentru pasul 
actual.
In cazul in care niciuna din cele 2 parcurgeri nu gaseste un rezultat favorabil
imediat intorc -1 deoarece inseamna ca nu am gasit nicio alta litera viabila
si implicit rezulta ca inputul nu poate fi rescris ca si palindrom.
Repet aceleasi operatii la fiecare pas pana cand cei 2 indici se intersecteaza
adica am aranjat atat prima jumatate cat si cea de-a doua .
In acest moment am obtinut un palindrom si nu ramane decat sa returnez suma
totala a numarului de interschimbari facute.


Problema 2 - Programare Dinamica

Pentru a 2a problema am ajuns la urmatoarea solutie:
Rezolvarea are la baza algoritmul pentru aflarea "distantei Levenstein"
(sursa: wikipedia.org/Levenstein_distance)
(distanta dintre 2 cuvinte (numarul de stergeri/inserari/inlocuiri necesare
pentru a ajunge de la un cuvant la celalalt - exact ceea ce se cere in enunt) 
cu o modificare importanta deoarece nu avem de-a face cu 2 cuvinte ci cu 
unul si o serie de NR_VAR variante.
Initial citeam toate cele NR_VAR variante de lungime N intr-o matrice cu
dimensiunile aferente dupa care in cadrul algoritmului cautam fiecare litera
din cuvantul original (solutia, cel de lungime M) in fiecare coloana a acelei
matrici (deoarece trebuie sa vedem daca acea litera se afla cumva in cel putin
una din cele NR_VAR variante, pe pozitia corespunzatoare). Acesta abordare depasea
limitele de timp pentru 3 teste mai solicitante (mai exact 6 7 si 9)
Asadar am schimbat abordarea si de data aceasta am o matrice de 130 de linii
corespunzatoare codificarii ASCII a fiecarui caracter (chiar daca teoretic avem
pana la 256 am observat ca nu avem de-a face cu numere mai mari de 130 deoarece
codificarea literelor alfabetului se opreste undeva pana in aceasta valoare, 122
mai exact), si N coloane.
Cum completez aceasta matrice:
Citesc pe rand fiecare "litera"/numar din fisier si de fiecare data updatez pozitia 
corespunzatoare din matrice cu valoarea "1".
De exemplu daca am litera "o" in una din variante pe prima pozitie sa zicem , atunci 
in matricea mea la linia 111 (care este codificarea ascii a literei o) pe prima 
coloana voi avea ca valoare "1" si astfel stiu ca litera o/codificare 111 se gaseste 
pe prima pozitie in cel putin una din variante.
Astfel timpul de executie se reduce semnificativ deoarece acum nu trebuie sa parcurg
toate cele NR_VAR pozitii ci trebuie sa verific 1 singura pozitie ( 1 vs 600 de 
itaratii cat este limita superiara pentru NR_VAR)
Astfel elimin orice problema legata de timpul de executie.
Pentru 2 substringuri egale evident distanta este egala cu 0 in caz contra vol alege
minimul dintre numarul de operatii necesare in urma unei stergeri / insesarii / 
inlocuirii unei valori pentru a ajunge la egalitate intre cele 2 cuvinte.
Practic completam o matrice cu dimensiunile M+1 si N=1 corespunzatoare lungimilor
cuvantului original respectiv lungimea variantelor la care adaugam o linie si o coloana
de 0.Pentru fiecare pozitie comparam caracterul corespunzator din cuvant respectiv 
seria de variante ( reprezentata de matricea explecata anterior), in cazul in care ele
coincid evident nu este nevoie de nicio modificare si vom copia valoarea corespunzatoare
pentru restul stringului (i-1,j-1) in caz contrar trebuie sa alegem minimul dintre
stergerea caracterului (i-1,j) inserarea (i,j-1) sau inlocuire (i-1)(j-1) si avem grija
sa adunam costul 1 corespunzator acestei operatii.
Completam matricea in totalitate si astfel elementul de pe ultima linie si ultima coloana
va reprezenta distanta dintre intregul cuvant original si intregul set de variante.

Pentru problema 3 nu am reusit sa implementez decat o abordare Greedy care initial trecea
13 din 15 teste dar ulterior updatarii acestora functioneaza doar pe primele 5 teste.
Am identificat exact care este cazul limita pentru care abordarea greedy duce la un rezultat
gresit , am o vaga banuiala ca totusi se poate rezolva si cu greedy dar este nevoie de 
tratarea acestui caz limita insa nu am reusit sa aloc suficient timp pentur aceasta.
Din punct de verede al programarii dinamice nu am reusit sa imi dau seama exact de recurenta
sau mai degraba de modul exact de compeltare a unei matrici similare cu cea de la problema 2.
Nu am sa includ fisierul sursa pentru problema 3 pentru a nu va produce probleme in procesul
de corectare al temelor avand in vedere ca este obligatoriu alegerea unei singure probleme 
dintre ultimele 2 coroborat cu faptul ca problema 2 imi aduce un punctaj mai mare decat
acele prime 5 teste.

Bibliografie:
Am mentionat mai sus pagina de wikipedia a algoritmului pentru aflarea distantei Levenstein.
Am folosti de asemenea cateva linii de cod din scheletul unor laboratoare
(makefile , citiri din fisier )

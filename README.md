# Vector
## Self-made vector class

## 1 - palyginimas.
Rezultatai butu tokie:
```
-----------------------------
Originalus vectorius!

!= testas
Vectoriai nelygus!

= testas
Vectoriai lygus!

size() testas
100

front() testas
2

resize(5) testas
Dabar size() rezultatas - 5

-----------------------------
Mano vectorius!

!= testas
Vectoriai nelygus!

= testas
Vectoriai lygus!

size() testas
100

front() testas
2

resize(5) testas
Dabar size() rezultatas - 5
```
Abejuose atvejuose sukuriami 2 vectoriai, tarkim v1 ir v1_compare.
v1 vectoriaus dydis pakeiciamas i 100 ir kiekvienam elementui priskiriamas skaicius 2.

**1 testas:**

v1 != v1_compare

**2 testas:**

v1.compare = v1

Ir tada atliekamas 1 testas pakartotinai.


**3 testas:**

v1.size()


**4 testas:**

v1.front()


**5 testas:**

v1.resize(5)

Ir tada pakartojamas 3 testas.


**P.S.** Norint pasileisti sita testa paciam uztenka i komandine eilute parasyti ```make vector```, o susibuildinus pasileisti ```test``` faila.

## 2 - spartumo analize.
|   Elementu skaicius   |   Originalus vectorius   |   Mano vectorius   |
| ------------- |:-------------:| -----:|
| 10000 | 0.0009987 sec. |0 sec. |
| 100000 | 0.0029957 sec. | 0.0020012 sec. |
| 1000000 | 0.0279792 sec. | 0.0159929 sec. |
| 10000000 | 0.277827 sec. | 0.172917 sec. |
| 100000000 | 2.69737 sec. | 1.59538 sec. |

## 3 - atminties perskirstymas.
 ```
 Orig vektorius - 3.41092
 Jo atiminties perskirstymu skaicius - 27

 Mano vektorius - 2.23562
 Jo atiminties perskirstymu skaicius - 27
 ```
 Atminties perskirstymu ivyko lygiai tiek pat kiek originaliam vectoriui.
 
 ## 4 - mano vectorius 3 darbe.
 Viskas veikia!

 Norint isitikinti paciam i komandine eilute reikia parasyti ```make run```, susibuildinus pasileisti ```test``` faila.
 
 Spartos atzvilgiu mano vectorius pasirode kiek greitesnis, taciau tokio zenklaus skirtumo kaip 2 punkte (spartos analizei) nera.
 
 ```std::vector uztruko - 2.60471```
 
 ```Vector uztruko - 2.55442```
 
 **Laikas susideda is _sugeneravimo_, ir _spausdinimo_ i faila, taip pat _skaitymo_ is to failo, ir _rusiavimo_.**
 
 




Riešenie je inšpirované algoritmom zo stránky  geeksforgeeks.org

Na vstup je zadané pole veľkosti size*size s prvou pozíciou označenou *.
Pri riešení sa znak odstráni a pridá sa, až keď sa nájde cesta do cieľa.

Algoritmus pre jednoduchšie počítanie pracuje so súradnicami x a y,
ktoré potom prepočíta na index poľa. 
Funguje ako rekurzívna funkcia, ktorá  skúša rekurzívne všetky smery.
Ak je smer valídny, tak ho označí '*'.

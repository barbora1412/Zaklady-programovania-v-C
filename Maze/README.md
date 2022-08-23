# Bludisko

## Zadanie úlohy

Potkan sa vie pohybovať po štvorcoch hore,dole, doprava i doľava. Bludisko je tvorené štvorcovou mriežkou rozmeru N x N. V bludisku sa nachádzajú prekážky vyznačené ````x````. Potkan pri pohybe nesmie naraziť do žiadnej prekážky.

Počiatočná pozícia potkana je v ľavom hornom rohu mriežky vyznačená ````*````.

Vašou úlohou bude zobraziť optimálnu cestu pre potkana v bludisku. Cestu potkana vyznačte ````*````.

Implementujte funkciu:

````int solve_maze(char* maze,int size);````

maze je jednorozmerné pole do ktorého je uložená mriežka po riadkoch za sebou. Na začiatku poľa sa nachádza prvý riadok mriežky, za ním nasleduje druhý a tak ďalej. Spolu sa v poli maze nachádza size ````*```` size znakov.

Vašou úlohou bude modifikovať pole maze tak, aby ste v ňom vyznačili cestu z bludiska čo sa nachádza v pravom dolnom rohu bludiska.

Riešenie je inšpirované algoritmom zo stránky  geeksforgeeks.org
Zadanie a šablóna @Daniel Hládek

## Program

Na vstup je zadané pole veľkosti size*size s prvou pozíciou označenou ````*````.
Pri riešení sa znak odstráni a pridá sa, až keď sa nájde cesta do cieľa.

Algoritmus pre jednoduchšie počítanie pracuje so súradnicami x a y,
ktoré potom prepočíta na index poľa. 
Funguje ako rekurzívna funkcia, ktorá  skúša rekurzívne všetky smery.
Ak je smer valídny, tak ho označí ````*````.


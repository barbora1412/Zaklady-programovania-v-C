# Hešovacia tabuľka

Vypracovanie zadania a šablóny od @Daniel Hládek

## Zadanie úlohy

Vytvorte databázu na uloženie informácií o počte cestujúcich do rôznych staníc. Databázu vytvorte pomocou hešovacej tabuľky so zreťazením.
V databáze môže byť o každej stanici maximálne jeden záznam o počte cestujúcich ktorí do nej cestujú.

## Vypracovanie úlohy

Tabuľka je vypracovaná ako dynamické pole smerníkov. Dynamicky sa alokuje štruktúra *station*. Každá stanica má poznačný počet koľají *tracks* a samotné pole *tracks*.
Do jednej koľaje je uložených niekoľko "vlakov" v podobe spojkového zoznamu. Jeden vlak predstavuje jedna štruktúra spojkový zoznam *car*. Do *tracks* sa uloží odkaz na prvý vozeň každého vlaku.


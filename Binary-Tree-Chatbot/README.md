#Expert z bufetu

Vypracovanie zadania od @Daniel Hládek

##Zadanie úlohy

Vašou úlohou bude naprogramovať chatbota, ktorý pomôže budúcim zamestnancom bufetu pri rozlišovaní druhov tovaru pomocou série otázok. Báza znalostí sa skladá z otázok typu áno a nie a odpovedí.

Systém najprv načíta bázu otázok a odpovedí. Každá otázka alebo odpoveď sa nachádza na práve jednom riadku. Odpovede sú vyznačené hviezdičkou na začiatku riadka. Po otázke na najprv nasleduje načítanie ďalšieho kroku áno a potom kroku nie. Každý krok znalostného systému je alebo odpoveď alebo ďalšia otázka. Báza pravidiel je ukončená prázdnym riadkom.

Otázky a odpovede spolu tvoria binárny vyhľadávací strom zapísaný vo formáte pre-order.

*Príklad bázy pravidiel s dvoma otázkami a troma druhmi tovaru:*
```
Je to ovocie alebo zelenina ?
* Jablko
Je to zelenej farby ?
* Kaleráb
* Mrkva
```
Po načítaní bázy pravidiel vypíšte počet tovarov v báze pravidiel. V prípade, že sa nedá správne načítať báza pravidiel vypíšte chybové hlásenie. Báza pravidiel je od používateľského vstupu oddelená prázdnym riadkom.

Ak sa bázu pravidiel podarilo načítať, spustite znalostný systém prvou otázkou. Spustenie znalostného systému znamená jeho rekurzívne prechádzanie typu preorder od koreňového uzla. Pri prechádzaní najprv zobrazte otázku alebo odpoveď ktorá sa nachádza v aktuálnom uzle. Ďalšie otázky alebo odpovede zobrazujte podľa toho, či používateľ odpovedá a pre prvú možnosť alebo n pre druhú. Ak systém nájde odpoveď, vypíšte správu a skončite program. Ak používateľ zadá nesprávny vstup, vypíšte správu a skončite program.

*Príklad vstupu:*
```
Je to ovocie alebo zelenina (a/n) ?
* Jablko
* Mrkva

n
```

*Príklad výstupu:*
```
MUDrC to vie.
Pozna 2 druhov ovocia a zeleniny.
Odpovedajte 'a' alebo 'n'
Je to ovocie alebo zelenina (a/n) ?
* Mrkva
Koniec
```

##Opis programu
Program na ukladanie údajov využíva štruktúru binárny strom. Zo vstupu vytvorí novú štruktúru, pričom v uzloch sú otázky a v listoch odpovede. Počet listov značí, koľko pozná ovocia a zeleniny.
###Spustenie znalostného programu
Pri zadaní odpovede sa strom prechádza hlbšie. Ide smerom doľava ak je odpoveď áno a doprava ak je odpoveď nie. Ak dorazí na list stromu tak vypíše odpoveď.

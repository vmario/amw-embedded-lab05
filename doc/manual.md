---
title: "Instrukcja laboratorium systemów wbudowanych"
subtitle: "Ćwiczenie 4: Obsługa sterownika wyświetlacza alfanumerycznego HD44780"
author: [Mariusz Chilmon <<mariusz.chilmon@ctm.gdynia.pl>>]
lang: "pl"
titlepage: yes
titlepage-logo: "logo.jpg"
colorlinks: yes
header-includes: |
  \usepackage{awesomebox}
...

> If the comment and code disagree, both are probably wrong.
>
> — _Bjarne Stroustrup_

# Cel ćwiczenia

Celem ćwiczenia jest zapoznanie się z:

* wymaganiami czasowymi w komunikacji z urządzeniami zewnętrznymi,
* wyświetlaniem tekstu na wyświetlaczach alfanumerycznych,
* prostymi operacjami na łańcuchach znaków.

# Uruchomienie programu wyjściowego

1. Umieść zworki na pinach `RS`, `E` i `D4`…`D7` złącza `J10` (na lewo od buzzera).
1. Zworkę `J15` (nad buzzerem) ustaw w pozycji `RW->GND`.
1. Umieść wyświetlacz w złączu `DIS1`.
1. Po włączeniu zasilania wyświetlacz powinien się świecić i mogą na nim wyświetlać się losowe znaki.

Używany wyświetlacz oparty jest na sterowniku Hitachi HD44780. Jest to sterownik wyświetlacza alfanumerycznego, czyli takiego, który jest w stanie wyświetlać tylko określony zestaw predefiniowanych znaków, np. liter, cyfr i znaków z zakresu ASCII. Uniemożliwia to wyświetlanie dowolnych kształtów, ale odciąża mikrokontroler od renderowania fontu i umożliwia bardzo proste sterowanie.

W tym przykładzie komunikacja ze sterownikiem została uproszczona do minimum. Szyna komunikacyjna została zredukowana z 8 bitów do 4 bitów, a linię `R/W` zwarto na stałe do masy, skutkiem czego niemożliwy jest odczyt odpowiedzi wyświetlacza na wysyłane komendy.

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{W systemach wbudowanych często wykorzystujemy uproszczone magistrale komunikacyjne, nawet jeżeli spowalnia to komunikację lub ogranicza funkcjonalność. Pozwala to bowiem zastosować mikrokontroler o mniejszej liczbie wyprowadzeń, co obniża koszt i~wymiary urządzenia.}

# Zadanie podstawowe

## Wymagania funkcjonalne

1. Wyświetlacz wyświetla poprawnie zadany tekst.
1. Kursor jest niewidoczny.

## Modyfikacja programu

Ze względu na brak możliwości odczytu danych z wyświetlacza, mikrokontroler nie może stwierdzić, kiedy zadana komenda została przetworzona. Wysyłanie kolejnej komendy, gdy poprzednia nie została obsłużona, skutkuje niepoprawną pracą kontrolera HD44780.

Zmodyfikuj metody `write()` komend zaimplementowanych w `lcdCommands.cpp`. Dodaj odpowiednie opóźnienie po wysłaniu każdej z komend. Udokumentuj, np. w opisie pliku, gdzie w&nbsp;dokumentacji kontrolera HD47780 można zweryfikować wielkość poszczególnych opóźnień.

\awesomebox[violet]{2pt}{\faBook}{violet}{Dokumentację kontrolera HD47780 znajdź samodzielnie w Internecie.}

\awesomebox[teal]{2pt}{\faCode}{teal}{Ponieważ odmierzamy krótkie odcinki czasu i to tylko w momencie aktualizowania wyświetlacza, nieopłacalne jest implementowanie ich odmierzania za pomocą timera. Użyj funkcji \lstinline{_delay_us()} i \lstinline{_delay_ms()}.}

\awesomebox[teal]{2pt}{\faCode}{teal}{Pamiętaj o dołączeniu odpowiedniego pliku nagłówkowego za pomocą dyrektywy preprocesora \lstinline{#include <>}.}

Zwróć uwagę na drugą linię wyświetlacza. Popraw sposób wyświetlania.

Odnajdź miejsce w kodzie inicjalizacyjnym wyświetlacza, gdzie konfigurowany jest kursor, i wyłącz go.

# Zadanie rozszerzone

## Wymagania funkcjonalne

1. Napisy zmieniające się w drugiej linii wyświetlacza są wyśrodkowane.

## Modyfikacja programu

Do klasy `Lcd` dodaj metodę `writeCentered(const char* text, uint8_t line)`, realizującą wyśrodkowanie napisu we wskazanej linii.

Wykorzystaj funkcję `strlen()` z biblioteki standardowej języka C, by określić długość wyświetlanego tekstu i określić miejsce rozpoczęcia jego drukowania.

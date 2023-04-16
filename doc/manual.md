---
title: "Instrukcja laboratorium systemów wbudowanych"
subtitle: "Ćwiczenie 5: Magistrala 1-Wire na przykładzie termometru DS18B20"
author: [Mariusz Chilmon <<mariusz.chilmon@ctm.gdynia.pl>>]
lang: "pl"
titlepage: yes
titlepage-logo: "logo.jpg"
colorlinks: yes
header-includes: |
  \usepackage{awesomebox}
...

> When you finally understand what you are doing, things will go right.
>
> — _Bill Fairbank_

# Cel ćwiczenia

Celem ćwiczenia jest zapoznanie się z:

* podstawami standardu 1-Wire,
* wykorzystaniem termometru DS18B20.

# Uruchomienie programu wyjściowego

1. Umieść zworki na pinach `RS`, `E` i `D4`…`D7` złącza `J10` (na lewo od buzzera).
1. Zworkę `J15` (nad buzzerem) ustaw w pozycji `RW->GND`.
1. Umieść wyświetlacz w złączu `DIS1`.
1. Podłącz pin `1WIRE` złącza `J22` (pod termometrem) do pinu `PC0` mikrokontrolera.
1. Po włączeniu zasilania wyświetlacz pokaże identyfikator `0x00000000000000` oraz temperaturę `0`.

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{Kod wyjściowy realizuje tylko proces resetowania magistrali i sprawdzania, czy jakikolwiek urządzenie odpowiedziało na ten sygnał (metoda \lstinline{Wire1::reset()}). Procedura ta jest realizowana cyklicznie co 1 sekundę w przerwaniu timera, więc, jeżeli odłączysz termometr od mikrokontrolera, po chwili zobaczysz komunikat błędu.}

# Zadanie podstawowe

## Wymagania funkcjonalne

1. Wyświetlacz wyświetla identyfikator termometru.

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{Każde urządzenie na magistrali 1-Wire musi posiadać unikalny numer, który umożliwia mikrokontrolerowi zaadresowanie konkretnego urządzenia jeżeli jest ich podłączonych wiele.}

## Modyfikacja programu

Uzupełnij metodę `romCode()` klasy `Thermometer`. W tym celu odczytaj z dokumentacji termometru kod rozkazu _Read ROM_, który pobiera z urządzenia _slave_, podłączonego do magistrali, jego numer seryjny. Wyślij ten rozkaz za pomocą metody `writeByte()` klasy `Wire1`, odczytaj 8 bajtów za pomocą metody `readByte()` i zwróć je w postaci struktury `RomCode`.

\awesomebox[teal]{2pt}{\faCode}{teal}{Zwróć uwagę, że struktura \lstinline{RomCode} zawiera tylko jedno pole \lstinline{bytes}, które jest tablicą o rozmiarze 8 bajtów. Jest to metoda w językach C i C++ na z}

Zwróć uwagę, że identyfikator termometru powinien zaczynać się od bajtu `0x28`.

\awesomebox[violet]{2pt}{\faBook}{violet}{Dokumentację termometru DS18B20 znajdź samodzielnie w Internecie. Producentem tego układu scalonego pierwotnie była firma Dallas, obecnie przejęta przez Maxim Integrated.}

# Zadanie rozszerzone

## Wymagania funkcjonalne

1. Wyświetlacz wyświetla identyfikator termometru i bieżącą temperaturę.

## Modyfikacja programu

Uzupełnij metodę `temperature()` klasy `Thermometer`.

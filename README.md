# RTT Logger

Biblioteka RTT Logger to lekki, wydajny mechanizm logowania dla systemów wbudowanych oparty na technologii [SEGGER Real Time Transfer (RTT)](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/). Pozwala na niskopoziomowe logowanie w czasie rzeczywistym bez wpływu na wydajność aplikacji.

## Właściwości

- Niskopoziomowe logowanie z minimalnym narzutem czasowym
- Brak konieczności stosowania interfejsu UART/SWO
- Wiele poziomów logowania (DEBUG, INFO, WARN, ERROR)
- Kolorowe wyjście ułatwiające analizę logów
- Łatwa integracja z projektami CMake
- Wygodne makra dla różnych poziomów logowania

## Wymagania

- CMake 3.12 lub nowszy
- Kompilator C obsługujący standard C11
- Kompatybilne debuggery (np. J-Link)

## Instalacja

### Jako submoduł Git

```bash
# W głównym katalogu Twojego projektu
git submodule add https://github.com/twoje-konto/rtt_logger.git
git submodule update --init
```

### Integracja z CMake

Dodaj następujące linie do głównego pliku CMakeLists.txt:

```cmake
# Dołącz submoduł RTT Logger
add_subdirectory(rtt_logger)

# Linkuj bibliotekę do twojego projektu
target_link_libraries(${TWOJ_PROJEKT} PRIVATE rtt_logger)
```

## Użycie

### Włączenie nagłówka

```c
#include "rtt_logger.h"
```

### Logowanie

```c
// Przykłady różnych poziomów logowania
DEBUG_LOG("Wartość zmiennej: %d", some_variable);
INFO_LOG("Inicjalizacja zakończona");
WARN_LOG("Wykryto niski poziom baterii: %d%%", battery_level);
ERROR_LOG("Błąd komunikacji: 0x%02X", error_code);
```

### Przeglądanie logów

Aby przeglądać logi, można użyć:

- Programu [J-Link RTT Viewer](https://www.segger.com/products/debug-probes/j-link/tools/rtt-viewer/)
- Programu [probe-rs](https://probe.rs/)
- Wtyczek do IDE (np. dla Visual Studio Code, Eclipse)

## Konfiguracja zaawansowana

Jeśli chcesz dostosować zachowanie RTT Logger, możesz zmodyfikować plik `SEGGER_RTT_Conf.h` zgodnie z Twoimi potrzebami. Najczęściej modyfikowane parametry:

```c
// Rozmiar bufora dla komunikatów wychodzących (target -> host)
#define BUFFER_SIZE_UP 1024

// Liczba buforów "w górę" (target -> host)
#define SEGGER_RTT_MAX_NUM_UP_BUFFERS 3
```

## Autor

Krzysztof Andrzejewski

## Licencja

Ten projekt jest udostępniany na licencji MIT, z wyjątkiem komponentów SEGGER, które podlegają ich oryginalnej licencji - zobacz [LICENSE](LICENSE) oraz nagłówki w plikach źródłowych.

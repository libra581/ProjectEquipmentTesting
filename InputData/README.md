# Модуль имитации тестовых данных (InputData)

Модуль формирует исходные данные и разовые команды на основе плана испытания (сформированного [циклограммой][1]).
Также модуль подает в определенное планом время ИД и РК на интерфейс взаимодействия по COM-порту (RS-232).

Структура подачи РК:

```C++
struct masRK
{
 bool Comp1;
 bool Comp2;
 bool EnableParachute;
 bool PS1;
 bool PS2;
 qint32 SpecInfo;
};
```

Структура подачи ИД (оборудование сбора информации):

```C++
struct DataBASI
 {
 quint16 usCodeMode;
 quint16 usNumSession;
 qint32 MemoryAddress;
 qint32 NumberProgram;
 qint32 AmountDataWords;
 qint32 State;
 QByteArray Reserve;
};
``` 

# Входные данные
Параметры командной строки: <br>
1. Тип оборудования: указатель на C-Style строку (Пример: "BASI", "BAPPD");
2. Путь к файлу плана: указатель на C-Style строку (Пример: "C:\\Users\\sds\\Documents\\Plan"). <br>

Ожидаемые действия пользователя: *отсутсвуют*.

# Основные классы и методы
* *ImitLogic* - класс, который используется для имитации исходных данных и подачи разовых команд по COM-порту в определенное время, указанное в плане.<br>
* *IInputData* - интерфейс, наследующий класс *QObject* и содержащий чисто виртуальные 
функции для реализации алгоритмов манипулирования данными в зависимости от типа оборудования.<br>
* *InputData\** - классы, которые наследует интерфейс IInputData и реализуют логику имитации входных данных тестируемого оборудования.<br>

# Выходные данные
Модуль вернет в **систему** одно из нескольких значений перечисления *CodeExec*:

```C++
enum class CodeExec
{
 ErrorPort = -3,
 ErrorFile = -2,
 Error = -1,
 Success = 0,
 Waiting = 1,
 PortEmpty = 2,
 AnalyzeError= 3,
};
```

[1]: ./CycleGramma



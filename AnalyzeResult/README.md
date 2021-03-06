# Модуль анализа (Analyze)

Модуль принимает ТМИ в определенное планом время (сформированного [циклограммой][1]) и сравнивает данные в части плана ТМИ с самим планом.
Модуль принимает в определенное планом время ТМИ с интерфейса взаимодействия по COM-порту (RS-232).

Структура РК:

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

Структура ИД (оборудования сбора информации):

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
1. тип оборудования: указатель на C-Style строку (Пример: "BASI", "BAPPD");
2. путь к файлу плана: указатель на C-Style строку (Пример: "C:\\Users\\sds\\Documents\\Plan");
3. путь к файлу ТМИ : указатель на C-Style строку (Пример: "C:\\Users\\sds\\Documents\\TMI");
4. путь к файлу анализа : указатель на C-Style строку (Пример: "C:\\Users\\sds\\Documents\\Analyze").<br>

Ожидаемые действия пользователя: *отсутсвуют*.

# Основные классы и методы
* *AnalyzeLogic* - класс, который используется для анализа выходных ТМИ данных и принятия данных по COM-порту в определенное планом время.<br>
* *IAnalyze* - интерфейс, наследующий класс *QObject* и содержащий чисто виртуальные 
функции для реализации алгоритмов анализа данных в зависимости от типа оборудования.<br>
* *Analyze\** - классы, которые используются для реализации алгоритмов чтения и анализа по плану выходных данных работы оборудования.<br>

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



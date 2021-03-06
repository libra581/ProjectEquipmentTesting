# Циклограмма (Cyclegramma)

Модуль реализует алгоритм формирования циклограммы проведения испытаний аппаратуры в графическом виде,
позволяет проводить настройку циклограммы, сохранение и открытие, а также формирование структуры плана.

# Входные данные
Параметры командной строки: 
1. путь к файлу плана (например, :/Cyclegramma);
2. вид оборудования (например, BASI);.<br>

Ожидаемые действия пользователя:<br>
выбор пользователем оборудования и режимов работы, ввод необходимой информации для каждого режима, 
выбор нужных отрезков времени на циклограмме и задание необходимых параметров.

# Основные классы и методы
* *сMainWindow* - класс отображения интерфейса пользователя, который реализует пользовательскую механики взаимодействия пользователя 
и интерфейсных объектов, отвечате за сброку всех модулей программы в единное целое.<br>
* *сSceneWithOptions* - класс-контейнер технологических процессов, определять механику взаимодействия сцены и пользователя.<br>
* *cCycleEllipse* - класс отображения фигуры в виде эллипса, которую можно помещать на сцену, как тех. процесс, 
а также используется для отображения графических эффектов эллипса.<br>

# Скриншоты
![циклограмма](https://i.pinimg.com/originals/56/d5/29/56d5297897548b5a172df7e14bdeba42.png)



The first step on OpenGL.


1. Отрисовка треугольниками
1.1. Возможность включить wireframe mode, в котором будет видно, из каких треугольников состоит фигурка.
2. Возможность накладывать различные текстуры
2.1. Возможность переключать текстуры нажатием на кнопку
3. Наличие перспективы
3.1. Наличие матрицы модели (translate, scale, rotate)
4. Вращение фигурки вокруг своей оси.
5. Наличие скайбокса

Первые шаги в изучении API OpenGL.

Программа собирается с помощью Makefile. Для запуска программы необходимо ввести make && ./scop models/*models_name*.obj в корневом файле проекта. В терминале откроется небольшое меню, где указаны клавиши для взаимодействия с программой.

Открытие окна, проверка различных событий, связанных с нажатием клавиш / кнопки мыши, реализуется с помощью библиотеки glfw.

Каждая .obj модель состоит из треугольников. Программа считывает расположение вертексов и отрисовывает по ним модель - получаются треугольники. Это можно увидеть, включив Wireframe mode, а так же при запуске программы. 

![wireframe](https://github.com/rimargri/Scop/raw/master/screenshots/wireframe_mode.png)

На модель можно наложить текстуру. В программе реализована возможность переключать разные текстуры путём нажатия на кнопку.

![wireframe](https://github.com/rimargri/Scop/raw/main/screenshots/texture_1.png)

![wireframe](https://github.com/rimargri/Scop/raw/main/screenshots/texture_2.png)

![wireframe](https://github.com/rimargri/Scop/raw/main/screenshots/texture_3.png)

![wireframe](https://github.com/rimargri/Scop/raw/main/screenshots/texture_4.png)

Модель можно крутить в разные стороны, двигать, приближать и отдалять - для этого в программу встроена матрица перспективы (чем дальше объект, тем он меньше) и матрица модели, состоящая из перемножения матриц сдвига (translate), масштабирования (scale), поворота (rotate).

![wireframe](https://github.com/rimargri/Scop/raw/main/screenshots/rotate.png)

![wireframe](https://github.com/rimargri/Scop/raw/main/screenshots/scale.png)

В программе присутствует Skybox - на него наложена текстура космоса.

![wireframe](https://github.com/rimargri/Scop/raw/main/screenshots/skybox.png)


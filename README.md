The first step on OpenGL.
Первые шаги в изучении API OpenGL.

Программа собирается с помощью Makefile. Для запуска программы необходимо ввести make && ./scop models/*models_name*.obj в корневом файле проекта. В терминале откроется небольшое меню, где указаны клавиши для взаимодействия с программой.

Открытие окна, проверка различных событий, связанных с нажатием клавиш / кнопки мыши, реализуется с помощью библиотеки glfw.

Каждая .obj модель состоит из треугольников. Программа считывает расположение вертексов и отрисовывает по ним модель - получаются треугольники. Это можно увидеть, включив Wireframe mode, а так же при запуске программы. 

![wireframe](https://github.com/rimargri/Scop/raw/master/screenshots/wireframe_mode.png)

![wireframe](https://github.com/rimargri/Scop/raw/master/screenshots/wireframe_dog.png)

На модель можно наложить текстуру. В программе реализована возможность переключать разные текстуры путём нажатия на кнопку.

![wireframe](https://github.com/rimargri/Scop/raw/master/screenshots/texture_1.png)

![wireframe](https://github.com/rimargri/Scop/raw/master/screenshots/texture_2.png)

![wireframe](https://github.com/rimargri/Scop/raw/master/screenshots/texture_3.png)

![wireframe](https://github.com/rimargri/Scop/raw/master/screenshots/texture_4.png)

![wireframe](https://github.com/rimargri/Scop/raw/master/screenshots/texture_5.png)

Модель можно крутить в разные стороны, двигать, приближать и отдалять - для этого в программу встроена матрица перспективы (чем дальше объект, тем он меньше) и матрица модели, состоящая из перемножения матриц сдвига (translate), масштабирования (scale), поворота (rotate).

![wireframe](https://github.com/rimargri/Scop/raw/master/screenshots/rotate.png)

![wireframe](https://github.com/rimargri/Scop/raw/master/screenshots/scale.png)

В программе присутствует Skybox - на него наложена текстура космоса.

![wireframe](https://github.com/rimargri/Scop/raw/master/screenshots/skybox.png)


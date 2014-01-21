cargo-limited-TSP
=================

The goal of the project is to solve TSP with distribution centre and limited number of packages that can be taken at one time. 


Building
~~~~~~~~

To build the program, you need g++ and cmake.
Go to Evolutionary/ directory and type 'make'.

To build tests, you also need gtest installed,
Go to Evolutionary/ directory and type 'make test'.

Commands above will create in directory Evolutionary/bin/ 
executable files 'Solve' and 'runTests'.

Running
~~~~~~~

Example:

./bin/Solve < ../Input/test_050_1.in

./bin/runTests



Algorytm ewolucyjny
-------------------

Osobnik
^^^^^^^
Każdy osobnik zapisuje jeden sposób dostarczenia kontenerów do miast.
Osobnik zkłada się z kursów, a każdy kurs zapisuje odwiedzenie kilku miast w podanej kolejności.

Reproduction
~~~~~~~~~~~~
W tej fazie osobniki dzielą się w pary i przez crossover generują potomków.
Każdych 2 osobników tworzy 2 potomków.

Crossover
~~~~~~~~~
Z dużym prawdopodobieństwem dla każdego kursu pierwszego z rodziców dołączamy go do potomka. Z reszty nieodwiedzonych miast tworzymy kursy maksymalnej ładowności, w kolejości, w jakiej występują one w drugim z rodziców.

Mutation
~~~~~~~~
Mutacja polega na zamianie 2 miast z różnych kursów.
Mutacja zachodzi dla kazdego osobnika z pewnym prawdopodobieństwem. 
By zwięszyć obszar przeszukiewania algorytmu, jesli nastąpi mutacja, powtarzamy procedurę dla tego osobnika od nowa. 
Np. jeśli prawdopodobieństwo mutacji wynosi 90%, to osobnik zostanie zmutowany średnio 10 razy.

Local Search
~~~~~~~~~~~~
W przypadku ograniczenia ładowności do 3, local search polega na zastapieniu każdego z kursów przez optymalny.
Jeśli ładowność jest ograniczona do >3, to przeszukiwani lokalne polega na zastapieniu każdego z kursów przez najlepszy z kilku powstałych przez permutację kolejności początkowego kursu. 

Evaluation
~~~~~~~~~~
Jest to krok, w którym oceniamy każdego osobnika, obliczając jesgo funkcję przystosowania.

Replacement
~~~~~~~~~~~
Polega na zastąpieniu starej populacji przez nową.
By zwiększyć nacisk na przeszukiwanie w okolicy najlepszych osobników, kopiujemy pewną część najlepszych osobników, dodając ich klony do populacji.
Do nowego pokolenia wchodzi tyle osobników, ile było na początku iteracji. 



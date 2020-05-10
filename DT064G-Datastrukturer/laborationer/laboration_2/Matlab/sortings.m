clc
clear
figure('NumberTitle', 'off', 'Name', 'Sorting algorithms');
%% Selection sort
ascending_selection_sort = readtable('../src/data_files/ascending_selection_sort.csv');
descending_selection_sort = readtable('../src/data_files/descending_selection_sort.csv');
constant_selection_sort = readtable('../src/data_files/constant_selection_sort.csv');
random_selection_sort = readtable('../src/data_files/random_selection_sort.csv');

subplot(2,3,1)
plot(table2array(ascending_selection_sort(1,:)),table2array(ascending_selection_sort(2,:)), 'g')
xlabel('Elements (N)')
ylabel('T[ms] (Average)')
grid on

hold on

plot(table2array(descending_selection_sort(1,:)),table2array(descending_selection_sort(2,:)), 'r')
hold on

plot(table2array(constant_selection_sort(1,:)),table2array(constant_selection_sort(2,:)), 'y')
hold on

plot(table2array(random_selection_sort(1,:)),table2array(random_selection_sort(2,:)), 'b')
legend('Ascending','Descending','Constant','Random')
title('Selection sort')

%% Insertion sort
ascending_insertion_sort = readtable('../src/data_files/ascending_insertion_sort.csv');
descending_insertion_sort = readtable('../src/data_files/descending_insertion_sort.csv');
constant_insertion_sort = readtable('../src/data_files/constant_insertion_sort.csv');
random_insertion_sort = readtable('../src/data_files/random_insertion_sort.csv');

subplot(2,3,2)
plot(table2array(ascending_insertion_sort(1,:)),table2array(ascending_insertion_sort(2,:)))
xlabel('Elements (N)')
ylabel('T[ms] (Average)')
title('Insertion sort')
grid on

hold on
plot(table2array(descending_insertion_sort(1,:)),table2array(descending_insertion_sort(2,:)))
hold on
plot(table2array(constant_insertion_sort(1,:)),table2array(constant_insertion_sort(2,:)))
hold on
plot(table2array(random_insertion_sort(1,:)),table2array(random_insertion_sort(2,:)))
legend('Ascending','Descending','Constant','Random')

%% Quick part sort
ascending_quick_part_sort = readtable('../src/data_files/ascending_quick_partition.csv');
descending_quick_part_sort = readtable('../src/data_files/descending_quick_partition.csv');
constant_quick_part_sort = readtable('../src/data_files/constant_quick_partition.csv');
random_quick_part_sort = readtable('../src/data_files/random_quick_partition.csv');

subplot(2,3,3)
plot(table2array(ascending_quick_part_sort(1,:)),table2array(ascending_quick_part_sort(2,:)))
xlabel('Elements (N)')
ylabel('T[ms] (Average)')
grid on

hold on
plot(table2array(descending_quick_part_sort(1,:)),table2array(descending_quick_part_sort(2,:)))
hold on
plot(table2array(constant_quick_part_sort(1,:)),table2array(constant_quick_part_sort(2,:)))
hold on
plot(table2array(random_quick_part_sort(1,:)),table2array(random_quick_part_sort(2,:)))
title('Quick sort')
legend('Ascending','Descending','Constant','Random')

%% Quick med3
ascending_quick_med3_sort = readtable('../src/data_files/ascending_quick_par3.csv');
descending_quick_med3_sort = readtable('../src/data_files/descending_quick_par3.csv');
constant_quick_med3_sort = readtable('../src/data_files/constant_quick_par3.csv');
random_quick_med3_sort = readtable('../src/data_files/random_quick_par3.csv');

subplot(2,3,4)
plot(table2array(ascending_quick_med3_sort(1,:)),table2array(ascending_quick_med3_sort(2,:)))
xlabel('Elements (N)')
ylabel('T[ms] (Average)')
grid on

hold on
plot(table2array(descending_quick_med3_sort(1,:)),table2array(descending_quick_med3_sort(2,:)))
hold on
plot(table2array(constant_quick_med3_sort(1,:)),table2array(constant_quick_med3_sort(2,:)))
hold on
plot(table2array(random_quick_med3_sort(1,:)),table2array(random_quick_med3_sort(2,:)))
title('Quick median 3')
legend('Ascending','Descending','Constant','Random')

%% Std
ascending_std_sort = readtable('../src/data_files/ascending_std_sort.csv');
descending_std_sort = readtable('../src/data_files/descending_std_sort.csv');
constant_std_sort = readtable('../src/data_files/constant_std_sort.csv');
random_std_sort = readtable('../src/data_files/random_std_sort.csv');

subplot(2,3,5)
plot(table2array(ascending_std_sort(1,:)),table2array(ascending_std_sort(2,:)))
xlabel('Elements (N)')
ylabel('T[ms] (Average)')
grid on

hold on
plot(table2array(descending_std_sort(1,:)),table2array(descending_std_sort(2,:)))
hold on
plot(table2array(constant_std_sort(1,:)),table2array(constant_std_sort(2,:)))
hold on
plot(table2array(random_std_sort(1,:)),table2array(random_std_sort(2,:)))
title('Std sort')
legend('Ascending','Descending','Constant','Random')

clc
clear
%% Selection sort

figure('NumberTitle', 'off', 'Name', 'Selection sort');
subplot(2,2,1)

ascending_selection_sort = readtable('../src/data_files/ascending_selection_sort.csv');
asc_sel_sort_x = table2array(ascending_selection_sort(1,:))
asc_sel_sort_y = table2array(ascending_selection_sort(2,:))
asc_sel_stddev = table2array(ascending_selection_sort(3,:))

f = fit(asc_sel_sort_x(:), asc_sel_sort_y(:), 'poly2');
plot(f, asc_sel_sort_x, asc_sel_sort_y)
hold on
e = errorbar(asc_sel_sort_x, asc_sel_sort_y, asc_sel_stddev, 'b')
e.LineStyle = 'none';

title('Selection sort - Ascending values')
legend({'Data','Fitted curve', 'std dev'})

xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,2)

descending_selection_sort = readtable('../src/data_files/descending_selection_sort.csv');

desc_sel_sort_x = table2array(descending_selection_sort(1,:))
desc_sel_sort_y = table2array(descending_selection_sort(2,:))
desc_sel_stddev = table2array(descending_selection_sort(3,:))

plot(desc_sel_sort_x, desc_sel_sort_y, 'r')
errorbar(desc_sel_sort_x, desc_sel_sort_y, desc_sel_stddev)

title('Selection sort - Descending values')
%%legend('Data','Std dev')

xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,3)

constant_selection_sort = readtable('../src/data_files/constant_selection_sort.csv');

const_sel_sort_x = table2array(constant_selection_sort(1,:))
const_sel_sort_y = table2array(constant_selection_sort(2,:))
const_sel_stddev = table2array(constant_selection_sort(3,:))

plot(const_sel_sort_x, const_sel_sort_y, 'r')
errorbar(const_sel_sort_x, const_sel_sort_y, const_sel_stddev)

title('Selection sort - Contant values')
%legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,4)

random_selection_sort = readtable('../src/data_files/random_selection_sort.csv');

rand_sel_sort_x = table2array(random_selection_sort(1,:))
rand_sel_sort_y = table2array(random_selection_sort(2,:))
rand_sel_stddev = table2array(random_selection_sort(3,:))

plot(rand_sel_sort_x, rand_sel_sort_y, 'r')
errorbar(rand_sel_sort_x, rand_sel_sort_y, rand_sel_stddev)

title('Selection sort - Random values')
%%legend('Data','Std dev')

xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

%% Insertion sort
figure('NumberTitle', 'off', 'Name', 'Insertion sort');
subplot(2,2,1)

ascending_insertion_sort = readtable('../src/data_files/ascending_insertion_sort.csv');
asc_ins_sort_x = table2array(ascending_insertion_sort(1,:))
asc_ins_sort_y = table2array(ascending_insertion_sort(2,:))
asc_ins_stddev = table2array(ascending_insertion_sort(3,:))

plot(asc_ins_sort_x, asc_ins_sort_y)

errorbar(asc_ins_sort_x, asc_ins_sort_y, asc_ins_stddev)

title('Insertion sort - Ascending values')
%legend('Data','Std dev')

xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,2)

descending_insertion_sort = readtable('../src/data_files/descending_insertion_sort.csv');

desc_ins_sort_x = table2array(descending_insertion_sort(1,:))
desc_ins_sort_y = table2array(descending_insertion_sort(2,:))
desc_ins_stddev = table2array(descending_insertion_sort(3,:))

plot(desc_ins_sort_x, desc_ins_sort_y)
errorbar(desc_ins_sort_x, desc_ins_sort_y, desc_ins_stddev)

title('Insertion sort - Descending values')
%legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,3)

constant_insertion_sort = readtable('../src/data_files/constant_insertion_sort.csv');

const_ins_sort_x = table2array(constant_insertion_sort(1,:))
const_ins_sort_y = table2array(constant_insertion_sort(2,:))
const_ins_stddev = table2array(constant_insertion_sort(3,:))

plot(const_ins_sort_x, const_ins_sort_y)
errorbar(const_ins_sort_x, const_ins_sort_y, const_ins_stddev)

title('Insertion sort - Contant values')
%legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,4)

random_insertion_sort = readtable('../src/data_files/random_insertion_sort.csv');

rand_ins_sort_x = table2array(random_insertion_sort(1,:))
rand_ins_sort_y = table2array(random_insertion_sort(2,:))
rand_ins_stddev = table2array(random_insertion_sort(3,:))

plot(rand_ins_sort_x, rand_ins_sort_y)
errorbar(rand_ins_sort_x, rand_ins_sort_y, rand_ins_stddev)

title('Insertion sort - Random values')
%legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on




%% Quick sort
figure('NumberTitle', 'off', 'Name', 'Quick sort');
subplot(2,2,1)

ascending_quick_partition_sort = readtable('../src/data_files/ascending_quick_partition_sort.csv');
asc_quick_sort_x = table2array(ascending_quick_partition_sort(1,:))
asc_quick_sort_y = table2array(ascending_quick_partition_sort(2,:))
asc_quick_stddev = table2array(ascending_quick_partition_sort(3,:))

plot(asc_quick_sort_x, asc_quick_sort_y)

errorbar(asc_quick_sort_x, asc_quick_sort_y, asc_quick_stddev)

title('Quick sort - Ascending values')
%legend('Data','Std dev')

xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,2)

descending_quick_partition_sort = readtable('../src/data_files/descending_quick_partition_sort.csv');

desc_quick_sort_x = table2array(descending_quick_partition_sort(1,:))
desc_quick_sort_y = table2array(descending_quick_partition_sort(2,:))
desc_quick_stddev = table2array(descending_quick_partition_sort(3,:))

plot(desc_quick_sort_x, desc_quick_sort_y)
errorbar(desc_quick_sort_x, desc_quick_sort_y, desc_quick_stddev)

title('Quick sort - Descending values')
%legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,3)

constant_quick_partition_sort = readtable('../src/data_files/constant_quick_partition_sort.csv');

const_quick_sort_x = table2array(constant_quick_partition_sort(1,:))
const_quick_sort_y = table2array(constant_quick_partition_sort(2,:))
const_quick_stddev = table2array(constant_quick_partition_sort(3,:))

plot(const_quick_sort_x, const_quick_sort_y)
errorbar(const_quick_sort_x, const_quick_sort_y, const_quick_stddev)

title('Quick sort - Contant values')
%legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,4)

random_quick_partition_sort = readtable('../src/data_files/random_quick_partition_sort.csv');

rand_quick_sort_x = table2array(random_quick_partition_sort(1,:))
rand_quick_sort_y = table2array(random_quick_partition_sort(2,:))
rand_quick_stddev = table2array(random_quick_partition_sort(3,:))

plot(rand_quick_sort_x, rand_quick_sort_y)
errorbar(rand_quick_sort_x, rand_quick_sort_y, rand_quick_stddev)

title('Quick sort - Random values')
%legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

%% Quick med3
figure('NumberTitle', 'off', 'Name', 'Quick sort median of three');
subplot(2,2,1)

ascending_quick_par3 = readtable('../src/data_files/ascending_quick_par3.csv');
asc_qm3_sort_x = table2array(ascending_quick_par3(1,:))
asc_qm3_sort_y = table2array(ascending_quick_par3(2,:))
asc_qm3_stddev = table2array(ascending_quick_par3(3,:))

plot(asc_qm3_sort_x, asc_qm3_sort_y)

errorbar(asc_qm3_sort_x, asc_qm3_sort_y, asc_qm3_stddev)

title('Quick sort m3 - Ascending values')
%legend('Data','Std dev')

xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,2)

descending_quick_par3 = readtable('../src/data_files/descending_quick_par3.csv');

desc_qm3_sort_x = table2array(descending_quick_par3(1,:))
desc_qm3_sort_y = table2array(descending_quick_par3(2,:))
desc_qm3_stddev = table2array(descending_quick_par3(3,:))

plot(desc_qm3_sort_x, desc_qm3_sort_y)
errorbar(desc_qm3_sort_x, desc_qm3_sort_y, desc_qm3_stddev)

title('Quick sort m3 - Descending values')
%legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,3)

constant_quick_par3 = readtable('../src/data_files/constant_quick_par3.csv');

const_qm3_sort_x = table2array(constant_quick_par3(1,:))
const_qm3_sort_y = table2array(constant_quick_par3(2,:))
const_qm3_stddev = table2array(constant_quick_par3(3,:))

plot(const_qm3_sort_x, const_qm3_sort_y)
errorbar(const_qm3_sort_x, const_qm3_sort_y, const_qm3_stddev)

title('Quick sort m3 - Contant values')
%legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,4)

random_quick_par3 = readtable('../src/data_files/random_quick_par3.csv');

rand_qm3_sort_x = table2array(random_quick_par3(1,:))
rand_qm3_sort_y = table2array(random_quick_par3(2,:))
rand_qm3_stddev = table2array(random_quick_par3(3,:))

plot(rand_qm3_sort_x, rand_qm3_sort_y)
errorbar(rand_qm3_sort_x, rand_qm3_sort_y, rand_qm3_stddev)

title('Quick sort m3 - Random values')
%legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

%% std sort
figure('NumberTitle', 'off', 'Name', 'std::sort');
subplot(2,2,1)

ascending_std_sort = readtable('../src/data_files/ascending_std_sort.csv');
asc_std_sort_x = table2array(ascending_std_sort(1,:))
asc_std_sort_y = table2array(ascending_std_sort(2,:))
asc_std_stddev = table2array(ascending_std_sort(3,:))

plot(asc_std_sort_x, asc_std_sort_y)

errorbar(asc_std_sort_x, asc_std_sort_y, asc_std_stddev)

title('std::sort - Ascending values')
legend('Data','Std dev')

xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,2)

descending_std_sort = readtable('../src/data_files/descending_std_sort.csv');

desc_std_sort_x = table2array(descending_std_sort(1,:))
desc_std_sort_y = table2array(descending_std_sort(2,:))
desc_std_stddev = table2array(descending_std_sort(3,:))

plot(desc_std_sort_x, desc_std_sort_y)
errorbar(desc_std_sort_x, desc_std_sort_y, desc_std_stddev)

title('std::sort - Descending values')
legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,3)

constant_std_sort = readtable('../src/data_files/constant_std_sort.csv');

const_std_sort_x = table2array(constant_std_sort(1,:))
const_std_sort_y = table2array(constant_std_sort(2,:))
const_std_stddev = table2array(constant_std_sort(3,:))

plot(const_std_sort_x, const_std_sort_y)
errorbar(const_std_sort_x, const_std_sort_y, const_std_stddev)

title('std::sort - Contant values')
legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on

subplot(2,2,4)

random_std_sort = readtable('../src/data_files/random_std_sort.csv');

rand_std_sort_x = table2array(random_std_sort(1,:))
rand_std_sort_y = table2array(random_std_sort(2,:))
rand_std_stddev = table2array(random_std_sort(3,:))

plot(rand_std_sort_x, rand_std_sort_y)
errorbar(rand_std_sort_x, rand_std_sort_y, rand_std_stddev)

title('std::sort - Random values')
legend('Data','Std dev')
xlabel('Elements (N)')
ylabel('T[µs] (Average)')
grid on


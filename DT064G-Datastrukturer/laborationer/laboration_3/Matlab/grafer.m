clc
clear

%% Subplots
linear_search = readtable('../src/data_files/linear_search.txt');
binary_search = readtable('../src/data_files/binary_search.txt');
bst = readtable('../src/data_files/binary_search_tree.txt');
hash_table = readtable('../src/data_files/hash_table.txt');

figure('NumberTitle', 'off', 'Name', 'Search algorithms');
subplot(2,2,1)
plot(table2array(linear_search(1,:)),table2array(linear_search(2,:)), 'g')
xlabel('Elements (N)')
ylabel('T[μs] (Average)')
grid on
title('Linear search')

subplot(2,2,2)
plot(table2array(binary_search(1,:)),table2array(binary_search(2,:)), 'r')
xlabel('Elements (N)')
ylabel('T[μs] (Average)')
grid on
title('Binary search')

subplot(2,2,3)
plot(table2array(bst(1,:)),table2array(bst(2,:)), 'y')
xlabel('Elements (N)')
ylabel('T[μs] (Average)')
grid on
title('Binary search tree')

subplot(2,2,4)
plot(table2array(hash_table(1,:)),table2array(hash_table(2,:)), 'b')
xlabel('Elements (N)')
ylabel('T[μs] (Average)')
title('hash table')
grid on


%% Gemensam graf
linear_search = readtable('../src/data_files/linear_search.txt');
binary_search = readtable('../src/data_files/binary_search.txt');
bst = readtable('../src/data_files/binary_search_tree.txt');
hash_table = readtable('../src/data_files/hash_table.txt');



table2array(linear_search(1,:)),table2array(linear_search(2,:))
plot(table2array(linear_search(1,:)),table2array(linear_search(2,:)), 'g')
xlabel('Elements (N)')
ylabel('T[μs] (Average)')
legend({'Linear', 'Binary', 'Bst', 'Hash table'})
hold on

plot(table2array(binary_search(1,:)),table2array(binary_search(2,:)), 'r')
hold on

plot(table2array(bst(1,:)),table2array(bst(2,:)), 'y')
hold on

plot(table2array(hash_table(1,:)),table2array(hash_table(2,:)), 'b')
%legend('Linear','Binary','Bst','Hash table')
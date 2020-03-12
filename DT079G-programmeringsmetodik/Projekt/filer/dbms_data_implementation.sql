/*
Course: DT079G - Programmeringsmetodik
Task:   Projekt
Author: Linus Sjöbro
*/

use vetClin;

-- Addresses data
-- --------------------
-- Addresses for employees
INSERT INTO address (address, city, state, zipCode) VALUES ('908 W.Capital Way',              'Tacoma',         'WA', 98401);
INSERT INTO address (address, city, state, zipCode) VALUES ('4726- 11th Ave. N.E.',           'Seattle',        'WA', 98105);
INSERT INTO address (address, city, state, zipCode) VALUES ('722 Moss Bar Blvd.',             'Kirkland',       'WA', 98033);
INSERT INTO address (address, city, state, zipCode) VALUES ('Coventry House Miner Rd.',       'Tacoma',         'WA', 98402);
INSERT INTO address (address, city, state, zipCode) VALUES ('7 Hounds tooth Rd.',             'Bellingham',     'WA', 98047);
INSERT INTO address (address, city, state, zipCode) VALUES ('14 Garret Hill',                 'Bellingham',     'WA', 98047);
INSERT INTO address (address, city, state, zipCode) VALUES ('507 - 20th Ave. E. Apt 2A',      'Seattle',        'WA', 98122);
INSERT INTO address (address, city, state, zipCode) VALUES ('Edgeham Hollow Winchester Way',  'Seattle',        'WA', 98125);
INSERT INTO address (address, city, state, zipCode) VALUES ('4110 Old Redmond Rd.',           'Redmond',        'WA', 98052);

-- Addresses for customers
INSERT INTO address (address, city, state, zipCode) VALUES ('21 Grace St.',                   'Tall Pines',     'WA', 98746);
INSERT INTO address (address, city, state, zipCode) VALUES ('66 10th St',                     'Mountain View',  'WA', 98401012);
INSERT INTO address (address, city, state, zipCode) VALUES ('1122 10th St',                   'Lakeville',      'OR', 974011011);
INSERT INTO address (address, city, state, zipCode) VALUES ('15 Marlin Lane',                 'Borderville',    'ID', 834835646);


-- Employees data
-- --------------------
INSERT INTO employees (lastName, firstName, educationalDegree, hireDate, homePhone, addressID) VALUES ('Plotter',     'Mary',     'PhD.', '1992-05-01', '(206) 555-9857', 7);
INSERT INTO employees (lastName, firstName, educationalDegree, hireDate, homePhone, addressID) VALUES ('Becker',      'Todd',     'MS.',  '1992-08-04', '(206) 555-9482', 1);
INSERT INTO employees (lastName, firstName, educationalDegree, hireDate, homePhone, addressID) VALUES ('Carrington',  'Maram',    'MS.',  '1992-04-01', '(206) 555-3412', 3);
INSERT INTO employees (lastName, firstName, educationalDegree, hireDate, homePhone, addressID) VALUES ('Walters',     'Margaret', 'MS.',  '1993-05-08', '(206) 555-8122', 9);
INSERT INTO employees (lastName, firstName, educationalDegree, hireDate, homePhone, addressID) VALUES ('Peters',      'peter',    'BS.',  '1993-10-17', '(71) 555-4848',  6);
INSERT INTO employees (lastName, firstName, educationalDegree, hireDate, homePhone, addressID) VALUES ('Chiu',        'Liu',      'MS.',  '1993-10-17', '(71) 555-7773',  4);
INSERT INTO employees (lastName, firstName, educationalDegree, hireDate, homePhone, addressID) VALUES ('Wally',       'Robert',   'AA.',  '1994-01-02', '(71) 555-5598',  8);
INSERT INTO employees (lastName, firstName, educationalDegree, hireDate, homePhone, addressID) VALUES ('Bowie',       'Rosie',    'BS.',  '1994-03-15', '(206) 555-1189', 2);
INSERT INTO employees (lastName, firstName, educationalDegree, hireDate, homePhone, addressID) VALUES ('Dennis',      'Anne',     'MS.',  '1994-11-05', '(71) 555-4444',  5);

-- Login data
-- --------------------

INSERT INTO logins (username, password, employeeID) VALUES ('mapl',   'pw', 1);
INSERT INTO logins (username, password, employeeID) VALUES ('tobe',   'pw', 2);


-- Breeds data
-- --------------------
INSERT INTO breeds (name, typeOfAnimal) VALUES ('Long Ear',        'RABBIT');
INSERT INTO breeds (name, typeOfAnimal) VALUES ('German Shepherd', 'DOG');
INSERT INTO breeds (name, typeOfAnimal) VALUES ('Chameleon',       'LIZARD');
INSERT INTO breeds (name, typeOfAnimal) VALUES ('',                'SKUNK');
INSERT INTO breeds (name, typeOfAnimal) VALUES ('Potbelly',        'PIG');
INSERT INTO breeds (name, typeOfAnimal) VALUES ('Palomino',        'HORSE');
INSERT INTO breeds (name, typeOfAnimal) VALUES ('Mixed',           'DOG');
INSERT INTO breeds (name, typeOfAnimal) VALUES ('',                'RAT');
INSERT INTO breeds (name, typeOfAnimal) VALUES ('Beagle',          'DOG');


-- Customers data
-- --------------------
INSERT INTO customers VALUES ('9210010592', 'Linus Sjöbro',     '(206) 555-6622', 10);
INSERT INTO customers VALUES ('9504081887', 'Carina Viklund',  '(206) 555-7623', 11);
INSERT INTO customers VALUES ('9608201365', 'Alexandra Viklund',     '(503) 555-6187', 12);
INSERT INTO customers VALUES ('6009022358', 'Leif Lageholm',    '(208) 555-7108', 13);




-- Pets data
-- --------------------

-- Pets that belongs to 9210010592
INSERT INTO animals VALUES ('9210010592-01', 'Bobo',           '1992-04-08', 'M', 1, '9210010592');
INSERT INTO animals VALUES ('9210010592-04', 'Fido',           '1990-06-01', 'M', 2, '9210010592');
INSERT INTO animals VALUES ('9210010592-02', 'Presto Chango',  '1992-05-01', 'F', 3, '9210010592');
INSERT INTO animals VALUES ('9210010592-03', 'Stinky',         '1991-08-01', 'M', 4, '9210010592');

-- Pets that belong to 9504081887
INSERT INTO animals VALUES ('9504081887-01', 'Patty',          '1991-02-15', 'F', 5, '9504081887');
INSERT INTO animals VALUES ('9504081887-02', 'Rising Sun',     '1990-04-10', 'M', 6, '9504081887');

-- Pet that belongs to 9608201887
INSERT INTO animals VALUES ('9608201365-01', 'Dee Dee',        '1991-02-15', 'F', 7, '9608201365');

-- Pets that belongs to 6009022358
INSERT INTO animals VALUES ('6009022358-01', 'Jerry',          '1988-02-01', 'M', 8, '6009022358');
INSERT INTO animals VALUES ('6009022358-02', 'Luigi',          '1992-08-01', 'M', 9, '6009022358');


-- Medications data
-- --------------------
INSERT INTO medications VALUES ('M0202', 'Zinc Oxide - 4 oz',         7.80);
INSERT INTO medications VALUES ('M0500', 'Nyostatine - 1 oz',         11.50);
INSERT INTO medications VALUES ('M0702', 'Xaritain Glyconol - 2 oz',  34.50);


-- Treatments data
-- --------------------
INSERT INTO treatments VALUES ('T1001', 'Labwork  - Cerology',        75  );
INSERT INTO treatments VALUES ('T1003', 'Lab work - Misc',            35  );
INSERT INTO treatments VALUES ('T0300', 'General Exam',               50  );
INSERT INTO treatments VALUES ('T2003', 'Flea Spray',                 25  );
INSERT INTO treatments VALUES ('T0404', 'Repair complex fracture',    230 );
INSERT INTO treatments VALUES ('T0408', 'Cast affected area',         120 );
INSERT INTO treatments VALUES ('T0622', 'Blood sample',               87  );

-- Visits data
-- --------------------

-- Visit 1
-- INSERT INTO visits (date, animalID, employeeID) VALUES ('1998-04-11', '9210010592-04', 4);
-- INSERT INTO visits_treatments VALUES (1, 'T1003');
-- INSERT INTO visits_treatments VALUES (1, 'T1001');
-- INSERT INTO visits_treatments VALUES (1, 'T0300');
-- INSERT INTO visits_medications VALUES (1, 'M0202');
--
-- -- Visit 2
-- INSERT INTO visits (date, animalID, employeeID) VALUES ('2016-02-25', '9504081887-01', 8);
-- INSERT INTO visits_treatments VALUES (2, 'T0300');
-- INSERT INTO visits_treatments VALUES (2, 'T2003');
-- INSERT INTO visits_treatments VALUES (2, 'T0622');

/*
Course: DT079G - Programmeringsmetodik
Task:   Projekt
Author: Linus Sjöbro
*/

-- Create and use database
CREATE DATABASE vetClin;
USE vetClin;

CREATE TABLE visits (
  ID                  int not null auto_increment,
  date                date,
  time                time,
  description         longtext,
  status              text,

  animalID            varchar(17),
  employeeID          int,

  CONSTRAINT visits_PK          PRIMARY KEY (ID)
);

CREATE TABLE medications (
  ID                  varchar(5) not null,
  name                varchar(25),
  price               float,

  CONSTRAINT medications_PK PRIMARY KEY (ID)
);

CREATE TABLE treatments (
  ID                  varchar(5) not null,
  name                varchar(25),
  price               float,

  CONSTRAINT treatments_PK PRIMARY KEY (ID)
);

CREATE TABLE visits_medications (
  visitID             int not null,
  medicationID        varchar(5) not null,

  CONSTRAINT visits_medications_PKs PRIMARY KEY (visitID, medicationID)
);

CREATE TABLE visits_treatments (
  visitID             int not null,
  treatmentID         varchar(5) not null,

  CONSTRAINT visits_treatments_PKs PRIMARY KEY (visitID, treatmentID)
);

CREATE TABLE breeds (
  ID                  int not null auto_increment,
  name                varchar(15),
  typeOfAnimal        varchar(15),

  CONSTRAINT breeds_PK PRIMARY KEY (ID)
);

CREATE TABLE animals (
  ID                  varchar(17) not null,
  name                varchar(20),
  dateOfBirth         date,
  gender              char(1),

  breedID             int NOT NULL,
  customerID          varchar(12) NOT NULL,

  CONSTRAINT animals_PK PRIMARY KEY (ID)
);

CREATE TABLE customers (
  ID                  varchar(12) not null,
  Name                varchar(40),
  phoneNumber         int,
  addressID           int,

  CONSTRAINT customers_PK PRIMARY KEY (ID)
);

CREATE TABLE address (
  ID                 int not null auto_increment,
  address             varchar(40),
  city                varchar(25),
  state               varchar(20),
  zipCode             int,

  CONSTRAINT address_PK PRIMARY KEY (ID)
);

CREATE TABLE employees (
  ID                 int not null auto_increment,
  lastName            varchar(20),
  firstName           varchar(20),
  educationalDegree   varchar(40),
  hireDate            date,
  homePhone           varchar(15),
  addressID           int,

  CONSTRAINT employees_PK PRIMARY KEY (ID)
);

CREATE TABLE logins (
  ID                int not null auto_increment,
  username          varchar(20),
  password          varchar(20),
  employeeID        int,

  CONSTRAINT logins_PK PRIMARY KEY (ID)
);

-- Add FK to tables
ALTER TABLE visits
  ADD CONSTRAINT visits_animal_FK     FOREIGN KEY (animalID)    REFERENCES animals    (ID),
  ADD CONSTRAINT visits_employee_FK   FOREIGN KEY (employeeID)  REFERENCES employees  (ID);

ALTER TABLE animals
  ADD CONSTRAINT animals_breed_FK     FOREIGN KEY (breedID)     REFERENCES breeds     (ID),
  ADD CONSTRAINT animals_customer_FK  FOREIGN KEY (customerID)  REFERENCES customers  (ID);

ALTER TABLE customers
  ADD CONSTRAINT customers_address_FK FOREIGN KEY (addressID)   REFERENCES address    (ID);

ALTER TABLE employees
  ADD CONSTRAINT employees_address_FK FOREIGN KEY (addressID)   REFERENCES address    (ID);

ALTER TABLE logins
  ADD CONSTRAINT logins_employee_FK   FOREIGN KEY (employeeID)  REFERENCES  employees (ID);

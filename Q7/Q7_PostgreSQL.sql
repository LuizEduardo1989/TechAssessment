-- Information about pets is kept in two separate tables:
-- PostgreSQL
--
--
-- TABLE dogs
--   id INTEGER NOT NULL PRIMARY KEY,
--   name VARCHAR(50) NOT NULL
--
-- TABLE cats
--   id INTEGER NOT NULL PRIMARY KEY,
--   name VARCHAR(50) NOT NULL
--
-- Write a query that select all distinct pet names.
--
--
-- Example case create statement:
 CREATE TABLE dogs (
   id INTEGER NOT NULL PRIMARY KEY,
   name VARCHAR(50) NOT NULL
 );
--
 CREATE TABLE cats (
   id INTEGER NOT NULL PRIMARY KEY,
   name VARCHAR(50) NOT NULL
 );
--
 INSERT INTO dogs(id, name) values(1, 'Lola');
 INSERT INTO dogs(id, name) values(2, 'Bella');
 INSERT INTO dogs(id, name) values(3, 'Malhado');
 INSERT INTO dogs(id, name) values(4, 'Denver');
 INSERT INTO dogs(id, name) values(5, 'Aurora');
 INSERT INTO cats(id, name) values(1, 'Lola');
 INSERT INTO cats(id, name) values(2, 'Kitty');
 INSERT INTO cats(id, name) values(3, 'Noelle');
 INSERT INTO cats(id, name) values(4, 'Malhado');

-- Expected output (in any order):
-- name
-- -----
-- Bella
-- Kitty
-- Lola
-- Noelle
-- Malhado
-- Denver
-- Aurora


select name from dogs
union
select name from cats;
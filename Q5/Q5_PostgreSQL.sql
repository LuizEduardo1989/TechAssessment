-- PostgreSQL
-- Create the [students] db table
CREATE TABLE public.students (
       id int4 NOT NULL GENERATED ALWAYS AS IDENTITY,
       "Name" varchar NOT NULL,
       marks int4 NOT NULL,
CONSTRAINT students_pk PRIMARY KEY (id)
);

-- Create the [grades] db table
CREATE TABLE public.grades (
       grade    int4 NOT NULL,
       min_mark int4 NOT NULL,
       max_mark int4 NOT NULL,
CONSTRAINT grades_pk PRIMARY KEY (grade)
);

-- PostgreSQL
-- Insert records into the [students] db table
INSERT INTO public.students ("Name", marks) 
VALUES ('Juia',88),
       ('Samantha',68),
       ('Maria',99),
       ('Scarlet',78),
       ('Ashley',63),
       ('Jane',81);

-- Insert records into the [grades] db table
INSERT INTO public.grades (grade,min_mark,max_mark) 
VALUES (1,0,9),
       (2,10,19),
       (3,20,29),
       (4,30,39),
       (5,40,49),
       (6,50,59),
       (7,60,69),
       (8,70,79),
       (9,80,89),
       (10,90,100);

-- PostgreSQL
SELECT CASE 
       -- If the grade is lower than 8, use "NULL" as Name
       WHEN t2.grade < 8 THEN 'NULL'
       -- Otherwise show the actual name
       ELSE t1."Name"
       END AS Name,
       t2.grade,
       t1.marks 
FROM students t1
-- Join the grades DB table by binding the marks column of the students table with
-- the min_mark and max_mark columns of the grades DB table
INNER JOIN grades t2 ON (t1.marks >= t2.min_mark AND t1.marks <= t2.max_mark)
-- Order by grade in Descending order, then by name in Ascending order and
-- for those students (NULLs) with the same grade (1-7) order by grade in Ascending order
ORDER BY t2.grade DESC, Name, t1.marks ASC